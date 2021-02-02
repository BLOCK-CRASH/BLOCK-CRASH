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

int C3DShaveItem::ShaveMyScorePoint;

C3DMoveItem::C3DMoveItem(CModel*model, CVector position, CVector rotation, CVector scale)
:m3DMItemBody(0)
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//���f���̎O�p�`�̐����A�R���C�_�̔z����쐬���܂�
	m3DMItemBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
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
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
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
		//�R���C�_���O�p�`�R���C�_�Őݒ肵�Ă����܂�
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

	TriF = true;//�O�p�͏�����true
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
					//if (RecF == true){
					//	RecHP = RecHP - 1;
					//}
					//if (PenF == true){
					//	PenHP = PenHP - 1;
					//}
					//if (HexF == true){
					//	HexHP = HexHP - 1;
					//}
					//if (HepF == true){
					//	HepHP = HepHP - 1;
					//}

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

	if (TriF == true){

		C3DShaveItem::mpModel==&mTri;

		if (TriHP < 0){//HP0�Ńt���O��false�ɕύX

			TriF = false;
			RecF= true;//���̃t���O��true�ɕύX
		}

	}

	if (RecF == true){

		C3DShaveItem::mpModel == &mRec;

		if (RecHP < 0){//HP0�Ńt���O��false�ɕύX

			RecF = false;
			PenF = true;//���̃t���O��true�ɕύX
		}

	}

	if (PenF == true){

		C3DShaveItem::mpModel == &mPen;

		if (PenHP < 0){//HP0�Ńt���O��false�ɕύX

			PenF = false;
			HexF = true;//���̃t���O��true�ɕύX
		}

	}

	if (HexF == true){

		C3DShaveItem::mpModel == &mHex;

		if (HexHP < 0){//HP0�Ńt���O��false�ɕύX

			HexF = false;
			HepF = true;//���̃t���O��true�ɕύX
		}

	}

	if (HepF == true){

		C3DShaveItem::mpModel == &mHep;

		if (HepHP < 0){//HP0�Ńt���O��false�ɕύX

			HepF = false;
			OctF = true;//���̃t���O��true�ɕύX
		}

	}
	
	if (OctF == true){

		C3DShaveItem::mpModel = &mOct;


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
