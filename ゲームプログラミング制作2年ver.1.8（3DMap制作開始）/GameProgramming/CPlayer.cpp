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
	CCharacter::Update();
	//モデルの三角形の数分、コライダの配列を作成します
	mColBody = new CCollider[model->mTriangles.size()];
	mColsize = model->mTriangles.size();
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mColBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);
		
		mColBody[i].ChangePriority();
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


	CCharacter::Update();
}


void CPlayer::TaskCollision(){

	for (int c = 0; c < mColsize; c++){

		mColBody[c].ChangePriority();

	}


}
