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
3D�ړ��p�A�C�e��
�t�B�[�o�[�p�A�ʏ�p
*/
class C3DMoveItem :public CMoveItem{
private:

	static CCharacter*mpthis;
	int mColsize;
	CCollider *m3DMItemBody;


public:

	C3DMoveItem() :m3DMItemBody(0){}

	~C3DMoveItem();
	C3DMoveItem(CModel*model, CVector position, CVector rotation, CVector scale);
	static bool RebirthF;
	void Update();

	void TaskCollision();

	static int BStageCount;
	bool B3DminusF;
	//int BDamageCount;
	int M3DMyScorePoint;
};
/*
���j�A�C�e��
���j���邱�Ƃł������Ƃ��N����
*/
class C3DOrbitItem :public CSpinItem{
public:

	C3DOrbitItem() :m3DSItemBody(0){}

	~C3DOrbitItem();
	C3DOrbitItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *m3DSItemBody;

	static bool RebirthF;

	static CCharacter*mpthis;

	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
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
�ό`�A�C�e��
��������HP�����炵�A
���̌`�œ_�������܂�
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

	static CModel mTri;//�O�p�`
	int TriHP;//�O�p�`
	bool TriF;//�O�p�`HP���Z�t���O
	static bool TR;//Tri����Rec��

	static CModel mRec;//�l�p�`
	int RecHP;//�l�p�`HP���Z�t���O
	bool RecF;//�l�p�`
	static bool RP;//Rec����Pen��

	static CModel mPen;//�܊p�`
	int PenHP;//�܊p�`HP���Z�t���O
	bool PenF;//�܊p�`
	static bool PH;//Pen����Hex��

	static CModel mHex;//�Z�p�`
	int HexHP;//�Z�p�`HP���Z�t���O
	bool HexF;//�Z�p�`
	static bool HH;//Hex����Hep��

	static CModel mHep;//���p�`
	int HepHP;//���p�`HP���Z�t���O
	bool HepF;//���p�`
	static bool HO;//Hep����Oct��

	static CModel mOct;//���p�`
	int OctHP;//���p�`HP���Z�t���O
	bool OctF;//���p�`
	static bool ON;//Oct����Non��

	static  CModel mNon;//��p�`
	int NonHP;//��p�`HP���Z�t���O
	bool NonF;//��p�`
	static bool NOF;//Non����Model�Ȃ���

	void ChangeModel();

	static CModel mShave;

	int falseTime;

	//static CModel mDec;//�\�p�`
	//int DecHP;//�\�p�`
	//bool DecF;//�\�p�`

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

	static CModel mIncreasebom;//���B���e

	static CModel mIncreasebox;//���B��

	static CModel mIncreasesuperbom;//���B�������e

	static CModel mIncreasemore;//���B�X�R�A�~�Q��
};


#endif