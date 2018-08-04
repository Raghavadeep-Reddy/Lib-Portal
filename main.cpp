#include <iostream>
#include "Library.h"
#include "Student.h"
#include<stdlib.h>
#include<conio.h>

using namespace std;

int menu(){
    int choice;

	cout<<"\t\t\t\t\t\tLibrary Portal\n";
	cout<<"\n1. Issue Book:";
	cout<<"\n2. Search a particular record:";
	cout<<"\n3. View all records:";
	cout<<"\n4. Return Book:";
	cout<<"\n5. Exit";
	cout<<"\n\n Choose Options:";
	cin>>choice;

	return choice;
}

int main() {
    Student s1;
    Book b1;
    Library lib;
    Issue is;
    int bookId;
    while(1){
      system("cls");
        switch(menu()){
      case 1:
          s1.setData();
          b1.setItemData();
          lib.issueBook(s1,b1);
          break;

      case 2:
          cout<<"\nEnter Book id:";
          cin>>bookId;
          is.searchRecord(bookId);
          break;

      case 3:
           is.viewAllRecords();
           break;

      case 4:
          cout<<"\nEnter Book id:";
          cin>>bookId;
          lib.returnBook(bookId);
          break;

      case 5:
          cout<<"\nThanks for using this software.";
          cout<<"\nPress Enter.";
          getch();
          exit(0);

      Default:
          cout<<"\nPress Select a valid option.";
        }
        getch();
    }
    return 0;
}
