#include "DxLib.h"
#include "Scene/Manager/SceneManager.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    SetWindowText("Game");
   
    // �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
    ChangeWindowMode(true);//true�������\��//false�t���X�N���[��

    if (DxLib_Init() == -1)		// �c�w���C�u��������������
    {
        return -1;			// �G���[���N�����璼���ɏI��
    }

    SetDrawScreen(DX_SCREEN_BACK);

	SceneManager m_sceneManager;
    std::cout << "SceneManager instance in main: " << &m_sceneManager << std::endl;

    m_sceneManager.Init();

    // �Q�[�����[�v
    while (ProcessMessage() != -1)
    {
        // ���̃t���[���̊J�n�������o���Ă���
        LONGLONG start = GetNowHiPerformanceCount();

        // �`����s���O�ɉ�ʂ��N���A����
        ClearDrawScreen();

        // �Q�[���̏���
        m_sceneManager.Update();
        m_sceneManager.Draw();

        // ��ʂ��؂�ւ��̂�҂�
        ScreenFlip();

        // esc�L�[�ŃQ�[���I��
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        // FPS60�ɌŒ肷��
        while (GetNowHiPerformanceCount() - start < 16667)
        {
            // 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
        }
    }

    m_sceneManager.Final();

    DxLib_End();				// �c�w���C�u�����g�p�̏I������

    return 0;				// �\�t�g�̏I�� 
}


//#include "DxLib.h"
//#include <cmath>
//#include <vector>
//#include <string>
//#include <memory>
//
//// 3D�x�N�g���N���X
//struct Vec3 {
//    float x, y, z;
//    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}
//    Vec3 operator+(const Vec3& v) const { return Vec3(x + v.x, y + v.y, z + v.z); }
//    Vec3 operator-(const Vec3& v) const { return Vec3(x - v.x, y - v.y, z - v.z); }
//    Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }
//    float length() const { return std::sqrt(x * x + y * y + z * z); }
//    Vec3 normalize() const { float len = length(); return (len > 0) ? (*this * (1.0f / len)) : *this; }
//};
//
//// �R���|�[�l���g���N���X
//class Component {
//public:
//    virtual ~Component() {}
//    virtual void update(float deltaTime) {}
//};
//
//// �g�����X�t�H�[���R���|�[�l���g
//class TransformComponent : public Component {
//public:
//    Vec3 position;
//    TransformComponent(const Vec3& pos = Vec3()) : position(pos) {}
//    void update(float deltaTime) override {}
//};
//
//// ���W�b�h�{�f�B�R���|�[�l���g
//class RigidbodyComponent : public Component {
//public:
//    Vec3 velocity;
//    float mass;
//    RigidbodyComponent(float m = 1.0f) : mass(m), velocity(0, 0, 0) {}
//    void update(float deltaTime) override {
//        // ���x���ʒu�ɔ��f
//        velocity = velocity * 0.99f;  // ���C����
//    }
//};
//
//// �R���C�_�[�R���|�[�l���g
//class ColliderComponent : public Component {
//public:
//    float radius;
//    ColliderComponent(float r = 1.0f) : radius(r) {}
//};
//
//// �v���C���[�N���X
//class Player {
//public:
//    TransformComponent transform;
//    RigidbodyComponent rigidbody;
//    ColliderComponent collider;
//    int color;
//
//    Player(const Vec3& pos)
//        : transform(pos), rigidbody(1.0f), collider(1.0f), color(GetColor(0, 255, 0)) {
//    }
//
//    void update(float deltaTime) {
//        // �v���C���[�̓��͏���
//        if (CheckHitKey(KEY_INPUT_UP)) transform.position.z -= 0.1f;
//        if (CheckHitKey(KEY_INPUT_DOWN)) transform.position.z += 0.1f;
//        if (CheckHitKey(KEY_INPUT_LEFT)) transform.position.x -= 0.1f;
//        if (CheckHitKey(KEY_INPUT_RIGHT)) transform.position.x += 0.1f;
//
//        // �X�V
//        transform.update(deltaTime);
//        rigidbody.update(deltaTime);
//    }
//
//    void draw() {
//        // �v���C���[��`��
//        DrawCircle((int)(transform.position.x * 50) + 320, (int)(transform.position.z * 50) + 240, (int)(collider.radius * 50), color, TRUE);
//    }
//};
//
//// �G�N���X
//class Enemy {
//public:
//    TransformComponent transform;
//    RigidbodyComponent rigidbody;
//    ColliderComponent collider;
//    int color;
//
//    Enemy(const Vec3& pos)
//        : transform(pos), rigidbody(1.0f), collider(1.0f), color(GetColor(255, 0, 0)) {
//    }
//
//    void update(float deltaTime) {
//        // �G�̎����I�ȓ����i��F�G��������E�ֈړ��j
//        transform.position.x += 0.05f;
//
//        // �X�V
//        transform.update(deltaTime);
//        rigidbody.update(deltaTime);
//    }
//
//    void draw() {
//        // �G��`��
//        DrawCircle((int)(transform.position.x * 50) + 320, (int)(transform.position.z * 50) + 240, (int)(collider.radius * 50), color, TRUE);
//    }
//};
//
//// �Փˏ����֐�
//void resolveCollision(Player& player, Enemy& enemy) {
//    Vec3 diff = enemy.transform.position - player.transform.position;
//    float dist = diff.length();
//    float overlap = (player.collider.radius + enemy.collider.radius) - dist;
//
//    if (overlap > 0) {
//        Vec3 collisionNormal = diff.normalize();
//        Vec3 push = collisionNormal * (overlap / 2);
//        player.transform.position = player.transform.position - push;
//        enemy.transform.position = enemy.transform.position + push;
//    }
//}
//
//
//// �v���O������ WinMain ����n�܂�܂�
//int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
//{
//    SetWindowText("HaneyAcception");
//   
//    // �ꕔ�̊֐���DxLib_Init()�̑O�Ɏ��s����K�v������
//    ChangeWindowMode(true);//true�������\��//false�t���X�N���[��
//
//    if (DxLib_Init() == -1)		// �c�w���C�u��������������
//    {
//        return -1;			// �G���[���N�����璼���ɏI��
//    }
//
//    SetDrawScreen(DX_SCREEN_BACK);
//
//    Player player(Vec3(0, 0, 0));
//    Enemy enemy(Vec3(3, 0, 0));
//
//    // �Q�[�����[�v
//    while (ProcessMessage() != -1)
//    {
//        // ���̃t���[���̊J�n�������o���Ă���
//        LONGLONG start = GetNowHiPerformanceCount();
//
//        // �`����s���O�ɉ�ʂ��N���A����
//        ClearDrawScreen();
//
//        // �Q�[���̏���
//        DrawFormatString(0, 0, GetColor(255, 255, 255), "Player: x=%.2f, z=%.2f", player.transform.position.x, player.transform.position.z);
//        DrawFormatString(0, 20, GetColor(255, 255, 255), "Enemy: x=%.2f, z=%.2f", enemy.transform.position.x, enemy.transform.position.z);
//
//        // �Փ˔���
//        resolveCollision(player, enemy);
//
//        // �X�V
//        player.update(start);
//        enemy.update(start);
//
//        // �`��
//        player.draw();
//        enemy.draw();
//
//        // ��ʂ��؂�ւ��̂�҂�
//        ScreenFlip();
//
//        // esc�L�[�ŃQ�[���I��
//        if (CheckHitKey(KEY_INPUT_ESCAPE))
//        {
//            break;
//        }
//
//        // FPS60�ɌŒ肷��
//        while (GetNowHiPerformanceCount() - start < 16667)
//        {
//            // 16.66�~���b(16667�}�C�N���b)�o�߂���܂ő҂�
//        }
//    }
//
//    DxLib_End();				// �c�w���C�u�����g�p�̏I������
//
//    return 0;				// �\�t�g�̏I�� 
//}



