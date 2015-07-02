#include "Device.h"

//Declare devices
Device ledBlue9(false, 9,false,false,0,255,0,20,true,200);
Device ledBlue6(false, 6,false,false,0,255,0,5,true,10);

Device ledMulti10(false, 10,false,false,0,255,0,20,true,200);
Device ledMulti11(false, 11,false,false,0,255,0,50,true,100);

//Device potInput(true,7,false,false,0,0,0,0,false,0);
//Device ledPotBased3(false,3,false,false,0,0,0,0,false,0);


void setup()
{
	Serial.begin(115200);
}

void loop()
{

  /* add main program code here */
	ledBlue9.Update();
	ledBlue6.Update();

	//ledMulti11.WriteValue(potInput.GetValue());
}
