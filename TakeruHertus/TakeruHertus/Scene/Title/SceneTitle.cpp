#include "SceneTitle.h"
#include "../Manager/SceneManager.h"

SceneTitle::SceneTitle()
{
}

SceneTitle::~SceneTitle()
{
}

void SceneTitle::Init()
{
}

void SceneTitle::Update()
{
	if (CheckHitKey(KEY_INPUT_SPACE) != 0)
	{
		SceneManager::GetInstance().RequestSceneChange(SceneType::SceneGame);
	}
}

void SceneTitle::Draw()
{
	std::cout << "SceneTitle" << std::endl;
	DrawString(320, 240, "SceneTitle", GetColor(255, 255, 255), TRUE);
}

void SceneTitle::Final()
{
}
