#pragma once
class Device
{
public:
	Device();
	~Device(void);
	void SetupDevice(int PinNumber, bool Digital, bool Input, int MinValue,  int MaxValue, int InitialValue, int StepValue, bool StepDirectionUp, int DelayToChange);
	void Update();
	void Update(int newValue);
	int GetValue();
	
private:
	int pinNumber;
	int lastUpdated;
	int maxValue;
	int minValue;
	int delayToChangeValue;
	int stepValue;
	bool stepDirectionUp;
	int currentValue;

	bool digital;
	bool input;
	bool TimeToUpdate();
	int getPinMode();
	void WriteValue(int value);
	int GetNextValue();
};

