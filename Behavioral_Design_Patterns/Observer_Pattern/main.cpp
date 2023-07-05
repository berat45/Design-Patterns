// DiveIntoDesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Cooler.h"
#include "Heater.h"
#include "MachineInterface.h"
#include "RoomTemperatureController.h"


int main()
{
	RTController main_RtControllerObject;
	/* Test scope declarations */
	{
		HeaterClass main_heaterClassObject(&main_RtControllerObject);
		CoolerClass main_coolerClassObject(&main_RtControllerObject);

		main_RtControllerObject.triggerRoomTemperatureChange();
		main_RtControllerObject.triggerRoomTemperatureChange();
		main_RtControllerObject.triggerRoomTemperatureChange();
		main_RtControllerObject.triggerRoomTemperatureChange();
	}


    return 0;
}

