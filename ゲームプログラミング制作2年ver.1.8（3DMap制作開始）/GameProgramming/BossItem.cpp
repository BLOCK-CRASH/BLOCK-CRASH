#include "BossItem.h"
CCharacter*C3DMoveItem::mpthis = 0;
CCharacter*C3DOrbitItem::mpthis = 0;
CCharacter*C3DShaveItem::mpthis = 0;
CCharacter*C3DIncreaseItem::mpthis = 0;

CModel C3DShaveItem::mTri;
CModel C3DShaveItem::mRec;
CModel C3DShaveItem::mPen;
CModel C3DShaveItem::mHex;
CModel C3DShaveItem::mHep;
CModel C3DShaveItem::mOct;
CModel C3DShaveItem::mNon;

CModel C3DIncreaseItem::mIncreasebom;//増殖爆弾
CModel C3DIncreaseItem::mIncreasebox;//増殖箱
CModel C3DIncreaseItem::mIncreasesuperbom;//増殖強化爆弾
CModel C3DIncreaseItem::mIncreasemore;//増殖スコア×２箱

//int C3DShaveItem::TriHP;
//int C3DShaveItem::RecHP;
//int C3DShaveItem::PenHP;
//int C3DShaveItem::HexHP;
//int C3DShaveItem::HepHP;
//int C3DShaveItem::OctHP;
//int C3DShaveItem::NonHP;

int C3DShaveItem::HP;

int C3DIncreaseItem::randIncr;

//bool C3DShaveItem::TriF;
//bool C3DShaveItem::RecF;
//bool C3DShaveItem::PenF;
//bool C3DShaveItem::HexF;
//bool C3DShaveItem::HepF;
//bool C3DShaveItem::OctF;
//bool C3DShaveItem::NonF;

bool C3DShaveItem::TR;
bool C3DShaveItem::RP;
bool C3DShaveItem::PH;
bool C3DShaveItem::HH;
bool C3DShaveItem::HO;
bool C3DShaveItem::ON;
bool C3DShaveItem::ModelChanF = false;

bool C3DIncreaseItem::IncrF = false;

int C3DShaveItem::ShaveMyScorePoint;

C3DMoveItem::C3DMoveItem(CModel*model, CVector position, CVector rotation, CVector scale)
:m3DMItemBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//モデルの三角形の数分、コライダの配列を作成します
	m3DMItemBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		m3DMItemBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}
	mTag = CCharacter::EITEM;

	mpthis = this;

	mEnabled = true;

	MMyScorePoint = 100;
}

C3DOrbitItem::C3DOrbitItem(CModel*model, CVector position, CVector rotation, CVector scale)
:m3DSItemBody(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;

	m3DSItemBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		m3DSItemBody[i].SetTriangle(this,
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


#define MODELHP1 15
#define MODELHP2 20
#define MODELHP3 30
#define MODELHP4 35
#define MODELHP5 40
#define MODELHP6 55
#define DUMMY -100
C3DShaveItem::C3DShaveItem(CModel*model, CVector position, CVector rotation, CVector scale)
:m3DShaveBody(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	HP = MODELHP1;
	mColSize = model->mTriangles.size();
	m3DShaveBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		m3DShaveBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		//m3DShaveBody[i].ChangePriority();

	}

	HP = MODELHP1;

	//TriHP = MODELHP1;
	//RecHP = MODELHP2;
	//PenHP = MODELHP2;
	//HexHP = MODELHP3;
	//HepHP = MODELHP3;
	//OctHP = MODELHP3;

	TriF = false;

	TR = false;
	RP = false;
	PH = false;
	HH = false;
	HO = false;

	mTag = CCharacter::ESHAVEITEM;

	mpthis = this;

	mEnabled = true;

	ShaveMyScorePoint = NULL;

}

#define RANDINC 10
C3DIncreaseItem::C3DIncreaseItem(CModel*model, CVector position, CVector rotation, CVector scale)
:mIncrease(0)
{

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;

	mIncrease = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mIncrease[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

	}

	mColsize = model->mTriangles.size();

	mTag = CCharacter::EINCREASE;

	IncrF = false;

	randIncr = RANDINC;
}

/*----------------------------------------------------------------------------------------------------------------------------*/
C3DMoveItem::~C3DMoveItem(){

	if (m3DMItemBody)
		delete[]m3DMItemBody;

}
C3DOrbitItem::~C3DOrbitItem(){

	if (m3DSItemBody)
		delete[]m3DSItemBody;

}

C3DShaveItem::~C3DShaveItem(){

	if (m3DShaveBody)
		delete[]m3DShaveBody;

}

C3DIncreaseItem::~C3DIncreaseItem(){

	if (mIncrease)
		delete[]mIncrease;

}
/*----------------------------------------------------------------------------------------------------------------------------*/

void C3DShaveItem::Init(){

	mTri.Load("3Model.obj", "3Model.mtl");
	mRec.Load("4Model.obj", "4Model.mtl");
	mPen.Load("5Model.obj", "5Model.mtl");
	mHex.Load("6Model.obj", "6Model.mtl");
	mHep.Load("7Model.obj", "7Model.mtl");
	mOct.Load("8Model.obj", "8Model.mtl");

	//C3DShaveItem::mTri.mMaterials[0].mDiffuse[3] = 0.5f;
	//C3DShaveItem::mRec.mMaterials[0].mDiffuse[3] = 0.5f;
	//C3DShaveItem::mPen.mMaterials[0].mDiffuse[3] = 0.5f;
	//C3DShaveItem::mHex.mMaterials[0].mDiffuse[3] = 0.5f;
	//C3DShaveItem::mHep.mMaterials[0].mDiffuse[3] = 0.5f;
	//C3DShaveItem::mOct.mMaterials[0].mDiffuse[3] = 0.5f;

}

void C3DIncreaseItem::Init(){

	mIncreasebox.Load("cube.obj", "cube.mtl");
	mIncreasebom.Load("Bomb.obj", "Bomb.mtl");
	mIncreasesuperbom.Load("RedBomb.obj", "RedBomb.mtl");
	mIncreasemore.Load("cube.obj", "cube.mtl");

}
/*----------------------------------------------------------------------------------------------------------------------------*/

void C3DOrbitItem::Collision(CCollider*sm, CCollider*y){}


void C3DShaveItem::Collision(CCollider*Sha, CCollider*y){

	switch (Sha->mType)
	{

	case CCollider::ETRIANGLE:

		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionTriangleSphere(Sha, y, &adjust)){

				if (y->mpParent->mTag == CCharacter::EBALL){
					HP = HP - 1;
				}

			}
		}
		break;
	}
}

void C3DIncreaseItem::Collision(CCollider*Inc, CCollider*y){

	switch (Inc->mType)
	{

	case CCollider::ETRIANGLE:

		if (y->mType == CCollider::ESPHERE){

			if (CCollider::CollisionTriangleSphere(Inc, y, &adjust)){

				if (y->mpParent->mpParent->mTag == CCharacter::EBALL){

					IncrF = true;

				}

			}
		}
		break;
	}


}
/*----------------------------------------------------------------------------------------------------------------------------*/

void C3DMoveItem::Update(){}
void C3DOrbitItem::Update(){}
void C3DShaveItem::Update(){

	if (C3DShaveItem::mpModel == &mTri){
		if (HP == 0){
			TR = true;
		}
	}
	if (C3DShaveItem::mpModel == &mRec){
		if (HP == 0){
			RP = true;
		}
	}
	if (C3DShaveItem::mpModel == &mPen){
		if (HP == 0){
			PH = true;
		}
	}
	if (C3DShaveItem::mpModel == &mHex){
		if (HP == 0){
			HH = true;
		}
	}
	if (C3DShaveItem::mpModel == &mHep){
		if (HP == 0){
			HO = true;
		}
	}

	if (TR == true){
		mEnabled = false;
		new C3DShaveItem(&mRec, CVector(), CVector(), CVector(8.0, 8.0, 8.0));
		HP = MODELHP2;
		TR = false;
	}
	if (RP == true){
		mEnabled = false;
		new C3DShaveItem(&mPen, CVector(), CVector(), CVector(7.0, 7.0, 7.0));
		HP = MODELHP3;
		RP = false;
	}
	if (PH == true){
		mEnabled = false;
		new C3DShaveItem(&mHex, CVector(), CVector(), CVector(35.0, 35.0, 35.0));
		HP = MODELHP4;
		PH = false;
	}
	if (HH == true){
		mEnabled = false;
		new C3DShaveItem(&mHep, CVector(0.0, 0.0, 0.0), CVector(), CVector(13.0, 13.0, 13.0));
		HP = MODELHP5;
		HH = false;
	}
	if (HO == true){
		mEnabled = false;
		new C3DShaveItem(&mOct, CVector(), CVector(), CVector(15.0, 15.0, 15.0));
		HP = MODELHP6;
		HO = false;
	}


	CCharacter::Update();
}
void C3DIncreaseItem::Update(){

	IncrF = false;

	if (IncrF == true){
		Increaserand();
	}

	CCharacter::Update();
}


void C3DShaveItem::ChangeModel(){}

void C3DIncreaseItem::Increaserand(){

	rand() % randIncr;

}

void C3DMoveItem::TaskCollision(){}
void C3DOrbitItem::TaskCollision(){}
void C3DShaveItem::TaskCollision(){

	for (int S = 0; S < mColSize; S++){
		m3DShaveBody[S].ChangePriority();
		//CCollisionManager::Get()->Collision(&m3DShaveBody[S]);
	}
}

void C3DIncreaseItem::TaskCollision(){

	for (int I = 0; I < mColsize; I++){
		mIncrease[I].ChangePriority();
		CCollisionManager::Get()->Collision(&mIncrease[I]);
	}
}
//mTri.Load("3Model.obj", "3Model.mtl");
//mRec.Load("4Model.obj", "4Model.mtl");
//mPen.Load("5Model.obj", "5Model.mtl");
//mHex.Load("6Model.obj", "6Model.mtl");
//mHep.Load("7Model.obj", "7Model.mtl");
//mOct.Load("8Model.obj", "8Model.mtl");
