#include "3DPlayer.h"
#include "CKey.h"

/*-------------------------------------------------------------------------------------------------------------------------------*/

#define MOUSE_S 10
///*-------------------------------------------------------------------------------------------------------------------------------*/
CCharacter *C3DPlayer::mpthis = 0;
//CCharacter *CBottomPlayer::mpthis = 0;
//#define G (9.8f/60.0f)  //重力加速度
//#define JUMPV0  (4.0f)  //ジャンプ初速
C3DPlayer::C3DPlayer(CModel*model, CVector position, CVector rotation, CVector scale)
:C3DPlayer()
{
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	//モデルの三角形の数分、コライダの配列を作成します
	mColBody = new CCollider[model->mTriangles.size()];
	for (int i = 0; i < model->mTriangles.size(); i++){
		//コライダを三角形コライダで設定していきます
		mColBody[i].SetTriangle(this,
			model->mTriangles[i].mV[0],
			model->mTriangles[i].mV[1],
			model->mTriangles[i].mV[2]);

		mColBody[i].ChangePriority();

	}

	mColsize = model->mTriangles.size();

	janpspead = 0;

	mpthis = this;

	mTag = CCharacter::EPLAYER;
}

//C3DCamera::C3DCamera(CModel*model, CVector position, CVector rotation, CVector scale)
//:C3DCamera()
//{
//	mpModel = model;
//	mPosition = position;
//	mRotation = rotation;
//	mScale = scale;
//	mpthis = this;
//
//}

/*-------------------------------------------------------------------------------------------------------------------------------*/

#define MOUSE_S 10
void C3DPlayer::Update(){

	mMouseCount = 0;

	++mMouseCount %= MOUSE_S;

	if (mMouseCount == 0){

		CInput::SetMousePos(mMouseX, mMouseY);

	}

	//座標取得

	int mx, my;

	float m(10.0);

	CInput::GetMousePos(&mx, &my);

	if (my < mMouseY){

		mRotation.mZ -= (mMouseY - my) / m;

	}

	if (mMouseY < my){

		mRotation.mZ -= (mMouseY - my) / m;

	}

	if (mx < mMouseX){

		mRotation.mY += (mMouseX - mx) / m;

	}

	if (mMouseX < mx){

		mRotation.mY += (mMouseX - mx) / m;

	}



	CCharacter::Update();
}

//void C3DCamera::Update(){
//
//	//static int mMouseCount = 0;
//	//++mMouseCount %= MOUSE_S;
//
//	//if (mMouseCount == 0){
//
//	//	CInput::SetMousePos(mMouseX, mMouseY);
//	//}
//	////座標取得
//	//int mx, my;
//	//float m(10.0);
//	//CInput::GetMousePos(&mx, &my);
//	//if (my < mMouseY){
//	//	mRotation.mX -= (mMouseY - my) / m;
//	//}
//	//if (mMouseY < my){
//	//	mRotation.mX -= (mMouseY - my) / m;
//	//}
//	//if (mx < mMouseX){
//	//	mRotation.mY += (mMouseX - mx) / m;
//	//}
//	//if (mMouseX < mx){
//	//	mRotation.mY += (mMouseX - mx) / m;
//	//}
//
//	CCharacter::Update();
//
//}
void C3DPlayer::TaskCollision(){

	for (int p = 0; p < mColsize; p++){

		mColBody[p].ChangePriority();

	}

}
//C3DCamera*C3DCamera::mpthis = 0;
//CCharacter *C3DBFPlayer::mpthis = 0;
//CCharacter *C3DRLPlayer::mpthis = 0;
//CCharacter *C3DTBPlayer::mpthis = 0;
//
////CCharacter *CBottomPlayer::mpthis = 0;
////#define G (9.8f/60.0f)  //重力加速度
////#define JUMPV0  (4.0f)  //ジャンプ初速
///*---------------------------------------------------------------------------------------*/
//C3DBFPlayer::C3DBFPlayer(CModel*model, CVector position, CVector rotation, CVector scale)//上下の板
//:C3DBFPlayer()
//{
//	mpModel = model;
//	mPosition = position;
//	mRotation = rotation;
//	mScale = scale;
//	//モデルの三角形の数分、コライダの配列を作成します
//	mColBody = new CCollider[model->mTriangles.size()];
//	for (int i = 0; i < model->mTriangles.size(); i++){
//		//コライダを三角形コライダで設定していきます
//		mColBody[i].SetTriangle(this,
//			model->mTriangles[i].mV[0],
//			model->mTriangles[i].mV[1],
//			model->mTriangles[i].mV[2]);
//
//		mColBody[i].ChangePriority();
//
//	}
//
//	mColsize = model->mTriangles.size();
//
//	mpthis = this;
//
//	mTag = CCharacter::EPLAYER;
//}
//
//C3DRLPlayer::C3DRLPlayer(CModel*model, CVector position, CVector rotation, CVector scale)//左右の板
//:C3DRLPlayer()
//{
//	mpModel = model;
//	mPosition = position;
//	mRotation = rotation;
//	mScale = scale;
//	//モデルの三角形の数分、コライダの配列を作成します
//	mColBody = new CCollider[model->mTriangles.size()];
//	for (int i = 0; i < model->mTriangles.size(); i++){
//		//コライダを三角形コライダで設定していきます
//		mColBody[i].SetTriangle(this,
//			model->mTriangles[i].mV[0],
//			model->mTriangles[i].mV[1],
//			model->mTriangles[i].mV[2]);
//
//		mColBody[i].ChangePriority();
//
//	}
//
//	mColsize = model->mTriangles.size();
//
//	mpthis = this;
//
//	mTag = CCharacter::EPLAYER;
//}
//
//C3DTBPlayer::C3DTBPlayer(CModel*model, CVector position, CVector rotation, CVector scale)//左右の板
//:C3DTBPlayer()
//{
//	mpModel = model;
//	mPosition = position;
//	mRotation = rotation;
//	mScale = scale;
//	//モデルの三角形の数分、コライダの配列を作成します
//	mColBody = new CCollider[model->mTriangles.size()];
//	for (int i = 0; i < model->mTriangles.size(); i++){
//		//コライダを三角形コライダで設定していきます
//		mColBody[i].SetTriangle(this,
//			model->mTriangles[i].mV[0],
//			model->mTriangles[i].mV[1],
//			model->mTriangles[i].mV[2]);
//
//		mColBody[i].ChangePriority();
//
//	}
//
//	mColsize = model->mTriangles.size();
//
//	mpthis = this;
//
//	mTag = CCharacter::EPLAYER;
//}
//
//void C3DBFPlayer::Update(){
//
//	static int mbfMouseCount = 0;
//	++mbfMouseCount %= MOUSE_S;
//
//	if (mbfMouseCount == 0){
//
//		CInput::SetMousePos(BFMouseX, BFMouseY);
//
//	}
//
//	//座標取得
//	int mx, my;
//
//	float BFm(10.0);
//
//	CInput::GetMousePos(&mx, &my);
//
//	if (my < BFMouseY){
//		mPosition.mY += (BFMouseY - my) / BFm;
//	}
//	if (mPosition.mY > 150){
//		mPosition.mY -= (BFMouseY - my) / BFm;
//	}
//
//
//	if (BFMouseY < my){
//		mPosition.mY += (BFMouseY - my) / BFm;
//	}
//	if (mPosition.mY <-150){
//		mPosition.mY -= (BFMouseY - my) / BFm;
//	}
//
//
//
//	if (mx < BFMouseX){
//		mPosition.mX -= (BFMouseX - mx) / BFm;
//	}
//	if (mPosition.mX > 130){
//		mPosition.mX += (BFMouseX - mx) / BFm;
//	}
//
//
//
//	if (BFMouseX < mx){
//		mPosition.mX -= (BFMouseX - mx) / BFm;
//	}
//	if (mPosition.mX < -130){
//		mPosition.mX += (BFMouseX - mx) / BFm;
//	}
//
//
//
//	CCharacter::Update();
//}
//
//void C3DRLPlayer::Update(){
//
//	static int mrlMouseCount = 0;
//	++mrlMouseCount %= MOUSE_S;
//
//	if (mrlMouseCount == 0){
//
//		CInput::GetMousePos(&RLMouseX, &RLMouseY);
//
//	}
//
//	//座標取得
//	int mx, my;
//
//	float RLm(10.0);
//
//	CInput::GetMousePos(&mx, &my);
//
//	if (my < RLMouseY){
//		mPosition.mY += (RLMouseY - my) / RLm;
//	}
//	if (mPosition.mY > 131){
//		mPosition.mY -= (RLMouseY - my) / RLm;
//	}
//
//
//	if (RLMouseY < my){
//		mPosition.mY += (RLMouseY - my) / RLm;
//	}
//	if (mPosition.mY <-151){
//		mPosition.mY -= (RLMouseY - my) / RLm;
//	}
//
//
//	if (mx < RLMouseX){
//		mPosition.mZ -= (RLMouseX - mx) / RLm;
//	}
//	if (mPosition.mZ > 100){
//		mPosition.mZ += (RLMouseX - mx) / RLm;
//	}
//
//
//
//	if (RLMouseX < mx){
//		mPosition.mZ -= (RLMouseX - mx) / RLm;
//	}
//	if (mPosition.mZ < -120){
//		mPosition.mZ += (RLMouseX - mx) / RLm;
//	}
//
//	CCharacter::Update();
//}
//
//void C3DTBPlayer::Update(){
//
//	static int mMouseCount = 0;
//	++mMouseCount %= MOUSE_S;
//
//	if (mMouseCount == 0){
//
//		CInput::GetMousePos(&TBMouseX, &TBMouseY);
//
//	}
//
//	//座標取得
//	int mx, my;
//
//	float TBm(10.0);
//
//	CInput::GetMousePos(&mx, &my);
//
//
//	if (my < TBMouseY){
//		mPosition.mZ += (TBMouseY - my) / TBm;
//	}
//	if (mPosition.mZ > 180){
//		mPosition.mZ -= (TBMouseY - my) / TBm;
//	}
//
//
//	if (TBMouseY < my){
//		mPosition.mZ += (TBMouseY - my) / TBm;
//	}
//	if (mPosition.mZ <-120){
//		mPosition.mZ -= (TBMouseY - my) / TBm;
//	}
//
//
//
//	if (mx < TBMouseX){
//		mPosition.mX -= (TBMouseX - mx) / TBm;
//	}
//	if (mPosition.mX > 130){
//		mPosition.mX += (TBMouseX - mx) / TBm;
//	}
//
//
//	if (TBMouseX < mx){
//		mPosition.mX -= (TBMouseX - mx) / TBm;
//	}
//	if (mPosition.mX < -130){
//		mPosition.mX += (TBMouseX - mx) / TBm;
//	}
//
//	CCharacter::Update();
//}
//
//#define MOUSE_S 3
//
////void C3DCamera::Update(){
////
////	static int mMouseCount = 0;
////	++mMouseCount %= MOUSE_S;
////
////	if (mMouseCount == 0){
////	
////		CInput::SetMousePos(mMouseX, mMouseY);
////	}
////	//座標取得
////	int mx, my;
////	float m(10.0);
////	CInput::GetMousePos(&mx, &my);
////	if (my < mMouseY){
////		mRotation.mX -= (mMouseY - my) / m;
////	}
////	if (mMouseY < my){
////		mRotation.mX -= (mMouseY - my) / m;
////	}
////	if (mx < mMouseX){
////		mRotation.mY += (mMouseX - mx) / m;
////	}
////	if (mMouseX < mx){
////		mRotation.mY += (mMouseX - mx) / m;
////	}
////
////	CCharacter::Update();
////
////}
//

/*---------------------------------------------------------------------------------------*/
//
//void C3DBFPlayer::TaskCollision(){
//
//	for (int p = 0; p < mColsize; p++){
//
//		mColBody[p].ChangePriority();
//
//	}
//
//}
//void C3DRLPlayer::TaskCollision(){
//
//	for (int p = 0; p < mColsize; p++){
//
//		mColBody[p].ChangePriority();
//
//	}
//
//}
//void C3DTBPlayer::TaskCollision(){
//
//	for (int p = 0; p < mColsize; p++){
//
//		mColBody[p].ChangePriority();
//
//	}
//
//}
