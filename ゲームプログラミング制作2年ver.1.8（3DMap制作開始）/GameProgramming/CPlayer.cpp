#include "CPlayer.h"
#include "CKey.h"

CCharacter *CPlayer::mpthis=0;
CCharacter *CBottomPlayer::mpthis = 0;
//#define G (9.8f/60.0f)  //重力加速度
//#define JUMPV0  (4.0f)  //ジャンプ初速
CPlayer::CPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = CVector(25.0f, 3.0f, 10.0f);;
	//モデルの三角形の数分、コライダの配列を作成します
	mColBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mColBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);
	}

	janpspead = 0;

	mpthis = this;

	mTag = CCharacter::EPLAYER;
}

CBottomPlayer::CBottomPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = CVector(25.0f, 3.0f, 10.0f);;
	//モデルの三角形の数分、コライダの配列を作成します
	mColBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mColBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);
	}

	janpspead = 0;

	mpthis = this;

	mTag = CCharacter::EPLAYER;
}

void CPlayer::Collision(CCollider*m,CCollider*y){
	return;
	//自身のコライダタイプの判定
	switch (m->mType){
	case CCollider::ETRIANGLE: //玉コライダ
		//相手が三角コライダの時
		if (y->mType == CCollider::ETRIANGLE){
			CVector adjust; //調整用ベクトル
			//三角形と線分の衝突判定
			if (CCollider::CollisionTriangleLine(y, m, &adjust)){
				//位置の更新
				mPosition = mPosition - adjust*-1.0;
				janpspead = 0;
				//行列の更新
				CCharacter::Update();
			}
		}
		break;
	}
}

void CBottomPlayer::Collision(CCollider*m, CCollider*y){
	return;
	//自身のコライダタイプの判定
	switch (m->mType){
	case CCollider::ETRIANGLE: //玉コライダ
		//相手が三角コライダの時
		if (y->mType == CCollider::ETRIANGLE){
			CVector adjust; //調整用ベクトル
			//三角形と線分の衝突判定
			if (CCollider::CollisionTriangleLine(y, m, &adjust)){
				//位置の更新
				mPosition = mPosition - adjust*-1.0;
				janpspead = 0;
				//行列の更新
				CCharacter::Update();
			}
		}
		break;
	}
}

void CPlayer::Update(){
	if (CKey::Push('N')){
		mRotation.mZ += 25.0f;
		if (CPlayer::mRotation.mZ > 25.1f){
			mRotation.mZ = 25.0f;
		}
	}
	 else if (CKey::Push('V')){
		mRotation.mZ -= 25.0f;
		if (CPlayer::mRotation.mZ < -25.1f){
			mRotation.mZ += 25.0f;
		}
	}
	else{
		mRotation.mZ = 0.0f;
	}
	if (CKey::Push('J')){
		mPosition.mX += 1.2;
		if (CPlayer::mPosition.mX >= 100 && CPlayer::mPosition.mX > 0){
		mPosition.mX -= 1.2;
		//mPosition.mZ += 0.3;
	}

	}
	if (CKey::Push('F')){
		mPosition.mX -= 1.2;

		if (CPlayer::mPosition.mX <= -100 && CPlayer::mPosition.mX < 0){
			mPosition.mX += 1.2;

		}
	}
	CCharacter::Update();
}


void CBottomPlayer::Update(){
	if (CKey::Push('N')){
		mRotation.mZ -= 25.0f;
		if (CBottomPlayer::mRotation.mZ < 25.1f){
			mRotation.mZ = -25.0f;
		}
	}
	else if (CKey::Push('V')){
		mRotation.mZ += 25.0f;
		if (CBottomPlayer::mRotation.mZ > 25.1f){
			mRotation.mZ = 25.0f;
		}
	}
	else{
		mRotation.mZ = 0.0f;
	}
	if (CKey::Push('J')){
		mPosition.mX -= 1.2;
		if (CBottomPlayer::mPosition.mX <= -120 && CBottomPlayer::mPosition.mX < 0){
			mPosition.mX += 1.2;
		}
	}
	if (CKey::Push('F')){
		if (CBottomPlayer::mPosition.mX >= 120 && CBottomPlayer::mPosition.mX > 0){
			mPosition.mX -= 1.2;
		}
		mPosition.mX += 1.2;
	}

	CCharacter::Update();
}
void CPlayer::TaskCollision(){

	mColBody[0].ChangePriority();
	mColBody[1].ChangePriority();
	mColBody[2].ChangePriority();
	mColBody[3].ChangePriority();
	mColBody[4].ChangePriority();
	mColBody[5].ChangePriority();
	mColBody[6].ChangePriority();
	mColBody[7].ChangePriority();
	mColBody[8].ChangePriority();
	mColBody[9].ChangePriority();
	mColBody[10].ChangePriority();
	mColBody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mColBody[0]);
	CCollisionManager::Get()->Collision(&mColBody[1]);
	CCollisionManager::Get()->Collision(&mColBody[2]);
	CCollisionManager::Get()->Collision(&mColBody[3]);
	CCollisionManager::Get()->Collision(&mColBody[4]);
	CCollisionManager::Get()->Collision(&mColBody[5]);
	CCollisionManager::Get()->Collision(&mColBody[6]);
	CCollisionManager::Get()->Collision(&mColBody[7]);
	CCollisionManager::Get()->Collision(&mColBody[8]);
	CCollisionManager::Get()->Collision(&mColBody[9]);
	CCollisionManager::Get()->Collision(&mColBody[10]);
	CCollisionManager::Get()->Collision(&mColBody[11]);

}
void CBottomPlayer::TaskCollision(){

	mColBody[0].ChangePriority();
	mColBody[1].ChangePriority();
	mColBody[2].ChangePriority();
	mColBody[3].ChangePriority();
	mColBody[4].ChangePriority();
	mColBody[5].ChangePriority();
	mColBody[6].ChangePriority();
	mColBody[7].ChangePriority();
	mColBody[8].ChangePriority();
	mColBody[9].ChangePriority();
	mColBody[10].ChangePriority();
	mColBody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mColBody[0]);
	CCollisionManager::Get()->Collision(&mColBody[1]);
	CCollisionManager::Get()->Collision(&mColBody[2]);
	CCollisionManager::Get()->Collision(&mColBody[3]);
	CCollisionManager::Get()->Collision(&mColBody[4]);
	CCollisionManager::Get()->Collision(&mColBody[5]);
	CCollisionManager::Get()->Collision(&mColBody[6]);
	CCollisionManager::Get()->Collision(&mColBody[7]);
	CCollisionManager::Get()->Collision(&mColBody[8]);
	CCollisionManager::Get()->Collision(&mColBody[9]);
	CCollisionManager::Get()->Collision(&mColBody[10]);
	CCollisionManager::Get()->Collision(&mColBody[11]);

}