#include "SceneGame.h"

SceneGame::SceneGame()
{
}

SceneGame::~SceneGame()
{

}

void SceneGame::Init()
{
}

void SceneGame::Update()
{
}

void SceneGame::Draw()
{
	
	std::cout << "SceneGame" << std::endl;
	DrawString(320, 240, "SceneGame", GetColor(255, 255, 255), TRUE);

}

void SceneGame::Final()
{
}
