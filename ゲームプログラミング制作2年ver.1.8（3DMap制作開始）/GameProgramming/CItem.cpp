#include "CItem.h"

CCharacter *CItem::mpthis = 0;
CCharacter *CMoveItem::mpthis = 0;
CCharacter*CSpinItem::mpthis = 0;
CCharacter*CBonus::mpthis = 0;
CCharacter*CExItem::mpthis = 0;
CCharacter*CSuperExItem::mpthis = 0;
CCharacter*CDeleteBlock::mpthis = 0;
CCharacter*CResBlock::mpthis = 0;

int CItem::BMyScorePoint = 0;
int CMoveItem::MMyScorePoint = 0;
int CSpinItem::SMyScorePoint = 0;
int CBonus::BMyScorePoint = 0;
int CExItem::BomCutScore = 0;
int CSuperExItem::SBomCutScore = 0;
int CColorItem::CMyScorePoint = 0;

int CColorItem::YScore = 0;
int CColorItem::RScore = 0;
int CColorItem::BScore = 0;
int CColorItem::GScore = 0;

float CColorItem::RCount = 0;
float CColorItem::BCount = 0;
float CColorItem::GCount = 0;
float CColorItem::YCount = 0;

int CExItem::BomTime = 0;
float CExItem::BBoundNum = 0;

int CSuperExItem::SBomTime = 0;
float CSuperExItem::SBBoundNum = 0;

bool::CSpinItem::RebirthF = false;
bool::CMoveItem::RebirthF = false;
bool::CMoveItem::FeverF = false;

bool::CColorItem::ChangeF = false;

bool::CColorItem::RBF = false;
bool::CColorItem::BGF = false;
bool::CColorItem::GYF = false;
bool::CColorItem::YRF = false;
bool::CColorItem::ScorePulsF = false;

bool::CColorItem::RedAttensionF = false;
bool::CColorItem::BuleAttensionF = false;
bool::CColorItem::GreenAttensionF = false;
bool::CColorItem::YellowAttensionF = false;

bool::CExItem::jumpBF = false;
bool::CExItem::ReBomF = true;//////////////リスポーンフラグtrueなら存在falseならリスポーン

bool::CSuperExItem::jumpSBF = false;
bool::CSuperExItem::ReSBomF = true;//////////////リスポーンフラグtrueなら存在falseならリスポーン

CModel CColorItem::mRed;
CModel CColorItem::mBlue;
CModel CColorItem::mGreen;
CModel CColorItem::mYellow;

CVector CExItem::mAdjust = CVector(0.0, 0.0, 0.0);
CVector CSuperExItem::mAdjust = CVector(0.0, 0.0, 0.0);

/*--------------------------------------------------------*/
CItem::CItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mItemBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//モデルの三角形の数分、コライダの配列を作成します
	mItemBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mItemBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}
	mTag = CCharacter::EITEM;

	BminusF = false;

	mpthis = this; 

	mEnabled = true;

	BDamageCount = 6;

	DefeatBonus = 500;

	BMyScorePoint = 120;
}

CMoveItem::CMoveItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mMItemBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//モデルの三角形の数分、コライダの配列を作成します
	mMItemBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mMItemBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}
	FeverTime = 20 * 60;

	mTag = CCharacter::EITEM;

	BminusF = 0;

	mpthis = this;

	MMyScorePoint = 200;
}

CSpinItem::CSpinItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mSItemBody(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;

	mSItemBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mSItemBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}
	mTag = CCharacter::ESPINITEM;

	SminusF = false;

	mpthis = this;

	mEnabled = true;

	//SDamageCount = 10;

	SMyScorePoint = 80;
}

CBonus::CBonus(CModel*model, CVector position, CVector rotation, CVector scale)
:mBoBody(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = CVector(3.0, 3.0, 5.0);

	mBoBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){

		mBoBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);
	}
	mTag = CCharacter::EMOVEBONUS;

	//MStageCount += 1;

	MminusF = false;

	mpthis = this;

	mEnabled = true;

	MDamageCount = 1;

	BMyScorePoint = 500;

	MoveTime = 60 * 60;
}

CExItem::CExItem(CModel*model, CVector position, CVector rotation, CVector scale)
:BomCol(this, CVector(), CVector(),
CVector(1.0,1.0,1.0), scale.mX){

	mpModel = model;

	mRotation = rotation;

	mPosition = position;

	mScale = scale;

	BjumpSpeed = CVector();
	
	BBoundNum = 0.75;

	CExItem::BomCol.mType = CCollider::ESPHERE;

	mTag = CCharacter::EBOMB;

	BomGoF = true;

	BomColF = false;

	jumpBF = false;

	mpthis = this;

	BomCutScore = 500;

	BomTime = 90 * 60;
}

CSuperExItem::CSuperExItem(CModel*model, CVector position, CVector rotation, CVector scale)
:SBomCol(this, CVector(), CVector(),
CVector(1.0, 1.0, 1.0), scale.mX){

	mpModel = model;

	mRotation = rotation;

	mPosition = position;

	mScale = scale;

	SBjumpSpeed = CVector();

	SBBoundNum = 0.75;

	CSuperExItem::SBomCol.mType = CCollider::ESPHERE;

	mTag = CCharacter::EHIGHBOM;

	SBomGoF = true;

	SBomColF = false;

	jumpSBF = false;

	mpthis = this;

	SBomCutScore = 500;

	SBomTime = 90 * 60;
}

CDeleteBlock::CDeleteBlock(CModel*model, CVector position, CVector rotation, CVector scale)
:mDelete(){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale/*CVector(10.0, 10.0, 10.0);*/;
	//モデルの三角形の数分、コライダの配列を作成します
	mDelete = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mDelete[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}

	mTag = CCharacter::EDELETE;

	mpthis = this;

}

CResBlock::CResBlock(CModel*model, CVector position, CVector rotation, CVector scale)
:mResp(){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale/*CVector(10.0, 10.0, 10.0);*/;
	//モデルの三角形の数分、コライダの配列を作成します
	mResp = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mResp[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}

	mTag = CCharacter::ERESDELETE;

	mpthis = this;

}

CColorItem::CColorItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mColorbody(){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale/*CVector(10.0, 10.0, 10.0);*/;
	//モデルの三角形の数分、コライダの配列を作成します
	mColorbody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mColorbody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}

	RBF = false;//赤から青へ変わるフラグ
	BGF = false;//青から緑へ変わるフラグ
	GYF = false;//緑から色へ変わるフラグ
	YRF = false;//黄色から赤へ変わるフラグ

	mTag = CCharacter::ECOLOR;

	CMyScorePoint = 0;

	ChangeF = false;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
CItem::~CItem(){

	if (mItemBody)
	delete[]mItemBody;

}
CMoveItem::~CMoveItem(){

	if (mMItemBody)
	delete[]mMItemBody;

}
CSpinItem::~CSpinItem(){

	if (mSItemBody)
	delete[]mSItemBody;

}
CBonus::~CBonus(){

	if (mBoBody)
	delete[]mBoBody;

}
CExItem::~CExItem(){

	mpthis = 0;

}
CSuperExItem::~CSuperExItem(){

	mpthis = 0;

}
CDeleteBlock::~CDeleteBlock(){

	if (mDelete)
		delete[]mDelete;

}
CResBlock::~CResBlock(){

	if (mResp)
		delete[]mResp;

}
CColorItem::~CColorItem(){

	if (mColorbody)
		delete[]mColorbody;


}

/*----------------------------------------------------------------------------------------------------------------------------*/
void CColorItem::Init(){

	mRed.Load("cube.obj", "Red.mtl");//赤
	mBlue.Load("cube.obj", "Blue.mtl");//青
	mGreen.Load("cube.obj", "Green.mtl");//緑
	mYellow.Load("cube.obj", "Yellow.mtl");//黄

	//mNextColor = mYellow;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

//衝突判定

void CSpinItem::Collision(CCollider*sm, CCollider*y){}

void CItem::Collision(CCollider*m, CCollider*y){

	switch (m->mType)
	{
	case CCollider::ETRIANGLE:

		if (y -> mType == CCollider::ESPHERE){

			if (CCollider::CollisionTriangleSphere(m, y, &aj)){

				BDamageCount--;

			}

		}
		break;

	}
}

void CExItem::Collision(CCollider*Bm, CCollider*y){

	switch (Bm->mType)
	{

	case CCollider::ESPHERE:

		if (y->mType == CCollider::ETRIANGLE){

			mRotation.mZ*-1;

			if (CCollider::CollisionTriangleSphere(y, Bm, &mAdjust)){

				if (BomColF == true){

						mAdjust.mZ = NULL;

						if (BBoundNum < 0.75){

							BBoundNum += 0.15;

						}

						else{

							BBoundNum = BBoundNum;

						}
					
					BjumpSpeed = mAdjust.Normalize()*BBoundNum;

					BomColF = false;

				}

				if (y->mpParent->mTag == CCharacter::EDELETE){

					BomGoF = false;

					mPosition = CVector(0.0f, 450.0f, 0.0f);

					BomGoF = true;

				}

				if (y->mpParent->mTag == CCharacter::ERESDELETE){

					BomGoF = false;

					mPosition = CVector(100.0f, 80.0f, 0.0f);

					BomGoF = true;


				}
			}
		}

		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionSphereSphere(y, Bm, &mAdjust)){

				if (y->mpParent->mTag == CCharacter::EBALL){

					ReBomF = false;
					ReBomF = true;

				}

			}
		}
		break;
	}
}

void CSuperExItem::Collision(CCollider*SBm, CCollider*y){

	switch (SBm->mType)
	{

	case CCollider::ESPHERE:

		if (y->mType == CCollider::ETRIANGLE){

			mRotation.mZ*-1;

			if (CCollider::CollisionTriangleSphere(y, SBm, &mAdjust)){

				if (SBomColF == true){

					mAdjust.mZ = NULL;

					if (SBBoundNum < 0.75){

						SBBoundNum += 0.15;

					}

					else{

						SBBoundNum = SBBoundNum;

					}

					SBjumpSpeed = mAdjust.Normalize()*SBBoundNum;

					SBomColF = false;

				}
				if (y->mpParent->mTag == CCharacter::EDELETE){

					SBomGoF = false;

					mPosition = CVector(0.0f, 450.0f, 0.0f);

					SBomGoF = true;

				}

				if (y->mpParent->mTag == CCharacter::ERESDELETE){

					SBomGoF = false;

					mPosition = CVector(-100.0f, 80.0f, 0.0f);

					SBomGoF = true;


				}
			}
		}

		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionSphereSphere(y, SBm, &mAdjust)){

				if (y->mpParent->mTag == CCharacter::EBALL){

					ReSBomF = false;
					ReSBomF = true;

				}

			}
		}
		break;
	}
}

void CColorItem::Collision(CCollider*Cm, CCollider*y){

	switch (Cm->mType)
	{
	case CCollider::ETRIANGLE:

		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionTriangleSphere(Cm, y, &aj)){

				if (y->mpParent->mTag == CCharacter::EBALL){
				
					ChangeF = true;

					if (ChangeF == true){

						if (CColorItem::mpModel == &mRed)//当たった時のmpModelが赤だった場合
						{
							RBF = true;

						}

						if (CColorItem::mpModel == &mBlue)//当たった時のmpModelが青だった場合
						{
							BGF = true;

						}

						if (CColorItem::mpModel == &mGreen)//当たった時のmpModelが緑だった場合
						{
							GYF = true;

						}

						if (CColorItem::mpModel == &mYellow){

							YRF = true;

						}

						CColorItem::ChangeColor();

					}

				}
			}
		}
		break;
	}

}

void CDeleteBlock::Collision(CCollider*Dm, CCollider*y){}
//更新処理
void CItem::Update(){

	if (CItem::BDamageCount < 1){

		mEnabled = false;

	}

	CCharacter::Update();

}

void CMoveItem::Update(){

	if (CMoveItem::FeverF == true){

		FeverTime--;

		if (FeverTime > 0){
		
			mPosition.mX += 2.3;

			mRotation.mZ += 0.25;
		}

	}

	if (FeverTime < 0){

		FeverF = false;

	}

	CCharacter::Update();

}

void CSpinItem::Update(){

	SminusF = true;

	if (RebirthF == false){

		mRotation.mZ += 1.3;

	}
	
	if (RebirthF == true){

		mRotation.mZ -= 1.3;

	}

	CCharacter::Update();

}

void CBonus::Update(){

	MminusF = true;

	if (CBonus::MoveTime > 0){
		
		MoveTime--;

	}

	if (CBonus::MoveTime <= 3000){

 		mPosition.mX -= 1.5;

	}

	if (CBonus::MoveTime <= 2280){
		
		mPosition.mX += 0;

	}
	if (CBonus::MoveTime <= 2000){

		mPosition.mX += 3;

	}
	CCharacter::Update();

}

void CExItem::Update(){

	mRotation.mZ += 0.7;

	if (BomGoF == true){

		BomTime--;

	}
	BomColF = true;

	CExItem::mAdjust = CVector(0.0, 0.0, 0.0);

	if (BomTime == 3000){
	
		CExItem::mPosition = mPosition + BjumpSpeed;

		CExItem::BjumpSpeed = CVector(0.0, -0.4, 0.0);

		CExItem::jumpBF = true;
	}

	if (jumpBF == true){

		mPosition = mPosition + BjumpSpeed;

	}

	if (ReBomF == false){

		mPosition = CVector(0.0f, 301.0f, 0.0f);

		ReBomF = true;

	}

	mPosition = mPosition + mAdjust + BjumpSpeed;

	CCharacter::Update();
}

void CSuperExItem::Update(){

	mRotation.mZ += 0.7;

	if (SBomGoF == true){

		SBomTime--;

	}
	SBomColF = true;

	CSuperExItem::mAdjust = CVector(0.0, 0.0, 0.0);

	if (SBomTime == 3000){

		CSuperExItem::mPosition = mPosition + SBjumpSpeed;

		CSuperExItem::SBjumpSpeed = CVector(0.0, -0.4, 0.0);

		CSuperExItem::jumpSBF = true;
	}

	if (jumpSBF == true){

		mPosition = mPosition + SBjumpSpeed;

	}

	if (ReSBomF == false){

		mPosition = CVector(0.0f, 301.0f, 0.0f);

		ReSBomF = true;

	}

	mPosition = mPosition + mAdjust + SBjumpSpeed;

	CCharacter::Update();
}

void CDeleteBlock::Update(){

	CCharacter::Update();

}

void CResBlock::Update(){

	CCharacter::Update();

}

void CColorItem::ChangeColor(){
	
	if (CColorItem::RBF == true){

		BCount = BCount - 1;
		RCount = RCount + 1;

		CColorItem::mpModel = &mBlue;
		CColorItem::RBF = false;
	}
	if (CColorItem::BGF == true){

		GCount = GCount - 1;
		BCount = BCount + 1;

		CColorItem::mpModel = &mGreen;
		CColorItem::BGF = false;
	}
	if (CColorItem::GYF == true){

		YCount = YCount - 1;
		GCount = GCount + 1;

		CColorItem::mpModel = &mYellow;
		CColorItem::GYF = false;
	}
	if (CColorItem::YRF == true){

		RCount = RCount - 1;
		YCount = YCount + 1;

		CColorItem::mpModel = &mRed;
		CColorItem::YRF = false;
	}


	CCharacter::Update();

}

void CColorItem::Update(){

	ScorePulsF = false;

	if (YCount == 0){

		YellowAttensionF = true;

		mEnabled = false;

	}
	if (RCount == 0){

		RedAttensionF = true;

		mEnabled = false;

	}
	if (BCount == 0){
		
		BuleAttensionF = true;

		mEnabled = false;

	}
	if (GCount == 0){

		GreenAttensionF = true;

		mEnabled = false;

	}


	//if (YCount == 0 || RCount == 0 || BCount == 0 || GCount == 0){

	//	ScorePulsF = false;

	//}

	CCharacter::Update();

}
/*------------------------------------------------------------*/
void CItem::TaskCollision(){

	//for (int i = 0; i < ARRAYSIZE(mItemBody); i++){

	mItemBody[0].ChangePriority();
	mItemBody[1].ChangePriority();
	mItemBody[2].ChangePriority();
	mItemBody[3].ChangePriority();
	mItemBody[4].ChangePriority();
	mItemBody[5].ChangePriority();
	mItemBody[6].ChangePriority();
	mItemBody[7].ChangePriority();
	mItemBody[8].ChangePriority();
	mItemBody[9].ChangePriority();
	mItemBody[10].ChangePriority();
	mItemBody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mItemBody[0]);
	CCollisionManager::Get()->Collision(&mItemBody[1]);
	CCollisionManager::Get()->Collision(&mItemBody[2]);
	CCollisionManager::Get()->Collision(&mItemBody[3]);
	CCollisionManager::Get()->Collision(&mItemBody[4]);
	CCollisionManager::Get()->Collision(&mItemBody[5]);
	CCollisionManager::Get()->Collision(&mItemBody[6]);
	CCollisionManager::Get()->Collision(&mItemBody[7]);
	CCollisionManager::Get()->Collision(&mItemBody[8]);
	CCollisionManager::Get()->Collision(&mItemBody[9]);
	CCollisionManager::Get()->Collision(&mItemBody[10]);
	CCollisionManager::Get()->Collision(&mItemBody[11]);

}

void CMoveItem::TaskCollision(){

	mMItemBody[0].ChangePriority();
	mMItemBody[1].ChangePriority();
	mMItemBody[2].ChangePriority();
	mMItemBody[3].ChangePriority();
	mMItemBody[4].ChangePriority();
	mMItemBody[5].ChangePriority();
	mMItemBody[6].ChangePriority();
	mMItemBody[7].ChangePriority();
	mMItemBody[8].ChangePriority();
	mMItemBody[9].ChangePriority();
	mMItemBody[10].ChangePriority();
	mMItemBody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mMItemBody[0]);
	CCollisionManager::Get()->Collision(&mMItemBody[1]);
	CCollisionManager::Get()->Collision(&mMItemBody[2]);
	CCollisionManager::Get()->Collision(&mMItemBody[3]);
	CCollisionManager::Get()->Collision(&mMItemBody[4]);
	CCollisionManager::Get()->Collision(&mMItemBody[5]);
	CCollisionManager::Get()->Collision(&mMItemBody[6]);
	CCollisionManager::Get()->Collision(&mMItemBody[7]);
	CCollisionManager::Get()->Collision(&mMItemBody[8]);
	CCollisionManager::Get()->Collision(&mMItemBody[9]);
	CCollisionManager::Get()->Collision(&mMItemBody[10]);
	CCollisionManager::Get()->Collision(&mMItemBody[11]);

}

void CSpinItem::TaskCollision(){

	mSItemBody[0].ChangePriority();
	mSItemBody[1].ChangePriority();
	mSItemBody[2].ChangePriority();
	mSItemBody[3].ChangePriority();
	mSItemBody[4].ChangePriority();
	mSItemBody[5].ChangePriority();
	mSItemBody[6].ChangePriority();
	mSItemBody[7].ChangePriority();
	mSItemBody[8].ChangePriority();
	mSItemBody[9].ChangePriority();
	mSItemBody[10].ChangePriority();
	mSItemBody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mSItemBody[0]);
	CCollisionManager::Get()->Collision(&mSItemBody[1]);
	CCollisionManager::Get()->Collision(&mSItemBody[2]);
	CCollisionManager::Get()->Collision(&mSItemBody[3]);
	CCollisionManager::Get()->Collision(&mSItemBody[4]);
	CCollisionManager::Get()->Collision(&mSItemBody[5]);
	CCollisionManager::Get()->Collision(&mSItemBody[6]);
	CCollisionManager::Get()->Collision(&mSItemBody[7]);
	CCollisionManager::Get()->Collision(&mSItemBody[8]);
	CCollisionManager::Get()->Collision(&mSItemBody[9]);
	CCollisionManager::Get()->Collision(&mSItemBody[10]);
	CCollisionManager::Get()->Collision(&mSItemBody[11]);

}

void CBonus::TaskCollision(){

	mBoBody[0].ChangePriority();
	mBoBody[1].ChangePriority();
	mBoBody[2].ChangePriority();
	mBoBody[3].ChangePriority();
	mBoBody[4].ChangePriority();
	mBoBody[5].ChangePriority();
	mBoBody[6].ChangePriority();
	mBoBody[7].ChangePriority();
	mBoBody[8].ChangePriority();
	mBoBody[9].ChangePriority();
	mBoBody[10].ChangePriority();
	mBoBody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mBoBody[0]);
	CCollisionManager::Get()->Collision(&mBoBody[1]);
	CCollisionManager::Get()->Collision(&mBoBody[2]);
	CCollisionManager::Get()->Collision(&mBoBody[3]);
	CCollisionManager::Get()->Collision(&mBoBody[4]);
	CCollisionManager::Get()->Collision(&mBoBody[5]);
	CCollisionManager::Get()->Collision(&mBoBody[6]);
	CCollisionManager::Get()->Collision(&mBoBody[7]);
	CCollisionManager::Get()->Collision(&mBoBody[8]);
	CCollisionManager::Get()->Collision(&mBoBody[9]);
	CCollisionManager::Get()->Collision(&mBoBody[10]);
	CCollisionManager::Get()->Collision(&mBoBody[11]);


}

void CDeleteBlock::TaskCollision(){

	mDelete[0].ChangePriority();
	mDelete[1].ChangePriority();
	mDelete[2].ChangePriority();
	mDelete[3].ChangePriority();
	mDelete[4].ChangePriority();
	mDelete[5].ChangePriority();
	mDelete[6].ChangePriority();
	mDelete[7].ChangePriority();
	mDelete[8].ChangePriority();
	mDelete[9].ChangePriority();
	mDelete[10].ChangePriority();
	mDelete[11].ChangePriority();
	
	CCollisionManager::Get()->Collision(&mDelete[0]);
	CCollisionManager::Get()->Collision(&mDelete[1]);
	CCollisionManager::Get()->Collision(&mDelete[2]);
	CCollisionManager::Get()->Collision(&mDelete[3]);
	CCollisionManager::Get()->Collision(&mDelete[4]);
	CCollisionManager::Get()->Collision(&mDelete[5]);
	CCollisionManager::Get()->Collision(&mDelete[6]);
	CCollisionManager::Get()->Collision(&mDelete[7]);
	CCollisionManager::Get()->Collision(&mDelete[8]);
	CCollisionManager::Get()->Collision(&mDelete[9]);
	CCollisionManager::Get()->Collision(&mDelete[10]);
	CCollisionManager::Get()->Collision(&mDelete[11]);

}

void CResBlock::TaskCollision(){

	mResp[0].ChangePriority();
	mResp[1].ChangePriority();
	mResp[2].ChangePriority();
	mResp[3].ChangePriority();
	mResp[4].ChangePriority();
	mResp[5].ChangePriority();
	mResp[6].ChangePriority();
	mResp[7].ChangePriority();
	mResp[8].ChangePriority();
	mResp[9].ChangePriority();
	mResp[10].ChangePriority();
	mResp[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mResp[0]);
	CCollisionManager::Get()->Collision(&mResp[1]);
	CCollisionManager::Get()->Collision(&mResp[2]);
	CCollisionManager::Get()->Collision(&mResp[3]);
	CCollisionManager::Get()->Collision(&mResp[4]);
	CCollisionManager::Get()->Collision(&mResp[5]);
	CCollisionManager::Get()->Collision(&mResp[6]);
	CCollisionManager::Get()->Collision(&mResp[7]);
	CCollisionManager::Get()->Collision(&mResp[8]);
	CCollisionManager::Get()->Collision(&mResp[9]);
	CCollisionManager::Get()->Collision(&mResp[10]);
	CCollisionManager::Get()->Collision(&mResp[11]);

}

void CColorItem::TaskCollision(){

	mColorbody[0].ChangePriority();
	mColorbody[1].ChangePriority();
	mColorbody[2].ChangePriority();
	mColorbody[3].ChangePriority();
	mColorbody[4].ChangePriority();
	mColorbody[5].ChangePriority();
	mColorbody[6].ChangePriority();
	mColorbody[7].ChangePriority();
	mColorbody[8].ChangePriority();
	mColorbody[9].ChangePriority();
	mColorbody[10].ChangePriority();
	mColorbody[11].ChangePriority();

	CCollisionManager::Get()->Collision(&mColorbody[0]);
	CCollisionManager::Get()->Collision(&mColorbody[1]);
	CCollisionManager::Get()->Collision(&mColorbody[2]);
	CCollisionManager::Get()->Collision(&mColorbody[3]);
	CCollisionManager::Get()->Collision(&mColorbody[4]);
	CCollisionManager::Get()->Collision(&mColorbody[5]);
	CCollisionManager::Get()->Collision(&mColorbody[6]);
	CCollisionManager::Get()->Collision(&mColorbody[7]);
	CCollisionManager::Get()->Collision(&mColorbody[8]);
	CCollisionManager::Get()->Collision(&mColorbody[9]);
	CCollisionManager::Get()->Collision(&mColorbody[10]);
	CCollisionManager::Get()->Collision(&mColorbody[11]);


}

void CExItem::TaskCollision(){

	BomCol.ChangePriority();

	CCollisionManager::Get()->Collision(&BomCol);

}
void CExItem::Render(){

	CCharacter::Render();

}


void CSuperExItem::TaskCollision(){

	SBomCol.ChangePriority();

	CCollisionManager::Get()->Collision(&SBomCol);

}
void CSuperExItem::Render(){

	CCharacter::Render();

}

