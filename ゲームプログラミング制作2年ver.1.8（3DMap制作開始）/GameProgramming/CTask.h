#ifndef CTASK_H
#define CTASK_H
/*
タスククラス
タスクリストの要素
*/

class CTaskManager;
class CCollisionManager;
class CTask {
private:
	CTask *mpNext;	//次のポインタ
	CTask *mpPrev;	//前のポインタ
public:
	bool mEnabled;	//有効フラグ
	int mPriority;	//優先度

	void SetPriority(int priority)
	{
		mPriority = priority;
	}
	int GetPriority()
	{
		return mPriority;
	}
	void SetEnabled(int enabled)
	{
		mEnabled = enabled;
	}
	bool GetEnabled()
	{
		return mEnabled;
	}

	friend CTaskManager;
	friend CCollisionManager;
	//デフォルトコンストラクタ
	CTask()
		: mpNext(0), mpPrev(0), mPriority(0), mEnabled(true) {}
	//デストラクタ
	virtual ~CTask() {}
	//更新
	virtual void Update() {}
	//描画
	virtual void Render() {}

	virtual void TaskCollision(){}

};

#endif
