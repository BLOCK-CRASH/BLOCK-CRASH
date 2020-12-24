#include "CCollisionManager.h"
//�R���C�_�N���X�̃C���N���[�h
#include "CCollider.h"
//���Ŏg�p�ł���悤�ɊO���ϐ��ō쐬
CCollisionManager CollisionManager;

CCollisionManager*CCollisionManager::instance = 0;

CCollisionManager*CCollisionManager::Get(){

	if (instance==0){

		instance = new CCollisionManager();

	}

	return instance;

}

//�Փˏ���
void CCollisionManager::Collision(CCollider*collider) {
	
	int sPri = collider->mPriority + 100;//�J�n�ʒu
	int ePri = collider->mPriority - 100;//�I���ʒu

	//���݈ʒu��擪�ɂ���
	CCollider *pos = (CCollider*)mpHead->mpNext;
		//�J�n�ʒu��擪��
		while (pos&&pos->mPriority>sPri) {

			//�ʒu�v�Z
			pos = (CCollider*)pos->mpNext;

		}
		if (pos){

			CCollider*next = (CCollider*)pos->mpNext;

			//�I���ʒu�܂ŌJ��Ԃ�
			while (next&&next->mPriority>=ePri)
			{

				collider->mpParent->Collision(collider, next);

				//�������߂�
				next = (CCollider*)next->mpNext;

			}

		}
	}

void CCollisionManager::Destory(){

	if (instance)

		delete instance;

	instance = 0;

}