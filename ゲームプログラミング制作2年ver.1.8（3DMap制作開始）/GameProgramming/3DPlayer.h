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

class C3DCamera :public CCharacter{
public:

	static C3DCamera*mpthis;

	CCollider*mColBody;

	C3DCamera() :mColBody(0){

		mMouseX = 1920 / 2;

		mMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&mMouseX, &mMouseY);

	}

	~C3DCamera(){

		if (mColBody)
			delete[] mColBody;

	}

	C3DCamera(CModel*model, CVector position, CVector rotation, CVector scale);

	int mMouseX;

	int mMouseY;

	void Update();
};
/*---------------------------------------------------------------------------------------*/
/*3DMap前後*/
class C3DBFPlayer :public CCharacter{
public:
	C3DBFPlayer() :mColBody(0){

		BFMouseX = 1920 / 2;

		BFMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&BFMouseX, &BFMouseY);

	}

	~C3DBFPlayer(){

		if (mColBody)
			delete[] mColBody;

	}
	int mColsize;
	C3DBFPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	//CCollider mColBody;
	static CCharacter *mpthis;
	int BFMouseX;
	int BFMouseY;
	//更新処理
	void Update();
	void TaskCollision();
};
/*3DMap左右*/
class C3DRLPlayer :public CCharacter{
public:
	C3DRLPlayer() :mColBody(0){

		RLMouseX = 1920 / 2;

		RLMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&RLMouseX, &RLMouseY);

	}

	~C3DRLPlayer(){

		if (mColBody)
			delete[] mColBody;

	}
	int mColsize;
	C3DRLPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	//CCollider mColBody;
	static CCharacter *mpthis;
	int RLMouseX;
	int RLMouseY;
	//更新処理
	void Update();
	void TaskCollision();
};
/*3DMap上下*/
class C3DTBPlayer :public CCharacter{
public:
	C3DTBPlayer() :mColBody(0){

		TBMouseX = 1920 / 2;

		TBMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&TBMouseX, &TBMouseY);

	}

	~C3DTBPlayer(){

		if (mColBody)
			delete[] mColBody;

	}
	int mColsize;
	C3DTBPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	//CCollider mColBody;
	static CCharacter *mpthis;
	int TBMouseX;
	int TBMouseY;
	//更新処理
	void Update();
	void TaskCollision();
};

#endif