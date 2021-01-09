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
	CPlayer():mColBody(0){}
	~CPlayer()
	{
		if (mColBody)
			delete[] mColBody;
	}
	float janpspead;
	CPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	static CCharacter *mpthis;
	//更新処理
	void Update();
	void Collision(CCollider*m, CCollider*y);
	void TaskCollision();
};
class CBottomPlayer :public CPlayer{
public:
	CBottomPlayer():mColBody(0){}
	~CBottomPlayer(){
	
		if (mColBody)
			delete[] mColBody;
	}
	CBottomPlayer(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mColBody;
	static CCharacter *mpthis;
	//更新処理
	void Update();
	void Collision(CCollider*m,CCollider*y);
	void TaskCollision();
};


class C3DPlayer :public CCharacter{
public:
	C3DPlayer():mColBody(0){}
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
	//更新処理
	void Update();
	void TaskCollision();
};

class C3DCamera :public CCharacter{
public:

	static C3DCamera*mpthis;

	C3DCamera(){

		mMouseX = 1920 / 2;

		mMouseY = 1080 / 2;

		mpthis = this;

		CInput::GetMousePos(&mMouseX, &mMouseY);
	}

	int mMouseX;

	int mMouseY;

	void Update();
};
#endif