#ifndef CSCENEGAME2_WAVE2_H
#define CSCENEGAME2_WAVE2_H
#include "CScene.h"
//
#include "CModel.h"
//
#include "CTaskManager.h"
//
#include "CPlayer.h"
//
#include "3DPlayer.h"
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


class CSceneGame2_Wave2 : public CScene {
public:

	~CSceneGame2_Wave2();

	CModel mItem;

	CModel mBoardR;

	CModel mBoard;

	CModel mBall;

	CModel mStage;

	CModel m3DPlayer2;

	CModel mDelete;

	CModel mIncreasebom;//増殖爆弾

	CModel mIncreasebox;//増殖箱

	CModel mIncreasesuperbom;//増殖強化爆弾

	CModel mIncreasemore;//増殖×２箱

	bool mEnable;

	bool ResetF;

	bool Result;

	bool CamChanOri;//初期値へ戻す

	bool CamChan1;//視点ステージ切り替え1

	bool CamChan2;//視点ステージ切り替え2

	bool CamChan3;//視点ステージ切り替え3

	bool CamChan4;//視点ステージ切り替え4

	bool CamChanTop;//視点ステージ切り替え上

	bool CamChanBottom;//視点ステージ切り替え下

	static int GAMETIME;

	static int COUNTDOWN;

	static int LETTERTIME;

	static int HighScore;

	EScene GetNextScene();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	void CameraTopBottom();

	void CameraLeftRight();

};
#endif