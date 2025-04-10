#pragma once
#include <DxLib.h>
#include <unordered_map>
#include <memory>
#include <string>
#include <vector>
#include <cassert>

/// <summary>
/// 基本コンポーネント
/// </summary>
class Component
{
public:
	virtual ~Component() = default;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Final() = 0;


};