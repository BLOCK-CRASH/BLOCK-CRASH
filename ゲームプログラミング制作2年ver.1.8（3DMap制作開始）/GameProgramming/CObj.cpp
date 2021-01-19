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
	//���f���̎O�p�`�̐����A�R���C�_�̔z����쐬���܂�
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
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
	//���f���̎O�p�`�̐����A�R���C�_�̔z����쐬���܂�
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
		mpCollider[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		mpCollider[i].ChangePriority();
	}

	mColsize = model->mTriangles.size();
	
	XF, YF, ZF = false;

	ROTATETIME = 0;

	ROTATETIME = 121 * 60;

}

C3DDelete::C3DDelete(CModel*model, const CVector &position, const
	CVector &rotation, const CVector &scale)
	:mpCollider(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CCharacter::Update();
	//���f���̎O�p�`�̐����A�R���C�_�̔z����쐬���܂�
	mpCollider = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
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
//�f�X�g���N�^
CObj::~CObj(){
	//�R���C�_������΍폜
	if (mpCollider){
		//delete[]�z����폜
		delete[] mpCollider;
	}
}

C3DMap::~C3DMap(){
	//�R���C�_������΍폜
	if (mpCollider){
		//delete[]�z����폜
		delete[] mpCollider;
	}
}

C3DDelete::~C3DDelete(){
	//�R���C�_������΍폜
	if (mpCollider){
		//delete[]�z����폜
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

	ROTATETIME--;

	//if (XF == true){
	//	mRotation.mX = 90.0;
	//	XF = false;
	//}
	//if (YF == true){
	//	mRotation.mY = 90.0;
	//	YF = false;
	//}
	//if (ZF == true){
	//	mRotation.mZ = 90.0;
	//	ZF = false;
	//}

	//if (ROTATETIME < 4840){

	//	XF = true;

	//	YF = true;

	//	ZF = true;
	//}

	//if (ROTATETIME < 2420){

	//	XF = true;

	//	YF = true;

	//	ZF = true;
	//}

	//mRotation.mZ += 0.1;

	CCharacter::Update();

}

void C3DDelete::Update(){

	CCharacter::Update();

}