#include "Book.h"
#include<string.h>
#include<iostream>

using namespace std;

    Book::Book(){
        b_id=0;
        strcpy(this->title,"No Title");
	    strcpy(this->author,"No Author");
	}

   	int Book::getBookId(){
		return b_id;
	}

	char* Book::getName(){
	  return title;
	}

    void Book::setItemData(){
     cout<<"\nEnter book id:";
     cin>>b_id;
     cin.ignore();
     cout<<"\nTitle:";
     cin.getline(title,19);
     cout<<"\nEnter author:";
     cin.getline(author,19);
    }

    void Book::showItemData(){
     cout<<endl<<"book-id:"<<b_id<<"\n"<<"title:"<<title<<"\n"<<"author:"<<author;
    }
