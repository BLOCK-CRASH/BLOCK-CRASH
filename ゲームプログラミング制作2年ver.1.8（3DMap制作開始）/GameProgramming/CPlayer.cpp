#include "CPlayer.h"
#include "CKey.h"

CCharacter *CPlayer::mpthis=0;
CPlayer::CPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:CPlayer()
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

void CPlayer::Collision(CCollider*m,CCollider*y){}

#define MOUSE_S 3
void CPlayer::Update(){

	static int mMouseCount = 0;
	++mMouseCount %= MOUSE_S;

	if (mMouseCount == 0){

		CInput::SetMousePos(mMouseX, mMouseY);

	}

	int mx, my;

	float m(10.0);

	CInput::GetMousePos(&mx, &my);

	if (my < mMouseY){

		mRotation.mX -= (mMouseY - my) / m;

	}

	if (mMouseY < my){

		mRotation.mX -= (mMouseY - my) / m;

	}

	//if (mx < mMouseX){

	//	mRotation.mY += (mMouseX - mx) / m;

	//}

	//if (mMouseX < mx){

	//	mRotation.mY += (mMouseX - mx) / m;

	//}


	CCharacter::Update();
}


void CPlayer::TaskCollision(){

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
