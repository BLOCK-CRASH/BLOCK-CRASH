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
class CBallPlayer :CCharacter{
public:
	CBallPlayer(){}
	~CBallPlayer();

	int BALLtime;

	static int FeverCount;//�t�B�[�o�[�J�E���g���܂���F�L�[�Ńt�B�[�o�[�^�C��

	CCollider BallCol;
	
	static CCharacter*mpthis;

	static CVector jumpspeed;

	static	CVector mAdjust;

	static bool jumpF;

	static bool ColF;

	static bool PlusF;

	bool minusF;

	bool Boundf;//�o�E���h�t���Otrue�ŉ��Zfalse�Ŗ���

	static int BallHP;

	static float BoundNum;	

	static float ScoreMore;//���Z����

	static bool ScorePulsF;//���Z�t���O
	
	static int ScoreBox;//�X�R�A��

	static int BScoreBox;//�X�R�A��(�m�[�}��

	static int SScoreBox;//�X�R�A��(�X�s��

	static int MScoreBox;//�X�R�A��(�ړ�

	static int CScoreBox;//�X�R�A��(�F

	//static int RCount;	//�ԃu���b�NHP
	//static int BCount; //�u���b�NHP
	//static int GCount; //�΃u���b�NHP
	//static int YCount; //���u���b�NHP

	//static bool BF; //�X�R�A�t���O(�m�[�}��

	//static bool SF;//�X�R�A�t���O(�X�s��

	//static bool MF;//�X�R�A�t���O(�ړ�

	static bool CF;//�X�R�A�t���O(�F

	//static bool BMF;

	//static bool BOF;//�X�R�A�t���O(���e

	static bool GoF;//�X�^�[�g�d�̓t���O	


	CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*m, CCollider*y);

	void TaskCollision();	
	void Update();
	void Render();

};

#endif
//static float MoreBox;//���Z��
