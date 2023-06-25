/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include "stdafx.h"
#include "ProxyBaseClass.h"

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/
void proxyBaseClass::proxyCommonFunctionality() const
{
	printf("proxyBaseClass(): proxyCommonFunctionality() has been called\n");
}

void proxyBaseClass::proxyMainFunctionality()
{
	printf("proxyBaseClass(): proxyMainFunctionality() has been called\n");
}