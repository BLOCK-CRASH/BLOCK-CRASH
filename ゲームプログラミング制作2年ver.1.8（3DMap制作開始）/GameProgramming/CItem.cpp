#include "CItem.h"

CCharacter *CItem::mpthis = 0;
CCharacter *CMoveItem::mpthis = 0;
CCharacter*CSpinItem::mpthis = 0;
CCharacter*CBonus::mpthis = 0;
CCharacter*CExItem::mpthis = 0;
CCharacter*CDeleteBlock::mpthis = 0;


int CItem::BMyScorePoint = 0;
int CMoveItem::MMyScorePoint = 0;
int CSpinItem::SMyScorePoint = 0;
int CBonus::BMyScorePoint = 0;
int CExItem::BomCutScore = 0;
int CColorItem::CMyScorePoint = 0;

int CExItem::BomTime = 0;
float CExItem::BBoundNum = 0;

bool::CSpinItem::RebirthF = false;
bool::CMoveItem::RebirthF = false;
bool::CMoveItem::FeverF = false;

bool::CColorItem::ChangeF = false;

bool::CColorItem::RBF = false;
bool::CColorItem::BGF = false;
bool::CColorItem::GYF = false;
bool::CColorItem::YRF = false;

bool::CExItem::jumpBF = false;
bool::CExItem::ReBomF = true;//////////////リスポーンフラグtrueなら存在falseならリスポーン

CModel CColorItem::mRed;
CModel CColorItem::mBlue;
CModel CColorItem::mGreen;
CModel CColorItem::mYellow;
//CModel * CColorItem::mpModel;
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
	FeverTime = 5 * 60;

	mTag = CCharacter::EITEM;

	BminusF = 0;

	mpthis = this;

	MMyScorePoint = 100;
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

	BomTime = 60 * 60;
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

	RBF = false;
	BGF = false;
	GYF = false;
	YRF = false;

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

	//CCollisionManager::Get()->Remove(this);
	mpthis = 0;

}
CDeleteBlock::~CDeleteBlock(){

	if (mDelete)
		delete[]mDelete;

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

	//new CColorItem(&mRed, CVector(0.0f, -80.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f), CVector(11.0, 11.0, 11.0));

	//mNextColor = mRed, mBlue, mGreen, mYellow;
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

			if (CCollider::CollisionTriangleSphere(y, Bm, &mAdjust)){

				if (BomColF == true){

						mAdjust.mZ = NULL;

						if (BBoundNum < 0.75){
							BBoundNum += 0.02;
						}
						else{
							BBoundNum = BBoundNum;
						}
					
					BjumpSpeed = mAdjust.Normalize()*BBoundNum;

					BomColF = false;

				}

				if (y->mpParent->mTag == CCharacter::EDELETE){

					BomGoF = false;

					mPosition = CVector(100.0f, 100.0f, 0.0f);

					BomGoF = true;

				}

			}
		}

		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionSphereSphere(y, Bm, &mAdjust)){

				if (y->mpParent->mTag == CCharacter::EBALL){

					//mEnabled = false;
					ReBomF = false;
					ReBomF = true;
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

				ChangeF = true;

				if (ChangeF == true){

					if (CColorItem::mpModel == &mRed){

						RBF = true;

					}

					if (CColorItem::mpModel == &mBlue){

						BGF = true;

					}

					if (CColorItem::mpModel == &mGreen){

						GYF = true;

					}

					if (CColorItem::mpModel == &mYellow){

						YRF = true;

					}

					//ChangeF = false;

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

		BminusF = true;

		if (RebirthF == false){

			mPosition.mX += 2.1;

		}

		if (RebirthF == true){

			mPosition.mX -= 2.2;

		}

		if (mPosition.mX == 1000){

			mPosition.mX = -500;

			//mEnabled = false;
		}

	}

	if (FeverTime < 0){

		FeverF = false;

		if (FeverF == false){

			mEnabled = false;

		}

		else if (FeverF == true){}

		//CTaskManager::Get()->Delete();

	}

	CCharacter::Update();

}

void CSpinItem::Update(){

	SminusF = true;

	if (RebirthF == false){

		mRotation.mZ++;

	}
	
	if (RebirthF == true){

		mRotation.mZ--;

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

		BomTime + 4000;

		ReBomF = true;

	}

	mPosition = mPosition + mAdjust + BjumpSpeed;

	CCharacter::Update();
}

void CDeleteBlock::Update(){

	CCharacter::Update();

}

void CColorItem::ChangeColor(){
	

	CCharacter::Update();

}

void CColorItem::Update(){

	if (CColorItem::mpModel == &mRed){
		
		RCount + 1;
	
	}

	if (CColorItem::mpModel == &mBlue){

		BCount + 1;

	}

	if (CColorItem::mpModel == &mGreen){

		GCount + 1;

	}

	if (CColorItem::mpModel == &mYellow){

		YCount + 1;

	}

	if (YCount == 4){

		mEnabled = false;

		CMyScorePoint = 20000;

	}

	if (RCount == 4){

		mEnabled = false;

		CMyScorePoint = 9500;

	}
	if (BCount == 4){

		mEnabled = false;

		CMyScorePoint = 7000;

	}
	if (GCount == 4){

		mEnabled = false;

		CMyScorePoint = 6000;

	}

	CCharacter::Update();

}
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


