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

	static int BallHP;

	static float BoundNum;	

	static float ScoreMore;//���Z����

	static bool ScorePulsF;//���Z�t���O
	
	static int ScoreBox;//�X�R�A��

	static int BScoreBox;//�X�R�A��(�m�[�}��

	static int SScoreBox;//�X�R�A��(�X�s��

	static int MScoreBox;//�X�R�A��(�ړ�

	static int CScoreBox;//�X�R�A��(�F

	static bool GoF;//�X�^�[�g�d�̓t���O	

	static bool BallF;//�{�[�����񂨂ӂ�

	CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*m, CCollider*y);

	void TaskCollision();	
	void Update();
	void Render();

};

#endif
//static float MoreBox;//���Z��
