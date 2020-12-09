#ifndef CINPUT_H
#define CINPUT_H

#include "GLFW/glfw3.h"

class CInput{

	//�E�B���h�|�C���^
	static GLFWwindow*mpWindow;

public:

	static void Init(GLFWwindow*w);

	//���W�擾�i���オ0.0�j

	static void GetMousePos(int *px, int *py);

	/*
	�}�E�X�{�^���̏��
	GetMouseButton(�{�^��)
	�{�^��:
	GLFW_MOUSE_BUTTON_LEFT:���{�^��
	GLFW_MOUSE_BUTTON_RIGHT:�E�{�^��
	return:
	true:������Ă���
	false:������Ă��Ȃ�
	*/

	static bool GetMouseButton(int button);

	/*
	�}�E�X�J�[�\���̍��W��ݒ肷��
	SetCursorPos(X���W,Y���W)
	�f�B�X�v���C�̍��オ���_(0,0)
	*/
	static void SetMousePos(int x, int y);
};
#endif