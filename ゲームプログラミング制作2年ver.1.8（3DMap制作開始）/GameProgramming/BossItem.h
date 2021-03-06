#ifndef CBOSSITEM_H
#define CBOSSITEM_H

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
//
#include "CItem.h"
/*
3D移動用アイテム
フィーバー用、通常用
*/
class C3DMoveItem :public CMoveItem{
private:

	static CCharacter*mpthis;
	int mColsize;
	CCollider *m3DMItemBody;
	void Update();
	void TaskCollision();

public:

	C3DMoveItem() :m3DMItemBody(0){}
	~C3DMoveItem();
	C3DMoveItem(CModel*model, CVector position, CVector rotation, CVector scale);
	static bool RebirthF;
	static int BStageCount;
	int M3DMyScorePoint;
};
/*
撃破アイテム
撃破することでいいことが起こる
*/
class C3DOrbitItem :public CSpinItem{
private:

	static CCharacter*mpthis;
	CCollider *m3DSItemBody;
	int mColsize;
	void Update();
	void TaskCollision();

public:

	C3DOrbitItem() :m3DSItemBody(0){}
	~C3DOrbitItem();
	C3DOrbitItem(CModel*model, CVector position, CVector rotation, CVector scale);
	static bool RebirthF;
	//衝突判定
	//（コライダ1、コライダ2）
	void Collision(CCollider*sm, CCollider*y);
	int ItemCount;
	static int SStageCount;
	bool S3DminusF;
	//int SDamageCount;
	int S3DMyScorePoint;

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

	static int HP;

	float SpeedUp;

	static CCharacter*mpthis;

	static int ShaveMyScorePoint;

	void Collision(CCollider*Sha, CCollider*y);

	static	bool ModelChanF;

	CVector adjust;

	void Update();

	void Init();

	void TaskCollision();

	static CModel mTri;//三角形
	int TriHP;//三角形
	bool TriF;//三角形HP減算フラグ
	static bool TR;//TriからRecへ

	static CModel mRec;//四角形
	int RecHP;//四角形HP減算フラグ
	bool RecF;//四角形
	static bool RP;//RecからPenへ

	static CModel mPen;//五角形
	int PenHP;//五角形HP減算フラグ
	bool PenF;//五角形
	static bool PH;//PenからHexへ

	static CModel mHex;//六角形
	int HexHP;//六角形HP減算フラグ
	bool HexF;//六角形
	static bool HH;//HexからHepへ

	static CModel mHep;//七角形
	int HepHP;//七角形HP減算フラグ
	bool HepF;//七角形
	static bool HO;//HepからOctへ

	static CModel mOct;//八角形
	int OctHP;//八角形HP減算フラグ
	bool OctF;//八角形
	static bool ON;//OctからNonへ

	static  CModel mNon;//九角形
	int NonHP;//九角形HP減算フラグ
	bool NonF;//九角形
	static bool NOF;//NonからModelなしへ

	void ChangeModel();

	static CModel mShave;

	int falseTime;

	//static CModel mDec;//十角形
	//int DecHP;//十角形
	//bool DecF;//十角形

};

class C3DIncreaseItem :public CCharacter{
public:

	C3DIncreaseItem() : mIncrease(0){}
		
	~C3DIncreaseItem();

	CCollider *mIncrease;

	C3DIncreaseItem(CModel*model, CVector position, CVector rotation, CVector scale);

	static CCharacter * mpthis;

	int mColsize;

	CVector adjust;

	enum EIncrease{};

	void Collision(CCollider*Inc, CCollider*y);

	void Update();

	void Init();

	void TaskCollision();

	void Increaserand();

	static int randIncr;

	static bool IncrF;

	static CModel mIncreasebom;//増殖爆弾

	static CModel mIncreasebox;//増殖箱

	static CModel mIncreasesuperbom;//増殖強化爆弾

	static CModel mIncreasemore;//増殖スコア×２箱
};


#endif