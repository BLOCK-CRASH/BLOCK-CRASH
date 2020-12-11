#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CRock.h"
//
#include "CItem.h"
int CSceneGame::GAMETIME;
int CSceneGame::LETTERTIME;
std::shared_ptr<CTexture>TextureExp(new CTexture());

void CSceneGame::Init() {

	GAMETIME = 4 * 60;

	mScene = EGAME1;


	TextureExp->Load("exp.tga");
	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	//mSky.Load("sky.obj", "sky.mtl");

	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBoard.Load("cube.obj", "cube.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mBomb.Load("Bomb.obj", "Bomb.mtl");

	mDelete.Load("cube.obj", "cube.mtl");

	//new CSpinItem(&mBoardR, CVector(-60.0f, 20.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(60.0f, 20.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(110.0f, 30.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(-110.0f, 30.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));

	//new CItem(&mBoard, CVector(40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(11.0, 11.0, 11.0));

	//new CItem(&mBoard, CVector(50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));

	//new CItem(&mBoard, CVector(120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 80.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 80.0f), CVector(11.0, 11.0, 11.0));

	//new CMoveItem(&mBoard, CVector(600.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(2.0f, 2.0f, 2.0));

	//アウトライン
	//new COut(&mOut,CVector(0.0f, -70.0f, 0.0f), CVector(), CVector(100.0f, 5.0f, 2.0));

	new CObj(&mBoard, CVector(255.0f, 130.0f, 0.0f), CVector(0.0f, 0.0f, 75.0), CVector(20.0f, 120.0f, 10.0));
	new CObj(&mBoard, CVector(-255.0f, 130.0f, 0.0f), CVector(0.0f, 0.0f, -75.0), CVector(20.0f, 120.0f, 10.0));
	new CObj(&mBoard, CVector(-235.0f, -120.0f, 0.0f), CVector(0.0f, 0.0f, -115.0), CVector(20.0f, 95.0f, 10.0));
	new CObj(&mBoard, CVector(235.0f, -120.0f, 0.0f), CVector(0.0f, 0.0f, 115.0), CVector(20.0f, 95.0f, 10.0));
	new CObj(&mBoard, CVector(-230.0f, -125.0f, 0.0f), CVector(0.0f, 0.0f, -15.0), CVector(20.0f, 160.0f, 10.0));
	new CObj(&mBoard, CVector(230.0f, -125.0f, 0.0f), CVector(0.0f, 0.0f, 15.0), CVector(20.0f, 160.0f, 10.0));
	new CObj(&mBoard, CVector(160.0f, 130.0f, 0.0f), CVector(0.0f, 0.0f, 45.0), CVector(20.0f, 20.0f, 10.0));
	new CObj(&mBoard, CVector(-130.0f, 130.0f, 0.0f), CVector(0.0f, 0.0f, 45.0), CVector(20.0f, 20.0f, 10.0));
	new CObj(&mBoard, CVector(195.0f, -132.0f, 0.0f), CVector(0.0f, 0.0f, -20.0), CVector(20.0f, 40.0f, 10.0));
	new CObj(&mBoard, CVector(-195.0f, -132.0f, 0.0f), CVector(0.0f, 0.0f, 20.0), CVector(20.0f, 40.0f, 10.0));

	//プレイヤー(板)
	new CPlayer(&mBoard, CVector(0.0f, 120.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 3.0f, 1.0));
	new CBottomPlayer(&mBoard, CVector(0.0f, -110.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0));
	//玉
	new CBallPlayer(&mBall, CVector(0.0f, 50.0f, 0.0f), CVector(), CVector(10.0f, 10.0f, 10.0));
	new CExItem(&mBomb, CVector(0.0f/*100*/, 100.0f, 0.0f), CVector(), CVector(10.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(0.0f, -300.0f, 0.0f), CVector(), CVector(200.0f, 5.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(0.0f, 250.0f, 0.0f), CVector(), CVector(200.0f, 5.0f, 10.0));

	CSceneGame::ResetF = true;
}


void CSceneGame::Update() {

	CTaskManager::Get()->Update();

	//

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = CVector(0.0f, 5.0f, -250.0f);
	//注視点を求める
	c = CVector(0.0f, 0.0f, 0.0f);
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f);

	//カメラの設定
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CMatrix Matrix;

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	CCollisionManager::Get()->Render();



	//2D描画開始
	Start2D(0, 800, 0, 600);


	if (GAMETIME > 60){

		GAMETIME--;

		if (ResetF == true){
		
			char buf[10];

			sprintf(buf, "%d", GAMETIME / 60);

			CText::DrawString(buf, 400, 500, 30, 30);

		}

	}

	else if (GAMETIME > 0){

		GAMETIME--;

			CText::DrawString("GO!!", 300, 500, 30, 30);
		}


	if (CBallPlayer::BallHP == 0){

		CBallPlayer::BallHP = 0;

		CText::DrawString("GAME OVER...", 280, 400, 15, 18);
	}

	//if (ItemsStageCount<= 0) {

	//	ResetF = false;

	//	CText::DrawString("WAVE CLEAR!", 280, 400, 15, 18);

	// 	//CBallPlayer::mpthis->mEnabled=false;

	//}

	//char buf[16];
	//sprintf(buf, "%d",)

	CText::DrawString("SUTAG.1", 20, 20, 10, 12);

	char buf[100];

	//CBallPlayer::ScoreBox = CBallPlayer::BScoreBox + CBallPlayer::SScoreBox;

	sprintf(buf, "%d", CBallPlayer::ScoreBox);

	CText::DrawString(buf, 200, 15, 10, 12);

	//if (CPlayer::mPosition){


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
