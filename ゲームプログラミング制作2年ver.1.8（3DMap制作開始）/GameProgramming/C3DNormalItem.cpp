#include "C3DNormalItem.h"

#define QUANTITY 50

CCharacter*C3DNormal::mpthis;
CCharacter*C3DDummy::mpthis;

int C3DNormal::HP;
int C3DNormal::Quantity;
C3DNormal::C3DNormal(CModel*model, CVector position, CVector rotation, CVector scale)
:mNormalBody(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale/*CVector(10.0, 10.0, 10.0);*/;
	//モデルの三角形の数分、コライダの配列を作成します
	mNormalBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mNormalBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}
	mpthis = this;

	mEnabled = true;

	Quantity = QUANTITY;
}

C3DDummy::C3DDummy(CModel*model, CVector position, CVector rotation, CVector scale)
:mDummyBody(){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale/*CVector(10.0, 10.0, 10.0);*/;
	//モデルの三角形の数分、コライダの配列を作成します
	mDummyBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mDummyBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}

}

C3DNormal::~C3DNormal(){

	if (mNormalBody)
		delete[]mNormalBody;

}
C3DDummy::~C3DDummy(){

	if (mDummyBody)
		delete[]mDummyBody;

}

void C3DNormal::Collision(CCollider*Nm, CCollider*y){

	switch (Nm->mType)
	{
	case CCollider::ETRIANGLE:
			if (CCollider::CollisionTriangleSphere(Nm, y, &a)){
				if (y->mpParent->mTag == CCharacter::EBALL){

					mEnabled = false;
					Quantity = Quantity - 1;
			}
		}
		break;
	}
}

void C3DNormal::Update(){
	//if (C3DNormal::HP < 1){
	//	mEnabled = false;
	//}
	CCharacter::Update();
}

void C3DDummy::Update(){
	CCharacter::Update();
}

void C3DNormal::TaskCollision(){
	for (int N = 0; N < mColsize; N++){
		mNormalBody[N].ChangePriority();
	}
}

void C3DDummy::TaskCollision(){
	for (int D = 0; D < mColsize; D++){
		mDummyBody[D].ChangePriority();
		CCollisionManager::Get()->Collision(&mDummyBody[D]);
	}
}
