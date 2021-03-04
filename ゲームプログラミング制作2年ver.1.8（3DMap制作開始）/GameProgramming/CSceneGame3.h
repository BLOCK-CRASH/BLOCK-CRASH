#ifndef CSCENEGAME3_H
#define CSCENEGAME3_H


#include "CScene.h"
//
#include "CTaskManager.h"
//
#include "3DPlayer.h"
//
#include "C3DNormalItem.h"
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
#include "CTexture.h"
//

class CSceneGame3 :public CScene{

	~CSceneGame3();

	CModel mDia;//ひし形

	CModel mRec;//四角形

	CModel mTri;//三角形

	CModel mBall;

	CModel mBomb;

	CModel mDelete;

	CModel m3DPlayer2;

	CModel mStage;

	CVector Scale;

	int Attention;//！点滅するための時間

	int CPAttentionTime;//！表示時間

	int TimeAttentionTime;//時間表示時間

	bool TimeAttension;//時間点滅フラグ

	bool CamChan1;//視点ステージ切り替え1

	bool CamChan2;//視点ステージ切り替え2

	bool CamChan3;//視点ステージ切り替え3

	bool CamChan4;//視点ステージ切り替え4

	bool CamChanTop;//視点ステージ切り替え上

	bool CamChanBottom;//視点ステージ切り替え下

	int GAMETIME;

	int COUNTDOWN;

	bool mEnable;

	bool ResetF;

	bool Result;

	void Init();

	void Update();

	EScene GetNextScene();

};
#endif