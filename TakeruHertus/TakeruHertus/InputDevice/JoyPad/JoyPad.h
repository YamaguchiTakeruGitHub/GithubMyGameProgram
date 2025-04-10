#pragma once
#include "../Base/InputDeviceBase.h"

class JoyPad : public InputDeviceBase
{
private:
	int padIndex;
	int currentState;
	int previousState;
	float axisX;
	float axisY;

public:
	JoyPad(int _index = 0);
	void Update() override;
	bool GetButton(int _button) const override;
	bool GetButtonDown(int _button) const override;
	bool GetButtonUp(int _button) const override;
	float GetAxisX() const override;
	float GetAxisY() const override;
};

