#include "CCollisionManager.h"
//コライダクラスのインクルード
#include "CCollider.h"
//他で使用できるように外部変数で作成
CCollisionManager CollisionManager;

CCollisionManager*CCollisionManager::instance = 0;

CCollisionManager*CCollisionManager::Get(){

	if (instance==0){

		instance = new CCollisionManager();

	}

	return instance;

}

//衝突処理
void CCollisionManager::Collision(CCollider*collider) {
	
	int sPri = collider->mPriority + 100;//開始位置
	int ePri = collider->mPriority - 100;//終了位置

	//現在位置を先頭にする
	CCollider *pos = (CCollider*)mpHead->mpNext;
		//開始位置を先頭へ
		while (pos&&pos->mPriority>sPri) {

			//位置計算
			pos = (CCollider*)pos->mpNext;

		}
		if (pos){

			CCollider*next = (CCollider*)pos->mpNext;

			//終了位置まで繰り返し
			while (next&&next->mPriority>=ePri)
			{

				collider->mpParent->Collision(collider, next);

				//次を求める
				next = (CCollider*)next->mpNext;

			}

		}
	}

void CCollisionManager::Destory(){

	if (instance)

		delete instance;

	instance = 0;

}