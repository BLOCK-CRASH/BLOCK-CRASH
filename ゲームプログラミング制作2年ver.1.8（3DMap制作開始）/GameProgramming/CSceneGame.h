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
/*
�t�B�[�o�[�Q�[�W
*/

//extern CTexture �e�N�X�`����;

class CGage :public CRectangle{

	void Render(){

		if (mEnabled){

			CRectangle::Render();

		}

	}

};


/*
�Q�[���̃V�[��
�X�e�[�W1�̃E�F�[�u1
*/

class CSceneGame : public CScene {
public:

	~CSceneGame();

	CModel m2DPlayer;

	CModel mRe2DPlayer;

	CModel mColorItemR;//������

	CModel mColorItemY;//�������F

	CModel mColorItemG;//������

	CModel mColorItemB;//������

	CModel mItem;

	CModel mBoardR;

	CModel mBoard;

	CModel mMove;

	CModel mBall;
	
	int Attention;//�I�_�ł��邽�߂̎���

	int BAttentionTime;//�I�\������

	int CPAttentionTime;//�I�\������

	bool BomAttension;//�{���x���t���O

	bool ColorAttension;//�J���[�_���_�Ńt���O

	CModel mDammyBall;

	CModel mBomb;

	CModel mDelete;//�X�e���X�ŕ\��

	CModel mStage1;

	int WAVE1GAMETIME;//�E�F�[�u1��������

	bool mEnable;

	bool ResetF;
	
	bool Result;

	bool BigTime;

	static int Stage1_Wave1Score;

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

	C3DCamera mCamera;

	static int YScore;

	static int RScore;

	static int BScore;

	static int GScore;

	bool mEnable;

	bool ResetF;

	bool Result;

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
