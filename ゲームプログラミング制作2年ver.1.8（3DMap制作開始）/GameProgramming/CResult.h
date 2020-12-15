#ifndef CRESULT_H
#define CRESULT_H

#include "CScene.h"
#include "CText.h"
#include "CRectangle.h"
class CResult :public CScene{
public:

	void Init();

	void Update();

	void Render();

	bool EScoreffF;//得点//////////////trueなら、表示falseなら消す

	bool ETotalffF;//合計点//////////////trueなら、表示falseなら消す

	int TotalScore;///////////Resultで表示するScore

	int EffCount;////////////カウント数値

	int EffCouTime;//////////数値表示時間

	EScene GetNextScene();

	~CResult();
};
#endif