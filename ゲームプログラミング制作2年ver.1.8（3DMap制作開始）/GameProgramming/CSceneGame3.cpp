#include "CSceneGame3.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"
//


void CSceneGame3::Init(){

	mScene = EGAME3;

	Result = false;

	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	CBlackText::mBFont.Load("font.tga");

	mBall.Load("sphere.obj", "sphere.mtl");

	mStage.Load("StageEdit0111.obj", "StageEdit0111.mtl");
	mStage.mMaterials[0].mDiffuse[3] = 0.75f;
	m3DPlayer2.Load("0205_3D_2Board.obj", "0205_3D_2Board.mtl");

	mDelete.Load("AriBox0205.obj", "AriBox0205.mtl");
	mDelete.mMaterials[0].mDiffuse[3] = 0.0f;

	mTri.Load("HalfTri.obj", "HalfTri.mtl");

	mRec.Load("cube.obj", "cube.mtl");

	mDia.Load("DiaRec.obj", "DiaRec.mtl");

	Scale = CVector(13, 10.5, 13);

	new C3DDelete(&mDelete, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0, 180.0), CVector(10, 10, 10));

	new C3DMap(&mStage, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0/*45*/, 180.0), CVector(7, 7, 7));

	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 90.0, 0.0), CVector(35, 35, 35));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 180.0, 0.0), CVector(35, 35, 35));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 270.0, 0.0), CVector(35, 35, 35));
	new C3DPlayer(&m3DPlayer2, CVector(0.0, 0.0, 0.0), CVector(0.0, 360.0, 0.0), CVector(35, 35, 35));

	new C3DNormal(&mRec, CVector(80.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(40.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(0.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-40.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-80.0, 0.0, 0.0), CVector(0.0, 0.0, 0.0), Scale);

	new C3DNormal(&mRec, CVector(80.0, 0.0, 60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(40.0, 0.0, 60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(0.0, 0.0, 60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-40.0, 0.0, 60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-80.0, 0.0, 60.0), CVector(0.0, 0.0, 0.0), Scale);
	
	new C3DNormal(&mRec, CVector(80.0, 0.0, -60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(40.0, 0.0, -60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(0.0, 0.0, -60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-40.0, 0.0, -60.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-80.0, 0.0, -60.0), CVector(0.0, 0.0, 0.0), Scale);

	new C3DNormal(&mRec, CVector(80.0, 0.0, 120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(40.0, 0.0, 120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(0.0, 0.0, 120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-40.0, 0.0, 120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-80.0, 0.0, 120.0), CVector(0.0, 0.0, 0.0), Scale);

	new C3DNormal(&mRec, CVector(80.0, 0.0, -120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(40.0, 0.0, -120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(0.0, 0.0, -120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-40.0, 0.0, -120.0), CVector(0.0, 0.0, 0.0), Scale);
	new C3DNormal(&mRec, CVector(-80.0, 0.0, -120.0), CVector(0.0, 0.0, 0.0), Scale);

	////玉
	new CBallPlayer(&mBall, CVector(0.0f, 75.0f, 0.0f), CVector(), CVector(7.0f, 7.0f, 7.0));

	CSceneGame3::ResetF = true;

	CamChan1 = true;
	CamChan2 = false;
	CamChan3 = false;
	CamChan4 = false;
	CamChanBottom = false;
	CamChanTop = false;

}

void CSceneGame3::Update(){

	CTaskManager::Get()->Update();

	if (CSceneGame3::GAMETIME > 61){
		Result = true;
	}
	if (CSceneGame3::GAMETIME < 61){
		mEnable = false;
		if (CKey::Once(VK_RETURN)){
			mScene = EGAME2_WAVE2;
		}
	}

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	if (CKey::Once('A')){
		CamChan1 = true;
	}
	if (CamChan1 == true){
		//A
		e = CVector(160.0f, 160.0f, 190.0f);
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
		e = CVector(160.0f, 160.0f, -190.0f);
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
		e = CVector(-160.0f, 160.0f, -190.0f);
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
		e = CVector(-160.0f, 160.0f, 190.0f);
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

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	//CCollisionManager::Get()->Render();

	//2D描画開始
	Start2D(0, 800, 0, 600);

	/*---------------------------------------------------------------------------------------*/

	//ステージ、ウェーブ名
	CText::DrawString("SUTAG3", 10, 585, 12, 14);
	CText::DrawString("WAVE 1", 10, 555, 12, 14);
	//残りブロック数
	CText::DrawString("BLOCK QUANTITY", 620, 575, 10, 16);

	CText::DrawString("BALL LIFE", 570, 30, 10, 16);

	char buf[100];
	sprintf(buf, "%d", CBallPlayer::BallHP);
	CBlackText::DrawString(buf, 780, 26, 12, 12);

	CTaskManager::Get()->Delete();

	//2D描画終了
	End2D();

	return;

}

CScene::EScene CSceneGame3::GetNextScene() {
	return mScene;
}
//デストラクタ
CSceneGame3::~CSceneGame3() {
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
