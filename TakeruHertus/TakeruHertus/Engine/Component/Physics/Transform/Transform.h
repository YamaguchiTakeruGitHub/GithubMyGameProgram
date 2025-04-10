#pragma once
#include "../../Base/Component.h"

/// <summary>
/// 位置・回転・スケールを管理
/// </summary>
class Transform : public Component
{
private:
	VECTOR m_position;
	VECTOR m_rotation;
	VECTOR m_scale;

public:
	void Init() override {};
	void Update() override {};
	void Draw() override {};
	void Final() override {};

	//===============================================
	// セット・ゲット関数
	//===============================================

	void SetPosition(const VECTOR& _position) { m_position = _position; }
	VECTOR GetPosition() const { return m_position; }

	void SetRotation(const VECTOR& _rotation) { m_rotation = _rotation; }
	VECTOR GetRotation() const { return m_rotation; }

	void SetScale(const VECTOR& _scale) { m_scale = _scale; }
	VECTOR GetScale() const { return m_scale; }

};

