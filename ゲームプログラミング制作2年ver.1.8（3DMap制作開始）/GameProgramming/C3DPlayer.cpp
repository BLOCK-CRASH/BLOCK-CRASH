#include "3DPlayer.h"
#include "CKey.h"

/*-------------------------------------------------------------------------------------------------------------------------------*/

#define MOUSE_S 10
///*-------------------------------------------------------------------------------------------------------------------------------*/
CCharacter *C3DPlayer::mpthis = 0;
C3DPlayer::C3DPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:C3DPlayer()
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
	mMouseCount = 0;

	mColsize = model->mTriangles.size();

	janpspead = 0;

	mpthis = this;

	mTag = CCharacter::EPLAYER;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

#define MOUSE_S 10
void C3DPlayer::Update(){

	++mMouseCount %= MOUSE_S;

	if (mMouseCount == 0){

		CInput::SetMousePos(mMouseX, mMouseY);

	}

	//���W�擾

	int mx, my;

	float m(16.0);

	CInput::GetMousePos(&mx, &my);

	if (my < mMouseY){

		mRotation.mX += (mMouseY - my) / m;

	}

	if (mMouseY < my){

		mRotation.mX += (mMouseY - my) / m;

	}

	if (mx < mMouseX){

		mRotation.mY -= (mMouseX - mx) / m;

	}

	if (mMouseX < mx){

		mRotation.mY -= (mMouseX - mx) / m;

	}



	CCharacter::Update();
}

void C3DPlayer::TaskCollision(){

	for (int p = 0; p < mColsize; p++){

		mColBody[p].ChangePriority();

	}

}
