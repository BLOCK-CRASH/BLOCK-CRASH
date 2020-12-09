#ifndef CROCK_H
#define CROCK_H

#include "CCharacter.h"
//
#include "CCollider.h"
//
#include "CItem.h"

class CRock :public CCharacter{
public:

	CRock(CModel*model,CVector position, CVector rotation, CVector scale);

	CCollider mColBody;

	//void Update();

};
#endif