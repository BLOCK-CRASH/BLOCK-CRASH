#ifndef CSCENEGAME3_H
#define CSCENEGAME3_H


#include "CScene.h"
//
#include "CSceneGame.h"
//
#include "CTaskManager.h"
//
#include "3DPlayer.h"
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
#include "CTexture.h"
//

class CSceneGame3 :public CScene{

	~CSceneGame3();

	CModel mItem;

	CModel mBall;

	CModel Bomb;

	CModel mDelete;

	CModel m3DPlayer2;

	bool mEnable;

	bool ResetF;

	bool Result;

	void Init();

	void Update();
};
#endif