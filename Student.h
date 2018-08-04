#ifndef Student_h
#define Student_h

#include "Person.h"

 class Student:public Person{     //Inheritance
    int rno;
    char name[20];

    public:

    Student();

    int getRollNo();

    char* getName();

    void setData();

    void showData();
};

#endif
