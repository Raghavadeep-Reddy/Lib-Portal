#ifndef Library_h
#define Library_h

#include "Issue.h"

class Library{

	Student studPtr;   //Association
    Book bookPtr;      //Association
    Issue issuePtr;    //Association

	public:

		Library();

		void issueBook(Student, Book);

		void returnBook(int bid);
};

#endif
