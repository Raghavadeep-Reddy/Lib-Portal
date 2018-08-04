#ifndef Book_h
#define Book_h

#include "Item.h"

class Book:public Item{     //Inheritance
	int b_id;
	char title[20],author[20];

    public:

    Book();

	int getBookId();

    char* getName();

    void setItemData();

    void showItemData();
};
#endif
