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

	CModel mColorItemR;//初期赤

	CModel mColorItemY;//初期黄色

	CModel mColorItemG;//初期赤

	CModel mColorItemB;//初期青

	CModel mItem;

	CModel mBoardR;

	CModel mBoard;

	CModel mBall;

	CModel mBomb;

	CModel mDelete;//ステルスで表示

	CModel mStage1;

	int WAVE2GAMETIME;//ウェーブ1制限時間

	//CModel mBlue;//青のマテリアル
	//CModel mGreen;//緑のマテリアル
	//CModel mRed;//赤のマテリアル
	//CModel mYellow;//黄のマテリアル

	bool mEnable;

	bool ResetF;

	bool Result;

	static int YScore;

	static int RScore;

	static int BScore;

	static int GScore;

	static int Stage1_Wave2Score;

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