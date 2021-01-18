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
//
#include "CModel.h"
/*
�m�[�}���A�C�e��
*/
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
	int DefeatBonus;//���j�{�[�i�X
	static int BMyScorePoint;

};
/*
�ړ��A�C�e���A�t�B�[�o�[�p�̗\��
*/
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
/*
��]�A�C�e��
*/
class CSpinItem :public CCharacter{
public:
	CSpinItem():mSItemBody(0){}

	~CSpinItem();
	CSpinItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mSItemBody;

	static bool RebirthF;

	static CCharacter*mpthis;

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
/*
�{�[�i�X�A�C�e���A�v�f���₵�\��
*/
class CBonus :public CCharacter{
public:
	CBonus():mBoBody(0){}

	~CBonus();
	CBonus(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mBoBody;

	static CCharacter*mpthis;

	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j

	void Update();

	int ItemCount;

	void TaskCollision();

	static int MStageCount;
	bool MminusF;
	int MDamageCount;
	static int BMyScorePoint;
	int MoveTime;
};
/*
���e
*/
class CExItem :public CCharacter{

public:

	CExItem(){}

	~CExItem();

	CCollider BomCol;

	static CCharacter*mpthis;

	CVector BjumpSpeed;

	CVector mAdjust;

	static bool jumpBF;

	static bool ReBomF;//////////////���X�|�[���t���Otrue�Ȃ瑶��false�Ȃ烊�X�|�[��

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
/*
s�폜�u���b�N�A�X�e�[�W���ɓ���邩��
*/
class CDeleteBlock :public CCharacter{

public:

	CDeleteBlock():mDelete(0){}

	~CDeleteBlock();

	CDeleteBlock(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mDelete;

	static CCharacter*mpthis;
	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j
	void Collision(CCollider*Dm, CCollider*y);

	void TaskCollision();

	void Update();

};

/*
�ϐF�A�C�e���A������ƐF��ϊ�
�����邱�Ƃŏ�����
*/
class CColorItem :public CItem{

public:

	CModel mRed;
	int RCount = 0;//�ԃu���b�N�J�E���g
	/*
	
	# Blender MTL File: 'None'
	# Material Count: 1

	newmtl Material
	Ns 323.999994
	Ka 0.0 0.0 0.0
	Kd 1.0 0.0 0.0
	Ks 0.0 0.0 0.0
	Ke 0.0 0.0 0.0
	Ni 1.450000
	d 1.000000
	illum 2
	*/
	CModel mBlue;
	int BCount = 0;//�u���b�N�J�E���g
	/*
	
# Blender MTL File: 'None'
# Material Count: 1

newmtl Material
Ns 323.999994
Ka 0.0 0.0 0.0
Kd 0.0 0.0 1.0
Ks 0.0 0.0 0.0
Ke 0.0 0.0 0.0
Ni 1.450000
d 1.000000
illum 2
*/

	CModel mGreen;
	int GCount = 0;//�΃u���b�N�J�E���g
	/*
	
	# Blender MTL File: 'None'
# Material Count: 1

newmtl Material
Ns 323.999994
Ka 0.0 0.0 0.0
Kd 0.0 0.65 0.0
Ks 0.0 0.0 0.0
Ke 0.0 0.0 0.0
Ni 1.450000
d 1.000000
illum 2
*/

	CModel mYellow;
	int YCount = 0;//���F�u���b�N�J�E���g
	/*
	
	# Blender MTL File: 'None'
	# Material Count: 1

	newmtl Material
	Ns 323.999994
	Ka 0.0 0.0 0.0
	Kd 1.0 1.0 0.0
	Ks 0.0 0.0 0.0
	Ke 0.0 0.0 0.0
	Ni 1.450000
	d 1.000000
	illum 2

*/
	static int CMyScorePoint;

	bool ChangeF;//�`�F���W�t���O//false�`�F���W����//true�F�����̐F�ȊO�֕ύX

	int COLORNUMBER;//�J���[�i���o�[//0=Red,1=Bule,2=Green,3=Yellow

	CModel mNextColor;//���ɗ��郂�f���̐F

	void Collision(CCollider*Cm, CCollider*y);

	void ChangeColor();

	void Init();

	void Update();

	void TaskCollision();

	//void Collision();

};
///////////////////////////////////////////////3D�Ŏg���p��Item

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

};
#endif