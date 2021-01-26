#include "CDammyBallPlayer.h"
#include "CKey.h"

//Dammy

bool::CDammyBallPlayer::jumpF = false;
bool::CDammyBallPlayer::ColF = false;
bool::CDammyBallPlayer::PlusF = false;
bool::CDammyBallPlayer::DammyScorePulsF = true;
bool::CDammyBallPlayer::DammyGoF = true;

CCharacter *CDammyBallPlayer::mpthis = 0;
int CDammyBallPlayer::DammyHP = 0;

float CDammyBallPlayer::DBoundNum = 0;
float CDammyBallPlayer::DammyScoreMore = 0;//加算数字
int CDammyBallPlayer::DammyScoreBox = 0;//スコア箱
int CDammyBallPlayer::DammyBScoreBox = 0; // スコア箱(ノーマル
int CDammyBallPlayer::DammySScoreBox = 0;//スコア箱(スピン
int CDammyBallPlayer::DammyMScoreBox = 0;//スコア箱(移動
int CDammyBallPlayer::DammyCScoreBox = 0;//スコア箱(色

CVector CDammyBallPlayer::jumpspeed = CVector(0.0, 0.0, 0.0);
CVector CDammyBallPlayer::mAdjust = CVector(0.0, 0.0, 0.0);

CDammyBallPlayer::CDammyBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:Dammycol(this, CVector(), CVector(),
CVector(1.0, 1.0, 1.0), scale.mX){

	mpModel = model;

	mRotation = rotation;

	mPosition = position;

	mScale = scale;

	jumpspeed = CVector();

	DBoundNum = 0.75;

	CDammyBallPlayer::Dammycol.mType = CCollider::ESPHERE;

	mTag = CCharacter::EDAMMYBALL;

	DammyHP = 20;

	DammyGoF = false;

	//BF, SF, MF, CF = false;

	//DammyScoreMore = 1.0;

	DammyScoreBox = 0;

	mpthis = this;

	DammyBallTime = 3 * 60;

	//minusF = true;
}

CDammyBallPlayer::~CDammyBallPlayer(){

	CCollisionManager::Get()->Remove(this);
	mpthis = 0;

}

void CDammyBallPlayer::CCollision(CCollider*Dammy, CCollider*y){

	switch (Dammy->mType)

	{
	
	case CCollider::ESPHERE:

		if (y->mType == CCollider::ETRIANGLE){

			if (CCollider::CollisionTriangleSphere(y, Dammy, &mAdjust)){

				DammyHP = DammyHP - 1;

				if (ColF == true){

					if (DBoundNum < 3.0){

						BMinusF = true;

						if (BMinusF == true){

							DBoundNum = DBoundNum + 0.05;

							BMinusF = false;

						}

					}

					else{

						DBoundNum = DBoundNum;

					}

					jumpspeed = mAdjust.Normalize()*DBoundNum;

					ColF = false;

				}

				if (y->mpParent->mTag == CCharacter::EITEM){

					DammyScoreBox = CDammyBallPlayer::DammyScoreBox + CItem::BMyScorePoint / 2;

				}

				if (y->mpParent->mTag == CCharacter::ESPINITEM){

					DammyScoreBox = CDammyBallPlayer::DammyScoreBox + CSpinItem::SMyScorePoint / 2;

				}

				if (y->mpParent->mTag == CCharacter::EMOVEITEM){

					DammyScoreBox = CDammyBallPlayer::DammyScoreBox + CMoveItem::MMyScorePoint / 2;

				}

				if (y->mpParent->mTag == CCharacter::ECOLOR){}

				if (y->mpParent->mTag == CCharacter::EMOVEBONUS){}

				if (y->mpParent->mTag == CCharacter::EDELETE){

					DammyHP = 0;

				}
			}
		}
		break;
	}

}

void CDammyBallPlayer::Update(){

	DammyBallTime--;

	ColF = true;

	CDammyBallPlayer::DammyBScoreBox = CItem::BMyScorePoint;
	CDammyBallPlayer::DammySScoreBox = CSpinItem::SMyScorePoint;
	CDammyBallPlayer::DammyMScoreBox = CMoveItem::MMyScorePoint;
	CDammyBallPlayer::DammyCScoreBox = CColorItem::CMyScorePoint;

	CDammyBallPlayer::mAdjust = CVector(0.0, 0.0, 0.0);

	if (DammyGoF == false){

		if (CDammyBallPlayer::DammyHP > 0){

			if (DammyBallTime < 0 && CKey::Once('D')){

				DammyGoF = true;

				CDammyBallPlayer::jumpspeed = CVector(0.0f, +1.5f, 0.0f);

				CDammyBallPlayer::jumpF = true;

			}
		}
	}

	if (jumpF == true){

		mPosition = mPosition + jumpspeed;

	}

	if (DammyHP < 0){

		mEnabled = false;

	}

	mPosition = mPosition + mAdjust + jumpspeed;

	CCharacter::Update();

}

void CDammyBallPlayer::TaskCollision(){

	Dammycol.ChangePriority();

	CCollisionManager::Get()->Collision(&Dammycol);


}
void CDammyBallPlayer::Render(){

	CCharacter::Render();
}
