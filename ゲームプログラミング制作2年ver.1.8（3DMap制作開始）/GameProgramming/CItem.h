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
ノーマルアイテム
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
	int DefeatBonus;//撃破ボーナス
	static int BMyScorePoint;

	int mColsize;

};
/*
移動アイテム、フィーバー用の予定
*/
class CMoveItem :public CCharacter{
public:
	CMoveItem():mMItemBody(0){}

	~CMoveItem();
	CMoveItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mMItemBody;

	static bool RebirthF;

	static bool FeverF;//フィーバーフラグfalseでなしtrueでフィーバー突入

	static CCharacter*mpthis;

	void Update();

	int ItemCount;

	int FeverTime;

	void TaskCollision();

	static int BStageCount;

	static int MMyScorePoint;

	int mColsize;

};
/*
回転アイテム
*/
class CSpinItem :public CCharacter{
public:
	CSpinItem():mSItemBody(0){}

	~CSpinItem();
	CSpinItem(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mSItemBody;

	static bool RebirthF;

	static CCharacter*mpthis;

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

	int mColsize;

};
/*
ボーナスアイテム、要素増やし予定
*/
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

	int mColsize;

};
/*
爆弾
*/
class CExItem :public CCharacter{

public:

	CExItem(){}

	~CExItem();

	CCollider BomCol;

	static CCharacter*mpthis;

	CVector BjumpSpeed;

	static CVector mAdjust;

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
/*
スーパー爆弾
*/
class CSuperExItem :public CCharacter{

public:

	CSuperExItem(){}

	~CSuperExItem();

	CCollider SBomCol;

	static CCharacter*mpthis;

	CVector SBjumpSpeed;

	static CVector mAdjust;

	static bool jumpSBF;

	static bool ReSBomF;//////////////リスポーンフラグtrueなら存在falseならリスポーン

	bool SBomGoF;

	bool SBomColF;

	static int SBomHP;

	static float SBBoundNum;

	static int SBomCutScore;//スコア減数

	static int SBomDamageCount;//ダメージ数

	static int SBomTime;

	CSuperExItem(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*SBm, CCollider*y);

	void Update();

	void TaskCollision();

	void Render();

};

/*
s削除ブロック、ステージ内に入れるかも
*/
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

	int mColsize;

};

/*
リスポーンブロック、ステージ内に入れるかも
*/
class CResBlock :public CCharacter{

public:

	CResBlock() :mResp(0){}

	~CResBlock();

	CResBlock(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider *mResp;

	static CCharacter*mpthis;
	//衝突判定
	//（コライダ1、コライダ2）
	//void Collision(CCollider*Dm, CCollider*y);

	void TaskCollision();

	void Update();

	int mColsize;

};

/*
変色アイテム、当たると色を変換
揃えることで消える
*/
class CColorItem :public CCharacter{

public:

	static bool ScorePulsF;

	CVector aj;

static CModel mBlue;//青のマテリアル
static CModel mGreen;//緑のマテリアル
static CModel mRed;//赤のマテリアル
static CModel mYellow;//黄のマテリアル

static	float YCount;//黄色ブロックカウントMaxで20000
static int YScore;
static bool YellowAttensionF;//黄色撃破点数点滅フラグ
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

static	float RCount;//赤ブロックカウントMaxで9500
static int RScore;
static bool RedAttensionF;//赤撃破点数点滅フラグ

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
	
static	float BCount;//青ブロックカウントMaxで7000
static int BScore;
static bool BuleAttensionF;//青撃破点数点滅フラグ

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

static float GCount;//緑ブロックカウントMaxで6000
static int GScore;
static bool GreenAttensionF;//緑撃破点数点滅フラグ

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

	static bool ChangeF;//チェンジフラグ//falseチェンジ無し//true色を今の色以外へ変更

	static bool RBF;//赤から青へのフラグ//falseチェンジ無し//true色を今の色以外へ変更

	static bool BGF;//青から緑へのフラグ//falseチェンジ無し//true色を今の色以外へ変更

	static bool GYF;//緑から黄色へのフラグ//falseチェンジ無し//true色を今の色以外へ変更
	
	static bool YRF;//黄色から赤へのフラグ//falseチェンジ無し//true色を今の色以外へ変更

	//static int COLORNUMBER;//カラーナンバー//0=Red,1=Bule,2=Green,3=Yellow

	CCollider*mColorbody;

	CModel mNextColor;

	//static CModel *mpModel;

	void Collision(CCollider*Cm, CCollider*y);

	void ChangeColor();

	void Init();

	void Update();

	void TaskCollision();

	int mColsize;

	//void Collision();

};
///////////////////////////////////////////////3Dで使う用のItem

#endif