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

	static int FeverCount;//フィーバーカウント溜まってFキーでフィーバータイム

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

	static float ScoreMore;//加算数字

	static bool ScorePulsF;//加算フラグ
	
	static int ScoreBox;//スコア箱

	static int BScoreBox;//スコア箱(ノーマル

	static int SScoreBox;//スコア箱(スピン

	static int MScoreBox;//スコア箱(移動

	static int CScoreBox;//スコア箱(色

	static bool GoF;//スタート重力フラグ	

	static bool BallF;//ボールおんおふぅ

	CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*m, CCollider*y);

	void TaskCollision();	
	void Update();
	void Render();

};

#endif
//static float MoreBox;//加算箱
