#pragma once
/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include "MachineInterface.h"
#include "RoomTemperatureController.h"
#include "CommonEnums.h"

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/
class HeaterClass : public MIClass
{
private:
	RTController* rtControllerObject;

public:
	/* Delete object creation on heap */
	void* operator new (size_t) = delete;
	HeaterClass() = delete;

	HeaterClass(RTController* RealRtControllerObject):
		rtControllerObject(RealRtControllerObject)
	{
		cout << "HeaterClass default constructor" << endl;
		rtControllerObject->externalRequest_registerObservers(this);
	}
	~HeaterClass()
	{
		cout << "HeaterClass default destructor" << endl;
		rtControllerObject->externalRequest_deregisterObservers(this);
	}

	void notifyEvent(ROOM_TEMPERATURE_DEGREES_ENUM roomTemp) override
	{
		cout << "Heater triggered but not active" << endl;
		if (roomTemp == ROOM_TEMP_LOW)
		{
			cout << "Heater is active!" << endl;
		}
	}
};

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/