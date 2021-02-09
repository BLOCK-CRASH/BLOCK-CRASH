#include "BossItem.h"
CCharacter*C3DMoveItem::mpthis = 0;
CCharacter*C3DOrbitItem::mpthis = 0;
CCharacter*C3DShaveItem::mpthis = 0;

CModel C3DShaveItem::mRec;
CModel C3DShaveItem::mTri;
//CModel C3DShaveItem::mRec;
CModel C3DShaveItem::mPen;
CModel C3DShaveItem::mHex;
CModel C3DShaveItem::mHep;
CModel C3DShaveItem::mOct;
CModel C3DShaveItem::mNon;
//CModel C3DShaveItem::mDec;

int C3DShaveItem::TriHP;
int C3DShaveItem::RecHP;
int C3DShaveItem::PenHP;
int C3DShaveItem::HexHP;
int C3DShaveItem::HepHP;
int C3DShaveItem::OctHP;
int C3DShaveItem::NonHP;

bool C3DShaveItem::TriF;
bool C3DShaveItem::RecF;
bool C3DShaveItem::PenF;
bool C3DShaveItem::HexF;
bool C3DShaveItem::HepF;
bool C3DShaveItem::OctF;
bool C3DShaveItem::NonF;

bool C3DShaveItem::TR;
bool C3DShaveItem::RP;
bool C3DShaveItem::PH;
bool C3DShaveItem::HH;
bool C3DShaveItem::HO;
bool C3DShaveItem::ON;

bool C3DShaveItem::ModelChanF = false;

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

	BminusF = 0;

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

C3DShaveItem::C3DShaveItem(CModel*model, CVector position, CVector rotation, CVector scale)
:m3DShaveBody(0){

	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	m3DShaveBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		m3DShaveBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		//m3DShaveBody[i].ChangePriority();

	}

	TriHP = 2;
	RecHP = 2;
	PenHP = 30;
	HexHP = 35;
	HepHP = 40;
	OctHP = 50;

	TriF = false;//三角は初期にtrue
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

	ShaveMyScorePoint = 0;

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
/*----------------------------------------------------------------------------------------------------------------------------*/

void C3DShaveItem::Init(){

	mTri.Load("3Model.obj","3Model.mtl");
	mRec.Load("4Model.obj","4Model.mtl");
	mPen.Load("5Model.obj","5Model.mtl");
	mHex.Load("6Model.obj", "6Model.mtl");
	mHep.Load("7Model.obj", "7Model.mtl");
	mOct.Load("8Model.obj", "8Model.mtl");

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
						TriF = true;//モデルがmTriならTriF=true
					}

					if (C3DShaveItem::mpModel == &mRec){
						RecF = true;//モデルがmTriならTriF=true
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

	if (C3DShaveItem::TriF == true){
		C3DShaveItem::TriHP = C3DShaveItem::TriHP - 1;
		TriF = false;
	}
	if (C3DShaveItem::RecF == true){
		C3DShaveItem::RecHP = C3DShaveItem::RecHP - 1;
		RecF = false;
	}

	ChangeModel();

	CCharacter::Update();
}


void C3DShaveItem::ChangeModel(){

	if (TriHP < 0){
		TR = true;//モデルを変えるためのフラをtrueへ
	};

	if (RecHP < 0){
		RP = true;//モデルを変えるためのフラをtrueへ
	};

	//if (C3DShaveItem::TR == true){
	//	C3DShaveItem::mpModel == &mRec;
	//	TriF = false;//HP==0でそのフラグをfalseへ
	//	TR = false;
	//}

	//if (C3DShaveItem::RP == true){
	//	TR = false;
	//	C3DShaveItem::mpModel == &mPen;
	//}

	//if (C3DShaveItem::PH == true){
	//	RP = false;
	//	C3DShaveItem::mpModel == &mHex;
	//}

	//if (C3DShaveItem::HH == true){
	//	PH = false;
	//	C3DShaveItem::mpModel == &mHep;
	//}

	//if (C3DShaveItem::HO == true){
	//	HH = false;
	//	C3DShaveItem::mpModel == &mOct;
	//}

}
void C3DMoveItem::TaskCollision(){}
void C3DOrbitItem::TaskCollision(){}
void C3DShaveItem::TaskCollision(){

	for (int S = 0; S < mColSize; S++){

		m3DShaveBody[S].ChangePriority();

		CCollisionManager::Get()->Collision(&m3DShaveBody[S]);

	}

}
//mTri.Load("3Model.obj", "3Model.mtl");
//mRec.Load("4Model.obj", "4Model.mtl");
//mPen.Load("5Model.obj", "5Model.mtl");
//mHex.Load("6Model.obj", "6Model.mtl");
//mHep.Load("7Model.obj", "7Model.mtl");
//mOct.Load("8Model.obj", "8Model.mtl");
