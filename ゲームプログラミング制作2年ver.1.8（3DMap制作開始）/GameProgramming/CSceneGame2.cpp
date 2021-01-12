#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"
//
int CSceneGame2::GAMETIME;
int CSceneGame2::COUNTDOWN;
int CSceneGame2::LETTERTIME;
void CSceneGame2::Init() {

	COUNTDOWN = 4 * 60;

	GAMETIME = 121 * 60;

	mScene = EGAME2;

	Result = false;

	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	CBlackText::mBFont.Load("font.tga");
	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBoard.Load("cube.obj", "cube.mtl");

	mItem.Load("sphere.obj", "sphere.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mStage.Load("StageEdit0111.obj", "StageEdit0111.mtl");
	mStage.mMaterials[0].mDiffuse[3] = 0.5f;

	//mStage.Load("STAGE(2)_Edit_OF_0102.obj", "STAGE(2)_Edit_OF_0102.mtl");

	m3DPlayer.Load("3DPlayer.obj","3DPlayer.mtl");

	mDelete.Load("3DMapDeleteBlock.obj", "3DMapDeleteBlock.mtl");
	//mDelete.mMaterials[0].mDiffuse[3] = 0.0f;

	//new CSpinItem(&mBoardR, CVector(-60.0f, 20.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(60.0f, 20.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(110.0f, 30.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(-110.0f, 30.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));

	//new CItem(&mBoard, CVector(40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(11.0, 11.0, 11.0));

	//new CItem(&mBoard, CVector(50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));

	//new CItem(&mBoard, CVector(120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 80.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 80.0f), CVector(11.0, 11.0, 11.0));

	new C3DMap(&mStage, CVector(0.0,31.0/*STAGE2の時だけ151*/,0.0), CVector(0.0,0.0,180.0), CVector(7.0, 7.0, 7.0));
	new C3DDelete(&mDelete, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0, 180.0), CVector(15.0, 15.0, 15.0));
	//new CMoveItem(&mBoard, CVector(600.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(2.0f, 2.0f, 2.0));

	//プレイヤー(板)

	new C3DPlayer(&m3DPlayer, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0, 180.0), CVector(0.9, 0.9, 0.9));

	////玉
	new CBallPlayer(&mBall, CVector(0.0f, 50.0f, 0.0f), CVector(), CVector(5.0f, 5.0f, 5.0));

	CSceneGame2::ResetF = true;

	CSceneGame2::mEnable = true;

}


void CSceneGame2::Update() {

	if (CSceneGame2::GAMETIME > 61){

		CTaskManager::Get()->Update();

		Result = true;

	}

	//if (CSceneGame2::GAMETIME < 1801){

	//	CSpinItem::RebirthF = true;
	//	CMoveItem::RebirthF = true;
	//}

	if (CSceneGame2::GAMETIME < 61){

		Result = false;

		mEnable = false;

		if (Result == false){

			if (CKey::Once(VK_RETURN)){

				mScene = ERESULT;

			}

		}

	}


	mCamera.mPosition = CVector(0.0, 0.0, 0.0);
	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める

	e = CVector(0.0f, 150.0f, 400.0f)*mCamera.mMatrix;

	//注視点を求める

	c = CVector(0.0f, 0.0f, 0.0f);

	//上方向を求める

	u = CVector(0.0f, 10.0f, 0.0f)*mCamera.mMatrix;

	//カメラの設定
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CMatrix Matrix;

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	CCollisionManager::Get()->Render();

	//2D描画開始
	Start2D(0, 800, 0, 600);

	if (COUNTDOWN > 60){

		//COUNTDOWN--;

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

			CText::DrawString(buf, 640, 30, 30, 30);

		}

		else{

			CText::DrawString("GAME  SET!!", 300, 500, 10, 12);

		}

	}

	if (CBallPlayer::BallHP == 0){

		CBallPlayer::BallHP = 0;

		CText::DrawString("GAME OVER...", 280, 400, 15, 18);
	}

	CText::DrawString("SUTAG.2", 20, 20, 10, 12);

	char buf[100];

	sprintf(buf, "%d", CBallPlayer::ScoreBox);

	CBlackText::DrawString(buf, 200, 20, 10, 12);

	CTaskManager::Get()->Delete();

	//2D描画終了
	End2D();

	return;

}
CScene::EScene CSceneGame2::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame2::~CSceneGame2() {
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
