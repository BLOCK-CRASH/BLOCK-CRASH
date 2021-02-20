#include "CSceneGame2.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"
//
#include "BossItem.h"
int CSceneGame2::GAMETIME;
int CSceneGame2::COUNTDOWN;
int CSceneGame2::LETTERTIME;
void CSceneGame2::Init() {

	COUNTDOWN = 4 * 60;

	GAMETIME = 121 * 60;

	mScene = EGAME2_WAVE1;

	Result = false;

	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	CBlackText::mBFont.Load("font.tga");
	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mStage.Load("StageEdit0118.obj", "StageEdit0118.mtl");

	mStage.mMaterials[0].mDiffuse[3] = 0.5f;

	m3DPlayer2.Load("0205_3D_2Board.obj", "0205_3D_2Board.mtl");

	m3DPlayer2.mMaterials[0].mDiffuse[3] = 0.75f;

	mDelete.Load("AriBox0205.obj", "AriBox0205.mtl");
	mDelete.mMaterials[0].mDiffuse[3] = 0.0f;

	C3DShaveItem::mTri.Load("3Model.obj", "3Model.mtl");
	C3DShaveItem::mRec.Load("cube.obj", "cube.mtl");
	C3DShaveItem::mPen.Load("5Model.obj", "5Model.mtl");
	C3DShaveItem::mHex.Load("6Model.obj", "6Model.mtl");
	C3DShaveItem::mHep.Load("7Model.obj", "7Model.mtl");
	C3DShaveItem::mOct.Load("8Model.obj", "8Model.mtl");

	new C3DDelete(&mDelete, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0, 180.0), CVector(10, 10, 10));

	new C3DMap(&mStage, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0/*45*/, 180.0), CVector(7.0, 7.0, 7.0));

	//プレイヤー(板)
	/*プレイヤー板前後*/

	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 90.0, 0.0), CVector(35.0, 35.0, 35.0));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 180.0, 0.0), CVector(35.0, 35.0, 35.0));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 270.0, 0.0), CVector(35.0, 35.0, 35.0));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 360.0, 0.0), CVector(35.0, 35.0, 35.0));

	////玉
	new CBallPlayer(&mBall, CVector(0.0f, 75.0f, 0.0f), CVector(), CVector(7.0f, 7.0f, 7.0));

	new C3DShaveItem(&C3DShaveItem::mTri, CVector(0.0, 0.0, 0.0), CVector(), CVector(8.0, 8.0, 8.0));

	CSceneGame2::ResetF = true;

	CSceneGame2::mEnable = true;

	CamChan1 = true;
	CamChan2 = false;
	CamChan3 = false;
	CamChan4 = false;
	CamChanBottom = false;
	CamChanTop = false;
}


void CSceneGame2::Update() {

	if (CSceneGame2::GAMETIME > 61){
		CTaskManager::Get()->Update();
		Result = true;
	}
	if (CSceneGame2::GAMETIME < 61){
		mEnable = false;
		if (CKey::Once(VK_RETURN)){
			mScene = EGAME2_WAVE2;
		}
	}

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	if (CKey::Once('A')){
		CamChan1 = true;
	}
	if (CamChan1 == true){
		//A
		e = CVector(160.0f, 160.0f, 200.0f);
		CamChan2 = false;
		CamChan3 = false;
		CamChan4 = false;
		CamChanBottom = false;
		CamChanTop = false;
	}

	if (CKey::Once('W')){
		CamChan2 = true;
	}
	if (CamChan2 == true){
		//W
		e = CVector(160.0f, 160.0f, -200.0f);
		CamChan1 = false;
		CamChan3 = false;
		CamChan4 = false;
		CamChanBottom = false;
		CamChanTop = false;
	}

	if (CKey::Once('D')){
		CamChan3 = true;
	}
	if (CamChan3 == true){
		//E
		e = CVector(-160.0f, 160.0f, -200.0f);
		CamChan1 = false;
		CamChan2 = false;
		CamChan4 = false;
		CamChanBottom = false;
		CamChanTop = false;

	}
	if (CKey::Once('X')){
		CamChan4 = true;
	}
	if (CamChan4 == true){
		//X
		e = CVector(-160.0f, 160.0f, 200.0f);
		CamChan1 = false;
		CamChan2 = false;
		CamChan3 = false;
		CamChanBottom = false;
		CamChanTop = false;
	}
	if (CKey::Once('Z')){
		CamChanBottom = true;
	}
	if (CamChanBottom == true){
		//Z
		e = CVector(-10.0f, -180.0f, -10.0f);
		CamChan1 = false;
		CamChan2 = false;
		CamChan3 = false;
		CamChan4 = false;
		CamChanTop = false;
	}

	if (CKey::Once('S')){
		CamChanTop = true;
	}
	if (CamChanTop == true){
		//S
		e = CVector(10.0f, 180.0f, 10.0f);
		CamChan1 = false;
		CamChan2 = false;
		CamChan3 = false;
		CamChan4 = false;
		CamChanBottom = false;
	}


	//注視点を求める

	c = CVector(0.0f, 0.0f, 0.0f);

	//上方向を求める

	u = CVector(0.0f, 10.0f, 0.0f);

	//カメラの設定
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CMatrix Matrix;

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

//void CSceneGame2::CameraTopBottom(){
//
//	glPushMatrix();
//
//	glViewport(600, 450, 200, 150);		//画面の描画エリア指定
//
//	glLoadIdentity();		//行列の初期化
//
//	CVector e, c, u;//視点、注視点、上方向
//
//	e = CVector(10.0f, 180.0f, 10.0f);
//
//	//注視点を求める
//
//	c = CVector(0.0f, 0.0f, 0.0f);
//
//	//上方向を求める
//
//	u = CVector(0.0f, 10.0f, 0.0f)/**mCamera.mMatrix*/;
//
//	glDisable(GL_DEPTH_TEST);
//
//	CTaskManager::Get()->Render();
//
//	glPopMatrix();
//
//	glViewport(0, 0, 800, 600);		//描画エリアの指定
//
//	glEnable(GL_DEPTH_TEST);
//
//}

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
