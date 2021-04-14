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
親アイテム
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
ノーマルアイテム
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
	int DefeatBonus;//撃破ボーナス
	static int BMyScorePoint;
	int mColsize;

};
/*
移動アイテム、フィーバー用の予定
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
	static bool FeverF;//フィーバーフラグfalseでなしtrueでフィーバー突入
	static int BStageCount;
	static int MMyScorePoint;
};
/*
回転アイテム
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

	//衝突判定
	//（コライダ1、コライダ2）

	static int SStageCount;
	static int SMyScorePoint;

};
/*
ボーナスアイテム、要素増やし予定
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
爆弾
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
	static bool ReBomF;//////////////リスポーンフラグtrueなら存在falseならリスポーン
	static int BomHP;
	static float BBoundNum;
	static int BomCutScore;//スコア減数
	static int BomDamageCount;//ダメージ数
	static int BomTime;
};
/*
スーパー爆弾
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
	static bool ReSBomF;//////////////リスポーンフラグtrueなら存在falseならリスポーン
	static int SBomHP;
	static float SBBoundNum;
	static int SBomCutScore;//スコア減数
	static int SBomDamageCount;//ダメージ数
	static int SBomTime;
};

/*
s削除ブロック、ステージ内に入れるかも
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
リスポーンブロック、ステージ内に入れるかも
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
変色アイテム、当たると色を変換
揃えることで消える
*/
class CColorItem :public CItem{

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

	CCollider*mColorbody;
	void Collision(CCollider*Cm, CCollider*y);
	void ChangeColor();
	void Init();
	void Update();
	void TaskCollision();
	int mColsize;

};
///////////////////////////////////////////////3Dで使う用のItem

#endif