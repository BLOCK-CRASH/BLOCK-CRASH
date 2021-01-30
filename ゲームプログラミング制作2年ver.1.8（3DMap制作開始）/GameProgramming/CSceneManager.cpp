#include "CSceneManager.h"
#include "CSceneGame.h"
#include "CSceneGame2.h"
#include "CSceneGame_Wave2.h"
#include "CTitle.h"
#include "CMenu.h"
#include "CResult.h"
CSceneManager SceneManager;

//�R���X�g���N�^
CSceneManager::CSceneManager()
: mpScene(0)
{}
//�f�X�g���N�^�i�폜�����Ƃ��Ɏ��s����܂��j
CSceneManager::~CSceneManager() {
	//�V�[��������΍폜
	if (mpScene)
		//�V�[���̍폜
		delete mpScene;
	mpScene = 0;
}
//����������
void CSceneManager::Init() {
	//�V�[������
	mScene = CScene::ETITEL;
	//�V�[���𐶐����A�|�C���^��ݒ肷��
	mpScene = new CTitle();
	//���������N���X�̃��\�b�h���Ă΂��
	mpScene->Init();
}
//�X�V����
void CSceneManager::Update() {
	//�|�C���^��Update���Ă�
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

		case CScene::EGAME1_WAVE1://�X�e�[�W1�̃E�F�[�u1
			mpScene = new CSceneGame();
			mpScene->Init();

			break;
		
		case CScene::EGAME1_WAVE2://�X�e�[�W1�̃E�F�[�u2
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
