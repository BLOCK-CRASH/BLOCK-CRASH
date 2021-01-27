#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"



int CSceneGame::COUNTDOWN;
int CSceneGame::LETTERTIME;

int CSceneGame::YScore;
int CSceneGame::RScore; 
int CSceneGame::BScore; 
int CSceneGame::GScore;

int CSceneGame::Stage1_Wave1Score;
std::shared_ptr<CTexture>TextureExp(new CTexture());

void CSceneGame::Init() {

	COUNTDOWN = 4 * 60;

	WAVE1GAMETIME = 21 * 60;

	mScene = EGAME1_WAVE1;

	Result = false;

	BigTime = true;

	CColorItem::RCount - 1;
	CColorItem::BCount - 1;
	CColorItem::GCount - 1;
	CColorItem::YCount - 1;

	YScore = 20000;//���F�����{�[�i�X
	RScore = 10000;//�Ԃ����{�[�i�X
	BScore = 7000;//�����{�[�i�X
	GScore = 5000;//�΂����{�[�i�X

	TextureExp->Load("exp.tga");
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	CText::mFont.Load("FontG.tga");
	CBlackText::mBFont.Load("font.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	CColorItem::mRed.Load("cube.obj", "Red.mtl");//��
	CColorItem::mBlue.Load("cube.obj", "Blue.mtl");//��
	CColorItem::mGreen.Load("cube.obj", "Green.mtl");//��
	CColorItem::mYellow.Load("cube.obj", "Yellow.mtl");//��

	mStage1.Load("2DStage0119.obj", "2DStage0119.mtl");

	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBoard.Load("cube.obj", "cube.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mDammyBall.Load("sphere.obj", "sphere.mtl");

	mBomb.Load("Bomb.obj", "Bomb.mtl");

	mDelete.Load("cube.obj", "cube.mtl");

	m2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");

	mRe2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");

	//mDelete.mMaterials[0].mDiffuse[3] = 0.0f;
	
	/*�X�s���A�C�e���u���b�N----------------------------------------------------------------------------*/
	//new CSpinItem(&mBoardR, CVector(150.0f, 230.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0f, 20.0f, 14.0));
	//new CSpinItem(&mBoardR, CVector(-150.0f, 230.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0f, 20.0f, 14.0));
	//new CSpinItem(&mBoardR, CVector(150.0f, -230.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0f, 20.0f, 14.0));
	//new CSpinItem(&mBoardR, CVector(-150.0f, -230.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0f, 20.0f, 14.0));

	new CSpinItem(&mBoardR, CVector(0.0f, 20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(22.0f, 22.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(-110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(0.0f, -20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0f,15.0f, 10.0));

	///*�ړ��A�C�e���u���b�N----------------------------------------------------------------------------*/

	new CMoveItem(&mBoard, CVector(-2000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0,15.0,5.0));
	new CMoveItem(&mBoard, CVector(-1900.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1700.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1600.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1500.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1400.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1300.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1200.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1100.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-1000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-900.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(15.0, 15.0, 5.0));
	new CMoveItem(&mBoard, CVector(-700.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0, 15.0, 5.0));

	/*�m�[�}���A�C�e���u���b�N----------------------------------------------------------------------------*/
	new CItem(&mBoard, CVector(150.0f/*40.0*/, -75.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(-150.0f/*40.0*/, -75.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(150.0f/*40.0*/, 75.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(-150.0f/*40.0*/, 75.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	
	new CItem(&mBoard, CVector(200.0f/*40.0*/, 150.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(17.0, 17.0, 17.0));
	new CItem(&mBoard, CVector(-200.0f/*40.0*/, 150.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(17.0, 17.0, 17.0));
	new CItem(&mBoard, CVector(200.0f/*40.0*/, -150.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(17.0, 17.0, 17.0));
	new CItem(&mBoard, CVector(200.0f/*40.0*/, -150.0f, 0.0f), CVector(0.0f, 0.0f, 30.0f/*45*/), CVector(17.0, 17.0, 17.0));

	//new CItem(&mBoard, CVector(200.0f/*40.0*/, -150.0f, 0.0f), CVector(0.0f, 0.0f, -30.0f/*45*/), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 65.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 65.0f), CVector(11.0, 11.0, 11.0));

	/*�J���[�A�C�e���u���b�N----------------------------------------------------------------------------*/

	new CColorItem(&CColorItem::mRed, CVector(0.0f, 200.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));
	//new CColorItem(&CColorItem::mBlue, CVector(0.0f, -200.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));
	new CColorItem(&CColorItem::mGreen, CVector(0.0f, -200.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));
	//new CColorItem(&CColorItem::mYellow, CVector(-250.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 15.0));

	///*�{�[�i�X�A�C�e���u���b�N----------------------------------------------------------------------------*/
	//new CBonus(&mBoard, CVector(600.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(2.0f, 2.0f, 2.0));

	new CObj(&mStage1, CVector(0.0f, 0.0f, 0.0f), CVector(90.0f, 90.0f, 90.0), CVector(40.0f, 40.0f, 40.0));

	//�v���C���[(��)
	new CPlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(1.65, 1.65, 1.65));
	new CRePlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(0.75, 0.75, 0.75));
	//
	//��
	new CBallPlayer(&mBall, CVector(0.0f, 80.0f, 0.0f), CVector(), CVector(9.0f, 9.0f, 9.0));
	new CExItem(&mBomb, CVector(0.0f/*100*/, 450.0f, 0.0f), CVector(), CVector(20.0f, 20.0f, 20.0));

	new CDammyBallPlayer(&mDammyBall, CVector(200.0, 50.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

	new CDeleteBlock(&mDelete, CVector(-320.0f, -320.0f, 0.0f), CVector(0.0, 0.0, -45.0), CVector(100.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(320.0f, -320.0f, 0.0f), CVector(0.0, 0.0, 45.0), CVector(100.0f, 10.0f, 10.0));

	new CDeleteBlock(&mDelete, CVector(310.0f, 310.0f, 0.0f), CVector(0.0, 0.0, -45.0), CVector(100.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(-310.0f, 310.0f, 0.0f), CVector(0.0, 0.0, 45.0), CVector(100.0f, 10.0f, 10.0));


	new CDeleteBlock(&mDelete, CVector(-70.0f, 450.0f, 0.0f), CVector(0.0, 0.0, 45.0), CVector(80.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(70.0f, 450.0f, 0.0f), CVector(0.0, 0.0, -45.0), CVector(80.0f, 10.0f, 10.0));
	new CDeleteBlock(&mDelete, CVector(0.0f, 490.0f, 0.0f), CVector(0.0, 0.0, 0.0), CVector(40.0f, 10.0f, 10.0));

	CSceneGame::ResetF = true;

	CSceneGame::mEnable = true;
}


void CSceneGame::Update() {

	if (CSceneGame::WAVE1GAMETIME > 61){
	
		CTaskManager::Get()->Update();
	
		Stage1_Wave1Score = CBallPlayer::ScoreBox;

		Result = true;

	}

	if (CSceneGame::WAVE1GAMETIME < 1801){

		CSpinItem::RebirthF=true;
		CMoveItem::RebirthF = true;
	}


	if (CSceneGame::WAVE1GAMETIME < 61){

		Result = false;

		mEnable = false;

		if (Result == false){

			if (CKey::Once(VK_RETURN)){

				mScene = EGAME1_WAVE2;

			}
		}
	}

	if (CBallPlayer::CF == true){
	
			//CColorItem::ScorePulsF = false;

			if (CColorItem::YCount == 0){

				CColorItem::ScorePulsF = true;

				if (CColorItem::ScorePulsF == true){

					CColorItem::CMyScorePoint = YScore;

					CColorItem::ScorePulsF = false;

		}

	}
			if (CColorItem::RCount == 0){

				CColorItem::ScorePulsF = true;

				if (CColorItem::ScorePulsF == true){

					CColorItem::CMyScorePoint = RScore;

					CColorItem::ScorePulsF = false;

		}

	}
			if (CColorItem::BCount == 0){
		
				CColorItem::ScorePulsF = true;

				if (CColorItem::ScorePulsF == true){

					CColorItem::CMyScorePoint = BScore;

					CColorItem::ScorePulsF = false;

		}

	}
			if (CColorItem::GCount == 0){

				CColorItem::ScorePulsF = true;

				if (CColorItem::ScorePulsF == true){

					CColorItem::CMyScorePoint = GScore;

					CColorItem::ScorePulsF = false;

		}
	}

}

	//CColorItem::ChangeColor();

	CBallPlayer::mAdjust.mZ = NULL;
	CDammyBallPlayer::mDAdjust.mZ = NULL;
	CExItem::mAdjust.mZ = NULL;

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = CVector(0.0f, 0.0f, -850.0f);////0.0,0.0,-300
	//�����_�����߂�
	c = CVector(0.0f, 0.0f, 0.0f);
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f);

	//�J�����̐ݒ�
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	//CCollisionManager::Get()->Render();

	//2D�`��J�n
	Start2D(0, 800, 0, 600);

	if (COUNTDOWN > 60){

		COUNTDOWN--;

		if (ResetF == true){
		
			char buf[10];

			sprintf(buf, "%d", COUNTDOWN / 60);

			CText::DrawString(buf, 400, 500, 30, 30);

		}

	}

	else if (COUNTDOWN > 0){

		COUNTDOWN--;

			CText::DrawString("GO!!", 300, 500, 30, 30);
		}

	if (COUNTDOWN <= 0){
	
		WAVE1GAMETIME--;

		if (WAVE1GAMETIME > 601){

			BigTime = false;

			if (BigTime == false){
			
				char buf[10];

				sprintf(buf, "%d", WAVE1GAMETIME / 60);

				CText::DrawString(buf, 680, 550, 30, 30);

			}

		}

		if (WAVE1GAMETIME > 61 && WAVE1GAMETIME < 600){

			BigTime = true;

			if (BigTime == true){

				char buf[10];

				sprintf(buf, "%d", WAVE1GAMETIME / 60);

				CText::DrawString(buf, 650, 530, 45, 45);

			}

		}

		if (WAVE1GAMETIME < 60){

			CText::DrawString("TIME UP!", 300, 500, 14, 16);
			CText::DrawString("LET'S NEXT WAVE", 260, 400, 10, 12);

			//���̃g�[�^���X�R�A

			CText::DrawString("PUSH ENTER KEY", 260, 330, 10, 12);


		}

	}

	if (CBallPlayer::BallHP == 0){

		CBallPlayer::BallHP = 0;

		CText::DrawString("GAME OVER...", 280, 400, 15, 18);
	}

	if (CBallPlayer::FeverCount > 19
		&& CMoveItem::FeverF == false){

		CText::DrawString("PUSH F KEY!!", 24, 50, 12, 14);

	}
	CText::DrawString("SUTAG.1", 20, 20, 10, 12);

	char buf[100];

	sprintf(buf, "%d", CSceneGame::Stage1_Wave1Score);

	CBlackText::DrawString(buf, 200, 20, 10, 12);

	CTaskManager::Get()->Delete();

	//2D�`��I��
	End2D();


	return;
	
}
CScene::EScene CSceneGame::GetNextScene() {
	return mScene;
}
//�f�X�g���N�^
CSceneGame::~CSceneGame() {
	//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++) {
		//�C���X�^���X�̍폜
		delete VectorRect[i];
	}
	//�ϒ��z��̃N���A
	VectorRect.clear();

	CTaskManager::Get()->Destory();
	CCollisionManager::Get()->Destory();

}
///*�}�b�v�u���b�N----------------------------------------------------------------------------*/
//new CObj(&mBoard, CVector(265.0f, 137.0f, 0.0f), CVector(0.0f, 0.0f, 75.0), CVector(15.0f, 120.0f, 10.0));
//new CObj(&mBoard, CVector(-265.0f, 137.0f, 0.0f), CVector(0.0f, 0.0f, -75.0), CVector(15.0f, 120.0f, 10.0));
//new CObj(&mBoard, CVector(-235.0f, -125.0f, 0.0f), CVector(0.0f, 0.0f, -10.0), CVector(20.0f, 170.0f, 10.0));
//new CObj(&mBoard, CVector(235.0f, -125.0f, 0.0f), CVector(0.0f, 0.0f, 10.0), CVector(20.0f, 170.0f, 10.0));
//new CObj(&mBoard, CVector(195.0f, -160.0f, 0.0f), CVector(0.0f, 0.0f, -20.0), CVector(20.0f, 40.0f, 10.0));
//new CObj(&mBoard, CVector(-195.0f, -160.0f, 0.0f), CVector(0.0f, 0.0f, 20.0), CVector(20.0f, 40.0f, 10.0));
//new CObj(&mBoard, CVector(-235.0f, -120.0f, 0.0f), CVector(0.0f, 0.0f, -115.0), CVector(20.0f, 95.0f, 10.0));
//new CObj(&mBoard, CVector(235.0f, -120.0f, 0.0f), CVector(0.0f, 0.0f, 115.0), CVector(20.0f, 95.0f, 10.0));
//new CObj(&mBoard, CVector(195.0f, 135.0f, 0.0f), CVector(0.0f, 0.0f, 40.0), CVector(20.0f, 20.0f, 10.0));
//new CObj(&mBoard, CVector(-195.0f, 135.0f, 0.0f), CVector(0.0f, 0.0f, -40.0), CVector(20.0f, 20.0f, 10.0));
