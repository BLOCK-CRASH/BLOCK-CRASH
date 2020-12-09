#ifndef COBJ_H
#define COBJ_H

#include "CCharacter.h"
//
#include "CCollider.h"
//
#include "CCollisionManager.h"
//
#include "CTaskManager.h"
class CObj :public CCharacter{
public:

	//コライダの追加
	CCollider*mpCollider;
	//コンストラクタで初期設定
	CObj(CModel*model, const CVector&position,
		const CVector&rotation, const CVector&scale);
	~CObj();

	void TaskCollision();

};

class C3DMap :public CCharacter{
public:

	//コライダの追加
	CCollider*mpCollider;
	int mColsize;
	//コンストラクタで初期設定
	C3DMap(CModel*model, const CVector&position,
		const CVector&rotation, const CVector&scale);
	
	bool XF;

	bool YF;

	bool ZF;

	int ROTATETIME;

	void TaskCollision();

	void Update();

};

#endif