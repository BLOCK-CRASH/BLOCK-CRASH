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

	bool CamChanOri;//�����l�֖߂�

	bool CamChan1;//���_�X�e�[�W�؂�ւ�1

	bool CamChan2;//���_�X�e�[�W�؂�ւ�2

	bool CamChan3;//���_�X�e�[�W�؂�ւ�3

	bool CamChan4;//���_�X�e�[�W�؂�ւ�4

	bool CamChanTop;//���_�X�e�[�W�؂�ւ���

	bool CamChanBottom;//���_�X�e�[�W�؂�ւ���

	static int Stage2_Wave1Score;

	static int GAMETIME;

	static int COUNTDOWN;

	static int LETTERTIME;

	EScene GetNextScene();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	void CameraTopBottom();

	void CameraLeftRight();

};
#endif