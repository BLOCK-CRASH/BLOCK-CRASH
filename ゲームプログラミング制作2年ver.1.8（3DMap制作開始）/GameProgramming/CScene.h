#ifndef CSCENE_H
#define CSCENE_H

/*
�V�[���̊��N���X
*/
class CScene {
public:
	enum EScene
	{
		ETITEL,//�^�C�g��
		EMENU,//�Z���N�g
		EGAME1_WAVE1,//�X�e�[�W1�̃E�F�[�u1
		EGAME1_WAVE2,//�X�e�[�W1�̃E�F�[�u2
		EGAME1_WAVE3,//�X�e�[�W1�̃E�F�[�u3

		EGAME2_WAVE1,//�X�e�[�W2
		EGAME2_WAVE2,//�X�e�[�W2


		EGAME3,//�X�e�[�W3


		ESTAGE1_RESULT,//���U���g���

		ESTAGE2_RESULT,//���U���g���

		ESTAGE3_RESULT,//���U���g���



		ESTAY,//2D�������
		ESTAY3D,//3D�������
	};

	//�V�[���ϊ�

	EScene mScene;

	//virtual ���z�֐�
	//�|�����[�t�B�Y���̎���
	//=0 �������z�֐��̐ݒ�
	virtual void Init() = 0;	//�������z�֐� ����������
	virtual void Update() = 0; //�������z�֐� �X�V����
	//���̃V�[���̎擾
	virtual EScene GetNextScene() = 0;
	virtual ~CScene() {}	//�f�X�g���N�^�̒�`
	//2D�`��X�^�[�g
	//Start2D(�����W, �E���W, �����W, ����W)
	void Start2D(float left, float right, float bottom, float top);
	//2D�`��I��
	void End2D();
	//�J�����̐ݒ�
	//Camera3D(���_X���W, ���_Y���W, ���_Z���W, �����_X���W, �����_Y���W, �����_Z���W, �����X, �����Y, �����Z)
	void Camera3D(float ex, float ey, float ez, float cx, float cy, float cz, float ux, float uy, float uz);
};


#endif
