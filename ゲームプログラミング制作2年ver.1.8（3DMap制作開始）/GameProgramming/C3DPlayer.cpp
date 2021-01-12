#include "CPlayer.h"
#include "CKey.h"

C3DCamera*C3DCamera::mpthis = 0;
CCharacter *C3DPlayer::mpthis = 0;
//CCharacter *CBottomPlayer::mpthis = 0;
//#define G (9.8f/60.0f)  //�d�͉����x
//#define JUMPV0  (4.0f)  //�W�����v����
C3DPlayer::C3DPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//���f���̎O�p�`�̐����A�R���C�_�̔z����쐬���܂�
	mColBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
		mColBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		mColBody[i].ChangePriority();

	}

	mColsize = model->mTriangles.size();

	janpspead = 0;

	mpthis = this;

	mTag = CCharacter::EPLAYER;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

#define MOUSE_S 3
void C3DPlayer::Update(){

	//static int mMouseCount = 0;
	//++mMouseCount %= MOUSE_S;

	//if (mMouseCount == 0){

	//	CInput::SetMousePos(mMouseX, mMouseY);

	//}

	////���W�擾

	//int mx, my;

	//float m(10.0);

	//CInput::GetMousePos(&mx, &my);

	//if (my < mMouseY){

	//	mRotation.mX -= (mMouseY - my) / m;

	//}

	//if (mMouseY < my){

	//	mRotation.mX -= (mMouseY - my) / m;

	//}

	//if (mx < mMouseX){

	//	mRotation.mY += (mMouseX - mx) / m;

	//}

	//if (mMouseX < mx){

	//	mRotation.mY += (mMouseX - mx) / m;

	//}


	if (CKey::Push(VK_LBUTTON)){

		mRotation.mX += 1;

		if (CKey::Push('R')){

		mRotation.mX -= 2;

		}

	}

	if (CKey::Push(VK_RBUTTON)){

		mRotation.mZ -= 1;

		if (CKey::Push('R')){

			mRotation.mZ += 2;

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
	//���W�擾
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

	for (int p = 0; p < mColsize; p++){

		mColBody[p].ChangePriority();

	}

}