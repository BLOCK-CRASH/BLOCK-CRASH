#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
//タスククラスのインクルード
#include "CTask.h"

/*
タスクマネージャ
タスクリストの管理
*/
class CTaskManager {
private:

	static CTaskManager *CTaskManager::instance;


protected:

	CTask *mpHead;	//先頭ポインタ

public:
//	CTask *mpTail;	//最後ポインタ
	//デフォルトコンストラクタ
	CTaskManager();
	//デストラクタ
	virtual ~CTaskManager();
	//リストに追加
	//Add(タスクのポインタ)
	void Add(CTask *task);
	//更新
	void Update();
	//描画
	void Render();
	//22
	//リストから削除
	//Remove(タスクのポインタ)
	void Remove(CTask *task);
	//インスタンス破棄
	void Destory();

	//22
	//タスクの削除
	void Delete();

	void TaskCollision();

	void ChangePriority(CTask*task, int priority);

	static CTaskManager*CTaskManager::Get();

};

//タスクマネージャyの外部参照

#endif
