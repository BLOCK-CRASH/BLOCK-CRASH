#ifndef C3DPLAYER_H
#define C3DPLAYER_H

#include "CCharacter.h"
//
#include "CCollider.h"
//
#include "CObj.h"
//
#include "CCollisionManager.h"
//
#include "CInput.h"

//class C3DCamera :public CCharacter{
//public:
//
//	static C3DCamera*mpthis;
//
//	CCollider*mColBody;
//
//	C3DCamera() :mColBody(0){
//
//		mMouseX = 1920 / 2;
//
//		mMouseY = 1080 / 2;
//
//		mpthis = this;
//
//		CInput::GetMousePos(&mMouseX, &mMouseY);
//
//	}
//
//	~C3DCamera(){
//
//		if (mColBody)
//			delete[] mColBody;
//
//	}
//
//	C3DCamera(CModel*model, CVector position, CVector rotation, CVector scale);
//
//	int mMouseX;
//
//	int mMouseY;
//
//	void Update();
//};

class C3DPlayer :public CCharacter{
public:
	C3DPlayer() :mColBody(0){

		mMouseX = 1920 / 2;

		mMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&mMouseX, &mMouseY);

	}

	~C3DPlayer(){

		if (mColBody)
			delete[] mColBody;

	}
	int mColsize;
	int mMouseCount;
	float janpspead;
	C3DPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	//CCollider mColBody;
	static CCharacter *mpthis;
	int mMouseX;
	int mMouseY;
	//çXêVèàóù
	void Update();
	void TaskCollision();
};

#endif