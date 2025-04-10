#pragma once
#include "../Base/SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle();
	~SceneTitle() override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

