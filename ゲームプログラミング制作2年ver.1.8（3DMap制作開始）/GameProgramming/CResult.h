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

	bool EScoreffF;//���_//////////////true�Ȃ�A�\��false�Ȃ����

	bool ETotalffF;//���v�_//////////////true�Ȃ�A�\��false�Ȃ����

	int TotalScore;///////////Result�ŕ\������Score

	int EffCount;////////////�J�E���g���l

	int EffCouTime;//////////���l�\������

	EScene GetNextScene();

	~CResult();
};
#endif