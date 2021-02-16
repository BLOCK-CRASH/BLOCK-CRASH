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


#define MODELHP1 5
#define MODELHP2 10
#define MODELHP3 15
#define FALSETIME 1
#define DUMMY 100
C3DShaveItem::C3DShaveItem(CModel*model, CVector position, CVector rotation, CVector scale)
:m3DShaveBody(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
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

	TriHP = MODELHP1;
	RecHP = MODELHP2;
	PenHP = MODELHP2;
	HexHP = MODELHP3;
	HepHP = MODELHP3;
	OctHP = MODELHP3;

	falseTime = FALSETIME;

	TriF = false;
	RecF = false;
	PenF = false;
	HexF = false;
	HepF = false;
	OctF = false;

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

		//m3DShaveBody[i].ChangePriority();

	}

	mColsize = model->mTriangles.size();

	mTag = CCharacter::EINCREASE;

	IncrF = false;

	randIncr = 10;
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

	//mTri.Load("3Model.obj", "3Model.mtl");
	//mRec.Load("4Model.obj", "4Model.mtl");
	//mPen.Load("5Model.obj", "5Model.mtl");
	//mHex.Load("6Model.obj", "6Model.mtl");
	//mHep.Load("7Model.obj", "7Model.mtl");
	//mOct.Load("8Model.obj", "8Model.mtl");

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
					if (C3DShaveItem::mpModel == &mTri){
						TriHP = TriHP - 1;
					}
					if (C3DShaveItem::mpModel == &mRec){
						RecHP = RecHP - 1;
					}
					if (C3DShaveItem::mpModel == &mPen){
						PenHP = PenHP - 1;
					}
					if (C3DShaveItem::mpModel == &mHex){
						HexHP = HexHP - 1;
					}
					if (C3DShaveItem::mpModel == &mHep){
						HepHP = HepHP - 1;
					}
					if (C3DShaveItem::mpModel == &mOct){
						OctHP = OctHP - 1;
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

	//if (C3DShaveItem::TriF == true){
	//	C3DShaveItem::TriHP = C3DShaveItem::TriHP - 1;
	//	TriF = false;
	//}
	//if (C3DShaveItem::RecF == true){
	//	C3DShaveItem::RecHP = C3DShaveItem::RecHP - 1;
	//	RecF = false;
	//}
	//if (C3DShaveItem::PenF == true){
	//	C3DShaveItem::PenHP = C3DShaveItem::PenHP - 1;
	//	PenF = false;
	//}
	//if (C3DShaveItem::HexF == true){
	//	C3DShaveItem::HexHP = C3DShaveItem::HexHP - 1;
	//	HexF = false;
	//}
	//if (C3DShaveItem::HepF == true){
	//	C3DShaveItem::HepHP = C3DShaveItem::HepHP - 1;
	//	HepF = false;
	//}
	//if (C3DShaveItem::OctF == true){
	//	C3DShaveItem::OctHP = C3DShaveItem::OctHP - 1;
	//	OctF = false;
	//}

	ChangeModel();

	CCharacter::Update();
}
void C3DIncreaseItem::Update(){

	IncrF = false;

	if (IncrF == true){
		Increaserand();
	}

	CCharacter::Update();
}


void C3DShaveItem::ChangeModel(){

	if (TriHP < 0){
		falseTime--;
		TR = true;//モデルを変えるためのフラをtrueへ
		TriF = false;
	};
	if (C3DShaveItem::TR == true){
		mEnabled = false;
		if (falseTime == 0){
		new C3DShaveItem(&C3DShaveItem::mRec, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));
		TriHP = DUMMY;
		}
		TR = false;
	}

	if (RecHP < 0){
		falseTime = FALSETIME;
		falseTime--;
		RP = true;//モデルを変えるためのフラをtrueへ
		RecF = false;
	};
	if (C3DShaveItem::RP == true){
		mEnabled = false;
		if (falseTime == 0){
			new C3DShaveItem(&C3DShaveItem::mPen, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));
			RecHP = DUMMY;
		}
		RP = false;
	}




	if (HexHP < 0){
		PH = true;//モデルを変えるためのフラをtrueへ
		if (PenHP > 0){
			mpModel = &mHex;
		}

	};

	if (C3DShaveItem::PH == true){
		mEnabled = false;
		new C3DShaveItem(&C3DShaveItem::mHex, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));
		mEnabled = true;
		HexF = false;//HP==0でそのフラグをfalseへ
		PH = false;
	}

	if (HepHP < 0){
		HH = true;//モデルを変えるためのフラグをtrueへ
		if (HexHP > 0){
			mpModel = &mHep;
		}

	};

	if (C3DShaveItem::HH == true){
		mEnabled = false;
		new C3DShaveItem(&C3DShaveItem::mHep, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));
		mEnabled = true;
		HepF = false;//HP==0でそのフラグをfalseへ
		HH = false;
	}

	if (OctHP < 0){
		HO = true;//モデルを変えるためのフラをtrueへ
		if (HepHP > 0){
			mpModel = &mOct;
		}
	};

	if (C3DShaveItem::HO == true){
		mEnabled = false;
		new C3DShaveItem(&C3DShaveItem::mOct, CVector(0.0, 0.0, 0.0), CVector(), CVector(5.0, 5.0, 5.0));
		mEnabled = true;
		OctF = false;//HP==0でそのフラグをfalseへ
		HO = false;
	}


}

void C3DIncreaseItem::Increaserand(){

	rand() % randIncr;

}

void C3DMoveItem::TaskCollision(){}
void C3DOrbitItem::TaskCollision(){}
void C3DShaveItem::TaskCollision(){

	for (int S = 0; S < mColSize; S++){
		m3DShaveBody[S].ChangePriority();
		CCollisionManager::Get()->Collision(&m3DShaveBody[S]);
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
