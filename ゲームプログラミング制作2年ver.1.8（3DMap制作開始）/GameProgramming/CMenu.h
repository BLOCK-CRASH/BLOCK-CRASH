#ifndef CMENU_H
#define CMENU_H

#include "CScene.h"
#include "CText.h"
#include "CRectangle.h"
#include "CCharacter.h"
class CMenu :public CScene{
public:

	int Y;

	int W;//���i����

	int H;//�����i����

	void Init();

	void Update();

	void Render();

	EScene GetNextScene();

	~CMenu();
};

#endif