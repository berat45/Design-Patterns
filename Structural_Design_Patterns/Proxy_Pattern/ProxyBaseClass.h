#pragma once
/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include <stdio.h>

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/
class proxyBaseClass
{

public:
	proxyBaseClass()
	{
		printf("proxyBaseClass(): Constructor has been called\n");
	}
	void proxyCommonFunctionality() const;
	virtual void proxyMainFunctionality();

private:
};
/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/