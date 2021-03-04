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

	CModel mDia;//�Ђ��`

	CModel mRec;//�l�p�`

	CModel mTri;//�O�p�`

	CModel mBall;

	CModel mBomb;

	CModel mDelete;

	CModel m3DPlayer2;

	CModel mStage;

	CVector Scale;

	int Attention;//�I�_�ł��邽�߂̎���

	int CPAttentionTime;//�I�\������

	int TimeAttentionTime;//���ԕ\������

	bool TimeAttension;//���ԓ_�Ńt���O

	bool CamChan1;//���_�X�e�[�W�؂�ւ�1

	bool CamChan2;//���_�X�e�[�W�؂�ւ�2

	bool CamChan3;//���_�X�e�[�W�؂�ւ�3

	bool CamChan4;//���_�X�e�[�W�؂�ւ�4

	bool CamChanTop;//���_�X�e�[�W�؂�ւ���

	bool CamChanBottom;//���_�X�e�[�W�؂�ւ���

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