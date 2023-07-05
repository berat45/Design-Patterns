/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include "stdafx.h"
#include "RoomTemperatureController.h"

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/

/* Basic state machine logic to update room temperature when trigger event occurs */
void RTController::setRoomTemperature()
{
	switch (this->roomTemperature)
	{
		case ROOM_TEMP_LOW:
		{
			cout << "Room temperature is set from ROOM_TEMP_LOW to ROOM_TEMP_MEDIUM" << endl;
			this->roomTemperature = ROOM_TEMP_MEDIUM;
			notifyObservers();
			break;
		}
		case ROOM_TEMP_MEDIUM:
		{
			cout << "Room temperature is set from ROOM_TEMP_MEDIUM to ROOM_TEMP_HIGH" << endl;
			this->roomTemperature = ROOM_TEMP_HIGH;
			notifyObservers();
			break;
		}
		case ROOM_TEMP_HIGH:
		{
			cout << "Room temperature is set from ROOM_TEMP_HIGH to ROOM_TEMP_HELL" << endl;
			this->roomTemperature = ROOM_TEMP_HELL;
			notifyObservers();
			break;
		}
		case ROOM_TEMP_HELL:
		{
			cout << "Room temperature is set from ROOM_TEMP_HELL to ROOM_TEMP_LOW" << endl;
			this->roomTemperature = ROOM_TEMP_LOW;
			notifyObservers();
			break;
		}
		default:
		{
			cout << "Unknown temperature state, back to ROOM_TEMP_LOW!" << endl;
			this->roomTemperature = ROOM_TEMP_LOW;
			notifyObservers();
			break;
		}
	}
}

/* Trigger method to change room temperature */
void RTController::triggerRoomTemperatureChange()
{
	cout << "Room temperature change triggered" << endl;
	this->setRoomTemperature();
}

/* External request as business logic */
void RTController::externalRequest_registerObservers(MIClass* observer)
{
	cout << "Observer is being registered" << endl;
	listOfObservers.push_back(observer);
}

/* External request as business logic */
void RTController::externalRequest_deregisterObservers(MIClass* observer)
{
	cout << "Observer is being deregistered" << endl;
	listOfObservers.remove(observer);
}

/* Main notification event */
void RTController::notifyObservers()
{
	for (auto observer : listOfObservers) observer->notifyEvent(this->roomTemperature);
}