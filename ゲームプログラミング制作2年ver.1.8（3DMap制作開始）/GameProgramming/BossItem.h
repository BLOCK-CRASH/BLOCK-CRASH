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
3D�ړ��p�A�C�e��
�t�B�[�o�[�p�A�ʏ�p
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

	static CCharacter*mpthis;

	static int ShaveMyScorePoint;

	void Collision(CCollider*Sha, CCollider*y);

	static	bool ModelChanF;

	CVector adjust;

	void Update();

	void Init();

	int u;

	void TaskCollision();

	static CModel mTri;//�O�p�`
	static int TriHP;//�O�p�`
	static bool TriF;//�O�p�`
	bool TR;//Tri����Rec��

	static CModel mRec;//�l�p�`
	static int RecHP;//�l�p�`
	static bool RecF;//�l�p�`
	bool RP;//Rec����Pen��

	static CModel mPen;//�܊p�`
	static int PenHP;//�܊p�`
	static bool PenF;//�܊p�`
	bool PH;//Pen����Hex��

	static CModel mHex;//�Z�p�`
	static int HexHP;//�Z�p�`
	static bool HexF;//�Z�p�`
	bool HH;//Hex����Hep��

	static CModel mHep;//���p�`
	static int HepHP;//���p�`
	static bool HepF;//���p�`
	bool HO;//Hep����Oct��

	static CModel mOct;//���p�`
	static int OctHP;//���p�`
	static bool OctF;//���p�`
	bool ON;//Oct����Non��

	static  CModel mNon;//��p�`
	static int NonHP;//��p�`
	static bool NonF;//��p�`
	bool NOF;//Non����Model�Ȃ���

	void ChangeModel();

	//static CModel mDec;//�\�p�`
	//int DecHP;//�\�p�`
	//bool DecF;//�\�p�`

};

#endif