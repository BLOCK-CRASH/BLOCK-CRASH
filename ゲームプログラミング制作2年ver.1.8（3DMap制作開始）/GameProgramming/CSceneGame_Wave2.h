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

	CModel mItem;

	CModel mBoardR;

	CModel mMove;

	CModel mBoard;

	CModel mSuperBomb;

	CModel mBall;

	int Attention;

	CModel mDammyBall;

	CModel mBomb;

	CModel mDelete;//�X�e���X�ŕ\��

	CModel mStage1;

	int WAVE2GAMETIME;//�E�F�[�u1��������

	int BAttentionTime;//�I�\������

	int CPAttentionTime;//�I�\������

	int TimeAttentionTime;//���ԕ\������

	bool BomAttension;//�{���x���t���O

	bool ColorAttension;//�J���[�_���_�Ńt���O

	bool TimeAttension;//���ԓ_�Ńt���O

	int WAVE1GAMETIME;//�E�F�[�u1��������

	bool mEnable;

	bool ResetF;

	bool Result;

	bool BigTime;

	static int Stage1_Wave2Score;

	static int YScore;//���F���j�X�R�A

	static int RScore;//�Ԍ��j�X�R�A

	static int BScore;//���j�X�R�A

	static int GScore;//�Ό��j�X�R�A

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