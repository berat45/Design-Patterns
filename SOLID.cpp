// DiveIntoDesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



/* S.O.L.I.D PRINCIPLE EXAMPLES */
#include <String>
#include <iostream>
#include <list>
using namespace std;

/* 1 */
/* SINGLE RESPONSIBILITY */
/* The Single Responsibility Principle states that a class should do one thing and therefore it should have only a single reason to change. */
#ifdef SRP
class book
{
private:
	string bookName;
	int bookId;
public:
	book() = delete;

	/* Delete assignment operator */
	book& operator = (const book& object) = delete;

	/* Constructor and provideBookInfo() function is the main business logic for this class */
	book(string bookname, int bookID):
		bookName(bookname), bookId(bookID)
	{}

	std::pair<string, int> provideBookInfo()
	{
		std::pair<string, int> resultPair = make_pair(bookName, bookId);
		return resultPair;
	}

	/* addBookToDatabase() is a violation for the SRP. Because the main business logic of this class is only returning the name and ID 
	   of the book. 
		1 --> Registration functionality of books are out of this class's scope
		2 --> Any change related with the registration functionality will cause a change for this class 
	   
	   What could be done? 
		Decision: Another class shall be created for this functionality
	   */
	void addBookToDatabase(std::pair<string, int> bookPair)
	{
		/* Some functionality to register books */
		/* ... */
	}
};
#endif /* SRP */

/* 2 */
/* Open-Closed Principle */
/* The Open-Closed Principle requires that classes should be open for extension and closed to modification. */

/* Same book class which is defined in SRP example has ben declared here again. Let's assume that addBookToDatabase() violation
   has been eliminated here and registration provided */
#ifdef OCP
class book
{
private:
	string bookName;
	int bookId;
public:
	book() = delete;

	/* Delete assignment operator */
	book& operator = (const book& object) = delete;

	/* Constructor and provideBookInfo() function is the main business logic for this class */
	book(string bookname, int bookID) :
		bookName(bookname), bookId(bookID)
	{}

	std::pair<string, int> provideBookInfo()
	{
		std::pair<string, int> resultPair = make_pair(bookName, bookId);
		return resultPair;
	}
};

class book_registeration
{
public:
	void addBookToDatabase(std::pair<string, int> bookPair)
	{
		/* Some functionality to register books: REGISTRATION TO DATABASE_X */
		/* ... */
	}
};

/* LET'S ASSUME THAT, AT THAT MOMENT, WE WANT TO ADD ANOTHER FUNCTIONALITY WHICH REGISTERS BOOKS INTO DATABASE_Y. We can
   do this only by modifying addBookToDatabase() method which is not suitable for open-closed principle. This is why the above
   class should have been introduced as below: */
class book
{
private:
	string bookName;
	int bookId;
public:
	book() = delete;

	/* Delete assignment operator */
	book& operator = (const book& object) = delete;

	/* Constructor and provideBookInfo() function is the main business logic for this class */
	book(string bookname, int bookID) :
		bookName(bookname), bookId(bookID)
	{}

	std::pair<string, int> provideBookInfo()
	{
		std::pair<string, int> resultPair = make_pair(bookName, bookId);
		return resultPair;
	}
};

class book_registeration
{
public:
	virtual void addBookToDatabase(std::pair<string, int> bookPair) {}
};

class DatabaseXRegistration : public book_registeration
{
	void addBookToDatabase(std::pair<string, int> bookPair) override
	{
		/* Some functionality to register books: REGISTRATION TO DATABASE_X */
		/* ... */
	}
};
class DatabaseYRegistration : public book_registeration
{
	void addBookToDatabase(std::pair<string, int> bookPair) override
	{
		/* Some functionality to register books: REGISTRATION TO DATABASE_Y */
		/* ... */
	}
};
#endif /* OCP */

/* 3 */
/* Liskov Substitution Principle */
/* When a child Class cannot perform the same actions as its parent Class, this can cause bugs.
   If you have a Class and create another Class from it, it becomes a parent and the new Class becomes a child. The child Class should be able to do everything the parent Class can do. This process is called Inheritance.
   The child Class should be able to process the same requests and deliver the same result as the parent Class or it could deliver a result that is of the same type. */
#ifdef LSP
class LspParentClass
{
protected:
	std::list<int> ConstructorInputs;
public:
	LspParentClass() = delete;
	LspParentClass(int input)
	{
		ConstructorInputs.push_back(input);
	}
	void constructorInputsGetter()
	{
		cout << "Base class --> Total number of ConstructorInputs: " << ConstructorInputs.size() << endl;
	}
	virtual void constructorInputsSizeCheck()
	{
		if (2 == ConstructorInputs.size())
		{
			throw 404; /* Throw dummy error */
		}
	}
};

/* Let's create a subclass */
class LspChildClass : public LspParentClass
{
	void constructorInputsSizeCheck() override
	{
		if (3 == ConstructorInputs.size()) /* VIOLATION 1 */
		{
			/* If the child Class doesn’t meet the same requirements with the parent class, it means the child class is changed partially/completely and violates this principle. */
			throw 505; /* VIOLATION 2 */
		}
	}
};
#endif /* LSP */

/* 4 */
/* Interface Segregation Principle */
/* Clients should not be forced to depend on methods that they do not use */
#ifdef ISP
class ISP_VehicleBaseClass
{
protected:
	virtual void turnSteeringWheel() = 0;
	virtual void changeShifter() = 0;
	virtual void stopMotor() = 0;
};

class CarClass : public ISP_VehicleBaseClass
{
protected:
	/* All three vehicle specific methods can be implemented here */
};

class MopedClass : public ISP_VehicleBaseClass
{
protected:
	/* Mopeds don't have shifter unit. 2nd functionality cannot be implemented here */			/* --> VIOLATION OF ISP */ 
};
#endif /* ISP */

/* 5 */
/* Dependency Inversion Principle */
/* High-level modules should not depend on low-level modules. Both should depend on the abstraction. Abstractions should not depend on details. Details should depend on abstractions. */
/* WRONG   : CUSTOMER <..> PROVIDER 
   CORRECT : CUSTOMER <..> PROVIDER INTERFACE <..> PROVIDER 1 OUT OF N PROVIDER CHILD CLASSES */


int main()
{
    return 0;
}

