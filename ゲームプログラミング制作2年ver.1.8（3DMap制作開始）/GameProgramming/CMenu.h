#ifndef CMENU_H
#define CMENU_H

#include "CScene.h"
#include "CText.h"
#include "CRectangle.h"
#include "CCharacter.h"
class CMenu :public CScene{
public:

	int Y;

	int W;//幅（文字

	int H;//高さ（文字

	void Init();

	void Update();

	void Render();

	EScene GetNextScene();

	~CMenu();
};

#endif