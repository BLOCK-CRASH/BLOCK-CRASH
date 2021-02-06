#ifndef CBOSSITEM_H
#define CBOSSITEM_H

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
//
#include "CModel.h"
//
#include "CScene.h"
//
#include "CKey.h"
//
#include "CText.h"
//
#include "CItem.h"
/*
3D移動用アイテム
フィーバー用、通常用
*/
class C3DMoveItem :public CMoveItem{

public:

	C3DMoveItem() :m3DMItemBody(0){}

	~C3DMoveItem();
	C3DMoveItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *m3DMItemBody;

	static bool RebirthF;

	static CCharacter*mpthis;

	void Update();

	void TaskCollision();

	static int BStageCount;
	bool B3DminusF;
	//int BDamageCount;
	int M3DMyScorePoint;

	int mColsize;

};
/*
撃破アイテム
撃破することでいいことが起こる
*/
class C3DOrbitItem :public CSpinItem{
public:

	C3DOrbitItem() :m3DSItemBody(0){}

	~C3DOrbitItem();
	C3DOrbitItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *m3DSItemBody;

	static bool RebirthF;

	static CCharacter*mpthis;

	//衝突判定
	//（コライダ1、コライダ2）
	void Collision(CCollider*sm, CCollider*y);

	void Update();

	int ItemCount;

	void TaskCollision();

	static int SStageCount;
	bool S3DminusF;
	//int SDamageCount;
	int S3DMyScorePoint;

	int mColsize;

};

/*
変形アイテム
当たってHPを減らし、
その形で点数が決まる
*/

class C3DShaveItem :public CCharacter{
public:

	C3DShaveItem() : m3DShaveBody(0){}

	~C3DShaveItem();

	C3DShaveItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider*m3DShaveBody;

	int mColSize;

	static CCharacter*mpthis;

	static int ShaveMyScorePoint;

	void Collision(CCollider*Sha, CCollider*y);

	static	bool ModelChanF;

	CVector adjust;

	void Update();

	void Init();

	int u;

	void TaskCollision();

	static CModel mTri;//三角形
	static int TriHP;//三角形
	static bool TriF;//三角形
	bool TR;//TriからRecへ

	static CModel mRec;//四角形
	static int RecHP;//四角形
	static bool RecF;//四角形
	bool RP;//RecからPenへ

	static CModel mPen;//五角形
	static int PenHP;//五角形
	static bool PenF;//五角形
	bool PH;//PenからHexへ

	static CModel mHex;//六角形
	static int HexHP;//六角形
	static bool HexF;//六角形
	bool HH;//HexからHepへ

	static CModel mHep;//七角形
	static int HepHP;//七角形
	static bool HepF;//七角形
	bool HO;//HepからOctへ

	static CModel mOct;//八角形
	static int OctHP;//八角形
	static bool OctF;//八角形
	bool ON;//OctからNonへ

	static  CModel mNon;//九角形
	static int NonHP;//九角形
	static bool NonF;//九角形
	bool NOF;//NonからModelなしへ

	void ChangeModel();

	//static CModel mDec;//十角形
	//int DecHP;//十角形
	//bool DecF;//十角形

};

#endif