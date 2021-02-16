#include "CKey.h"
#include "CSceneGame.h"
#include "CMenu.h"

void CMenu::Init(){

	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	//タイトル設定
	mScene = EMENU;

	 Y = 370;

	 W = 15;

	 H = 18;
}

void CMenu::Update(){

	CTaskManager::Get()->Update();

	CTaskManager::Get()->Render();


	//2D描画開始
	Start2D(0, 800, 0, 600);

	CText::DrawString("STAGE SELECT", 250, 550, 15, 18);

	CText::DrawString("LEVEL", 500, 430, 15, 18);

	if (Y == 370){

		W = 17; H = 20;
	}

	else{

		W = 15; H = 18;

	}

	CText::DrawString("STAGE1", 150, 370, W, H); 
	
	CText::DrawString("...EASY", 420, 370, 15, 18);

	if (Y == 300){

		W = 17; H = 20;
	}

	else{

		W = 15; H = 18;

	}

	CText::DrawString("STAGE2 ", 150, 300, W, H); 
	
	CText::DrawString("...NORMAL", 420, 300, 15, 18);


	if (Y == 230){

		W = 17; H = 20;
	}

	else{

		W = 15; H = 18;

	}

	CText::DrawString("STAGE3", 150, 230, W, H); 

	CText::DrawString("...DIFFICULT!!", 420, 230, 15, 18);

	for (int i = 0; i < VectorRect.size(); i++) {
		//描画処理
		VectorRect[i]->Render();

	}

	CText::DrawString("[       ]", 115, Y, 15, 18);

	if (Y == 230 && CKey::Once('S')){

		Y = 370;

	}

	if (CKey::Once('S')){

		Y = Y - 70;

	}

		if (Y == 370 && CKey::Once('W')){

			Y = 230;
		}

		if (CKey::Once('W')){

		Y = Y + 70;
	}

	if (Y==370&&CKey::Once(VK_RETURN))
	{
		mScene = EGAME1_WAVE1;
	}

	if (Y == 300 && CKey::Once(VK_RETURN))
	{
		mScene = EGAME2_WAVE1;
	}

	End2D();

	CTaskManager::Get()->Delete();

	return;

}

CScene::EScene CMenu::GetNextScene(){

	return mScene;
}

void CMenu::Render(){


}

CMenu::~CMenu(){

	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();

	CTaskManager::Get()->Destory();

}