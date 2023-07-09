// DiveIntoDesignPatterns.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



/* S.O.L.I.D PRINCIPLE EXAMPLES */
#include <String>
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
#endif /* OCP */
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


/* 3 */
/* Liskov Substitution Principle */





int main()
{
    return 0;
}

