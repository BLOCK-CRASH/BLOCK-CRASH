#ifndef CITEM_H
#define CITEM_H

#include "CCharacter.h"
//
#include "CCollider.h"
//
#include "CTaskManager.h"
//
#include "CScene.h"
//
#include "CCollisionManager.h"
//
#include "CEffect.h"

class CItem :public CCharacter{
public:
	CItem():mItemBody(0){}

	~CItem();
	CItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mItemBody;

	CVector aj;

	static CCharacter*mpthis;

	void Update();

	void Collision(CCollider*sm, CCollider*y);

	int ItemCount;

	void TaskCollision();

	static int BStageCount;
	bool BminusF;
	int BDamageCount;
	int DefeatBonus;//撃破ボーナス
	static int BMyScorePoint;

};

class CMoveItem :public CCharacter{
public:
	CMoveItem():mMItemBody(0){}

	~CMoveItem();
	CMoveItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mMItemBody;

	static bool RebirthF;

	static CCharacter*mpthis;

	void Update();

	int ItemCount;

	void TaskCollision();

	static int BStageCount;
	bool BminusF;
	//int BDamageCount;
	static int MMyScorePoint;

};

class CSpinItem :public CCharacter{
public:
	CSpinItem():mSItemBody(0){}

	~CSpinItem();
	CSpinItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mSItemBody;

	static bool RebirthF;

	static CCharacter*mpthis;

	static bool GameSwitch;

	//衝突判定
	//（コライダ1、コライダ2）
	void Collision(CCollider*sm, CCollider*y);

	void Update();

	int ItemCount;

	void TaskCollision();

	static int SStageCount;
	bool SminusF;
	//int SDamageCount;
	static int SMyScorePoint;
};

class CBonus :public CCharacter{
public:
	CBonus():mBoBody(0){}

	~CBonus();
	CBonus(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mBoBody;

	static CCharacter*mpthis;

	//衝突判定
	//（コライダ1、コライダ2）

	void Update();

	int ItemCount;

	void TaskCollision();

	static int MStageCount;
	bool MminusF;
	int MDamageCount;
	static int BMyScorePoint;
	int MoveTime;
};

class CExItem :public CCharacter{

public:

	CExItem(){}

	~CExItem();

	CCollider BomCol;

	static CCharacter*mpthis;

	CVector BjumpSpeed;

	CVector mAdjust;

	static bool jumpBF;

	static bool ReBomF;//////////////リスポーンフラグtrueなら存在falseならリスポーン

	bool BomGoF;

	bool BomColF;

	static int BomHP;

	static float BBoundNum;

	static int BomCutScore;//スコア減数

	static int BomDamageCount;//ダメージ数

	static int BomTime;

	CExItem(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*Bm, CCollider*y);

	void Update();

	void TaskCollision();

	void Render();

};

class CDeleteBlock :public CCharacter{

public:

	CDeleteBlock():mDelete(0){}

	~CDeleteBlock();

	CDeleteBlock(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mDelete;

	static CCharacter*mpthis;
	//衝突判定
	//（コライダ1、コライダ2）
	void Collision(CCollider*Dm, CCollider*y);

	void TaskCollision();

	void Update();

};

class CColoreItem:public CCharacter{

public:


};


#endif