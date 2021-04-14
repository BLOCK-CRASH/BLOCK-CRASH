#ifndef CITEM_H
#define CITEM_H

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

/*
�e�A�C�e��
*/

class CItem :public CCharacter{
public:
	CItem();
	virtual void Update();
	virtual void Render();
protected:
	static CCharacter*mpthis;
};

/*
�m�[�}���A�C�e��
*/
class CNormalItem :public CItem{
private:
	void Collision(CCollider*sm, CCollider*y);
	void Update();
	void TaskCollision();

	static CItem*mpthis;
	int ItemCount;
	CVector aj;

public:
	CNormalItem() :mItemBody(0){}
	~CNormalItem();
	CNormalItem(CModel*model, CVector position, CVector rotation, CVector scale);
	CCollider *mItemBody;
	static int BStageCount;
	bool BminusF;
	int BDamageCount;
	int DefeatBonus;//���j�{�[�i�X
	static int BMyScorePoint;
	int mColsize;

};
/*
�ړ��A�C�e���A�t�B�[�o�[�p�̗\��
*/
class CMoveItem :public CItem{
private:
	void Update();
	void TaskCollision();

	static CCharacter*mpthis;
	CCollider *mMItemBody;
	int ItemCount;
	int FeverTime;
	int mColsize;

public:
	CMoveItem():mMItemBody(0){}
	~CMoveItem();
	CMoveItem(CModel*model, CVector position, CVector rotation, CVector scale);
	static bool RebirthF;
	static bool FeverF;//�t�B�[�o�[�t���Ofalse�łȂ�true�Ńt�B�[�o�[�˓�
	static int BStageCount;
	static int MMyScorePoint;
};
/*
��]�A�C�e��
*/
class CSpinItem :public CItem{
private:
	void Update();
	void TaskCollision();
	CCollider *mSItemBody;

	static CCharacter*mpthis;
	int ItemCount;

public:
	CSpinItem():mSItemBody(0){}
	~CSpinItem();
	CSpinItem(CModel*model, CVector position, CVector rotation, CVector scale);

	static bool RebirthF;
	bool SminusF;

	//�Փ˔���
	//�i�R���C�_1�A�R���C�_2�j

	static int SStageCount;
	static int SMyScorePoint;

};
/*
�{�[�i�X�A�C�e���A�v�f���₵�\��
*/
class CBonus :public CItem{
private:

	void Update();
	void TaskCollision();

	CCollider *mBoBody;
	static CCharacter*mpthis;
	bool MminusF;
	int MDamageCount;
	int MoveTime;
	int mColsize;

public:
	static int BMyScorePoint;
	static int MStageCount;

	CBonus():mBoBody(0){}
	~CBonus();
	CBonus(CModel*model, CVector position, CVector rotation, CVector scale);
};
/*
���e
*/
class CExItem :public CItem{
private:

	void Collision(CCollider*Bm, CCollider*y);
	void Update();
	void TaskCollision();
	void Render();

	bool BomGoF;
	bool BomColF;

	CCollider BomCol;
	static CCharacter*mpthis;

public:

	CExItem(){}
	~CExItem();
	CExItem(CModel*model, CVector position, CVector rotation, CVector scale);
	CVector BjumpSpeed;
	static CVector mAdjust;
	static bool jumpBF;
	static bool ReBomF;//////////////���X�|�[���t���Otrue�Ȃ瑶��false�Ȃ烊�X�|�[��
	static int BomHP;
	static float BBoundNum;
	static int BomCutScore;//�X�R�A����
	static int BomDamageCount;//�_���[�W��
	static int BomTime;
};
/*
�X�[�p�[���e
*/
class CSuperExItem :public CItem{
private:

	void Collision(CCollider*SBm, CCollider*y);
	void Update();
	void TaskCollision();
	void Render();

	bool SBomGoF;
	bool SBomColF;

	CCollider SBomCol;

public:

	CSuperExItem(){}
	~CSuperExItem();
	CSuperExItem(CModel*model, CVector position, CVector rotation, CVector scale);
	static CCharacter*mpthis;
	CVector SBjumpSpeed;
	static CVector mAdjust;
	static bool jumpSBF;
	static bool ReSBomF;//////////////���X�|�[���t���Otrue�Ȃ瑶��false�Ȃ烊�X�|�[��
	static int SBomHP;
	static float SBBoundNum;
	static int SBomCutScore;//�X�R�A����
	static int SBomDamageCount;//�_���[�W��
	static int SBomTime;
};

/*
s�폜�u���b�N�A�X�e�[�W���ɓ���邩��
*/
class CDeleteBlock :public CItem{
private:

	void TaskCollision();
	void Update();

	CCollider *mDelete;
	static CCharacter*mpthis;
	int mColsize;

public:

	CDeleteBlock():mDelete(0){}
	~CDeleteBlock();
	CDeleteBlock(CModel*model, CVector position, CVector rotation, CVector scale);

};

/*
���X�|�[���u���b�N�A�X�e�[�W���ɓ���邩��
*/
class CResBlock :public CCharacter{
private:
	void TaskCollision();
	void Update();

	CCollider *mResp;
	static CCharacter*mpthis;
	int mColsize;

public:

	CResBlock() :mResp(0){}
	~CResBlock();
	CResBlock(CModel*model, CVector position, CVector rotation, CVector scale);

};

/*
�ϐF�A�C�e���A������ƐF��ϊ�
�����邱�Ƃŏ�����
*/
class CColorItem :public CItem{

public:

	static bool ScorePulsF;
	CVector aj;

static CModel mBlue;//�̃}�e���A��
static CModel mGreen;//�΂̃}�e���A��
static CModel mRed;//�Ԃ̃}�e���A��
static CModel mYellow;//���̃}�e���A��

static	float YCount;//���F�u���b�N�J�E���gMax��20000
static int YScore;
static bool YellowAttensionF;//���F���j�_���_�Ńt���O
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

static	float RCount;//�ԃu���b�N�J�E���gMax��9500
static int RScore;
static bool RedAttensionF;//�Ԍ��j�_���_�Ńt���O
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
	
static	float BCount;//�u���b�N�J�E���gMax��7000
static int BScore;
static bool BuleAttensionF;//���j�_���_�Ńt���O
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

static float GCount;//�΃u���b�N�J�E���gMax��6000
static int GScore;
static bool GreenAttensionF;//�Ό��j�_���_�Ńt���O
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

	CColorItem(CModel*model, CVector position, CVector rotation, CVector scale);
	~CColorItem();
	static int CMyScorePoint;
	static bool ChangeF;//�`�F���W�t���O//false�`�F���W����//true�F�����̐F�ȊO�֕ύX
	static bool RBF;//�Ԃ���ւ̃t���O//false�`�F���W����//true�F�����̐F�ȊO�֕ύX
	static bool BGF;//����΂ւ̃t���O//false�`�F���W����//true�F�����̐F�ȊO�֕ύX
	static bool GYF;//�΂��物�F�ւ̃t���O//false�`�F���W����//true�F�����̐F�ȊO�֕ύX
	static bool YRF;//���F����Ԃւ̃t���O//false�`�F���W����//true�F�����̐F�ȊO�֕ύX

	CCollider*mColorbody;
	void Collision(CCollider*Cm, CCollider*y);
	void ChangeColor();
	void Init();
	void Update();
	void TaskCollision();
	int mColsize;

};
///////////////////////////////////////////////3D�Ŏg���p��Item

#endif