#include "CKey.h"
#include "CSceneGame.h"
#include "CTitle.h"

void CTitle::Init(){

	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);

	//�^�C�g���ݒ�
	mScene = ETITEL;

}

void CTitle::Update(){
	
	CTaskManager::Get()->Update();

	CTaskManager::Get()->Render();


	//2D�`��J�n
	Start2D(0, 800, 0, 600);

	CText::DrawString("BLOCK CRASH", 280, 400, 15, 18);

	for (int i = 0; i < VectorRect.size(); i++) {
		//�`�揈��
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
	
	//�S�ẴC���X�^���X���폜���܂�
	for (int i = 0; i < VectorRect.size(); i++) {
		//�C���X�^���X�̍폜
		delete VectorRect[i];
	}
	//�ϒ��z��̃N���A
	VectorRect.clear();

}