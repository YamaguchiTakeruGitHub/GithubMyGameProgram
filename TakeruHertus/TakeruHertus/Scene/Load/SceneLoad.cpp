#include "SceneLoad.h"
#include "../Manager/SceneManager.h"

SceneLoad::SceneLoad()
	: m_nextScene()
	, m_timer(0)
{
}

SceneLoad::~SceneLoad()
{
}

void SceneLoad::Init()
{
	m_timer = 0;
}

void SceneLoad::Update()
{
	std::cout << "SceneLoad::Update called. Timer: " << m_timer << std::endl;
	m_timer++;

	if (m_timer >= 60)
	{
		std::cout << "SceneLoad: Timer reached 60. Changing scene to: "
			<< static_cast<int>(m_nextScene) << std::endl;
		SceneManager::GetInstance().ChangeScene(m_nextScene);
	}
}

void SceneLoad::Draw()
{
	std::cout << "SceneLoad" << std::endl;
}

void SceneLoad::Final()
{

}

void SceneLoad::SetNextScene(SceneType& _nextScene)
{
	std::cout << "SceneLoad::SetNextScene called. Next Scene: " << static_cast<int>(_nextScene) << std::endl;
	m_nextScene = _nextScene;
}
