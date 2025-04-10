#pragma once
#include "../Base/SceneBase.h"

class SceneGame : public SceneBase
{
public:
	SceneGame();
	~SceneGame() override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

