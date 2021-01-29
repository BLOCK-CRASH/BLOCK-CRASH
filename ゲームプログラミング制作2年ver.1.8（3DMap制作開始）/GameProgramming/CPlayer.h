#ifndef CPLAYER_H
#define CPLAYER_H

#include "CCharacter.h"
//
#include "CCollider.h"
//
#include "CObj.h"
//
#include "CCollisionManager.h"
//
#include "CInput.h"
class CPlayer :public CCharacter{
public:
	CPlayer()
		:mColBody(0)
	{
	
		mMouseX = 1920 / 2;

		mMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&mMouseX, &mMouseY);
	
	}

	~CPlayer()
	{
		if (mColBody)
			delete[] mColBody;
	}
	int mMouseX;
	int mMouseY;
	int mColsize;
	float janpspead;
	CPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	static CCharacter *mpthis;
	//更新処理
	void Update();
	void Collision(CCollider*m, CCollider*y);
	void TaskCollision();
};

class CRePlayer :public CCharacter{
public:
	CRePlayer()
		:mColBody(0)
	{

		mMouseX = 1920 / 2;

		mMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&mMouseX, &mMouseY);

	}

	~CRePlayer()
	{
		if (mColBody)
			delete[] mColBody;
	}
	int mMouseX;
	int mMouseY;
	int mColsize;
	float janpspead;
	CRePlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	static CCharacter *mpthis;
	//更新処理
	void Update();
	void Collision(CCollider*m, CCollider*y);
	void TaskCollision();
};

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
	float janpspead;
	C3DPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	//CCollider mColBody;
	static CCharacter *mpthis;
	int mMouseX;
	int mMouseY;
	//更新処理
	void Update();
	void TaskCollision();
};

class C3DCamera :public CCharacter{
public:

	static C3DCamera*mpthis;

	CCollider*mColBody;

	C3DCamera():mColBody(0){

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
#endif