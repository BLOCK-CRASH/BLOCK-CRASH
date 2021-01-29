#ifndef CSCENEGAME_WAVE2_H
#define CSCENEGAME_WAVE2_H
#include "CScene.h"
//
#include "CModel.h"
//
#include "CTaskManager.h"
//
#include "CPlayer.h"
//
#include "CItem.h"
//
#include "CBallPlayer.h"
//
#include "CRectangle.h"
//
#include "CItem.h"
//
#include "CTask.h"
//
#include "CKey.h"
//
#include "CRectangle.h"
//
#include "CDammyBallPlayer.h"

/*
フィーバーゲージ
*/

//extern CTexture テクスチャ名;

class CGage_Wave2 :public CRectangle{

	void Render(){

		if (mEnabled){

			CRectangle::Render();

		}

	}

};


/*
ゲームのシーン
ステージ1のウェーブ2
*/

class CSceneGame_Wave2 : public CScene {
public:

	~CSceneGame_Wave2();

	CModel m2DPlayer;

	CModel mRe2DPlayer;

	CModel mItem;

	CModel mBoardR;

	CModel mMove;

	CModel mBoard;

	CModel mSuperBomb;

	CModel mBall;

	int Attention;

	CModel mDammyBall;

	CModel mBomb;

	CModel mDelete;//ステルスで表示

	CModel mStage1;

	int WAVE2GAMETIME;//ウェーブ1制限時間

	int BAttentionTime;//！表示時間

	int CPAttentionTime;//！表示時間

	int TimeAttentionTime;//時間表示時間

	bool BomAttension;//ボム警告フラグ

	bool ColorAttension;//カラー点数点滅フラグ

	bool TimeAttension;//時間点滅フラグ

	int WAVE1GAMETIME;//ウェーブ1制限時間

	bool mEnable;

	bool ResetF;

	bool Result;

	bool BigTime;

	static int Stage1_Wave2Score;

	static int YScore;//黄色撃破スコア

	static int RScore;//赤撃破スコア

	static int BScore;//青撃破スコア

	static int GScore;//緑撃破スコア

	static int COUNTDOWN;

	static int LETTERTIME;

	static int resultScore;

	static int HighScore;

	EScene GetNextScene();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

};
#endif