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
class CoolerClass : public MIClass
{
private:
	RTController* rtControllerObject;

public:
	/* Delete object creation on heap */
	void* operator new (size_t) = delete;
	CoolerClass() = delete;

	CoolerClass(RTController* RealRtControllerObject):
		rtControllerObject(RealRtControllerObject)
	{
		cout << "CoolerClass default constructor" << endl;
		rtControllerObject->externalRequest_registerObservers(this);
	}
	~CoolerClass()
	{
		cout << "CoolerClass default destructor" << endl;
		rtControllerObject->externalRequest_deregisterObservers(this);
	}

	void notifyEvent(ROOM_TEMPERATURE_DEGREES_ENUM roomTemp) override
	{
		cout << "Cooler triggered but not active" << endl;
		if (roomTemp == ROOM_TEMP_HELL)
		{
			cout << "Cooler is active!" << endl;
		}
	}
};
/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/