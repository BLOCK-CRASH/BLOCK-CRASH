#ifndef CINPUT_H
#define CINPUT_H

#include "GLFW/glfw3.h"

class CInput{

	//ウィンドポインタ
	static GLFWwindow*mpWindow;

public:

	static void Init(GLFWwindow*w);

	//座標取得（左上が0.0）

	static void GetMousePos(int *px, int *py);

	/*
	マウスボタンの状態
	GetMouseButton(ボタン)
	ボタン:
	GLFW_MOUSE_BUTTON_LEFT:左ボタン
	GLFW_MOUSE_BUTTON_RIGHT:右ボタン
	return:
	true:押されている
	false:押されていない
	*/

	static bool GetMouseButton(int button);

	/*
	マウスカーソルの座標を設定する
	SetCursorPos(X座標,Y座標)
	ディスプレイの左上が原点(0,0)
	*/
	static void SetMousePos(int x, int y);
};
#endif