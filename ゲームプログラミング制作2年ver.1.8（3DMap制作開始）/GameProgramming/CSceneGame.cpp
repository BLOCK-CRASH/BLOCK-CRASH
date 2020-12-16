#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"
int CSceneGame::GAMETIME;
int CSceneGame::COUNTDOWN;
int CSceneGame::LETTERTIME;
std::shared_ptr<CTexture>TextureExp(new CTexture());

void CSceneGame::Init() {

	COUNTDOWN = 4 * 60;

	GAMETIME = 61 * 60;

	mScene = EGAME1;

	Result = false;

	TextureExp->Load("exp.tga");
	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CBlackText::mBFont.Load("font.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBoard.Load("cube.obj", "cube.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mBomb.Load("Bomb.obj", "Bomb.mtl");

	mDelete.Load("cube.obj", "cube.mtl");
	mDelete.mMaterials[0].mDiffuse[3] = 0.0f;
	
	/*スピンアイテムブロック----------------------------------------------------------------------------*/
	new CSpinItem(&mBoardR, CVector(-60.0f, 20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	new CSpinItem(&mBoardR, CVector(60.0f, 20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	new CSpinItem(&mBoardR, CVector(110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	new CSpinItem(&mBoardR, CVector(-110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	new CSpinItem(&mBoardR, CVector(0.0f, -20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0f,15.0f, 10.0));

	/*ノーマルアイテムブロック----------------------------------------------------------------------------*/
	new CItem(&mBoard, CVector(40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(-40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(-50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 80.0f), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(-120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 80.0f), CVector(11.0, 11.0, 11.0));
	/*ボーナスアイテムブロック----------------------------------------------------------------------------*/
	new CBonus(&mBoard, CVector(600.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(2.0f, 2.0f, 2.0));
	/*移動アイテムブロック----------------------------------------------------------------------------*/
	new CMoveItem(&mBoard, CVector(-120.0f, -130.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(6.0, 6.0, 6.0));
	new CMoveItem(&mBoard, CVector(120.0f, -130.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(6.0, 6.0, 6.0));
	new CMoveItem(&mBoard, CVector(60.0f, -25.0f, 0.0f), CVector(0.0f, 0.0f, 60.0f), CVector(6.0, 6.0, 6.0));
	new CMoveItem(&mBoard, CVector(-60.0f, -25.0f, 0.0f), CVector(0.0f, 0.0f, -60.0f), CVector(6.0, 6.0, 6.0));
	new CMoveItem(&mBoard, CVector(140.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 110.0f), CVector(6.0, 6.0, 6.0));
	new CMoveItem(&mBoard, CVector(-140.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, -110.0f), CVector(6.0, 6.0, 6.0));

	/*マップブロック----------------------------------------------------------------------------*/
	new CObj(&mBoard, CVector(265.0f, 137.0f, 0.0f), CVector(0.0f, 0.0f, 75.0), CVector(15.0f, 120.0f, 10.0));
	new CObj(&mBoard, CVector(-265.0f, 137.0f, 0.0f), CVector(0.0f, 0.0f, -75.0), CVector(15.0f, 120.0f, 10.0));
	new CObj(&mBoard, CVector(-235.0f, -125.0f, 0.0f), CVector(0.0f, 0.0f, -10.0), CVector(20.0f, 170.0f, 10.0));
	new CObj(&mBoard, CVector(235.0f, -125.0f, 0.0f), CVector(0.0f, 0.0f, 10.0), CVector(20.0f, 170.0f, 10.0));
	new CObj(&mBoard, CVector(195.0f, -160.0f, 0.0f), CVector(0.0f, 0.0f, -20.0), CVector(20.0f, 40.0f, 10.0));
	new CObj(&mBoard, CVector(-195.0f, -160.0f, 0.0f), CVector(0.0f, 0.0f, 20.0), CVector(20.0f, 40.0f, 10.0));
	new CObj(&mBoard, CVector(-235.0f, -120.0f, 0.0f), CVector(0.0f, 0.0f, -115.0), CVector(20.0f, 95.0f, 10.0));
	new CObj(&mBoard, CVector(235.0f, -120.0f, 0.0f), CVector(0.0f, 0.0f, 115.0), CVector(20.0f, 95.0f, 10.0));
	new CObj(&mBoard, CVector(195.0f, 135.0f, 0.0f), CVector(0.0f, 0.0f, 40.0), CVector(20.0f, 20.0f, 10.0));
	new CObj(&mBoard, CVector(-195.0f, 135.0f, 0.0f), CVector(0.0f, 0.0f, -40.0), CVector(20.0f, 20.0f, 10.0));

	//プレイヤー(板)
	new CPlayer(&mBoard, CVector(0.0f, 120.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 3.0f, 1.0));
	new CBottomPlayer(&mBoard, CVector(0.0f, -110.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0));
	//玉
	new CBallPlayer(&mBall, CVector(0.0f, 50.0f, 0.0f), CVector(), CVector(5.0f, 5.0f, 5.0));
	new CExItem(&mBomb, CVector(0.0f/*100*/, 300.0f, 0.0f), CVector(), CVector(10.0f, 10.0f, 10.0));

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

	new CDeleteBlock(&mDelete, CVector(0.0f, -260.0f, 0.0f), CVector(), CVector(200.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(0.0f, 230.0f, 0.0f), CVector(), CVector(200.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(250.0f, 0.0f, 0.0f), CVector(0.0,0.0,90.0), CVector(200.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(-250.0f, 0.0f, 0.0f), CVector(0.0, 0.0, 90.0), CVector(200.0f, 10.0f, 10.0));

	CSceneGame::ResetF = true;
}


void CSceneGame::Update() {

	if (CSceneGame::GAMETIME > 61){
	
		CTaskManager::Get()->Update();
	
		Result = true;
	}

	if (CSceneGame::GAMETIME < 1801){

		CSpinItem::RebirthF=true;

	}


	if (CSceneGame::GAMETIME < 61){

		Result = false;

		if (Result == false){

			if (CKey::Once(VK_RETURN)){

				mScene = ERESULT;

			}


		}

	}

	//

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = CVector(0.0f, 5.0f, -300.0f);
	//注視点を求める
	c = CVector(0.0f, 0.0f, 0.0f);
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f);

	//カメラの設定
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	CCollisionManager::Get()->Render();

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
	
		if (GAMETIME > 60){

			GAMETIME--;

			char buf[10];

			sprintf(buf, "%d", GAMETIME / 60);

			CText::DrawString(buf, 680, 30, 30, 30);

		}

		else{

			CText::DrawString("GAME  SET!!", 300, 500, 10, 12);

		}

	}

	if (CBallPlayer::BallHP == 0){

		CBallPlayer::BallHP = 0;

		CText::DrawString("GAME OVER...", 280, 400, 15, 18);
	}

	CText::DrawString("SUTAG.1", 20, 20, 10, 12);

	char buf[100];

	sprintf(buf, "%d", CBallPlayer::ScoreBox);

	CBlackText::DrawString(buf, 200, 20, 10, 12);

	//if (CBallPlayer::ScoreBox <= -1){

	//	CBlackText::DrawString("-", 15, 20, 10, 12);

	//}

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
}
