#include "CSceneManager.h"
#include "CSceneGame.h"
#include "CSceneGame2.h"
#include "CSceneGame_Wave2.h"
#include "CTitle.h"
#include "CMenu.h"
#include "CResult.h"
CSceneManager SceneManager;

//コンストラクタ
CSceneManager::CSceneManager()
: mpScene(0)
{}
//デストラクタ（削除されるときに実行されます）
CSceneManager::~CSceneManager() {
	//シーンがあれば削除
	if (mpScene)
		//シーンの削除
		delete mpScene;
	mpScene = 0;
}
//初期化処理
void CSceneManager::Init() {
	//シーン識別
	mScene = CScene::ETITEL;
	//シーンを生成し、ポインタを設定する
	mpScene = new CTitle();
	//生成したクラスのメソッドが呼ばれる
	mpScene->Init();
}
//更新処理
void CSceneManager::Update() {
	//ポインタのUpdateを呼ぶ
	mpScene->Update();

	if (mScene != mpScene->GetNextScene()){
		mScene = mpScene->GetNextScene();

		delete mpScene;

		switch (mScene){

		case CScene::ETITEL:
			mpScene = new CTitle();
			mpScene->Init();

			break;

		case CScene::EMENU:

			mpScene = new CMenu();
			mpScene->Init();

			break;

		case CScene::EGAME1_WAVE1://ステージ1のウェーブ1
			mpScene = new CSceneGame();
			mpScene->Init();

			break;
		
		case CScene::EGAME1_WAVE2://ステージ1のウェーブ2
			mpScene = new CSceneGame_Wave2();
			mpScene->Init();

			break;

		case CScene::EGAME2:
			mpScene = new CSceneGame2();
			mpScene->Init();

			break;

		case CScene::ESTAGE1_RESULT:

			mpScene = new CResult();
			mpScene->Init();

			break;
		}
	}
}
