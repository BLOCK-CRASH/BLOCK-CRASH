#ifndef CBALLPLAYER_H
#define CBALLPLAYER_H

#include "CCharacter.h"

#include "CCollider.h"

#include "CPlayer.h"

#include "CCollisionManager.h"

#include "CText.h"

#include "CItem.h"

#include "CScene.h"

#include "CEffect.h"

#include "3DPlayer.h"

#include "BossItem.h"
class CBallPlayer :CCharacter{
private:
public:
	CBallPlayer(){}
	~CBallPlayer();

	int BALLtime;

	static int FeverCount;//�t�B�[�o�[�J�E���g���܂���F�L�[�Ńt�B�[�o�[�^�C��

	CCollider BallCol;
	
	static CCharacter*mpthis;

	CVector jumpspeed;

	CVector Rejumpspeed;

	static CVector mAdjust;//�ʂ̌���

	CVector InVector;//���ˊp

	CVector ReVector;//���ˊp

	float dot;//����

	bool jumpF;

	bool ColF;

	bool PlusF;

	bool minusF;

	bool Boundf;//�o�E���h�t���Otrue�ŉ��Zfalse�Ŗ���

	static int BallHP;

	float BoundNum;	

	static float ScoreMore;//���Z����

	static bool ScorePulsF;//���Z�t���O
	
	static int ScoreBox;//�X�R�A��

	static int BScoreBox;//�X�R�A��(�m�[�}��

	static int SScoreBox;//�X�R�A��(�X�s��

	static int MScoreBox;//�X�R�A��(�ړ�

	static int CScoreBox;//�X�R�A��(�F

	static bool CF;//�X�R�A�t���O(�F

	bool GoF;//�X�^�[�g�d�̓t���O	

	int BallVec;//�{�[���̐i�ޕ���

	CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*m, CCollider*y);

	void TaskCollision();	
	void Update();
	void Render();

};

#endif
//static float MoreBox;//���Z��
