#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H
//タスクマネージャのインクルード
#include "CTaskManager.h"
class CCollider;

/*
コリジョンマネージャ
コライダのリスト管理
*/
class CCollisionManager : public CTaskManager {
public:
	//衝突処理
	void Collision(CCollider *collider);

	void Destory();

	static CCollisionManager*CCollisionManager::Get();
	
	static CCollisionManager*CCollisionManager::instance;

};


#endif
