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

	mStage.Load("StageEdit0118.obj", "StageEdit0118.mtl");
	//mStage.Load("0205Stage_type_Wind.obj", "0205Stage_type_Wind.mtl");

	mStage.mMaterials[0].mDiffuse[3] = 0.5f;


	//mStage.Load("3DMap_02_02.obj", "3DMap_02_02.mtl");
	//mStage.mMaterials[0].mDiffuse[3] = 0.3f;

	//mStage.Load("STAGE(2)_Edit_OF_0102.obj", "STAGE(2)_Edit_OF_0102.mtl");

	//m3DPlayer.Load("3DPlayer0118.obj", "3DPlayer0118.mtl");
	m3DPlayer1.Load("0205_3D_1Board.obj", "0205_3D_1Board.mtl");
	m3DPlayer2.Load("0205_3D_2Board.obj", "0205_3D_2Board.mtl");
	m3DPlayer3.Load("0205_3D_3Board.obj", "0205_3D_3Board.mtl");
	m3DPlayer4.Load("0205_3D_4Board.obj", "0205_3D_4Board.mtl");

	m3DPlayer1.mMaterials[0].mDiffuse[3] = 0.75f;
	m3DPlayer2.mMaterials[0].mDiffuse[3] = 0.75f;
	m3DPlayer3.mMaterials[0].mDiffuse[3] = 0.75f;
	m3DPlayer4.mMaterials[0].mDiffuse[3] = 0.75f;

	//m3DPlayer.Load("3DPlayerBoard.obj","3DPlayerBoard.mtl");

	mDelete.Load("AriBox0205.obj", "AriBox0205.mtl");
	mDelete.mMaterials[0].mDiffuse[3] = 0.0f;

	C3DShaveItem::mTri.Load("3Model.obj", "3Model.mtl");
	C3DShaveItem::mRec.Load("4Model.obj", "4Model.mtl");
	C3DShaveItem::mPen.Load("5Model.obj", "5Model.mtl");
	C3DShaveItem::mHex.Load("6Model.obj", "6Model.mtl");
	C3DShaveItem::mHep.Load("7Model.obj", "7Model.mtl");
	C3DShaveItem::mOct.Load("8Model.obj", "8Model.mtl");

	//mShave.Load("mTri.obj", "mTri.mtl");//3DShaveItem//最初は三角形モデル

	//new CSpinItem(&mBoardR, CVector(-60.0f, 20.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(60.0f, 20.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(110.0f, 30.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));
	//new CSpinItem(&mBoardR, CVector(-110.0f, 30.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(10.0f, 5.0f, 6.0));

	//new CCamera();

	//new CMoveItem(&mBoard, CVector(600.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(2.0f, 2.0f, 2.0));

	new C3DDelete(&mDelete, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0, 180.0), CVector(10, 10, 10));

	new C3DMap(&mStage, CVector(0.0, 0.0/*STAGE2の時だけ151*/, 0.0), CVector(0.0, 0.0/*45*/, 180.0), CVector(7.0, 7.0, 7.0));

	//プレイヤー(板)
	/*プレイヤー板前後*/
	//new C3DBFPlayer(&m3DPlayer, CVector(0.0, 0.0, 185.0), CVector(0.0, 90.0, 90.0), CVector(3.5, 3.5, 3.5));
	//new C3DBFPlayer(&m3DPlayer, CVector(0.0, 0.0, -185.0), CVector(0.0, -90.0, -90.0), CVector(3.5, 3.5, 3.5));

	//new C3DRLPlayer(&m3DPlayer, CVector(140.0, 0.0, 0.0), CVector(0.0, 0.0, 90.0), CVector(3.5, 3.5, 3.5));
	//new C3DRLPlayer(&m3DPlayer, CVector(-140.0, 0.0, 0.0), CVector(-90.0, 0.0, -90.0), CVector(3.5, 3.5, 3.5));


	//new C3DTBPlayer(&m3DPlayer, CVector(0.0, -130.0, 0.0), CVector(0.0, 0.0, 0.0), CVector(3.5, 3.5, 3.5));
	//new C3DTBPlayer(&m3DPlayer, CVector(0.0, 130.0, 0.0), CVector(0.0, 0.0, 0.0), CVector(3.5, 3.5, 3.5));

	//new C3DBFPlayer(&m3DPlayer, CVector(-120.0, -110.0, -190.0), CVector(0.0, -90.0, -90.0), CVector(4.5, 4.5, 4.5));

	///*ノーマルアイテムブロック----------------------------------------------------------------------------*/
	//new CItem(&mBoard, CVector(-150.0f, 140.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0, 1.0, 1.0));
	//new CItem(&mBoard, CVector(150.0f, 140.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0, 1.0, 1.0));
	//new CItem(&mBoard, CVector(0.0f, 140.0f, 150.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0, 1.0, 1.0));
	//new CItem(&mBoard, CVector(0.0f, 140.0f, -150.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0, 1.0, 1.0));
	//
	new C3DShaveItem(&C3DShaveItem::mTri, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));

	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 90.0, 0.0), CVector(35.0, 35.0, 35.0));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 180.0, 0.0), CVector(35.0, 35.0, 35.0));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 270.0, 0.0), CVector(35.0, 35.0, 35.0));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 360.0, 0.0), CVector(35.0, 35.0, 35.0));

	////玉
	new CBallPlayer(&mBall, CVector(0.0f, 75.0f, 0.0f), CVector(), CVector(7.0f, 7.0f, 7.0));

	//new C3DPlayer(&m3DPlayer1, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), CVector(40, 40, 40));
	//new C3DPlayer(&m3DPlayer3, CVector(100.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), CVector(40, 40, 40));
	//new C3DPlayer(&m3DPlayer4, CVector(150.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), CVector(40, 40, 40));

	//new C3DPlayer(&m3DPlayer, CVector(-100.0, 0.0, 0.0), CVector(180.0, 0.0, -180.0), CVector(40, 40, 40));

	//new C3DCamera(&mBoard, CVector(), CVector(), CVector());

	//CamChan1 = false;

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

		Result = false;

		mEnable = false;

		if (Result == false){

			if (CKey::Once(VK_RETURN)){

				mScene = ESTAGE2_RESULT;

			}

		}

	}

	if (C3DShaveItem::TR == true){

		new C3DShaveItem(&C3DShaveItem::mRec, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));

		C3DShaveItem::TriF = false;//HP==0でそのフラグをfalseへ
		C3DShaveItem::TR = false;
	}
	
	if (C3DShaveItem::RP == true){

		new C3DShaveItem(&C3DShaveItem::mPen, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));

		C3DShaveItem::RecF = false;//HP==0でそのフラグをfalseへ
		C3DShaveItem::RP = false;
	}

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める

	//e = CVector(160.0f, 160.0f, 200.0f);

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

	u = CVector(0.0f, 10.0f, 0.0f)/**mCamera.mMatrix*/;

	//カメラの設定
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CMatrix Matrix;

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	//CCollisionManager::Get()->Render();

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
