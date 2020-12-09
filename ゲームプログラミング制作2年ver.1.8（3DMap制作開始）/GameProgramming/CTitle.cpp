#include "CKey.h"
#include "CSceneGame.h"
#include "CTitle.h"

void CTitle::Init(){

	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	//タイトル設定
	mScene = ETITEL;

}

void CTitle::Update(){
	
	CTaskManager::Get()->Update();

	CTaskManager::Get()->Render();


	//2D描画開始
	Start2D(0, 800, 0, 600);

	CText::DrawString("BLOCK CRASH", 280, 400, 15, 18);

	for (int i = 0; i < VectorRect.size(); i++) {
		//描画処理
		VectorRect[i]->Render();

	}
		if (CKey::Once(VK_RETURN))
		{
			mScene = EMENU;
		}

	End2D();

	CTaskManager::Get()->Delete();

	return;

}

CScene::EScene CTitle::GetNextScene(){

	return mScene;
}

void CTitle::Render(){}

CTitle::~CTitle(){
	
	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();

}