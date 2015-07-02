#pragma once
#include "Arduino.h"

class Device
{
public:
	Device();
	Device(bool Debug, int PinNumber, bool Digital, bool Input, int MinValue,  int MaxValue, int InitialValue, int StepValue, bool StepDirectionUp, int DelayToChange);
	~Device(void);
	void SetupDevice(bool Debug, int PinNumber, bool Digital, bool Input, int MinValue,  int MaxValue, int InitialValue, int StepValue, bool StepDirectionUp, int DelayToChange);
	void Update();
	void Update(int newValue);
	int GetValue();
	void WriteValue(int value);

private:
	int pinNumber;
	int lastUpdated;
	int maxValue;
	int minValue;
	int delayToChangeValue;
	int stepValue;
	bool stepDirectionUp;
	int currentValue;
	bool debug;
	bool digital;
	bool input;

	bool TimeToUpdate();
	int getPinMode();

	int GetNextValue();
};

