#ifndef CSCENEGAME_H
#define CSCENEGAME_H
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
//
#include "CTexture.h"
//

/*
フィーバーゲージ
*/

//extern CTexture テクスチャ名;

//class CGage :public CRectangle{
//
//	void Render(){
//
//		if (mEnabled){
//
//			CRectangle::Render();
//
//		}
//
//	}
//
//};


/*
ゲームのシーン
ステージ1のウェーブ1
*/

class CSceneGame : public CScene {
public:

	~CSceneGame();

	CModel m2DPlayer;

	CModel mRe2DPlayer;

	CModel mItem;

	CModel mBoardR;

	CModel mBoard;

	CModel mMove;

	CModel mBall;
	
	int Attention;//！点滅するための時間

	int BAttentionTime;//ボム表示時間

	int CPAttentionTime;//！表示時間

	int TimeAttentionTime;//時間表示時間

	bool BomAttension;//ボム警告フラグ

	bool ColorAttension;//カラー点数点滅フラグ

	bool TimeAttension;//時間点滅フラグ

	CModel mDammyBall;

	CModel mBomb;

	CModel mDelete;//ステルスで表示

	CModel mStage1;

	int WAVE1GAMETIME;//ウェーブ1制限時間

	bool mEnable;

	bool ResetF;
	
	bool Result;

	bool BigTime;

	static int Stage1_Wave1Score;

	static int YScore;//黄色撃破スコア

	static int RScore;//赤撃破スコア

	static int BScore;//青撃破スコア

	static int GScore;//緑撃破スコア

	static int COUNTDOWN;

	static int LETTERTIME;

	EScene GetNextScene();	
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	void Render();

};


#endif
