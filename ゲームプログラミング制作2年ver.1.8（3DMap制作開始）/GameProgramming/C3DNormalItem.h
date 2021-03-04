#ifndef C3DNORMALITEM_H
#define C3DNORMALITEM_H

#include "CCharacter.h"
//
#include "CCollider.h"
//
#include "CTaskManager.h"
//
#include "CCollisionManager.h"
//
#include "CEffect.h"
//
#include "CModel.h"
//
#include "CKey.h"
//
#include "CText.h"
class C3DNormal :public CCharacter{
public:
	C3DNormal() :mNormalBody(0){}

	~C3DNormal();
	C3DNormal(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mNormalBody;

	CVector a;

	static CCharacter*mpthis;

	void Update();

	void Collision(CCollider*Nm, CCollider*y);

	void TaskCollision();

	int BDamageCount;
	int DefeatBonus;//撃破ボーナス

	static int HP;

	static int Quantity;

	int mColsize;

};

class C3DDummy :public CCharacter{

	C3DDummy():mDummyBody(0){}

	~C3DDummy();

	C3DDummy(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider*mDummyBody;

	CVector a;

	static CCharacter*mpthis;

	void Update();

	void TaskCollision();

	int mColsize;

};
#endif