#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<conio.h>
#include"cow.h"
#include"milk.h"
#include"staff.h"
#include"dairyPdct.h"
using namespace std;
int flag;
class Login
{
        protected:
            char username[50];
            char password[50];
            int i;
            unsigned int role;
        public:
            char ch;
            // cow c1;
            void Register()
            {
               
                ofstream fs("logindata.txt",ios::app);   
                cout<<"\n\t\t\t\t\t\t\tEnter Username : ";
                cin>>username;
                cout<<"\n\t\t\t\t\t\t\tEnter password: ";
                i=0;
                do{
                ch=getch();
                if(ch!=13)
                {
                    {
                        password[i]=ch;
                        cout<<"*";
                        i++;
                        }
               }
               else{
                password[i]='\0';
               }
               }while(ch!=13);
                 cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                 cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                 cout<<"\n\t\t\t\t\t\t\t||\t  Registered Successfully\t||\n";
                 cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                 cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                 fs<<username<<" "<<password<<" ";
                 fs.close();
                 cout<<"\n\t\t\t\t\t\t\tPress 'Enter' and Log in to your account";
                  getch(); 
            }
            void login(char  un[],char pw[])
            {
                ifstream fs("logindata.txt",ios::in);
                if(!fs.eof())
                {
                fs>>username>>password;   
               
                if(strcmp(un,this->username)==0 && strcmp(pw,this->password)==0)
                 {
                    flag=1;
                    cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                    cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                    cout<<"\n\t\t\t\t\t\t\t||********logged in Successfully********||\n";
                    cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                    cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                     cout<<"\n\t\t\t\t\t\t\tPress 'Enter' to continue";
                }
                else{
                    cout<<"\n\n\t\t\t\t\t\t\t==========================================\n";
                    cout<<"\n\t\t\t\t\t\t\t\t$ Wrong username/password $\n";
                    cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                    cout<<"\n\t\t\t\t\t\t\tPress 'Enter' to Login again";
                }
                }
                fs.close(); 
                getch();
            }
};
main()
{
   
    Login l1;
    cow c1;
    milk m1;
    staff s1;
    dairy d1;
    int i;
    char username[50],password[50];
    int ch,choice;
    bool status=true;
    bool stts=false;
    while(1)
    {
    system("cls");
    cout<<"\n\t\t\t\t\t\t\t==========================================\n";
    cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
    cout<<"\n\t\t\t\t\t\t\t||**********  Welcome to DAIRY *********||\n";
    cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
    cout<<"\n\t\t\t\t\t\t\t||\t\t1. Login\t\t||\n";
    cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
    cout<<"\n\t\t\t\t\t\t\t||\t\t2. Register\t\t||\n";
    cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
    cout<<"\n\t\t\t\t\t\t\t||\t\t3. Exit\t\t\t||\n";
    cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
    cout<<"\n\t\t\t\t\t\t\t==========================================\n";
    cout<<"\n\t\t\t\t\t\t\t==========================================\n";
    cout<<"\n\t\t\t\t\t\t\tEnter your choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
             cout<<"\n\t\t\t\t\t\t\t==========================================\n";
            cout<<"\n\t\t\t\t\t\t\tUsername : "; cin>>username;
            cout<<"\n\t\t\t\t\t\t\tPassword : ";
            i=0;
             do{
               ch=getch();
                if(ch!=13)
                {
                    password[i]=ch;
                    cout<<"*";
                     i++;
                    }
                else{
                    password[i]='\0';
                }
               }while(ch!=13);
           l1.login(username,password);
           if(flag)
           {
            while(status)
            {
                cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                cout<<"\n\t\t\t\t\t\t\t||\t    1. STAFFS\t\t\t||\n";
                cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                cout<<"\n\t\t\t\t\t\t\t||\t    2. COW DETAILS\t\t||\n";
                cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                cout<<"\n\t\t\t\t\t\t\t||\t    3. MILK COLLECTION\t\t||\n";
                cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                cout<<"\n\t\t\t\t\t\t\t||\t    4. DAIRY PRODUCTS\t\t||\n";
                cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                cout<<"\n\t\t\t\t\t\t\t||\t    5. Exit\t\t\t||\n";
                cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                cout<<"\n\t\t\t\t\t\t\tEnter Your Choice:"; cin>>choice;
                switch(choice)
                {
                    case 1:s1.staffFunction();
                            break;
                    case 2:c1.cowfunction();
                            break;
                    case 3:m1.milkfunction();
                            break;
                    case 4:d1.dairyfunction();
                            break;
                    case 5:status=false;
                }        
           }
        }
        break;
        case 2:
                l1.Register();
                //stts=true;
        break;
        case 3:
            exit(1);
    }
  }
}