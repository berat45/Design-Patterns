#pragma once
/*  This file is written by Berat Erdemkilic for demo purposes */

/***************************************************************/
/************************* INCLUDES ****************************/
/***************************************************************/
#include "ProxyBaseClass.h"

/***************************************************************/
/************************* VARIABLES ***************************/
/***************************************************************/
class ProxyAClass : public proxyBaseClass
{
private:
	int proxyA_dummy;
public:

	/* Delete specific template specialisation which is double */
	ProxyAClass(double input) = delete;
	/* Copy constructor which is deleted */
	ProxyAClass(ProxyAClass& obj) = delete;

	ProxyAClass(int inp):
		proxyA_dummy(inp)
	{
		printf("ProxyAClass(): Constructor has been called\n");
	}

	void proxyMainFunctionality() override
	{
		printf("ProxyAClass(): proxyMainFunctionality() has been called\n");
	}

};

/***************************************************************/
/************************* DEFINITIONS *************************/
/***************************************************************/

/***************************************************************/
/********************** FUNCTION PROTOTYPES ********************/
/***************************************************************/
