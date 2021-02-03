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

	CModel m3DPlayer;

	CModel mDelete;

	CModel mShave;

	C3DCamera mCamera;

	static int YScore;

	static int RScore;

	static int BScore;

	static int GScore;

	bool mEnable;

	bool ResetF;

	bool Result;

	bool CamChanRightF;//���_�X�e�[�W�E���؂�ւ�

	bool CamChanLeftF;//���_�X�e�[�W���؂�ւ�

	bool CamChanBackF;//���_�X�e�[�W����؂�ւ�

	static int GAMETIME;

	static int COUNTDOWN;

	static int LETTERTIME;

	//static int resultScore;

	static int HighScore;

	EScene GetNextScene();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

};
#endif