#include "CPlayer.h"
#include "CKey.h"

C3DCamera*C3DCamera::mpthis = 0;
CCharacter *C3DPlayer::mpthis = 0;
//CCharacter *CBottomPlayer::mpthis = 0;
//#define G (9.8f/60.0f)  //重力加速度
//#define JUMPV0  (4.0f)  //ジャンプ初速
C3DPlayer::C3DPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//モデルの三角形の数分、コライダの配列を作成します
	mColBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mColBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);
	}

	janpspead = 0;

	mpthis = this;

	mTag = CCharacter::EPLAYER;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

#define MOUSE_S 3
void C3DPlayer::Update(){
	if (CKey::Push('N')){
		mRotation.mZ += 25.0f;
		if (C3DPlayer::mRotation.mZ > 25.1f){
			mRotation.mZ = 25.0f;
		}
	}
	else if (CKey::Push('V')){
		mRotation.mZ -= 25.0f;
		if (C3DPlayer::mRotation.mZ < -25.1f){
			mRotation.mZ += 25.0f;
		}
	}
	else{
		mRotation.mZ = 0.0f;
	}
	if (CKey::Push('J')){
		mPosition.mX += 1.2;
		if (C3DPlayer::mPosition.mX >= 100 && C3DPlayer::mPosition.mX > 0){
			mPosition.mX -= 1.2;
			mPosition.mZ += 0.3;
		}

	}
	if (CKey::Push('F')){
		mPosition.mX -= 1.2;

		if (C3DPlayer::mPosition.mX <= -100 && C3DPlayer::mPosition.mX < 0){
			mPosition.mX += 1.2;

		}
	}
	CCharacter::Update();
}

void C3DCamera::Update(){

	static int mMouseCount = 0;
	++mMouseCount %= MOUSE_S;

	if (mMouseCount == 0){
	
		CInput::SetMousePos(mMouseX, mMouseY);
	
	}

	//座標取得

	int mx, my;

	float m(10.0);

	CInput::GetMousePos(&mx, &my);

	if (my < mMouseY){

		mRotation.mX -= (mMouseY - my) / m;

	}

	if (mMouseY < my){

		mRotation.mX -= (mMouseY - my) / m;

	}

	if (mx < mMouseX){

		mRotation.mY += (mMouseX - mx) / m;

	}

	if (mMouseX < mx){

		mRotation.mY += (mMouseX - mx) / m;

	}

	CCharacter::Update();

}
/*-------------------------------------------------------------------------------------------------------------------------------*/
void C3DPlayer::TaskCollision(){

	mColBody[0].ChangePriority();
	mColBody[1].ChangePriority();
	mColBody[2].ChangePriority();
	mColBody[3].ChangePriority();
	mColBody[4].ChangePriority();
	mColBody[5].ChangePriority();
	mColBody[6].ChangePriority();
	mColBody[7].ChangePriority();
	mColBody[8].ChangePriority();
	mColBody[9].ChangePriority();
	mColBody[10].ChangePriority();
	mColBody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mColBody[0]);
	CCollisionManager::Get()->Collision(&mColBody[1]);
	CCollisionManager::Get()->Collision(&mColBody[2]);
	CCollisionManager::Get()->Collision(&mColBody[3]);
	CCollisionManager::Get()->Collision(&mColBody[4]);
	CCollisionManager::Get()->Collision(&mColBody[5]);
	CCollisionManager::Get()->Collision(&mColBody[6]);
	CCollisionManager::Get()->Collision(&mColBody[7]);
	CCollisionManager::Get()->Collision(&mColBody[8]);
	CCollisionManager::Get()->Collision(&mColBody[9]);
	CCollisionManager::Get()->Collision(&mColBody[10]);
	CCollisionManager::Get()->Collision(&mColBody[11]);

}