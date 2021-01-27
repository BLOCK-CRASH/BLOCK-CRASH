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
�t�B�[�o�[�Q�[�W
*/

//extern CTexture �e�N�X�`����;

class CGage_Wave2 :public CRectangle{

	void Render(){

		if (mEnabled){

			CRectangle::Render();

		}

	}

};


/*
�Q�[���̃V�[��
�X�e�[�W1�̃E�F�[�u2
*/

class CSceneGame_Wave2 : public CScene {
public:

	~CSceneGame_Wave2();

	CModel m2DPlayer;

	CModel mRe2DPlayer;

	CModel mColorItemR;//������

	CModel mColorItemY;//�������F

	CModel mColorItemG;//������

	CModel mColorItemB;//������

	CModel mItem;

	CModel mBoardR;

	CModel mBoard;

	CModel mBall;

	CModel mBomb;

	CModel mDelete;//�X�e���X�ŕ\��

	CModel mStage1;

	int WAVE2GAMETIME;//�E�F�[�u1��������

	//CModel mBlue;//�̃}�e���A��
	//CModel mGreen;//�΂̃}�e���A��
	//CModel mRed;//�Ԃ̃}�e���A��
	//CModel mYellow;//���̃}�e���A��

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
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

};
#endif