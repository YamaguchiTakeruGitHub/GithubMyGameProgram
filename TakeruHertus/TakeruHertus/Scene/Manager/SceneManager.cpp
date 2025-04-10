#include "SceneManager.h"
#include "../SceneCommon.h"

SceneManager::SceneManager()
{
    std::cout << "SceneManager instance created. Address: " << this << std::endl;

	m_sceneTitle	 = std::make_shared<SceneTitle>();
	m_sceneGame		 = std::make_shared<SceneGame>();
	m_sceneResult	 = std::make_shared<SceneResult>();
	m_sceneLoad		 = std::make_shared<SceneLoad>();

	m_currentScene = m_sceneTitle;
}

SceneManager::~SceneManager()
{
	m_currentScene->Final();
}

void SceneManager::Init()
{
	m_currentScene->Init();
}

void SceneManager::Update()
{
    std::cout << "SceneManager::Update called. Current Scene Type: "
        << typeid(*m_currentScene).name()
        << ", Address: " << m_currentScene.get() << std::endl;
    m_currentScene->Update();
}


void SceneManager::Draw()
{
	m_currentScene->Draw();
}

void SceneManager::Final()
{
	m_currentScene->Final();
}

void SceneManager::ChangeScene(SceneType _newScene)
{
    std::cout << "Entering ChangeScene. New Scene: " << static_cast<int>(_newScene) << std::endl;

    try
    {
        std::cout << "SceneManager::ChangeScene called. New Scene: "
            << static_cast<int>(_newScene) << std::endl;

        m_currentScene->Final();
        std::cout << "Finalized current scene." << std::endl;

        switch (_newScene)
        {
        case SceneType::SceneTitle:
            m_currentScene = m_sceneTitle;
            break;
        case SceneType::SceneGame:
            m_currentScene = m_sceneGame;
            break;
        case SceneType::SceneResult:
            m_currentScene = m_sceneResult;
            break;
        case SceneType::SceneLoad:
            m_currentScene = m_sceneLoad;
            break;
        }

        std::cout << "Initializing new scene: " << static_cast<int>(_newScene) << std::endl;
        m_currentScene->Init();
        std::cout << "Current Scene after ChangeScene: "
            << typeid(*m_currentScene).name()
            << ", Address: " << m_currentScene.get() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception in ChangeScene: " << e.what() << std::endl;
    }
}

void SceneManager::RequestSceneChange(SceneType _nextScene)
{
    std::cout << "Requesting scene change to: " << static_cast<int>(_nextScene) << std::endl;
    auto loadScene = std::dynamic_pointer_cast<SceneLoad>(m_sceneLoad);
    if (loadScene)
    {
        loadScene->SetNextScene(_nextScene);
    }
	m_currentScene = m_sceneLoad;
    std::cout << "Current Scene after RequestSceneChange: "
        << typeid(*m_currentScene).name()
        << ", Address: " << m_currentScene.get() << std::endl;
    m_currentScene->Init();
}

