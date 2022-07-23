#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include<sstream>
#include<cstdio>
#include"cow.h"
using namespace std;
bool cmod=false;
void cow::read()
{
	cout<<"\n\t\t\t\t\t\t\t==========================================\n";
	cout << "\n\t\t\t\t\t\t\tCOW ID : ";
	cin>>Cow_ID; 
	// cout<<"BREED:";
	cout << "\n\t\t\t\t\t\t\tBREED : ";
	cin>>Breed; 
    // cout<<"STATUS:";
	cout << "\n\t\t\t\t\t\t\tSTATUS : ";
	cin>>Status; 
    // cout<<"PRICE:";
	cout << "\n\t\t\t\t\t\t\tAMOUNT : ";
	cin>>Amount;
}

void cow::pack()
{
	buffer.erase();
	buffer+=Cow_ID+"|"+Breed+"|"+Status+"|"+Amount+"$";
	buffer+="\n";
}

void cow::write()
{
	fstream file;
	file.open("cow.txt",ios::out|ios::app|ios::binary);
	file<<buffer;
	file.close();
}

void cow::unpack()
{
	int i=0;
	Cow_ID.erase();
	while(buffer[i]!='|')
		Cow_ID+=buffer[i++];

	Breed.erase();
	i++;
	while(buffer[i]!='|')
		Breed+=buffer[i++];

	
	Status.erase();
	i++;
	while(buffer[i]!='|')
		Status+=buffer[i++];

	
	Amount.erase();
	i++;
	while(buffer[i]!='$')
		Amount+=buffer[i++];
}

void cow::display()
{

	fstream file,copy;
	string ch="";
	int i,flag=0;
	system("cls");
	file.open("cow.txt",ios::in|ios::binary);
    // copy.open("temp.txt",ios::out|ios::binary);
	cout<<"\n\t\t\t\t\t\t\t==========================================\n";
	// cout << "\t\t\t\t\t\t\t    COW ID|BREED|STASTUS|AMOUNT$";
	cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
	while(!file.eof())
	{
		buffer.erase();
		getline(file,buffer);
		// ch=buffer;
		if(buffer[0]!='*'&& !file.eof())
		{
            flag=1;
			unpack();
			cout<< "\t\t\t\t\t\t\t\t    COW ID : " << Cow_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t    Breed  : " << Breed<<endl;
			cout<< "\t\t\t\t\t\t\t\t    Status : " << Status<<endl;
			cout<< "\t\t\t\t\t\t\t\t    Amount : " << Amount;
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			// cout << "\n\t\t\t\t\t     " << ch << "\n";
			// cout<<ch<<endl;			
		}
	}
    if(flag==0)
	{
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  No Records About Cow\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
    // cout<<"No Records About cow\n";
    // remove("cow.txt");
    // rename("temp.txt","cow.txt");
     file.close();
    // copy.close();
	}
}

int cow::search(string key)
{
	int pos=0,flag=0;
	fstream file;
	system("cls");
	file.open("cow.txt",ios::in|ios::binary);
	while(!file.eof())
	{
		// if(file.eof());
		// break;
		buffer.erase();
		pos=file.tellg();
		getline(file,buffer);
		unpack();
		if(key==Cow_ID)
		{
			cout << "\n\t\t\t\t\t\t\t       ******** RECORD FOUND ********\n";
		// 	cout<<"\n\t\t\t\t\t\t\t==========================================\n";
		// cout << "\t\t\t\t\t\t\t       COW ID|BREED|STATUS|AMOUNT$";
		cout << 	"\n\t\t\t\t\t\t\t------------------------------------------\n";
		cout<< "\t\t\t\t\t\t\t\t    COW ID : " << Cow_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t    Breed  : " << Breed<<endl;
			cout<< "\t\t\t\t\t\t\t\t    Status : " << Status<<endl;
			cout<< "\t\t\t\t\t\t\t\t    Amount : " << Amount;
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			// cout<<"Record found\n"<<buffer;
			flag=1;
			return pos;
		}
	}
	file.close();
	if(flag!=1)
    {
		cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
		cout << "\t\t\t\t\t\t\t| \t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t|    ******* RECORD NOT FOUND *******    |\n";
		cout << "\t\t\t\t\t\t\t| \t\t\t\t\t |";
		cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
        // cout<<"\nRecord not found\n";
		return -1;
    }
}

int cow::delete_data(string key)
{
	int pos,flag=0;
	fstream file;
	pos=search(key);
	if(pos>=0)
	{
		file.open("cow.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else{
	return 0;
	}
}

int cow::modify(string key)
{
	int ch;
	if(delete_data(key))
	{
		cmod=true;
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||     -----  WHAT TO MODIFY -----\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      1. COW ID              \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      2. BREED               \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      3. STATUS              \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      4. AMOUNT              \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      5. EXIT                \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\tEnter your choice : ";
	// cout<<"What to modify:\n 1.Cow_ID\n2.Breed\n3.Status\n4.Amount\n";
	cin>>ch;
	switch(ch)
	{
		case 1: 
			cout << "\n\t\t\t\t\t\t\tCow ID: ";
		// cout<<"Cow_ID:";
			cin>>Cow_ID;
			break;
		case 2: 
			cout << "\n\t\t\t\t\t\t\tBreed: ";
			// cout<<"Breed:";
			cin>>Breed;
			break;
		case 3: 
			cout << "\n\t\t\t\t\t\t\tStatus: ";
			// cout<<"Status:";
			cin>>Status;
			break;
		case 4: 
			cout << "\n\t\t\t\t\t\t\tAmount: ";
			// cout<<"Amount:";
			cin>>Amount;
			break;
		case 5:return 0;
		default:
			cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
			// cout<<"wrong choice";
		break;
	}
	pack();
	write();
}

}

// void cow::UpdateStatus(string key)
// {
//    if(delete_data(key))
//     {
//         Status="Sold";
//         pack();
//         write();
//         cout<<"Status updated successfully\n";

//     }
// }

int cow::cowfunction()
{
	int ch,i,count;
	string key;
	cow c1;
	while(1)
	{
		cout<<"\n\t\t\t\t\t\t\t==========================================\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||     *********  MENU *********\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  1. ADD COW DETAILS\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  2. DELETE COW DETAILS\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  3. SEARCH COW DETAILS\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  4. MODIFY COW DETAILS\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  5. DISPLAY COW DETAILS\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  6. EXIT\t\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t==========================================\n";
		cout<<"\n\t\t\t\t\t\t\t==========================================\n";
		cout<<"\n\t\t\t\t\t\t\tEnter your choice : ";
		//cout<<"\nMenu\n1.Add cow\n2.Delete cow\n3.Search cow\n4.Modify cow Detail\n5.Sale cow\n6.Display\n7.Ext\n";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				cout<<"\n\t\t\t\t\t\t\tHOW MANY : ";
			// cout<<"How many:\n";
				cin>>count;
				for(i=0;i<count;i++)
				{
					// cout<<"Data\n";
					c1.read();
					c1.pack();
					c1.write();
				}
				cout<<"\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t||    Cow details added Successfully    ||\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t==========================================\n";
				break;
			case 2: 
					cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				cout<<"\n\t\t\t\t\t\t\tENTER THE COW ID : ";
			// cout<<"Enter the Cow_ID:";
				cin>>key;
				i=c1.delete_data(key);
				if(i==1)
					// cout<<"\nRecord deleted\n";
					{
					cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                 cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                 cout<<"\n\t\t\t\t\t\t\t||\t      Record Deleted    \t||\n";
                 cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                 cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				}
				// else 
				// 	cout<<"\nRecord not deleted\n";
				    break;
			case 3: 
					cout << "\n\t\t\t\t\t\t\t==========================================\n";
				cout << "\n\t\t\t\t\t\t\tENTER COW ID : ";
			// cout<<"Enter the Cow_ID:";
				    cin>>key;
				    c1.search(key);
				    break;
			case 4: 
					cout << "\n\t\t\t\t\t\t\tENTER COW ID : ";
					// cout<<"Enter the Cow_ID:";
				    cin>>key;
				    c1.modify(key);
					if(cmod==true)
					{
						cout<<"\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
						// cout<<"\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t||   Cow details modified Successfully  ||\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
			// cout << "\n\t\t\t\t\t\t\t==========================================\n";
					}
				    break;
            // case 5: cout<<"Enter the Cow_ID:";
			// 	    cin>>key;
			// 	    c1.UpdateStatus(key);
            //         break;
            case 5: c1.display();
				    break;
			case 6: return 0;
			default:
			cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
				// cout<<"wrong choice\n";
				break;
		} 
	}
}