#include "CSceneGame_Wave2.h"
//
#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"

int CSceneGame_Wave2::COUNTDOWN;
int CSceneGame_Wave2::LETTERTIME;

int CSceneGame_Wave2::YScore;
int CSceneGame_Wave2::RScore;
int CSceneGame_Wave2::BScore;
int CSceneGame_Wave2::GScore;

int CSceneGame_Wave2::Stage1_Wave2Score;
extern std::shared_ptr<CTexture>TextureExp;
void CSceneGame_Wave2::Init() {

	COUNTDOWN = 4 * 60;

	Attention = 1 * 60;

	BAttentionTime = 4 * 60;

	CPAttentionTime = 4 * 60;

	WAVE2GAMETIME = 100 * 60;

	mScene = EGAME1_WAVE2;
	Result = false;

	BigTime = true;

	YScore = 20000;//黄色けしボーナス
	RScore = 10000;//赤けしボーナス
	BScore = 7000;//青けしボーナス
	GScore = 5000;//緑けしボーナス

	TextureExp->Load("exp.tga");
	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CBlackText::mBFont.Load("font.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	CColorItem::mRed.Load("cube.obj", "Red.mtl");//赤
	CColorItem::mBlue.Load("cube.obj", "Blue.mtl");//青
	CColorItem::mGreen.Load("cube.obj", "Green.mtl");//緑
	CColorItem::mYellow.Load("cube.obj", "Yellow.mtl");//黄

	mStage1.Load("2DStage0119.obj", "2DStage0119.mtl");

	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBoard.Load("cube.obj", "cube.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mBomb.Load("Bomb.obj", "Bomb.mtl");

	mSuperBomb.Load("Bomb.obj", "Bomb.mtl");

	mDelete.Load("cube.obj", "cube.mtl");

	m2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");

	mRe2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");

	//mDelete.mMaterials[0].mDiffuse[3] = 0.0f;

	/*スピンアイテムブロック----------------------------------------------------------------------------*/
	new CSpinItem(&mBoardR, CVector(-200.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0), CVector(20.0f, 20.0f, 14.0));
	new CSpinItem(&mBoardR, CVector(200.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0), CVector(20.0f, 20.0f, 14.0));

	new CSpinItem(&mBoardR, CVector(0.0f, 20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(22.0f, 22.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(-110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(0.0f, -20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0f,15.0f, 10.0));

	///*移動アイテムブロック----------------------------------------------------------------------------*/

	new CMoveItem(&mBoard, CVector(-2000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1900.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1700.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1600.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1500.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1400.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1300.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1200.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1100.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-900.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-700.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));

	/*ノーマルアイテムブロック----------------------------------------------------------------------------*/
	//new CItem(&mBoard, CVector(200.0f/*40.0*/, -150.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(200.0f/*40.0*/, 150.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-200.0f/*40.0*/, -150.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-200.0f/*40.0*/, 150.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(11.0, 11.0, 11.0));

	//new CItem(&mBoard, CVector(-40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 65.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 65.0f), CVector(11.0, 11.0, 11.0));

	/*カラーアイテムブロック----------------------------------------------------------------------------*/

	CColorItem::RCount = 2;
	CColorItem::BCount = 2;
	CColorItem::GCount = 2;
	CColorItem::YCount = 2;

	new CColorItem(&CColorItem::mBlue, CVector(250.0f, 100.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));
	new CColorItem(&CColorItem::mYellow, CVector(-250.0f, -100.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));

	CColorItem::BCount = CColorItem::BCount - 1;

	CColorItem::YCount = CColorItem::YCount - 1;

	//new CColorItem(&CColorItem::mGreen, CVector(0.0f, -200.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));
	//new CColorItem(&CColorItem::mRed, CVector(0.0f, 200.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));

	///*ボーナスアイテムブロック----------------------------------------------------------------------------*/
	new CBonus(&mBoard, CVector(600.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(2.0f, 2.0f, 2.0));

	new CObj(&mStage1, CVector(0.0f, 0.0f, 0.0f), CVector(90.0f, 90.0f, 90.0), CVector(40.0f, 40.0f, 40.0));

	//プレイヤー
	new CPlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(1.65, 1.65, 1.65));
	new CRePlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(0.75, 0.75, 0.75));
	//
	//玉
	new CBallPlayer(&mBall, CVector(0.0f, 80.0f, 0.0f), CVector(), CVector(9.0f, 9.0f, 9.0));
	new CExItem(&mBomb, CVector(0.0f/*100*/, 450.0f, 0.0f), CVector(), CVector(20.0f, 20.0f, 20.0));
	new CExItem(&mBomb, CVector(-70.0f/*100*/, 550.0f, 0.0f), CVector(), CVector(20.0f, 20.0f, 20.0));

	new CDammyBallPlayer(&mDammyBall, CVector(200.0, 50.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));

	/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

	new CDeleteBlock(&mDelete, CVector(-320.0f, -320.0f, 0.0f), CVector(0.0, 0.0, -45.0), CVector(100.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(320.0f, -320.0f, 0.0f), CVector(0.0, 0.0, 45.0), CVector(100.0f, 10.0f, 10.0));

	new CDeleteBlock(&mDelete, CVector(310.0f, 310.0f, 0.0f), CVector(0.0, 0.0, -45.0), CVector(100.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(-310.0f, 310.0f, 0.0f), CVector(0.0, 0.0, 45.0), CVector(100.0f, 10.0f, 10.0));

	new CDeleteBlock(&mDelete, CVector(-210.0f, 550.0f, 0.0f), CVector(0.0, 0.0, 90.0), CVector(160.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(210.0f, 550.0f, 0.0f), CVector(0.0, 0.0, -90.0), CVector(160.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(0.0f, 610.0f, 0.0f), CVector(0.0, 0.0, 0.0), CVector(240.0f, 10.0f, 10.0));

	CSceneGame_Wave2::ResetF = true;

	CSceneGame_Wave2::mEnable = true;

}


void CSceneGame_Wave2::Update() {

	if (CSceneGame_Wave2::WAVE2GAMETIME > 61){

		CTaskManager::Get()->Update();

		Result = true;

		Stage1_Wave2Score = CBallPlayer::ScoreBox;

	}

	if (CSceneGame_Wave2::WAVE2GAMETIME < 1801){

		CSpinItem::RebirthF = true;
		CMoveItem::RebirthF = true;
	}


	if (CSceneGame_Wave2::WAVE2GAMETIME < 61){

		Result = false;

		mEnable = false;

		if (Result == false){

			if (CKey::Once(VK_RETURN)){

				mScene = ESTAGE1_RESULT;

			}
		}
	}

	CBallPlayer::mAdjust.mZ = NULL;
	CDammyBallPlayer::mDAdjust.mZ = NULL;
	CExItem::mAdjust.mZ = NULL;

	if (CBallPlayer::CF == true){

		//CColorItem::ScorePulsF = false;

		if (CColorItem::YCount == 0){

			CColorItem::ScorePulsF = true;

			if (CColorItem::ScorePulsF == true){

				CColorItem::CMyScorePoint = YScore;

				CColorItem::ScorePulsF = false;

			}

		}
		if (CColorItem::RCount == 0){

			CColorItem::ScorePulsF = true;

			if (CColorItem::ScorePulsF == true){

				CColorItem::CMyScorePoint = RScore;

				CColorItem::ScorePulsF = false;

			}

		}
		if (CColorItem::BCount == 0){

			CColorItem::ScorePulsF = true;

			if (CColorItem::ScorePulsF == true){

				CColorItem::CMyScorePoint = BScore;

				CColorItem::ScorePulsF = false;

			}

		}
		if (CColorItem::GCount == 0){

			CColorItem::ScorePulsF = true;

			if (CColorItem::ScorePulsF == true){

				CColorItem::CMyScorePoint = GScore;

				CColorItem::ScorePulsF = false;

			}
		}

	}


	//CColorItem::ChangeColor();

	CBallPlayer::mAdjust.mZ = NULL;

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = CVector(0.0f, 0.0f, -850.0f);////0.0,0.0,-300
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

	if (COUNTDOWN > 60){

		COUNTDOWN--;

		if (ResetF == true){

			char buf[10];

			sprintf(buf, "%d", COUNTDOWN / 60);

			CText::DrawString(buf, 400, 500, 30, 30);

		}

	}

	else if (COUNTDOWN > 0){

		COUNTDOWN--;

		CText::DrawString("GO!!", 300, 500, 30, 30);
	}

	if (COUNTDOWN <= 0){

		if (WAVE2GAMETIME > 60){

			WAVE2GAMETIME--;

			char buf[10];

			sprintf(buf, "%d", WAVE2GAMETIME / 60);

			CText::DrawString(buf, 680, 30, 30, 30);

		}

		else{

			CText::DrawString("TIME UP!", 300, 500, 10, 12);

			CText::DrawString("PUSH ENTER KEY", 300, 500, 6, 8);


		}

	}

	if (CBallPlayer::BallHP == 0){

		CBallPlayer::BallHP = 0;

		CText::DrawString("GAME OVER...", 280, 400, 15, 18);
	}

	if (CBallPlayer::FeverCount > 19
		&& CMoveItem::FeverF == false){

		CText::DrawString("PUSH F KEY!!", 24, 50, 12, 14);

	}
	CText::DrawString("SUTAG.1", 20, 20, 10, 12);

	char buf[100];

	sprintf(buf, "%d", CSceneGame_Wave2::Stage1_Wave2Score);

	CBlackText::DrawString(buf, 200, 20, 10, 12);

	CTaskManager::Get()->Delete();

	//2D描画終了
	End2D();


	return;

}
CScene::EScene CSceneGame_Wave2::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame_Wave2::~CSceneGame_Wave2() {
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

