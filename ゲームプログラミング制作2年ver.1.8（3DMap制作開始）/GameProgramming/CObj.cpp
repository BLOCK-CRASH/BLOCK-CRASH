#include "CObj.h"
CObj::CObj(CModel*model, const CVector &position, const
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

	for (int c = 0; c < mColsize; c++){

		mpCollider[c].ChangePriority();

	}

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

	//mRotation.mZ += 0.07;

	//mRotation.mY += 0.07;

	CCharacter::Update();

}

void C3DDelete::Update(){

	CCharacter::Update();

}