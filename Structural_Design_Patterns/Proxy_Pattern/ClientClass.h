#pragma once
/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include "ProxyBaseClass.h"

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/
class ClientClass
{
private:
	proxyBaseClass& proxyBaseClassObj;
public:
	ClientClass(proxyBaseClass& proxyBaseClassMainObj):
		proxyBaseClassObj(proxyBaseClassMainObj)
	{

	}
	void ClientFunction()
	{
		proxyBaseClassObj.proxyMainFunctionality();
	}
};

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/