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

	static int FeverCount;//フィーバーカウント溜まってFキーでフィーバータイム

	CCollider BallCol;
	
	static CCharacter*mpthis;

	CVector jumpspeed;

	CVector Rejumpspeed;

	static CVector mAdjust;//面の向き

	CVector InVector;//入射角

	CVector ReVector;//反射角

	float dot;//内積

	bool jumpF;

	bool ColF;

	bool PlusF;

	bool minusF;

	bool Boundf;//バウンドフラグtrueで加算falseで無効

	static int BallHP;

	float BoundNum;	

	static float ScoreMore;//加算数字

	static bool ScorePulsF;//加算フラグ
	
	static int ScoreBox;//スコア箱

	static int BScoreBox;//スコア箱(ノーマル

	static int SScoreBox;//スコア箱(スピン

	static int MScoreBox;//スコア箱(移動

	static int CScoreBox;//スコア箱(色

	static bool CF;//スコアフラグ(色

	bool GoF;//スタート重力フラグ	

	int BallVec;//ボールの進む方向

	CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale);

	void Collision(CCollider*m, CCollider*y);

	void TaskCollision();	
	void Update();
	void Render();

};

#endif
//static float MoreBox;//加算箱
