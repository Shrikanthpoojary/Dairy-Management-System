#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<ctime>
#include"milk.h"
using namespace std;
bool mmod=false;
void milk::read()
{
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
	cout << "\n\t\t\t\t\t\t\tMILK COLLECTION ID : ";
	cin >> milk_ID;
	// cout<<"Liters:";
	cout << "\n\t\t\t\t\t\t\tLITERS : ";
	cin >> ltr;
	liters = to_string(ltr);
	// cout<<"Price/Liter:";
	cout << "\n\t\t\t\t\t\t\tPRICE/LITER : ";
	cin >> ppl;
	price_per_ltr = to_string(ppl);
	ans = ltr * ppl;
	total = to_string(ans);
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
}

void milk::pack()
{
	buffer.erase();
	buffer+=milk_ID+"|"+liters+"|"+price_per_ltr+"|"+total+"|"+day+"-"+mon+"-"+year+"$";
	buffer+="\n";
}

void milk::write()
{
	fstream file;
	file.open("milk.txt",ios::out|ios::app|ios::binary);
	file<<buffer;
	file.close();
}

void milk::unpack()
{
	int i=0;
	milk_ID.erase();
	while(buffer[i]!='|')
		milk_ID+=buffer[i++];

	liters.erase();
	i++;
	while(buffer[i]!='|')
		liters+=buffer[i++];

	
	price_per_ltr.erase();
	i++;
	while(buffer[i]!='|')
		price_per_ltr+=buffer[i++];

	
	total.erase();
	i++;
	while(buffer[i]!='|')
		total+=buffer[i++];

	dy.erase();
	i++;
	while (buffer[i] != '-')
		 dy+= buffer[i++];

	mn.erase();
	i++;
	while (buffer[i] != '-')
		mn += buffer[i++];

	yr.erase();
	i++;
	while (buffer[i] != '$')
		yr += buffer[i++];
}

void milk::display()
{
	fstream file,copy;
	string ch="";
	int i,flag=0;
	system("cls");
	file.open("milk.txt",ios::in|ios::binary);
    // copy.open("temp.txt",ios::out|ios::binary);
	while(!file.eof())
	{
		buffer.erase();
		getline(file,buffer);
		ch=buffer;
		if(ch[0]!='*' && !file.eof())
		{
            flag=1;
			unpack();
			// cout<<ch<<endl;	
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			cout<< "\t\t\t\t\t\t\t\t       MILK ID : " << milk_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t        LITERS : " << liters<<endl;
			cout<< "\t\t\t\t\t\t\t\t   PRICE/LITER : " << price_per_ltr<<endl;
			cout<< "\t\t\t\t\t\t\t\t   TOTAL PRICE : " << total<<endl;
			cout<< "\t\t\t\t\t\t\t\t          DATE : " << dy<<"-"<<mn<<"-"<<yr;
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";		
		}
	}
    if(flag==0)
	{
    // cout<<"No Records About milk\n";
    // remove("milk.txt");
    // rename("temp.txt","milk.txt");
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  No Records About Milk\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
	}
     file.close();
    // copy.close();
}

int milk::search(string key)
{
	int pos=0,flag=0;
	fstream file;
	system("cls");
	file.open("milk.txt",ios::in|ios::binary);
	while(!file.eof())
	{
		buffer.erase();
		pos=file.tellg();
		getline(file,buffer);
		unpack();
		if(key==milk_ID)
		{
			cout << "\n\t\t\t\t\t\t\t       ******** RECORD FOUND ********\n";
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			// cout << "\t\t\t\t\t\t\t\t" << buffer;
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			cout<< "\t\t\t\t\t\t\t\t       MILK ID : " << milk_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t        LITERS : " << liters<<endl;
			cout<< "\t\t\t\t\t\t\t\t   PRICE/LITER : " << price_per_ltr<<endl;
			cout<< "\t\t\t\t\t\t\t\t   TOTAL PRICE : " << total<<endl;
			cout<< "\t\t\t\t\t\t\t\t          DATE : " << dy<<"-"<<mn<<"-"<<yr;
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

int milk::delete_data(string key)
{
	int pos,flag=0;
	fstream file;
	pos=search(key);
	if(pos>=0)
	{
		file.open("milk.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else
	return 0;
}

int milk::modify(string key)
{
	int ch;
	if(delete_data(key))
{
	mmod=true;
	// cout<<"\nWhat to modify:\n1.Milk Collection ID\n2.Liters\n3.Price/Liter\n";
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||     -----  WHAT TO MODIFY -----\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  1. MILK COLLECTION ID   \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  2. LITERS               \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  3. PRICE/LITER          \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  4. EXIT                 \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\tEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: cout << "\n\t\t\t\t\t\t\tMilk Collection ID:";
			cin>>milk_ID;
			break;
		case 2:cout << "\n\t\t\t\t\t\t\tLiters:";
			cin>>ltr;
            ppl = stoi(price_per_ltr);
            ans=ltr*ppl;
            liters=to_string(ltr);
            total=to_string(ans);
			break;
		case 3: cout << "\n\t\t\t\t\t\t\tPrice/Liter:";
			cin>>ppl;
            ltr=stoi(liters);
            ans=ltr*ppl;
            price_per_ltr=to_string(ppl);
            total=to_string(ans);
			break;
		case 4:
			return 0;
		default:
			cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
			break;
	}
	pack();
	write();
}
}

int milk::milkfunction()
{
	int ch,j=0,i,count;
	string key;
	milk m1;
	while(1)
	{
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||     *********  MENU *********\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  1. ADD MILK DETAILS\t\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  2. DELETE MILK DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  3. SEARCH MILK DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  4. MODIFY MILK DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  5. DISPLAY MILK DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  6. EXIT\t\t\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\tEnter your choice : ";
		//cout<<"\nMenu\n1.Add Milk Detail\n2.Delete Milk Detail\n3.Search Milk Detail\n4.Modify milk Detail\n5.Display Milk Details\n6.Ext\n";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				cout<<"\n\t\t\t\t\t\t\tHOW MANY : ";
				cin>>count;
				for(i=0;i<count;i++)
				{
				
					m1.read();
					m1.pack();
					m1.write();
				}
				cout << "\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t||    milk details added Successfully   ||\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t==========================================\n";
				break;
			case 2: cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				cout<<"\n\t\t\t\t\t\t\tENTER THE MILK ID : "; 
				cin>>key;
				j=m1.delete_data(key);
				if(j==1)
				{
					cout<<"\n\t\t\t\t\t\t\t==========================================\n";
                 cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                 cout<<"\n\t\t\t\t\t\t\t||\t      Record Deleted    \t||\n";
                 cout<<"\t\t\t\t\t\t\t||\t\t\t\t\t||";
                 cout<<"\n\t\t\t\t\t\t\t==========================================\n";
				}
					// cout<<"\nRecord deleted\n";
				// else 
				// 	cout<<"\nRecord not deleted\n";
				break;
			case 3: cout << "\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\n\t\t\t\t\t\t\tENTER THE MILK COLLECTION_ID : ";
				cin>>key;
				m1.search(key);
				break;
			case 4: cout << "\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\n\t\t\t\t\t\t\tENTER THE MILK COLLECTION_ID : ";
				cin>>key;
				m1.modify(key);
				if(mmod==true)
				{
					cout<<"\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
					cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
					cout << "\n\t\t\t\t\t\t\t||  Milk details modified Successfully  ||\n";
					cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
					cout << "\n\t\t\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
				}
				break;
			case 5: m1.display();
				break;
			case 6: return 0;
			default:
			cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
			break;
		} 
	}
}