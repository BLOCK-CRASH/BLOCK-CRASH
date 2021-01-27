#include "CBallPlayer.h"
#include "CKey.h"

bool::CBallPlayer::ScorePulsF = true;

//bool::CBallPlayer::BF = false;//(ノーマル:trueで点数追加falseで無効
//bool::CBallPlayer::SF = false;//(スピン:trueで点数追加falseで無効
//bool::CBallPlayer::MF = false;//(移動:trueで点数追加falseで無効
bool::CBallPlayer::CF = false;//(色:trueで点数追加falseで無効
//bool::CBallPlayer::BMF = false;//(ボーナス:trueで点数追加falseで無効
//bool::CBallPlayer::BOF = false;//(ボム:trueで減点falseで無効

CCharacter *CBallPlayer::mpthis = 0;
int CBallPlayer::BallHP = 0;

float CBallPlayer::BoundNum = 0;
float CBallPlayer::ScoreMore = 0;//加算数字
int CBallPlayer::ScoreBox = 0;//スコア箱
int CBallPlayer::BScoreBox = 0; // スコア箱(ノーマル
int CBallPlayer::SScoreBox = 0;//スコア箱(スピン
int CBallPlayer::MScoreBox = 0;//スコア箱(移動
int CBallPlayer::CScoreBox = 0;//スコア箱(色

//int CBallPlayer::RCount = 0;//赤ブロックHP
//int CBallPlayer::BCount = 0;//青ブロックHP
//int CBallPlayer::GCount = 0;//緑ブロックHP
//int CBallPlayer::YCount = 0;//黄ブロックHP

int CBallPlayer::FeverCount = 0;

extern std::shared_ptr<CTexture>TextureExp;

CVector CBallPlayer::jumpspeed = CVector(0.0, 0.0, 0.0);
CVector CBallPlayer::mAdjust = CVector(0.0, 0.0, 0.0);
CBallPlayer::CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:BallCol(this, CVector(), CVector(),
CVector(1.0,1.0,1.0), scale.mX){

	mpModel = model;
	
	mRotation = rotation;

	mPosition = position;

	mScale = scale;

	jumpspeed = CVector();

	BoundNum = 0.75;
	
	CBallPlayer::BallCol.mType = CCollider::ESPHERE;

	mTag = CCharacter::EBALL;

	BallHP = 5;

	GoF = false;

	ScoreMore = 1.0;

	ScoreBox = 0;

	mpthis = this;

	BALLtime = 3 * 60;

	FeverCount = 20;

	minusF = false;
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

					if (BoundNum < 3.0){

						Boundf = true;

						if (Boundf == true){
						
							BoundNum = BoundNum + 0.2;

							Boundf = false;
						}

					}

					else{

						BoundNum = BoundNum;

					}
					
					jumpspeed = mAdjust.Normalize()*BoundNum;

					ColF = false;

				}

				if (y->mpParent->mTag == CCharacter::EITEM){ 

					ScoreBox = CBallPlayer::ScoreBox + CItem::BMyScorePoint;

					FeverCount++;

				}
					//ScorePulsF = false;

				if (y->mpParent->mTag == CCharacter::ESPINITEM){

					ScoreBox = CBallPlayer::ScoreBox + CSpinItem::SMyScorePoint;

					FeverCount++;

				}

				if (y->mpParent->mTag == CCharacter::EMOVEITEM){

					ScoreBox = CBallPlayer::ScoreBox + CMoveItem::MMyScorePoint;

				}

				if (y->mpParent->mTag == CCharacter::ECOLOR){}

				if (y->mpParent->mTag == CCharacter::EMOVEBONUS){

					ScoreBox = ScoreBox + CBonus::BMyScorePoint;

					FeverCount + 2;

				}

				if (y->mpParent->mTag == CCharacter::EDELETE){

					mPosition.mY = 80.0;

					mPosition.mX = 0.0;

					jumpspeed = CVector(0.0,0.0,0.0);

					jumpF = false;

					BallHP = BallHP - 1;

					GoF = false;
				}

			}

		}

		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionSphereSphere(m, y, &mAdjust)){

				if (y->mpParent->mTag == CCharacter::EBOMB){

					new CEffect(y->mPosition*y->mMatrix*y->mpParent->mMatrix, 10.0f, 10.0f, TextureExp, 4, 4, 3);

					CExItem::ReBomF = false;
					minusF=true;
				}
			}
		}
		break;
	}
}

void CBallPlayer::Update(){

	BALLtime--;

	ColF = true;

	CBallPlayer::BScoreBox = CItem::BMyScorePoint;
	CBallPlayer::SScoreBox = CSpinItem::SMyScorePoint;
	CBallPlayer::MScoreBox = CMoveItem::MMyScorePoint;
	CBallPlayer::CScoreBox = CColorItem::CMyScorePoint;

	CBallPlayer::mAdjust = CVector(0.0, 0.0, 0.0);
	
	if (GoF == false){

		if (CBallPlayer::BallHP > 0){

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


	if (minusF == true){

		ScoreBox = ScoreBox - CExItem::BomCutScore;
		minusF = false;

	}


	mPosition = mPosition + mAdjust + jumpspeed;

	CCharacter::Update();


}

void CBallPlayer::TaskCollision(){

	BallCol.ChangePriority();

	CCollisionManager::Get()->Collision(&BallCol);


}
void CBallPlayer::Render(){

	CCharacter::Render();
}

