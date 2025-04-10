#pragma once
#include "../SceneType.h"
#include <DxLib.h>
#include <iostream>

class SceneBase
{
public:
	virtual ~SceneBase() {};

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Final() = 0;

};

