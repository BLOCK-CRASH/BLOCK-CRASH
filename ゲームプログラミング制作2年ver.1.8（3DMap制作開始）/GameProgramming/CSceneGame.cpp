#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CCollisionManager.h"
//
#include "CItem.h"



int CSceneGame::GAMETIME;
int CSceneGame::COUNTDOWN;
int CSceneGame::LETTERTIME;
std::shared_ptr<CTexture>TextureExp(new CTexture());

void CSceneGame::Init() {

	COUNTDOWN = 4 * 60;

	GAMETIME = 61 * 60;

	mScene = EGAME1;

	Result = false;

	TextureExp->Load("exp.tga");
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	CText::mFont.Load("FontG.tga");
	CBlackText::mBFont.Load("font.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	//mColorItemR.Load("cube.obj", "Red.mtl");

	//mColorItemY.Load("cube.obj", "Yellow.mtl");

	//mColorItemG.Load("cube.obj", "Green.mtl");

	//mColorItemB.Load("cube.obj", "Blue.mtl");

	CColorItem::mRed.Load("cube.obj", "Red.mtl");//��
	CColorItem::mBlue.Load("cube.obj", "Blue.mtl");//��
	CColorItem::mGreen.Load("cube.obj", "Green.mtl");//��
	CColorItem::mYellow.Load("cube.obj", "Yellow.mtl");//��

	mStage1.Load("2DStage0119.obj", "2DStage0119.mtl");

	mBoardR.Load("cubeRotate.obj", "cubeRotate.mtl");

	mBoard.Load("cube.obj", "cube.mtl");

	mBall.Load("sphere.obj", "sphere.mtl");

	mBomb.Load("Bomb.obj", "Bomb.mtl");

	mDelete.Load("cube.obj", "cube.mtl");

	m2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");

	mRe2DPlayer.Load("2DPlayer0119_001.obj", "2DPlayer0119_001.mtl");

	//mDelete.mMaterials[0].mDiffuse[3] = 0.0f;
	
	/*�X�s���A�C�e���u���b�N----------------------------------------------------------------------------*/
	new CSpinItem(&mBoardR, CVector(250.0f, 200.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(14.0f, 14.0f, 14.0));
	new CSpinItem(&mBoardR, CVector(-250.0f, 200.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(14.0f, 14.0f, 14.0));

	//new CSpinItem(&mBoardR, CVector(60.0f, 20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(-110.0f, 70.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(8.0f, 8.0f, 5.0));
	//new CSpinItem(&mBoardR, CVector(0.0f, -20.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(15.0f,15.0f, 10.0));

	/*�m�[�}���A�C�e���u���b�N----------------------------------------------------------------------------*/
	new CItem(&mBoard, CVector(0.0f/*40.0*/, -50.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(0.0f/*40.0*/, -40.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(0.0f/*40.0*/, -30.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f/*45*/), CVector(11.0, 11.0, 11.0));
	new CItem(&mBoard, CVector(0.0f/*40.0*/, -20.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f/*45*/), CVector(11.0, 11.0, 11.0));

	
	//new CItem(&mBoard, CVector(-40.0f, 70.0f, 1.0f), CVector(0.0f, 0.0f, 45.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-50.0f, -60.0f, 1.0f), CVector(0.0f, 0.0f, 40.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 65.0f), CVector(11.0, 11.0, 11.0));
	//new CItem(&mBoard, CVector(-120.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 65.0f), CVector(11.0, 11.0, 11.0));
	/*�J���[�A�C�e���u���b�N----------------------------------------------------------------------------*/

	new CColorItem(&CColorItem::mRed, CVector(0.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(11.0, 11.0, 11.0));
	//new CColorItem(&CColorItem::mBlue, CVector(20.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(11.0, 11.0, 11.0));
	//new CColorItem(&CColorItem::mGreen, CVector(40.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(11.0, 11.0, 11.0));
	//new CColorItem(&CColorItem::mYellow, CVector(60.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(11.0, 11.0, 11.0));

	///*�ړ��A�C�e���u���b�N----------------------------------------------------------------------------*/
	
	new CMoveItem(&mBoard, CVector(-2000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1900.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1700.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1600.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1500.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1400.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1300.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1200.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1100.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-1000.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-900.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-800.0f, -200.0f, 0.0f), CVector(0.0f, 0.0f, 15.0f), CVector(20.0, 20.0, 20.0));
	new CMoveItem(&mBoard, CVector(-700.0f, 100.0f, 0.0f), CVector(0.0f, 0.0f, 45.0f), CVector(20.0, 20.0, 20.0));

	///*�{�[�i�X�A�C�e���u���b�N----------------------------------------------------------------------------*/
	//new CBonus(&mBoard, CVector(600.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(2.0f, 2.0f, 2.0));

	new CObj(&mStage1, CVector(0.0f, 0.0f, 0.0f), CVector(90.0f, 90.0f, 90.0), CVector(40.0f, 40.0f, 40.0));

	//�v���C���[(��)
	new CPlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(1.6, 1.6, 1.6));
	new CRePlayer(&m2DPlayer, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 90.0f), CVector(0.7, 0.7, 0.7));
	
	//��
	new CBallPlayer(&mBall, CVector(0.0f, 0.0f, 0.0f), CVector(), CVector(9.0f, 9.0f, 9.0));
	new CExItem(&mBomb, CVector(0.0f/*100*/, 450.0f, 0.0f), CVector(), CVector(20.0f, 20.0f, 20.0));

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

	if (CSceneGame::GAMETIME > 61){
	
		CTaskManager::Get()->Update();
	
		Result = true;

	}

	if (CSceneGame::GAMETIME < 1801){

		CSpinItem::RebirthF=true;
		CMoveItem::RebirthF = true;
	}


	if (CSceneGame::GAMETIME < 61){

		Result = false;

		mEnable = false;

		if (Result == false){

			if (CKey::Once(VK_RETURN)){

				mScene = ERESULT;

			}
		}
	}


	if (CColorItem::RBF == true){
		CColorItem::mRed = CColorItem::mBlue;
		CColorItem::RBF = false;
	}
	if (CColorItem::BGF == true){
		CColorItem::mBlue = CColorItem::mGreen;
		CColorItem::BGF = false;
	}
	if (CColorItem::GYF == true){
		CColorItem::mGreen = CColorItem::mYellow;
		CColorItem::GYF = false;
	}
	if (CColorItem::YRF == true){
		CColorItem::mYellow = CColorItem::mRed;
		CColorItem::YRF = false;
	}

	//CColorItem::ChangeColor();

	CBallPlayer::mAdjust.mZ = NULL;

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = CVector(0.0f, 0.0f, -550.0f);////0.0,0.0,-300
	//�����_�����߂�
	c = CVector(0.0f, 0.0f, 0.0f);
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f);

	//�J�����̐ݒ�
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);

	CTaskManager::Get()->Render();

	CTaskManager::Get()->TaskCollision();

	CCollisionManager::Get()->Render();

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
	
		if (GAMETIME > 60){

			//GAMETIME--;

			char buf[10];

			sprintf(buf, "%d", GAMETIME / 60);

			CText::DrawString(buf, 680, 30, 30, 30);

		}

		else{

			CText::DrawString("GAME  SET!!", 300, 500, 10, 12);

		}

	}

	if (CBallPlayer::BallHP == 0){

		CBallPlayer::BallHP = 0;

		CText::DrawString("GAME OVER...", 280, 400, 15, 18);
	}

	if (CBallPlayer::FeverCount > 19
		&& CMoveItem::FeverF == false){

		CText::DrawString("PUSH F KEY!!", 320, 40, 18, 20);

	}
	CText::DrawString("SUTAG.1", 20, 20, 10, 12);

	char buf[100];

	sprintf(buf, "%d", CBallPlayer::ScoreBox);

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
