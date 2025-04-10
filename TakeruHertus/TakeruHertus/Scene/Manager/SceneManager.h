#pragma once
#include "../Base/SceneBase.h"

class SceneManager
{
private:
	//���݂̃V�[��
	std::shared_ptr<SceneBase> m_currentScene;

	//���[�h�V�[��
	std::shared_ptr<SceneBase> m_sceneLoad;
	
	/*�e�V�[��*/
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

	//MEMO�FSceneManager��friend class��LoadScene���w�肵�Ă������Load�V�[����private��������悤�ɂȂ�

	/// <summary>
	/// ���̂܂܃V�[���J�ځiLoadScene�Ŏg�p�j
	/// </summary>
	/// <param name="_newScene"></param>
	void ChangeScene(SceneType _newScene);

	/// <summary>
	/// ���[�h�o�R�ŃV�[���J��
	/// </summary>
	/// <param name="_nextScene"></param>
	void RequestSceneChange(SceneType _nextScene);

	

};

