#include "DxLib.h"
#include "Scene/Manager/SceneManager.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
    AllocConsole();
    FILE* fp;
    freopen_s(&fp, "CONOUT$", "w", stdout);

    SetWindowText("Game");
   
    // 一部の関数はDxLib_Init()の前に実行する必要がある
    ChangeWindowMode(true);//true小さい表示//falseフルスクリーン

    if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
    {
        return -1;			// エラーが起きたら直ちに終了
    }

    SetDrawScreen(DX_SCREEN_BACK);

	SceneManager m_sceneManager;
    std::cout << "SceneManager instance in main: " << &m_sceneManager << std::endl;

    m_sceneManager.Init();

    // ゲームループ
    while (ProcessMessage() != -1)
    {
        // このフレームの開始時刻を覚えておく
        LONGLONG start = GetNowHiPerformanceCount();

        // 描画を行う前に画面をクリアする
        ClearDrawScreen();

        // ゲームの処理
        m_sceneManager.Update();
        m_sceneManager.Draw();

        // 画面が切り替わるのを待つ
        ScreenFlip();

        // escキーでゲーム終了
        if (CheckHitKey(KEY_INPUT_ESCAPE))
        {
            break;
        }

        // FPS60に固定する
        while (GetNowHiPerformanceCount() - start < 16667)
        {
            // 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
        }
    }

    m_sceneManager.Final();

    DxLib_End();				// ＤＸライブラリ使用の終了処理

    return 0;				// ソフトの終了 
}


//#include "DxLib.h"
//#include <cmath>
//#include <vector>
//#include <string>
//#include <memory>
//
//// 3Dベクトルクラス
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
//// コンポーネント基底クラス
//class Component {
//public:
//    virtual ~Component() {}
//    virtual void update(float deltaTime) {}
//};
//
//// トランスフォームコンポーネント
//class TransformComponent : public Component {
//public:
//    Vec3 position;
//    TransformComponent(const Vec3& pos = Vec3()) : position(pos) {}
//    void update(float deltaTime) override {}
//};
//
//// リジッドボディコンポーネント
//class RigidbodyComponent : public Component {
//public:
//    Vec3 velocity;
//    float mass;
//    RigidbodyComponent(float m = 1.0f) : mass(m), velocity(0, 0, 0) {}
//    void update(float deltaTime) override {
//        // 速度を位置に反映
//        velocity = velocity * 0.99f;  // 摩擦減衰
//    }
//};
//
//// コライダーコンポーネント
//class ColliderComponent : public Component {
//public:
//    float radius;
//    ColliderComponent(float r = 1.0f) : radius(r) {}
//};
//
//// プレイヤークラス
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
//        // プレイヤーの入力処理
//        if (CheckHitKey(KEY_INPUT_UP)) transform.position.z -= 0.1f;
//        if (CheckHitKey(KEY_INPUT_DOWN)) transform.position.z += 0.1f;
//        if (CheckHitKey(KEY_INPUT_LEFT)) transform.position.x -= 0.1f;
//        if (CheckHitKey(KEY_INPUT_RIGHT)) transform.position.x += 0.1f;
//
//        // 更新
//        transform.update(deltaTime);
//        rigidbody.update(deltaTime);
//    }
//
//    void draw() {
//        // プレイヤーを描画
//        DrawCircle((int)(transform.position.x * 50) + 320, (int)(transform.position.z * 50) + 240, (int)(collider.radius * 50), color, TRUE);
//    }
//};
//
//// 敵クラス
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
//        // 敵の自動的な動き（例：敵が左から右へ移動）
//        transform.position.x += 0.05f;
//
//        // 更新
//        transform.update(deltaTime);
//        rigidbody.update(deltaTime);
//    }
//
//    void draw() {
//        // 敵を描画
//        DrawCircle((int)(transform.position.x * 50) + 320, (int)(transform.position.z * 50) + 240, (int)(collider.radius * 50), color, TRUE);
//    }
//};
//
//// 衝突処理関数
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
//// プログラムは WinMain から始まります
//int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
//{
//    SetWindowText("HaneyAcception");
//   
//    // 一部の関数はDxLib_Init()の前に実行する必要がある
//    ChangeWindowMode(true);//true小さい表示//falseフルスクリーン
//
//    if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
//    {
//        return -1;			// エラーが起きたら直ちに終了
//    }
//
//    SetDrawScreen(DX_SCREEN_BACK);
//
//    Player player(Vec3(0, 0, 0));
//    Enemy enemy(Vec3(3, 0, 0));
//
//    // ゲームループ
//    while (ProcessMessage() != -1)
//    {
//        // このフレームの開始時刻を覚えておく
//        LONGLONG start = GetNowHiPerformanceCount();
//
//        // 描画を行う前に画面をクリアする
//        ClearDrawScreen();
//
//        // ゲームの処理
//        DrawFormatString(0, 0, GetColor(255, 255, 255), "Player: x=%.2f, z=%.2f", player.transform.position.x, player.transform.position.z);
//        DrawFormatString(0, 20, GetColor(255, 255, 255), "Enemy: x=%.2f, z=%.2f", enemy.transform.position.x, enemy.transform.position.z);
//
//        // 衝突判定
//        resolveCollision(player, enemy);
//
//        // 更新
//        player.update(start);
//        enemy.update(start);
//
//        // 描画
//        player.draw();
//        enemy.draw();
//
//        // 画面が切り替わるのを待つ
//        ScreenFlip();
//
//        // escキーでゲーム終了
//        if (CheckHitKey(KEY_INPUT_ESCAPE))
//        {
//            break;
//        }
//
//        // FPS60に固定する
//        while (GetNowHiPerformanceCount() - start < 16667)
//        {
//            // 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
//        }
//    }
//
//    DxLib_End();				// ＤＸライブラリ使用の終了処理
//
//    return 0;				// ソフトの終了 
//}



