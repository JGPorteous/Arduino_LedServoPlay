#include "Device.h"

//Declare Items
Device blueLed;

void setup()
{


  /* add setup code here */
	//Device blueLed(9,false,false,0,255,1,true,20);
	//Device blueLed(9,false,false,0,255,1,0,true,0);

	//Set Defaults
	blueLed.SetupDevice(9,false,false,0,255,0,20,true,200);
}

void loop()
{

  /* add main program code here */
	blueLed.Update();
}
