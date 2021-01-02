#include "CObj.h"
CObj::CObj(CModel*model, const CVector &position, const
	CVector &rotation, const CVector &scale)
	:mpCollider(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//モデルの三角形の数分、コライダの配列を作成します
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mpCollider[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		mpCollider[i].ChangePriority();
	}

	mTag = CCharacter::EWALL;

}

C3DMap::C3DMap(CModel*model, const CVector &position, const
	CVector &rotation, const CVector &scale)
	:mpCollider(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CCharacter::Update();
	//モデルの三角形の数分、コライダの配列を作成します
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mpCollider[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		mpCollider[i].ChangePriority();
	}

	mColsize = model->mTriangles.size();
	
	XF, YF, ZF = false;

	ROTATETIME = 0;

	mTag = CCharacter::EWALL;

	ROTATETIME = 60 * 60;

}

C3DDelete::C3DDelete(CModel*model, const CVector &position, const
	CVector &rotation, const CVector &scale)
	:mpCollider(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CCharacter::Update();
	//モデルの三角形の数分、コライダの配列を作成します
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mpCollider[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		mpCollider[i].ChangePriority();
	}

	mColsize = model->mTriangles.size();

	mTag = CCharacter::EDELETE;
}
/*-------------------------------------------------------------------------------------------*/
//デストラクタ
CObj::~CObj(){
	//コライダがあれば削除
	if (mpCollider){
		//delete[]配列を削除
		delete[] mpCollider;
	}
}

C3DMap::~C3DMap(){
	//コライダがあれば削除
	if (mpCollider){
		//delete[]配列を削除
		delete[] mpCollider;
	}
}

C3DDelete::~C3DDelete(){
	//コライダがあれば削除
	if (mpCollider){
		//delete[]配列を削除
		delete[] mpCollider;
	}
}
/*-------------------------------------------------------------------------------------------*/
void CObj::TaskCollision(){

	mpCollider[0].ChangePriority();
	mpCollider[1].ChangePriority();
	mpCollider[2].ChangePriority();
	mpCollider[3].ChangePriority();
	mpCollider[4].ChangePriority();
	mpCollider[5].ChangePriority();
	mpCollider[6].ChangePriority();
	mpCollider[7].ChangePriority();
	mpCollider[8].ChangePriority();
	mpCollider[9].ChangePriority();
	mpCollider[10].ChangePriority();
	mpCollider[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mpCollider[0]);
	CCollisionManager::Get()->Collision(&mpCollider[1]);
	CCollisionManager::Get()->Collision(&mpCollider[2]);
	CCollisionManager::Get()->Collision(&mpCollider[3]);
	CCollisionManager::Get()->Collision(&mpCollider[4]);
	CCollisionManager::Get()->Collision(&mpCollider[5]);
	CCollisionManager::Get()->Collision(&mpCollider[6]);
	CCollisionManager::Get()->Collision(&mpCollider[7]);
	CCollisionManager::Get()->Collision(&mpCollider[8]);
	CCollisionManager::Get()->Collision(&mpCollider[9]);
	CCollisionManager::Get()->Collision(&mpCollider[10]);
	CCollisionManager::Get()->Collision(&mpCollider[11]);

}

void C3DMap::TaskCollision(){

	for (int c = 0; c < mColsize; c++){

		mpCollider[c].ChangePriority();

	}

}

void C3DDelete::TaskCollision(){

	for (int c = 0; c < mColsize; c++){

		mpCollider[c].ChangePriority();

	}

}
/*-------------------------------------------------------------------------------------------*/

void C3DMap::Update(){

	ROTATETIME--;

	XF, YF, ZF = false;

	if (ROTATETIME = 3540){

		XF = true;

	}

	mRotation.mZ += 0.5;

	CCharacter::Update();

}

void C3DMap::RotateUpdate(){

	if (XF == true){

		mRotation.mX = mRotation.mX + 90.0;

	}

	if (YF == true){

		mRotation.mY = mRotation.mY + 90.0;

	}

	if (ZF == true){

		mRotation.mZ = mRotation.mZ + 90.0;

	}

}
void C3DDelete::Update(){

	CCharacter::Update();

}