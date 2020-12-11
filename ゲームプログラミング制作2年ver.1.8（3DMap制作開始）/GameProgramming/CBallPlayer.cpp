#include "CBallPlayer.h"
#include "CKey.h"

bool::CBallPlayer::jumpF = false;
bool::CBallPlayer::ColF = false;
bool::CBallPlayer::PlusF = false;
bool::CBallPlayer::ScorePulsF = true;
bool::CBallPlayer::GoF = true;
bool::CBallPlayer::BallF = false;

CCharacter *CBallPlayer::mpthis = 0;
int CBallPlayer::BallHP = 6;

float CBallPlayer::BoundNum = 0;
float CBallPlayer::ScoreMore = 0;//加算数字
int CBallPlayer::ScoreBox = -180;//スコア箱
int CBallPlayer::BScoreBox = 0;
int CBallPlayer::SScoreBox = 0;

extern std::shared_ptr<CTexture>TextureExp;

CVector CBallPlayer::jumpspeed = CVector(0.0, 0.0, 0.0);
CBallPlayer::CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:BallCol(this, CVector(), CVector(),
CVector(1.0,1.0,1.0), scale.mX){

	mTag = CCharacter::EBALL;

	mpModel = model;
	
	mRotation = rotation;

	mPosition = position;

	mScale = scale;

	jumpspeed = CVector();

	BoundNum = 0.75;
	
	CBallPlayer::BallCol.mType = CCollider::ESPHERE;

	GoF = false;

	ScoreMore = 1.0;

	ScoreBox = 0;

	mpthis = this;

	BALLtime = 3 * 60;
}

CBallPlayer::~CBallPlayer(){

	CCollisionManager::Get()->Remove(this);
	mpthis = 0;

}
void CBallPlayer::Collision(CCollider*m, CCollider*y){

	switch (m->mType)
	{

	case CCollider::ESPHERE://自分のコライダ

		if (y->mType == CCollider::ETRIANGLE){		

			if (CCollider::CollisionTriangleSphere(y, m, &mAdjust)){

				if (ColF == true){

					mAdjust.mZ = NULL;
					

					if (BoundNum < 1.3){
						BoundNum += 0.05;
					}
					else{
						BoundNum = BoundNum;
					}
					
					jumpspeed = mAdjust.Normalize()*BoundNum;

					ColF = false;
				}

				if (y->mpParent->mTag == CCharacter::EITEM){

					ScoreMore + 0.1;

					ScoreBox = ScoreBox + CItem::BMyScorePoint;

					ScorePulsF = false;

				}
				if (y->mpParent->mTag == CCharacter::ESPINITEM){

					ScoreMore + 0.1;

					ScoreBox = ScoreBox + CSpinItem::SMyScorePoint;
				}
				if (y->mpParent->mTag == CCharacter::EBOMB){

					ScoreBox = ScoreBox-CExItem::BomCutScore;

				}

				if (y->mpParent->mTag == CCharacter::EPLAYER){		//プレイヤーならScoreMoreを初期値へ戻す

					ScoreMore = 1.0;

				}

				if (y->mpParent->mTag == CCharacter::EMOVEBONUS){

					ScoreBox = ScoreBox + CMoveItem::MMyScorePoint;

				}

				if (y->mpParent->mTag == CCharacter::EDELETE){

					mPosition.mY = 50.0;

					mPosition.mX = 0.0;

					jumpspeed = CVector(0.0,0.0,0.0);

					jumpF = false;

					BallHP = BallHP - 1;

					BallF = true;

					GoF = false;
				}

			}


		}
		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionSphereSphere(m, y, &mAdjust)){

				if (y->mpParent->mTag == CCharacter::EBOMB){

					ScoreBox = ScoreBox - CExItem::BomCutScore;

					new CEffect(mPosition, 100.0, 100.0, TextureExp, 4, 4, 7);

				}

			}
		}
		break;
	}
}

void CBallPlayer::Update(){

	BALLtime--;

	ColF = true;

	//PlusF = true;

	//ScoreBox  /*BScoreBox + SScoreBox*/++;

	CBallPlayer::mAdjust = CVector(0.0, 0.0, 0.0);
	
	if (GoF == false){

		if (CBallPlayer::BallHP){

			if (BALLtime < 0 && CKey::Once(' ')){

				GoF = true;

				CBallPlayer::jumpspeed = CVector(0.0f, +0.75f, 0.0f);

				CBallPlayer::jumpF = true;

			}
		}
	}

	if (jumpF == true){

		mPosition = mPosition + jumpspeed;

	}

	if (ScorePulsF == false){

		CBallPlayer::BScoreBox = CItem::BMyScorePoint*CBallPlayer::ScoreMore;
		CBallPlayer::SScoreBox = CSpinItem::SMyScorePoint*CBallPlayer::ScoreMore;

		ScorePulsF = true;

	}
	CCharacter::Update();


}

void CBallPlayer::TaskCollision(){

	BallCol.ChangePriority();

	CCollisionManager::Get()->Collision(&BallCol);
}
void CBallPlayer::Render(){

	mPosition = mPosition + mAdjust + jumpspeed;

	CCharacter::Update();
	CCharacter::Render();
}

