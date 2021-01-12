#include "CResult.h"
#include "CKey.h"
#include "CSceneGame.h"
#include "CTitle.h"

void CResult::Init(){

	EScoreffF = 0;

	ETotalffF = 0;

	EffCount = 0;

	EffCouTime = 5 * 60;

	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	//タイトル設定
	mScene = ERESULT;

}

void CResult::Update(){

	EffCount += 49;

	EffCouTime--;

	CTaskManager::Get()->Update();

	CTaskManager::Get()->Render();


	//2D描画開始
	Start2D(0, 800, 0, 600);

	CText::DrawString("GAME  SET!!", 300, 500, 12, 14);
	CText::DrawString("RUNK", 200, 80, 16, 14);

	CText::DrawString("YOU SCORE  ....", 140, 400, 12, 14);////////////////////////得点
	CText::DrawString("TOTAL[        ]", 160, 180, 19, 21);////////////////////////残機数

	
	char buf[100];

	//得点処理
/*-----------------------------------------------------------------------------------------------------*/
	if (EffCouTime > 241){
	
		EScoreffF = true;

		if (EScoreffF == true){

			sprintf(buf, "%d", EffCount / 1);
			CBlackText::DrawString(buf, 550, 400, 17, 19);

		}

	}

	if (EffCouTime < 240) {

		EScoreffF = false;

	}

	if (EScoreffF == false){

		sprintf(buf, "%d", CBallPlayer::ScoreBox);
		CBlackText::DrawString(buf, 550, 400, 17, 19);

	}

/*-----------------------------------------------------------------------------------------------------*/
//残機数処理
/*-----------------------------------------------------------------------------------------------------*/


	CText::DrawString("LIFE BONUS ....", 140, 330, 12, 14);////////////////////////残機数
	sprintf(buf, "%d", CBallPlayer::BallHP);
	CText::DrawString(buf, 550, 330, 17, 19);

/*-----------------------------------------------------------------------------------------------------*/
//合計点処理
/*-----------------------------------------------------------------------------------------------------*/

	if (EffCouTime >= 120){

		ETotalffF = true; 

		if (ETotalffF == true){

			sprintf(buf, "%d", EffCount / 1);
			CBlackText::DrawString(buf, 470, 180, 17, 19);

		}

	}
	if (EffCouTime <119){
	
		ETotalffF = false;

	}


	if (ETotalffF == false){

		sprintf(buf, "%d", TotalScore);
		CBlackText::DrawString(buf, 450, 180, 19, 24);

		if (CBallPlayer::BallHP >= 0) {/////////////////////////////BallHPが残っていれば掛けて合計する

			TotalScore = CBallPlayer::BallHP*CBallPlayer::ScoreBox;////////////////////////BallHP*合計点

		}

	}


/*-----------------------------------------------------------------------------------------------------*/
//ランク処理
/*-----------------------------------------------------------------------------------------------------*/

	if (EffCouTime < 1){
	
		if (TotalScore < 4999){

			CBlackText::DrawString("D", 500, 80, 16, 14);

		}

		if (TotalScore < 9999 && TotalScore > 5000){

			CBlackText::DrawString("C", 500, 80, 16, 14);

		}

		if (TotalScore < 17499 && TotalScore > 10000){

			CBlackText::DrawString("B", 500, 80, 17, 15);

		}

		if (TotalScore < 24999 && TotalScore > 15000) {

			CBlackText::DrawString("A", 500, 80, 20, 18);

		}

		if (TotalScore < 25000 && TotalScore > 30000) {

			CBlackText::DrawString("S!", 500, 80, 20, 18);

		}

		if (TotalScore > 30001) {

			CBlackText::DrawString("SS!!", 500, 80, 20, 18);

		}

	}


	if (EffCouTime < -120){

		if (CKey::Once(VK_RETURN)){

			mScene = ETITEL;

		}

	}

	End2D();

	CTaskManager::Get()->Delete();

	return;

}

CScene::EScene CResult::GetNextScene(){

	return mScene;
}

void CResult::Render(){}

CResult::~CResult(){

	//全てのインスタンスを削除します
	for (int i = 0; i < VectorRect.size(); i++) {
		//インスタンスの削除
		delete VectorRect[i];
	}
	//可変長配列のクリア
	VectorRect.clear();

	CTaskManager::Get()->Destory();

}