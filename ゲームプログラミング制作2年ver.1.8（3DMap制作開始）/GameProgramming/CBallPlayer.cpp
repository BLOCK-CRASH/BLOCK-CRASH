#include "CBallPlayer.h"
#include "CKey.h"

bool::CBallPlayer::ScorePulsF = true;

//bool::CBallPlayer::BF = false;//(ノーマル:trueで点数追加falseで無効
//bool::CBallPlayer::SF = false;//(スピン:trueで点数追加falseで無効
//bool::CBallPlayer::MF = false;//(移動:trueで点数追加falseで無効
bool::CBallPlayer::CF = false;//(色:trueで点数追加falseで無効
//bool::CBallPlayer::BMF = false;//(ボーナス:trueで点数追加falseで無効
//bool::CBallPlayer::BOF = false;//(ボム:trueで減点falseで無効

CCharacter *CBallPlayer::mpthis;
int CBallPlayer::BallHP;

float CBallPlayer::ScoreMore;//加算数字
int CBallPlayer::ScoreBox;//スコア箱
int CBallPlayer::BScoreBox; // スコア箱(ノーマル
int CBallPlayer::SScoreBox;//スコア箱(スピン
int CBallPlayer::MScoreBox;//スコア箱(移動
int CBallPlayer::CScoreBox;//スコア箱(色

int CBallPlayer::FeverCount;

CVector CBallPlayer::mAdjust;//法線ベクトル
CVector CBallPlayer::mVector;//内積

extern std::shared_ptr<CTexture>TextureExp;

CBallPlayer::CBallPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:BallCol(this, CVector(), CVector(),
CVector(1.0,1.0,1.0), scale.mX){

	mpModel = model;
	
	mRotation = rotation;

	mPosition = position;

	mScale = scale;

	//priority = 1;

	jumpspeed = CVector();

	BoundNum = CVector(NULL, NULL, NULL);
	
	CBallPlayer::BallCol.mType = CCollider::ESPHERE;

	mTag = CCharacter::EBALL;

	BallHP = 5;

	GoF = false;

	ScoreMore = 1.0;

	ScoreBox = 0;

	mpthis = this;

	//BALLtime = 180;

	FeverCount = 20;

	minusF = false;

	BallVec = NULL;

	mAdjust = CVector(NULL,NULL,NULL);//法線ベクトル

	mVector = CVector(NULL, NULL, NULL);//内積
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

				jumpF = false;

				if (ColF == true){

					if (BoundNum.mX < 3.0 || BoundNum.mY || 3.0 || BoundNum.mZ < 3.0){

						Boundf = true;

						if (Boundf == true){
						
							BoundNum.mX = BoundNum.mX + 0.00005;
							BoundNum.mY = BoundNum.mY + 0.00005;
							BoundNum.mZ = BoundNum.mZ + 0.00005;

							Boundf = false;
						}
					}
					else{
					//	BoundNum = BoundNum;
					}

					mVector = CVector((jumpspeed.mX * mAdjust.mX), (jumpspeed.mY * mAdjust.mY), (jumpspeed.mZ * mAdjust.mZ));

					jumpspeed = jumpspeed + (mVector * 2);

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
				if (y->mpParent->mTag == CCharacter::EMOVEBONUS){
					ScoreBox = ScoreBox + CBonus::BMyScorePoint;
					FeverCount + 2;
				}

				if (y->mpParent->mTag == CCharacter::EDELETE){

					mPosition = CVector(0.0, 80.0, 0.0);

					BoundNum = CVector(0.0, 0.75, 0.0);

					jumpspeed = CVector(0.0, 0.0, 0.0);

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

	//mVector = jumpspeed + mAdjust.Normalize() * 2;

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

				CBallPlayer::jumpF = true;
				if (jumpF == true){

					jumpspeed.mY += 2;

					jumpF = false;
				}

			}
		}
	}

	if (CBallPlayer::FeverCount > 19){

		if (CKey::Once('F')){

			CMoveItem::FeverF = true;

			CBallPlayer::FeverCount = 0;
		}

	}


	if (minusF == true){

		ScoreBox = ScoreBox - CExItem::BomCutScore;
		minusF = false;

	}


	mPosition = mPosition + jumpspeed;

	CCharacter::Update();


}

void CBallPlayer::TaskCollision(){

	BallCol.ChangePriority();

	CCollisionManager::Get()->Collision(&BallCol);


}
void CBallPlayer::Render(){

	CCharacter::Render();
}

