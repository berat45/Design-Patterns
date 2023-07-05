#pragma once
/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include <iostream>
#include "CommonEnums.h"
using namespace std;

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/
class MIClass
{
public:
	/* Delete object creation on heap */
	void* operator new (size_t) = delete;

	MIClass()
	{
		cout << "MIClass default constructor" << endl;
	}
	~MIClass()
	{
		cout << "MIClass default destructor" << endl;
	}

	/* Pure virtual notify method */
	virtual void notifyEvent(ROOM_TEMPERATURE_DEGREES_ENUM roomTemp)
	{
		cout << "Default notify event!" << endl;
	}
};

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/