#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"

extern CTexture FeverGage;

int CSceneGame::COUNTDOWN;
int CSceneGame::LETTERTIME;

int CSceneGame::YScore;
int CSceneGame::RScore; 
int CSceneGame::BScore; 
int CSceneGame::GScore;

int CSceneGame::Stage1_Wave1Score;
std::shared_ptr<CTexture>TextureExp(new CTexture());

#define COUNTDOUN 240
#define ATTENTION 60
#define BATTENTIONTIME 240
#define CPCOUNTDOUNTIME 240
#define TIMEATTENTIONTIME 120
#define STAGE1_WAVE1TIME 4800

#define COLORHP 2

#define YELLOWPOINT 20000
#define REDPOINT 10000
#define BULEPOINT 7000
#define GREENPOINT 5000

void CSceneGame::Init() {

	COUNTDOWN = COUNTDOUN;

	Attention = ATTENTION;

	BAttentionTime = BATTENTIONTIME;

	CPAttentionTime = CPCOUNTDOUNTIME;

	TimeAttentionTime = TIMEATTENTIONTIME;

	WAVE1GAMETIME = STAGE1_WAVE1TIME;

	mScene = EGAME1_WAVE1;

	Result = false;

	BigTime = true;

	YScore = YELLOWPOINT;//黄色けしボーナス
	RScore = REDPOINT;//赤けしボーナス
	BScore = BULEPOINT;//青けしボーナス
	GScore = GREENPOINT;//緑けしボーナス

	TextureExp->Load("exp.tga");
	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CBlackText::mBFont.Load("font.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	CColorItem::mRed.Load("cube.obj", "Red.mtl");//赤
	CColorItem::mBlue.Load("cube.obj", "Blue.mtl");//青
	CColorItem::mGreen.Load("cube.obj", "Green.mtl");//緑
	CColorItem::mYellow.Load("cube.obj", "Yellow.mtl");//黄

	//FeverGage.Load();

	mStage1.Load("2DStage0119.obj", "2DStage0119.mtl");

	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBoard.Load("cube.obj", "cube.mtl");

	mMove.Load("cube.obj", "movecube.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mDammyBall.Load("sphere.obj", "sphere.mtl");

	mBomb.Load("Bomb.obj", "Bomb.mtl");

	mDelete.Load("cube.obj", "cube.mtl");

	m2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");

	mRe2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");
	
	/*スピンアイテムブロック----------------------------------------------------------------------------*/

	new CSpinItem(&mBoardR, CVector(0.0f, 20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(22.0f, 22.0f, 5.0));

	/*移動アイテムブロック----------------------------------------------------------------------------*/

	new CMoveItem(&mMove, CVector(-2000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1900.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1700.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1600.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1500.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1400.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1300.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1200.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1100.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-1000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-900.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mMove, CVector(-700.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));

	/*ノーマルアイテムブロック----------------------------------------------------------------------------*/
	new CNormalItem(&mBoard, CVector(150.0f/*40.0*/, -75.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CNormalItem(&mBoard, CVector(-150.0f/*40.0*/, -75.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CNormalItem(&mBoard, CVector(150.0f/*40.0*/, 75.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CNormalItem(&mBoard, CVector(-150.0f/*40.0*/, 75.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	
	new CNormalItem(&mBoard, CVector(200.0f/*40.0*/, 150.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(17.0, 17.0, 17.0));
	new CNormalItem(&mBoard, CVector(-200.0f/*40.0*/, 150.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(17.0, 17.0, 17.0));
	new CNormalItem(&mBoard, CVector(200.0f/*40.0*/, -150.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(17.0, 17.0, 17.0));
	new CNormalItem(&mBoard, CVector(-200.0f/*40.0*/, -150.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(17.0, 17.0, 17.0));

	/*カラーアイテムブロック----------------------------------------------------------------------------*/

	//CColorItem::RCount = COLORHP;
	//CColorItem::BCount = COLORHP;
	//CColorItem::GCount = COLORHP;
	//CColorItem::YCount = COLORHP;

	//new CColorItem(&CColorItem::mRed, CVector(0.0f, 200.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));
	//new CColorItem(&CColorItem::mYellow, CVector(0.0f, -200.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));

	//CColorItem::RCount = CColorItem::RCount - 1;

	//CColorItem::YCount = CColorItem::YCount - 1;

	///*ボーナスアイテムブロック----------------------------------------------------------------------------*/

	new CObj(&mStage1, CVector(0.0f, 0.0f, 0.0f), CVector(90.0f, 90.0f, 90.0), CVector(40.0f, 40.0f, 40.0));

	//プレイヤー
	new CPlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(1.65, 1.65, 1.65));
	new CRePlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(0.75, 0.75, 0.75));
	//
	//玉
	new CBallPlayer(&mBall, CVector(0.0f, 80.0f, 0.0f), CVector(), CVector(9.0f, 9.0f, 9.0));
	new CExItem(&mBomb, CVector(0.0f/*100*/, 450.0f, 0.0f), CVector(), CVector(20.0f, 20.0f, 20.0));

	//new CDammyBallPlayer(&mDammyBall, CVector(200.0, 50.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

	new CDeleteBlock(&mDelete, CVector(-320.0f, -320.0f, 0.0f), CVector(0.0, 0.0, -45.0), CVector(100.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(320.0f, -320.0f, 0.0f), CVector(0.0, 0.0, 45.0), CVector(100.0f, 10.0f, 10.0));

	new CDeleteBlock(&mDelete, CVector(310.0f, 310.0f, 0.0f), CVector(0.0, 0.0, -45.0), CVector(100.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(-310.0f, 310.0f, 0.0f), CVector(0.0, 0.0, 45.0), CVector(100.0f, 10.0f, 10.0));


	new CResBlock(&mDelete, CVector(-210.0f, 480.0f, 0.0f), CVector(0.0, 0.0, 90.0), CVector(80.0f, 10.0f, 10.0));
	new CResBlock(&mDelete, CVector(210.0f, 480.0f, 0.0f), CVector(0.0, 0.0, -90.0), CVector(80.0f, 10.0f, 10.0));
	new CResBlock(&mDelete, CVector(0.0f, 530.0f, 0.0f), CVector(0.0, 0.0, 0.0), CVector(240.0f, 10.0f, 10.0));

	CSceneGame::ResetF = true;

	CSceneGame::mEnable = true;
}


void CSceneGame::Update() {

	if (CSceneGame::WAVE1GAMETIME > 61){
	
		CTaskManager::Get()->Update();
	
		Stage1_Wave1Score = CBallPlayer::ScoreBox + CColorItem::CMyScorePoint;

		Result = true;

	}

	if (CSceneGame::WAVE1GAMETIME < 1801){

		CSpinItem::RebirthF=true;
		CMoveItem::RebirthF = true;
	}


	if (CSceneGame::WAVE1GAMETIME < 61){

		Result = false;

		mEnable = false;

		if (Result == false){

			if (CKey::Once(VK_RETURN)){

				mScene = EGAME1_WAVE2;

			}
		}
	}

	CBallPlayer::mAdjust.mZ = NULL;
	CDammyBallPlayer::mDAdjust.mZ = NULL;
	CExItem::mAdjust.mZ = NULL;

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = CVector(0.0f, 0.0f, -550.0f);
	//注視点を求める
	c = CVector(0.0f, 0.0f, 0.0f);
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f);

	//カメラの設定
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	//CCollisionManager::Get()->Render();

	//2D描画開始
	Start2D(0, 800, 0, 600);

	/*---------------------------------------------------------------------------------------*/

	//ステージ、ウェーブ名
	CText::DrawString("SUTAG1", 10, 585, 12, 14);
	CText::DrawString("WAVE 1", 10, 555, 12, 14);
	CText::DrawString("WAVE1TIME", 620, 575, 10, 16);
	CText::DrawString("BALL LIFE", 570, 30, 10, 16);

	char buf[100];
	sprintf(buf, "%d", CBallPlayer::BallHP);
	CBlackText::DrawString(buf, 780, 26, 12, 12);

	//フィーバーゲージ
	if (CBallPlayer::FeverCount > 19
		&& CMoveItem::FeverF == false){

		CText::DrawString("PUSH F KEY!!", 24, 50, 12, 14);

	}

	//獲得カラーポイント

	//現在スコア

	CText::DrawString("SCORE", 40, 20, 12, 14);

	sprintf(buf, "%d", CSceneGame::Stage1_Wave1Score + CColorItem::CMyScorePoint);

	CBlackText::DrawString(buf, 200, 20, 10, 12);

	/*---------------------------------------------------------------------------------------*/

	if (COUNTDOWN > 0){//最初のカウントダウン

		COUNTDOWN--;

		if (ResetF == true){
		
			char buf[10];

			if (COUNTDOWN > 61){
			
				sprintf(buf, "%d", COUNTDOWN / 60);

				CText::DrawString(buf, 400, 500, 30, 30);

			}

			if (COUNTDOWN < 60 && COUNTDOWN > 0){

				CText::DrawString("GO!!", 300, 500, 30, 30);

			}


		}

	}

	/*---------------------------------------------------------------------------------------*/

	//タイム処理

	if (COUNTDOWN <= 0){
		WAVE1GAMETIME--;
	}
		if (WAVE1GAMETIME > 601){//ウェーブごとの時間
			BigTime = false;
			if (BigTime == false){
				if (WAVE1GAMETIME > 1801){

					char buf[10];
					sprintf(buf, "%d", WAVE1GAMETIME / 60);
					CText::DrawString(buf, 680, 540, 20, 20);
				}
			}
		}

		if (WAVE1GAMETIME < 1800 && WAVE1GAMETIME > 1720){
			TimeAttentionTime--;
			if (TimeAttentionTime > 0){
				TimeAttension = true;
				Attention--;
				if (TimeAttension == true){

					if (Attention < 30){
						char buf[10];
						sprintf(buf, "%d", WAVE1GAMETIME / 60);
						CText::DrawString(buf, 400, 520, 30, 30);
					}
				}
				if (Attention == 0){
					Attention = 1 * 60;
				}
			}
		}

		if (TimeAttentionTime < 0){
			TimeAttension = false;
		}

		if (WAVE1GAMETIME > 61 && WAVE1GAMETIME < 1719){//ウェーブごとの時間、大文字
			BigTime = true;
			if (BigTime == true){
				char buf[10];
				sprintf(buf, "%d", WAVE1GAMETIME / 60);
				CText::DrawString(buf, 678, 520, 45, 45);
			}
		}
		//！点滅
		
		if (CExItem::BomTime < 3000){
			BAttentionTime--;
			if (BAttentionTime > 0){
				BomAttension = true;
				Attention--;
				if (Attention < 30 && BomAttension == true){
					CText::DrawString("BOM IN!", 25, 500, 11, 20);
				}
				if (Attention == 0){
					Attention = 1 * 60;
				}
			}
		}
		if (BAttentionTime < 0){
			BomAttension = false;
		}

/*--------------------------------------------------------------------------------------*/
		
		if (CColorItem::YellowAttensionF == true){//黄色撃破
			CColorItem::ScorePulsF = true;
			if (CColorItem::ScorePulsF == true){
				CColorItem::CMyScorePoint = YScore;
				CColorItem::ScorePulsF = false;
			}

			CPAttentionTime--;
			if (CPAttentionTime > 0){
				ColorAttension = true;
				Attention--;
				if (ColorAttension == true){
					if (Attention > 0 && Attention < 10 ||/**/
						Attention > 30 && Attention < 40/**/){
						CText::DrawString("YELLOW BONUS", 26, 500, 7, 14);
						sprintf(buf, "%d",CColorItem::CMyScorePoint);
						CText::DrawString(buf, 30, 470, 12, 14);
					}
				}

				if (Attention == 0){
					Attention = 1 * 60;
				}
			}
		}

		if (CPAttentionTime < 0){
			ColorAttension = false;
			CColorItem::YellowAttensionF = false;
		}

/*--------------------------------------------------------------------------------------*/

			if (CColorItem::RedAttensionF == true){//赤撃破
				CColorItem::ScorePulsF = true;
				if (CColorItem::ScorePulsF == true){
					CColorItem::CMyScorePoint = RScore;
					CColorItem::ScorePulsF = false;
				}

				CPAttentionTime--;
				if (CPAttentionTime > 0){
					ColorAttension = true;
					Attention--;
					if (ColorAttension == true){
						if (Attention > 0 && Attention < 10 ||/**/
							Attention > 30 && Attention < 40/**/){
							CText::DrawString("RED BONUS", 26, 500, 7, 14);
							sprintf(buf, "%d", CColorItem::CMyScorePoint);
							CText::DrawString(buf, 30, 470, 12, 14);
						}
					}

					if (Attention == 0){
						Attention = 1 * 60;
					}
				}
			}

		if (CPAttentionTime < 0){
			ColorAttension = false;
			CColorItem::RedAttensionF = false;
		}

/*--------------------------------------------------------------------------------------*/
	
		if (CColorItem::BuleAttensionF == true){//青撃破
			CColorItem::ScorePulsF = true;
			if (CColorItem::ScorePulsF == true){
				CColorItem::CMyScorePoint = BScore;
				CColorItem::ScorePulsF = false;
			}

			CPAttentionTime--;
			if (CPAttentionTime > 0){
				ColorAttension = true;
				Attention--;
				if (ColorAttension == true){
					if (Attention > 0 && Attention < 10 ||/**/
						Attention > 30 && Attention < 40/**/){
						CText::DrawString("BULE BONUS", 26, 500, 7, 14);
						sprintf(buf, "%d", CColorItem::CMyScorePoint);
						CText::DrawString(buf, 30, 470, 12, 14);
					}
				}

				if (Attention == 0){
					Attention = 1 * 60;
				}
			}
		}

		if (CPAttentionTime < 0){
			ColorAttension = false;
			CColorItem::BuleAttensionF = false;
		}

/*--------------------------------------------------------------------------------------*/

		if (CColorItem::GreenAttensionF == true){//緑撃破
			CColorItem::ScorePulsF = true;
			if (CColorItem::ScorePulsF == true){
				CColorItem::CMyScorePoint = GScore;
				CColorItem::ScorePulsF = false;
			}

			CPAttentionTime--;
			if (CPAttentionTime > 0){
				ColorAttension = true;
				Attention--;
				if (ColorAttension == true){
					if (Attention > 0 && Attention < 10 ||/**/
						Attention > 30 && Attention < 40/**/){
						CText::DrawString("GREEN BONUS", 26, 500, 7, 14);
						sprintf(buf, "%d", CColorItem::CMyScorePoint);
						CText::DrawString(buf, 30, 470, 12, 14);
					}
				}

				if (Attention == 0){
					Attention = 1 * 60;
				}
			}
		}

		if (CPAttentionTime < 0){
			ColorAttension = false;
			CColorItem::GreenAttensionF = false;
		}

/*--------------------------------------------------------------------------------------*/


	if (WAVE1GAMETIME < 60){

		//時間切れ
		CText::DrawString("TIME UP!", 300, 500, 14, 16);
		CText::DrawString("LET'S NEXT WAVE", 260, 400, 10, 12);
		CText::DrawString("PUSH ENTER KEY", 260, 330, 10, 12);

	}

	if (CBallPlayer::BallHP == 0){

		CText::DrawString("GAME OVER...", 280, 400, 15, 18);

		if (CSceneGame::WAVE1GAMETIME < 61){

			Result = false;

			mEnable = false;

			if (Result == false){

				if (CKey::Once(VK_RETURN)){

					mScene = ESTAGE1_RESULT;

				}
			}
		}
	}

	CTaskManager::Get()->Delete();

	//2D描画終了
	End2D();

	return;
	
}
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame::~CSceneGame() {
	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();

	CTaskManager::Get()->Destory();
	CCollisionManager::Get()->Destory();

}
