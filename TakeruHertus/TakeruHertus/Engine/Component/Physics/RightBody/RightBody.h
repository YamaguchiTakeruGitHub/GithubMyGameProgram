#pragma once
#include "../Base/Component.h"

/// <summary>
/// �����I���������I�u�W�F�N�g
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
	// �Z�b�g�E�Q�b�g�֐�
	//===============================================

	void SetDirection(const VECTOR& _direction) { m_direction = _direction; }
	VECTOR GetDirection() const { return m_direction; }

	void SetVelocity(const VECTOR& _velocity) { m_velocity = _velocity; }
	VECTOR GetVelocity() const { return m_velocity; }

};

