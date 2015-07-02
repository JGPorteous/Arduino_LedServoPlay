#include "Device.h"
#include "Arduino.h"


Device::Device()
{}

void Device::SetupDevice(int PinNumber, bool Digital, bool Input, int MinValue, int MaxValue, int InitialValue, int StepValue, bool StepDirectionUp, int DelayToChange)
{
	pinNumber = PinNumber;
	digital = Digital;
	input = Input;
	maxValue = MaxValue;
	minValue = MinValue;
	delayToChangeValue = DelayToChange;
	lastUpdated = millis();
	stepValue = StepValue;
	stepDirectionUp = StepDirectionUp;
	currentValue = InitialValue;

	pinMode(pinNumber,getPinMode());
}

int Device::getPinMode()
{
	//Get current pin mode INPUT or OUTPUT
	if (input)
		return INPUT;
	else
		return OUTPUT;
}


bool Device::TimeToUpdate()
{
	if (stepValue == 0)
		if ((lastUpdated + delayToChangeValue) <= millis())
		{
			lastUpdated = millis();
			return true;
		} else
		{
			return false;
		}
}

void Device::Update()
{
	if (TimeToUpdate())
	{
		currentValue = GetNextValue();

		WriteValue(currentValue);
	}

	lastUpdated = millis();
}

void Device::Update(int newValue)
{
	if (TimeToUpdate())
		WriteValue(newValue);

	lastUpdated = millis();
}

void Device::WriteValue(int value)
{
	if (digital)
		digitalWrite(pinNumber,value);
	else
		analogWrite(pinNumber, value);
}

int Device::GetNextValue()
{
	if (stepDirectionUp) //Increasing values
	{
		currentValue = currentValue + stepValue;

		if (currentValue >= maxValue)
		{
			currentValue = maxValue;
			stepDirectionUp = !stepDirectionUp; //Inverts Direction
		}
	} else {  //Decreasing values
		currentValue = currentValue - stepValue;

		if (currentValue <= minValue)
		{
			currentValue = minValue;
			stepDirectionUp = !stepDirectionUp; //Invers Direction
		}
	}

}

int Device::GetValue()
{
	if (digital)
		return digitalRead(pinNumber);
	else
		return analogRead(pinNumber);
}


