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

static int ItemsStageCount;

class CItem :public CCharacter{
public:
	CItem(){}

	~CItem();
	CItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mItemBody;

	static CCharacter*mpthis;
	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*im, CCollider*y);

	void Update();

	int ItemCount;

	void TaskCollision();

	static int BStageCount;
	bool BminusF;
	//int BDamageCount;
	static int BMyScorePoint;

};

class CSpinItem :public CCharacter{
public:
	CSpinItem(){}

	~CSpinItem();
	CSpinItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mSItemBody;

	static CCharacter*mpthis;

	static bool GameSwitch;

	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*sm, CCollider*y);

	void Update();

	int ItemCount;

	void TaskCollision();

	static int SStageCount;
	bool SminusF;
	//int SDamageCount;
	static int SMyScorePoint;
};

class CMoveItem :public CCharacter{
public:
	CMoveItem(){}

	~CMoveItem();
	CMoveItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mMItemBody;

	static CCharacter*mpthis;

	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*Mm, CCollider*y);

	void Update();

	int ItemCount;

	void TaskCollision();

	static int MStageCount;
	bool MminusF;
	int MDamageCount;
	static int MMyScorePoint;
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

	bool BomGoF;

	bool BomColF;

	static int BomHP;

	static float BBoundNum;

	static int BomCutScore;//�X�R�A����

	static int BomDamageCount;//�_���[�W��

	static int BomTime;

	CExItem(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*Bm, CCollider*y);

	void Update();

	void TaskCollision();

	void Render();

};

class CDeleteBlock :public CCharacter{

public:

	CDeleteBlock(){}

	//~CItem();
	CDeleteBlock(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mDelete;

	static CCharacter*mpthis;
	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*Dm, CCollider*y);

	void TaskCollision();

	void Update();

};
#endif