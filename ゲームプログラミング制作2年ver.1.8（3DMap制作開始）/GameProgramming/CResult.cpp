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

	//�^�C�g���ݒ�
	mScene = ERESULT;

}

void CResult::Update(){

	EffCount += 49;

	EffCouTime--;

	CTaskManager::Get()->Update();

	CTaskManager::Get()->Render();


	//2D�`��J�n
	Start2D(0, 800, 0, 600);

	CText::DrawString("GAME  SET!!", 300, 500, 12, 14);
	CText::DrawString("RUNK", 200, 80, 16, 14);

	CText::DrawString("YOU SCORE  ....", 140, 400, 12, 14);////////////////////////���_
	CText::DrawString("TOTAL[        ]", 160, 180, 19, 21);////////////////////////�c�@��

	
	char buf[100];

	//���_����
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
//�c�@������
/*-----------------------------------------------------------------------------------------------------*/


	CText::DrawString("LIFE BONUS ....", 140, 330, 12, 14);////////////////////////�c�@��
	sprintf(buf, "%d", CBallPlayer::BallHP);
	CText::DrawString(buf, 550, 330, 17, 19);

/*-----------------------------------------------------------------------------------------------------*/
//���v�_����
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

		if (CBallPlayer::BallHP >= 0) {/////////////////////////////BallHP���c���Ă���Ί|���č��v����

			TotalScore = CBallPlayer::BallHP*CBallPlayer::ScoreBox;////////////////////////BallHP*���v�_

		}

	}


/*-----------------------------------------------------------------------------------------------------*/
//�����N����
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

	//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++) {
		//�C���X�^���X�̍폜
		delete VectorRect[i];
	}
	//�ϒ��z��̃N���A
	VectorRect.clear();

	CTaskManager::Get()->Destory();

}