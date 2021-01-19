#include "CItem.h"

CCharacter*C3DMoveItem::mpthis = 0;
CCharacter*C3DOrbitItem::mpthis = 0;

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
/*----------------------------------------------------------------------------------------------------------------------------*/
C3DMoveItem::~C3DMoveItem(){

	if (m3DMItemBody)
		delete[]m3DMItemBody;

}
C3DOrbitItem::~C3DOrbitItem(){

	if (m3DSItemBody)
		delete[]m3DSItemBody;

}
/*----------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------------------------*/

void C3DMoveItem::Update(){}
void C3DOrbitItem::Update(){}

void C3DMoveItem::TaskCollision(){}
void C3DOrbitItem::TaskCollision(){}

void C3DOrbitItem::Collision(CCollider*sm, CCollider*y){}
