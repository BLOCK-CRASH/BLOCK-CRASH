#ifndef CCHARACTER_H
#define CCHARACTER_H
//ベクトルクラスのインクルード
#include "CVector.h"
//モデルクラスのインクルード
#include "CModel.h"
//マトリクスクラスのインクルード
#include "CMatrix.h"
//タスククラスのインクルード
#include "CTask.h"
//#include "CCollider.h"
//コライダクラスの宣言
class CCollider;
/*
キャラクタークラス
ゲームキャラクタの基本的な機能を定義する
*/
class CCharacter : public CTask {
public:
	//種類
	enum ETag {
		ENONE,	//初期値
		EWALL,//マップの壁
		EPOINT,	//ポイント
		EPLAYER,//プレイヤー
		EBALL, //ボールプレイヤー
		EDAMMYBALL,//ダミーボール
		EITEM,//普通ブロック
		ESPINITEM,//回転ブロック
		EMOVEITEM,//フィーバーアイテム
		EBOMB,//爆発ブロック
		EHIGHBOM,//スーパーボム
		EMOVEBONUS,//移動ボーナスブロック
		EDELETE,//削除ブロック
		ERESDELETE,//初期位置リスブロック
		ECOLOR//色変えブロック
	};
	ETag mTag;
//	CCharacter *mpParent;	//親
	CVector mPosition; //位置
	CVector mRotation; //回転
	CVector mScale; //拡大縮小
	CModel *mpModel; //モデルのポインタ
	CMatrix mMatrix; //合成行列
	CMatrix mMatrixTranslate; //平行移動行列
	CMatrix mMatrixRotate; //回転行列
	CMatrix mMatrixScale; //拡大縮小行列
	//22
	CCharacter();
	~CCharacter();
	//更新処理
	void Update();
	//描画処理
	void Render();
	//衝突処理
	virtual void Collision(CCollider *mycol, CCollider *youcol) {}
	//
	//void ChangePriority(int priority);
};

#endif
