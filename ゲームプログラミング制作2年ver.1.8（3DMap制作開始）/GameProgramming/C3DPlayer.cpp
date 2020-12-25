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

		mColBody[i].ChangePriority();

	}

	mColsize = model->mTriangles.size();

	janpspead = 0;

	mpthis = this;

	PlayerMoveW = 0;
	PlayerMoveA = 0;
	PlayerMoveS = 0;
	PlayerMoveD = 0;

	mTag = CCharacter::EPLAYER;
}

/*-------------------------------------------------------------------------------------------------------------------------------*/

#define MOUSE_S 3
void C3DPlayer::Update(){

	if (CKey::Push('W')){

		PlayerMoveW = false;

		if (PlayerMoveW == false){

			mRotation.mZ -= 0.5;

		}
		if (CKey::Push('A') || CKey::Push('S') || CKey::Push('D')){

			PlayerMoveA = true;
			PlayerMoveS = true;
			PlayerMoveD = true;

		}
		PlayerMoveW = true;
	}
/*-------------------------------------------------------------------------------*/
	if (CKey::Push('A')){

		PlayerMoveA = false;
		PlayerMoveW = true;
		PlayerMoveS = true;
		PlayerMoveD = true;

		if (PlayerMoveA == false){
		
			mRotation.mX -= 0.5;

		}

		if (CKey::Push('W') || CKey::Push('S') || CKey::Push('D')){

			PlayerMoveW = true;
			PlayerMoveS = true;
			PlayerMoveD = true;

		}
		PlayerMoveA = true;
	}
/*-------------------------------------------------------------------------------*/
		if (CKey::Push('S')){

		PlayerMoveS = false;

		if (PlayerMoveS == false){

			mRotation.mZ += 0.5;

		}

		if (CKey::Push('W') || CKey::Push('A') || CKey::Push('D')){

			PlayerMoveW = true;
			PlayerMoveA = true;
			PlayerMoveD = true;

		}
		PlayerMoveS = true;
	}
/*-------------------------------------------------------------------------------*/
		if (CKey::Push('D')){

		PlayerMoveD = false;

		if (PlayerMoveD == false){

			mRotation.mX += 0.5;

		}

		if (CKey::Push('W') || CKey::Push('A') || CKey::Push('S')){

			PlayerMoveW = true;
			PlayerMoveA = true;
			PlayerMoveS = true;

		}
		PlayerMoveD = true;
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

	for (int p = 0; p < mColsize; p++){

		mColBody[p].ChangePriority();

	}

}