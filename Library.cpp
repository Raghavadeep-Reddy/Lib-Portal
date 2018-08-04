#include "Library.h"
#include<windows.h>
#include<iostream>
#include<fstream>
#include<ctime>

using namespace std;

		Library::Library(){}

        void Library::issueBook(Student s,Book b){
            SYSTEMTIME stime;

            GetSystemTime(&stime);
            int preDate[3]={stime.wDay,stime.wMonth,stime.wYear};
            int Arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
            int leapArr[]={0,31,29,31,30,31,30,31,31,30,31,30,31};

            int ex_day,ex_month,ex_year,k=0,*arr;

            stime.wYear%4==0?arr=leapArr:arr=Arr;

            for(int i=0;i<stime.wMonth;i++)
                k=k+arr[i];

            k=k+stime.wDay+30;

            if(k>365)
                ex_year=stime.wYear+1;

            else
                ex_year=stime.wYear;

            for(int i=0;i<13;i++){
                ex_day=k-arr[i];

                if(ex_day<arr[i+1]){
                    ex_month=i+1;
                    break;
                }
                else
                    k=ex_day;
            }
            ex_month%=12;

            int exDate[3]={ex_day,ex_month,ex_year};

            issuePtr.issueBook(s,b,preDate,exDate);
		}

		void Library::returnBook(int bid){

		    int Arr[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
            int leapArr[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
            int *arr=Arr;

            int x=issuePtr.deleteRecord(bid);

            if(x==0)
            {
                cout<<"\nBook Not Issued";
                return ;
            }

            SYSTEMTIME stime;
            GetSystemTime(&stime);

            int k1=0,k2=0;

            if(stime.wYear%4==0)
                arr=leapArr;

            for(int i=0;i<stime.wMonth;i++)
                k1=k1+arr[i];

                k1=k1+stime.wDay;

            if(stime.wYear%4==0)
                arr=leapArr;

            for(int i=0;i<stime.wMonth;i++)
              k2=k2+arr[i];

            k2=k2+stime.wDay+365*(stime.wYear-x);
            int fine=5*(k2-k1);

            cout<<"\nSuccessfully deleted\n"<<"Fine is:"<<fine;
		}
