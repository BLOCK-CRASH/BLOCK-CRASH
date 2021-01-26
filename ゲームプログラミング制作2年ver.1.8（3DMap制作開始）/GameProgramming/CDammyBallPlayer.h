#ifndef CDAMMYBALLPLAYER_H
#define CDAMMYBALLPLAYER_H
#include "CCharacter.h"

#include "CCollider.h"

#include "CPlayer.h"

#include "CCollisionManager.h"

#include "CText.h"

#include "CItem.h"

#include "CScene.h"

#include "CEffect.h"

class CDammyBallPlayer :public CCharacter{
public:

	CDammyBallPlayer(){}

	~CDammyBallPlayer();

	int DammyBallTime;

	CCollider Dammycol;

	static CCharacter*mpthis;

	static CVector jumpspeed;

	static	CVector mAdjust;

	static bool jumpF;

	static bool ColF;

	static bool PlusF;

	bool minusF;//�_��

	bool BMinusF;//�_�~�[�����p�t���O

	static int DammyHP;

	static float DBoundNum;

	static float DammyScoreMore;//���Z����

	static bool DammyScorePulsF;//���Z�t���O

	static int DammyScoreBox;//�X�R�A��

	static int DammyBScoreBox;//�X�R�A��(�m�[�}��

	static int DammySScoreBox;//�X�R�A��(�X�s��

	static int DammyMScoreBox;//�X�R�A��(�ړ�

	static int DammyCScoreBox;//�X�R�A��(�F

	static bool DammyGoF;//�X�^�[�g�d�̓t���O	

	CDammyBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale);

	void CCollision(CCollider*Dammy, CCollider*y);

	void TaskCollision();

	void Update();

	void Render();
};
#endif