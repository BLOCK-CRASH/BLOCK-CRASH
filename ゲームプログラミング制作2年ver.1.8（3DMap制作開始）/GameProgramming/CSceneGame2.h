#ifndef CSCENEGAME2_H
#define CSCENEGAME2_H
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


class CSceneGame2 : public CScene {
public:

	~CSceneGame2();

	CModel mItem;

	CModel mBoardR;

	CModel mBoard;

	CModel mBall;

	CModel mStage;

	CModel m3DPlayer1;
	CModel m3DPlayer2;
	CModel m3DPlayer3;
	CModel m3DPlayer4;

	CModel mDelete;

	CModel mShave;

	//C3DCamera mCamera;

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

	static int Stage2_Wave1Score;

	static int GAMETIME;

	static int COUNTDOWN;

	static int LETTERTIME;

	EScene GetNextScene();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	void CameraTopBottom();

	void CameraLeftRight();

};
#endif