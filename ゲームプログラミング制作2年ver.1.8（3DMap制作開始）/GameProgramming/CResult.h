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

	EScene GetNextScene();

	~CResult();
};
#endif