#include "Issue.h"
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

   Issue::Issue(){}

   void Issue::issueBook(Student student, Book book, int* predate, int* exdate) {
        this->student = student;
        this->book = book;
        for(int i=0;i<3;i++){
            preDate[i]=predate[i];
            exDate[i]=exdate[i];
        }
        if(student.getRollNo()==0 || book.getBookId()==0){
            cout<<"\nPlease fill the details first";
            return ;
        }
        ofstream fout;
        fout.open("library.txt",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        cout<<"\nSuccessfully Inserted";
   }

     int Issue::getB_Id(){
       return book.getBookId();
     }

   void Issue::showDetails(){
       student.showData();
       book.showItemData();
       cout<<endl<<"Issued Date:"<<preDate[0]<<"/"<<preDate[1]<<"/"<<preDate[2];
       cout<<endl<<"Expiry Date"<<exDate[0]<<"/"<<exDate[1]<<"/"<<exDate[2]<<endl;
    }

  void Issue::searchRecord(int bid){
    ifstream fin;
    fin.open("library.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile not found";

    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(bid==book.getBookId())
                showDetails();

          fin.read((char*)this,sizeof(*this));
        }
     }
  }

  void Issue::viewAllRecords(){
    ifstream fin;
    fin.open("library.txt",ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile not found";

    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
          showDetails();
          fin.read((char*)this,sizeof(*this));
        }
     }
  }

  int Issue::deleteRecord(int bid){
    ifstream fin;
    ofstream fout;
    fin.open("library.txt",ios::in|ios::binary);

    int x=0;
        fout.open("temp.txt",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(bid!=book.getBookId())
                fout.write((char*)this,sizeof(*this));
            else
                x=exDate[2];

                fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("library.txt");
        rename("temp.txt","library.txt");

      return x;
  }
