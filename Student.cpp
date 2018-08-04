#include "Student.h"
#include<string.h>
#include<iostream>

using namespace std;

   Student::Student(){
       rno=0;
       strcpy(name,"No Student");
   }

    int Student::getRollNo(){
    	return rno;
	}

	char* Student::getName(){
	  return name;
	}

   void Student::setData(){
       cout<<"\nEnter roll number:";
       cin>>rno;
       cin.ignore();
       cout<<"\nEnter name:";
       cin.getline(name,19);
   }

   void Student::showData(){
       cout<<endl<<"Roll No:"<<rno<<"\n"<<"Name:"<<name;
   }
