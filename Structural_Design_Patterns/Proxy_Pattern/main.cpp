// DiveIntoDesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DiveIntoDesignPatterns.h"
#include "ProxyA.h"
#include "ProxyB.h"
#include "ProxyBaseClass.h"
#include "ClientClass.h"

int main()
{
	proxyBaseClass proxyBaseClassMainObj;
	ProxyBClass proxyBClassMainObj(3);
	ClientClass clientClassMainObj(proxyBClassMainObj);
	clientClassMainObj.ClientFunction();
#if 0
	GfG obj1;
	GfG obj2;
	obj1.i = 2;
	obj2.i = 3;

	// prints value of i
	cout << obj1.i << " " << obj2.i;

	Animal<int>* animalObject = new Cat();
	animalObject->feed();

	deviceRunner deviceRunnerObj;
	deviceRunnerObj.deviceInfCaller();
#endif
    return 0;
}

