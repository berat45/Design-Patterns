#pragma once
/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include <list>
#include <iostream>
#include "CommonEnums.h"
#include "MachineInterface.h"
using namespace std;

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/
class RTController
{
public:
	/* Delete object creation on heap */
	void* operator new (size_t) = delete;

	RTController()
	{
		cout << "RTController Class default constructor" << endl;
	}
	~RTController()
	{
		cout << "RTController Class default destructor" << endl;
	}

	void setRoomTemperature();
	void triggerRoomTemperatureChange();
	void externalRequest_registerObservers(MIClass* observer);
	void externalRequest_deregisterObservers(MIClass* observer);
	void notifyObservers();

private:
	std::list<MIClass*> listOfObservers;
	ROOM_TEMPERATURE_DEGREES_ENUM roomTemperature;
	
};

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/