#ifndef Issue_h
#define Issue_h

#include "Student.h"
#include "Book.h"

//It has Composition relationship as without book n student, issue cannot exist.

class Issue {
public:
    Book book;
    Student student;
    int preDate[3],exDate[3];

    public:

    Issue();

    void issueBook(Student student, Book book, int* preDate, int* exDate);

    char* getName();

    int getB_Id();

    void showDetails();

    void viewAllRecords();

    void searchRecord(int bid);

    int deleteRecord(int r_no);
};
#endif
