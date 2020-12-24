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
/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:

	~CSceneGame();

	CModel mItem;

	CModel mBoardR;

	CModel mBoard;

	CModel mBall;
	
	CModel mBomb;

	CModel mDelete;//ステルスで表示

	bool mEnable;

	bool ResetF;
	
	bool Result;

	static int GAMETIME;

	static int COUNTDOWN;

	static int LETTERTIME;

	static int resultScore;

	static int HighScore;

	EScene GetNextScene();	
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
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

	C3DCamera mCamera;

	//CPlayer Player;

	bool ResetF;

	static int GAMETIME;

	static int LETTERTIME;

	static int resultScore;

	static int HighScore;

	EScene GetNextScene();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

};

#endif
