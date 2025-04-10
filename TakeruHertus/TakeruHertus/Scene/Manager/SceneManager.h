#pragma once
#include "../Base/SceneBase.h"

class SceneManager
{
private:
	//現在のシーン
	std::shared_ptr<SceneBase> m_currentScene;

	//ロードシーン
	std::shared_ptr<SceneBase> m_sceneLoad;
	
	/*各シーン*/
	std::shared_ptr<SceneBase> m_sceneTitle;
	std::shared_ptr<SceneBase> m_sceneGame;
	std::shared_ptr<SceneBase> m_sceneResult;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Update();
	void Draw();
	void Final();

	static SceneManager& GetInstance() { static SceneManager instance; return instance; }

	//MEMO：SceneManagerでfriend classでLoadSceneを指定してあげればLoadシーンでprivateも扱えるようになる

	/// <summary>
	/// そのままシーン遷移（LoadSceneで使用）
	/// </summary>
	/// <param name="_newScene"></param>
	void ChangeScene(SceneType _newScene);

	/// <summary>
	/// ロード経由でシーン遷移
	/// </summary>
	/// <param name="_nextScene"></param>
	void RequestSceneChange(SceneType _nextScene);

	

};

