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
:m3DShaveBody(){

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

		m3DShaveBody[i].ChangePriority();

	}
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

	TriHP = 10;
	RecHP = 25;
	PenHP = 30;
	HexHP = 35;
	HepHP = 40;
	OctHP = 50;
	int u = 0;
	TriF = true;//三角は初期にtrue
	RecF = false;
	PenF = false;
	HexF = false;
	HepF = false;
	OctF = false;
}

/*----------------------------------------------------------------------------------------------------------------------------*/

void C3DOrbitItem::Collision(CCollider*sm, CCollider*y){}


void C3DShaveItem::Collision(CCollider*Sha, CCollider*y){

	switch (Sha->mType)
	{	
	case CCollider::ETRIANGLE:

		if (y->mType == CCollider::ESPHERE){
			
			if (y->mpParent->mTag == CCharacter::EBALL){

				u = 1;

			}
		
		}
		break;
	}

}
/*----------------------------------------------------------------------------------------------------------------------------*/

void C3DShaveItem::ChangeModel(){


	TriHP = TriHP - 1;
	ModelChanF = false;

	if (C3DShaveItem::TR == true){
		C3DShaveItem::mpModel == &mRec;
	}

	if (C3DShaveItem::RP == true){
		TR = false;
		C3DShaveItem::mpModel == &mPen;

	}

	if (C3DShaveItem::PH == true){
		RP = false;
		C3DShaveItem::mpModel == &mHex;
	}

	if (C3DShaveItem::HH == true){
		PH = false;
		C3DShaveItem::mpModel == &mHep;
	}

	if (C3DShaveItem::HO == true){
		HH = false;
		C3DShaveItem::mpModel == &mOct;
	}


	CCharacter::Update();

}


void C3DMoveItem::Update(){}
void C3DOrbitItem::Update(){}
void C3DShaveItem::Update(){


	if (ModelChanF == true){

		ChangeModel();

	}

	if (TriHP > 0){
		TriF = true;
	}
	if (TriHP < 0){
		TriF = false;
		TR = true;
	}
	/*---------------------------------------------*///
	if (RecHP > 0){
		RecF = true;
	}
	if (RecHP < 0){
		RecF = false;
		RP = true;
	}
	/*---------------------------------------------*///

	if (PenHP > 0){
		PenF = true;
	}

	//mTri.Load("3Model.obj", "3Model.mtl");
	//mRec.Load("4Model.obj", "4Model.mtl");
	//mPen.Load("5Model.obj", "5Model.mtl");
	//mHex.Load("6Model.obj", "6Model.mtl");
	//mHep.Load("7Model.obj", "7Model.mtl");
	//mOct.Load("8Model.obj", "8Model.mtl");

	mRotation.mX += 0.5;

	mRotation.mZ += 1.0;


	CCharacter::Update();
}

void C3DMoveItem::TaskCollision(){}
void C3DOrbitItem::TaskCollision(){}
void C3DShaveItem::TaskCollision(){

	for (int C = 0; C < mColSize; C++){

		m3DShaveBody[C].ChangePriority();

	}

}
