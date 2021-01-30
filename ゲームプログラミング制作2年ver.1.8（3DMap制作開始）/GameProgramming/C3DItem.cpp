#include "CItem.h"

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

		m3DShaveBody[1].ChangePriority();

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
	mRec.Load("4Model.obj","4Model.obj");
	mPen.Load("5Model.obj","5Model.mtl");
	mHex.Load("6Model.obj", "6Model.mtl");
	mHep.Load("7Model.obj", "7Model.mtl");
	mOct.Load("8Model.obj", "8Model.mtl");

	TriHP = 20;
	RecHP = 25;
	PenHP = 30;
	HexHP = 35;
	HepHP = 40;
	OctHP = 50;

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

			if (CCollider::CollisionTriangleSphere(Sha, y, &adjust)){
				if (y->mpParent->mTag == CCharacter::EBALL){
					
					if (TriF == true){
						TriHP = TriHP - 1;
					}
					if (RecF == true){
						RecHP = RecHP - 1;
					}
					if (PenF == true){
						PenHP = PenHP - 1;
					}
					if (HexF == true){
						HexHP = HexHP - 1;
					}
					if (HepF == true){
						HepHP = HepHP - 1;
					}

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

	if (TriHP < 0){
		C3DShaveItem::mpModel = &mRec;//TriHP0でモデル変更。
		RecF= true;
	}
	if (RecHP < 0){
		C3DShaveItem::mpModel = &mPen;//TriHP0でモデル変更。
		PenF = true;
	}
	if (PenHP < 0){
		C3DShaveItem::mpModel = &mHex;//TriHP0でモデル変更。
		HexF = true;
	}
	if (HexHP < 0){
		C3DShaveItem::mpModel = &mHep;//TriHP0でモデル変更。
		HepF = true;
	}
	if (HepHP < 0){
		C3DShaveItem::mpModel = &mOct;//TriHP0でモデル変更。
		OctF = true;
	}
	CCharacter::Update();
}

void C3DMoveItem::TaskCollision(){}
void C3DOrbitItem::TaskCollision(){}

void C3DShaveItem::TaskCollision(){

	for (int C = 0; C < mColSize; C++){

		m3DShaveBody[C].ChangePriority();

	}

}
