#pragma once
#include "../Base/SceneBase.h"
#include "../SceneType.h"

class SceneLoad : public SceneBase
{
private:
	SceneType m_nextScene;
	int m_timer;

public:
	SceneLoad();
	~SceneLoad() override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;

	void SetNextScene(SceneType& _nextScene);
};

