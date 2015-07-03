#include "Device.h"


Device::Device()
{}

Device::~Device()
{}

Device::Device(bool Debug, int PinNumber, bool Digital, bool Input, int MinValue,  int MaxValue, int InitialValue, int StepValue, bool StepDirectionUp, int DelayToChange)
{
	SetupDevice(Debug, PinNumber, Digital, Input, MinValue, MaxValue, InitialValue, StepValue, StepDirectionUp, DelayToChange);
}
	
void Device::SetupDevice(bool Debug, int PinNumber, bool Digital, bool Input, int MinValue, int MaxValue, int InitialValue, int StepValue, bool StepDirectionUp, int DelayToChange)
{
	//Serial.println("Device Setup");
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

	//Setup PIN Mode
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
	if (debug)
	{
		Serial.println(millis());
		Serial.println(lastUpdated);
		Serial.println(lastUpdated + delayToChangeValue);
	}
	if ((lastUpdated + delayToChangeValue) <= millis())
	{
		if (debug)
			Serial.println("Time to update!");
		 
		 if (debug)
			 Serial.println("Update");
		return true;
	} else
	{
		if (debug)
			 Serial.println("NOT TIME TO UPDATE!");
		return false;
	}
	if (debug)
		Serial.println("-----------");
}

void Device::Update()
{
	if (debug)
	{
		 Serial.print("Current Value: ");
		Serial.println(currentValue);
		Serial.println("-----------");
	}
	if (TimeToUpdate())
	{
		//if (pinNumber = 8)
			//Serial.println("Time To update");
		lastUpdated = millis();
		currentValue = GetNextValue();

		WriteValue(currentValue);
		
	}

}

void Device::Update(int newValue)
{
	if (TimeToUpdate())
	{
		WriteValue(newValue);
		//lastUpdated = millis();
	}
}

void Device::WriteValue(int value)
{
	if (digital)
		digitalWrite(pinNumber,value);
	else
		analogWrite(pinNumber, value);
	//if (pinNumber = 8)
			//Serial.write("Written value %S\n", value);
}

int Device::GetNextValue()
{
	if (debug)
		Serial.println(currentValue);
	
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

	if (debug)
		Serial.println(currentValue);
	if (debug)
		Serial.println("-------------");
	return currentValue;
}

int Device::GetValue()
{
	int value;

	if (digital)
		value = digitalRead(pinNumber);
	else
		value = analogRead(pinNumber);
	
	if (debug)
	{
		Serial.print("GetValue : " );
		Serial.println(value);
	}

	return value;
}

