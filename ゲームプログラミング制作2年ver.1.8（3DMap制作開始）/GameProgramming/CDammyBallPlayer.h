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

	bool minusF;//点数

	bool BMinusF;//ダミー減速用フラグ

	static int DammyHP;

	static float DBoundNum;

	static float DammyScoreMore;//加算数字

	static bool DammyScorePulsF;//加算フラグ

	static int DammyScoreBox;//スコア箱

	static int DammyBScoreBox;//スコア箱(ノーマル

	static int DammySScoreBox;//スコア箱(スピン

	static int DammyMScoreBox;//スコア箱(移動

	static int DammyCScoreBox;//スコア箱(色

	static bool DammyGoF;//スタート重力フラグ	

	CDammyBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale);

	void CCollision(CCollider*Dammy, CCollider*y);

	void TaskCollision();

	void Update();

	void Render();
};
#endif