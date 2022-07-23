#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include<cstdio>
#include"staff.h"
using namespace std;
bool smod=false;
void staff::read()
{
	// cout<<"STAFF ID:";
	// cin>>Staff_ID; 
	// cout<<"NAME:";
	// cin>>Staff_name; 
	// cout<<"CONTACT:";
	// cin>>Contact;
    // cout<<"DESIGNATION:";
	// cin>>Designation;
	cout<<"\n\t\t\t\t\t\t\t==========================================\n";
	cout << "\n\t\t\t\t\t\t\tSTAFF ID : ";
	cin>>Staff_ID; 
	// cout<<"NAME:";
	cout << "\n\t\t\t\t\t\t\tNAME : ";
	cin>>Staff_name; 
	// cout<<"CONTACT:";
	cout << "\n\t\t\t\t\t\t\tCONTACT : ";
	cin>>Contact;
    // cout<<"DESIGNATION:";
	cout << "\n\t\t\t\t\t\t\tDEISGNATION : ";
	cin>>Designation; 
} 


void staff::pack()
{
	buffer.erase();
	buffer+=Staff_ID+"|"+Staff_name+"|"+Contact+"|"+Designation+"$";
	buffer+="\n";
}

void staff::write()
{
	fstream file;
	file.open("staff.txt",ios::out|ios::app|ios::binary);
	file<<buffer;
	file.close();
}

void staff::unpack()
{
	int i=0;
	Staff_ID.erase();
	while(buffer[i]!='|')
		Staff_ID+=buffer[i++];

	Staff_name.erase();
	i++;
	while(buffer[i]!='|')
		Staff_name+=buffer[i++];
	
	Contact.erase();
	i++;
	while(buffer[i]!='|')
		Contact+=buffer[i++];

	Designation.erase();
	i++;
	while(buffer[i]!='$')
		Designation+=buffer[i++];	
}

void staff::display()
{

	fstream file,copy;
	string ch="";
	int i,flag=0;
	system("cls");
	file.open("staff.txt",ios::in);
    // copy.open("temp.txt",ios::out|ios::binary);
	cout<<"\n\t\t\t\t\t\t\t==========================================\n";
	// cout << "\t\t\t\t\t\t\t    STAFF ID|NAME|CONTACT|DESIGNATION$";
	cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
	while(!file.eof())
	{
		buffer.erase();
		getline(file,buffer);
		// ch.erase();
		// ch=buffer;
		if(buffer[0]!='*' && !file.eof())
		{
            flag=1;
			unpack();
			// cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			cout<< "\t\t\t\t\t\t\t\t      STAFF ID : " << Staff_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t    STAFF NAME : " << Staff_name<<endl;
			cout<< "\t\t\t\t\t\t\t\t       CONTACT : " << Contact<<endl;
			cout<< "\t\t\t\t\t\t\t\t   DESIGNATION : " << Designation<<endl;
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			// cout<<ch<<endl;			
		}
	}
    if(flag==0)
	{
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  No Records About Staff\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
	}
    // cout<<"No Records About Staff\n";
    // remove("staff.txt");
    // rename("temp.txt","staff.txt");
     file.close();
    // copy.close();

}

int staff::search(string key)
{
	int pos=0,flag=0;
	fstream file;
	system("cls");
	file.open("staff.txt",ios::in|ios::binary);
	while(!file.eof())
	{
		buffer.erase();
		pos=file.tellg();
		getline(file,buffer);
		unpack();
		if(key==Staff_ID)
		{
			// cout<<"Record found\n"<<buffer;
			cout << "\n\t\t\t\t\t\t\t       ******** RECORD FOUND ********\n";
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			cout<< "\t\t\t\t\t\t\t\t      STAFF ID : " << Staff_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t    STAFF NAME : " << Staff_name<<endl;
			cout<< "\t\t\t\t\t\t\t\t       CONTACT : " << Contact<<endl;
			cout<< "\t\t\t\t\t\t\t\t   DESIGNATION : " << Designation<<endl;
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
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

int staff::delete_data(string key)
{
	int pos,flag=0;
	fstream file;
	pos=search(key);
	if(pos>=0)
	{
		file.open("staff.txt");
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

int staff::modify(string key)
{
	int ch;
	if(delete_data(key))
	{
		smod=true;
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||     -----  WHAT TO MODIFY -----\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      1. STAFF ID       \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      2. NAME           \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      3. CONTACT              \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      4. DEISGNATION      \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t      5. EXIT             \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\tEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: cout << "\n\t\t\t\t\t\t\tStaff ID: "; 
			cin>>Staff_ID;
			break;
		case 2: cout << "\n\t\t\t\t\t\t\tName: ";
			cin>>Staff_name;
			break;
		case 3:cout << "\n\t\t\t\t\t\t\tContact: ";
			cin>>Contact;
			break;
		case 4:cout << "\n\t\t\t\t\t\t\tDesignation: ";
			cin>>Designation;
			break;
			case 5:return 0;
		default:
				cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
			break;

	}
	pack();
	write();
}
}

int staff::staffFunction()
{
	int ch,i,count;
	string key;
	staff s1;
	while(1)
	{
		cout<<"\n\t\t\t\t\t\t\t==========================================\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||     *********  MENU *********\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  1. ADD STAFF\t\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  2. DELETE STAFF\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  3. SEARCH STAFF\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  4. MODIFY STAFF DETAILS\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  5. DISPLAY STAFF DETAILS\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t||\t  6. EXIT\t\t\t||\n";
		cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout<<"\n\t\t\t\t\t\t\t==========================================\n";
		cout<<"\n\t\t\t\t\t\t\t==========================================\n";
		cout<<"\n\t\t\t\t\t\t\tEnter your choice : ";
		//cout<<"\nMenu\n1.Add Staff\n2.Delete Staff\n3.Search Staff\n4.Modify Staff Detail\n5.Display \n6.Ext\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				cout<<"\n\t\t\t\t\t\t\tHOW MANY : ";
				cin>>count;
				for(i=0;i<count;i++)
				{
					s1.read();
					s1.pack();
					s1.write();
				}
				cout<<"\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t||   Staff details added Successfully   ||\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t==========================================\n";
				break;
			case 2: cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				cout<<"\n\t\t\t\t\t\t\tENTER THE STAFF ID : "; 
				cin>>key;
				i=s1.delete_data(key);
				if(i==1)
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
			case 3:cout << "\n\t\t\t\t\t\t\t==========================================\n";
				cout << "\n\t\t\t\t\t\t\tENTER STAFF ID : ";
				cin>>key;
				s1.search(key);
				break;
			case 4: cout << "\n\t\t\t\t\t\t\tENTER STAFF ID : ";
				cin>>key;
				s1.modify(key);
				if(smod=true)
				{
					cout<<"\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
					cout << "\t\t\t\t\t\t\t||\t\t\t\t\t  ||";
					cout << "\n\t\t\t\t\t\t\t||   Staff details modified Successfully  ||\n";
					cout << "\t\t\t\t\t\t\t||\t\t\t\t\t  ||";
					cout << "\n\t\t\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
				}
				break;
			case 5: s1.display();
				break;
			case 6: return 0;
			default:cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
			break;
		} 
	}
}