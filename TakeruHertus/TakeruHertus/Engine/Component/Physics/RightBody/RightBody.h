#pragma once
#include "../Base/Component.h"

/// <summary>
/// 物理的特性を持つオブジェクト
/// </summary>
class RightBody : public Component
{
private:
	VECTOR m_direction;
	VECTOR m_velocity;
	
public:

	void Init() override {};
	void Update() override {};
	void Draw() override {};
	void Final() override {};

	
	//===============================================
	// セット・ゲット関数
	//===============================================

	void SetDirection(const VECTOR& _direction) { m_direction = _direction; }
	VECTOR GetDirection() const { return m_direction; }

	void SetVelocity(const VECTOR& _velocity) { m_velocity = _velocity; }
	VECTOR GetVelocity() const { return m_velocity; }

};

