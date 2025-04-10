#include "JoyPad.h"

void JoyPad::Update()
{
	previousState = currentState;
	currentState = GetJoypadInputState(padIndex);
}