#include "CRock.h"
//
#include "CItem.h"
CRock::CRock(CModel*model, CVector position, CVector rotation, CVector scale)
:mColBody(this, CVector(0.0f, 1.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f, 1.0f, 1.0f), 9.0f){

	//ƒ‚ƒfƒ‹AˆÊ’uA‰ñ“]AŠgk
	mpModel = model;

	mPosition = position;

	mRotation = rotation;

	mScale = scale;

}

//void Update(){
//
//	if (CItem::ItemCount > 3){
//
//	
//
//	}
//	
//}