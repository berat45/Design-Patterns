#pragma once
/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include "ProxyBaseClass.h"

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/
class ProxyBClass : public proxyBaseClass
{
private:
	int proxyB_dummy;
	proxyBaseClass proxyBaseClassBobj;
public:

	/* Delete specific template specialisation which is double */
	ProxyBClass(double input) = delete;
	/* Copy constructor which is deleted */
	ProxyBClass(ProxyBClass& obj) = delete;

	ProxyBClass(int inp) :
		proxyB_dummy(inp)
	{
		printf("ProxyBClass(): Constructor has been called\n");
	}

	void proxyMainFunctionality() override
	{
		proxyBaseClassBobj.proxyMainFunctionality();
	}

};

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/
