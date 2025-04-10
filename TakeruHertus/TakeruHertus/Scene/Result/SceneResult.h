#pragma once
#include "../Base/SceneBase.h"
class SceneResult : public SceneBase
{
public:
	SceneResult();
	~SceneResult() override;

	void Init() override;
	void Update() override;
	void Draw() override;
	void Final() override;
};

