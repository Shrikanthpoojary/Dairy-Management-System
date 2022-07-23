#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<sstream>
#include<iostream>
#include<string>
#include<cstdio>
#include"dairyPdct.h"
using namespace std;
bool pmod=false;
void dairy::read()
{
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
	cout << "\n\t\t\t\t\t\t\tPRODUCT ID : ";
	cin >> Product_ID;
	cout << "\n\t\t\t\t\t\t\tPRODUCT NAME : ";
	cin >> Product_name;
	cout << "\n\t\t\t\t\t\t\tPRICE : ";
	cin >> prce;
	prdctPrice = to_string(prce);
	cout << "\n\t\t\t\t\t\t\tQUANTITY : ";
	cin >> qnt;
	Quantity = to_string(qnt);
	ttl = prce * qnt;
	TotalPrice = to_string(ttl);
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
}

void dairy::pack()
{
	buffer.erase();
	buffer+=Product_ID+"|"+Product_name+"|"+prdctPrice+"|"+Quantity+"|"+TotalPrice+"$";
	buffer+="\n";
}

void dairy::write()
{
	fstream file;
	file.open("product.txt",ios::out|ios::app|ios::binary);
	file<<buffer;
	file.close();
}

void dairy::unpack()
{
	int i=0;
	Product_ID.erase();
	while(buffer[i]!='|')
		Product_ID+=buffer[i++];

	Product_name.erase();
	i++;
	while(buffer[i]!='|')
		Product_name+=buffer[i++];
	
	prdctPrice.erase();
	i++;
	while(buffer[i]!='|')
		prdctPrice+=buffer[i++];

    Quantity.erase();
	i++;
	while(buffer[i]!='|')
		Quantity+=buffer[i++];

    TotalPrice.erase();
    i++;
    while(buffer[i]!='$')
        TotalPrice+=buffer[i++];
}

void dairy::display()
{
	fstream file,copy;
	string ch="";
	int i,flag=0;
	system("cls");
	file.open("product.txt",ios::in|ios::binary);
    // copy.open("temp.txt",ios::out|ios::binary);
	cout << "\t\t\t\t\t\t\t------------------------------------------\n";
	while(!file.eof())
	{
		buffer.erase();
		getline(file,buffer);
		ch=buffer;
		if(ch[0]!='*' && !file.eof())
		{
            flag=1;
			// cout<<ch<<endl;	
			unpack();		
			cout<< "\t\t\t\t\t\t\t\t    PRODUCT ID : " << Product_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t          NAME : " << Product_name<<endl;
			cout<< "\t\t\t\t\t\t\t\t         PRICE : " << prdctPrice<<endl;
			cout<< "\t\t\t\t\t\t\t\t      QUANTITY : " << Quantity<<endl;
			cout<< "\t\t\t\t\t\t\t\t   Total Price : " << TotalPrice<<endl;
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
		}
	}
	cout << "\t\t\t\t\t\t\t------------------------------------------\n";
    if(flag==0)
	{
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t  No Records About Product\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
	}
    // cout<<"No Records About Product\n";
    // remove("product.txt");
    // rename("temp.txt","product.txt");
     file.close();
    // copy.close();
}

int dairy::search(string key)
{
	int pos=0,flag=0;
	fstream file;
	system("cls");
	file.open("product.txt",ios::in|ios::binary);
	while(!file.eof())
	{
		buffer.erase();
		pos=file.tellg();
		getline(file,buffer);
		unpack();
		if(key==Product_ID)
		{
			cout << "\n\t\t\t\t\t\t\t       ******** RECORD FOUND ********\n";
			cout << "\n\t\t\t\t\t\t\t------------------------------------------\n";
			cout<< "\t\t\t\t\t\t\t\t    PRODUCT ID : " << Product_ID<<endl;
			cout<< "\t\t\t\t\t\t\t\t          NAME : " << Product_name<<endl;
			cout<< "\t\t\t\t\t\t\t\t         PRICE : " << prdctPrice<<endl;
			cout<< "\t\t\t\t\t\t\t\t      QUANTITY : " << Quantity<<endl;
			cout<< "\t\t\t\t\t\t\t\t   Total Price : " << TotalPrice<<endl;
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

int dairy::delete_data(string key)
{
	int pos,flag=0;
	fstream file;
	pos=search(key);
	if(pos>=0)
	{
		file.open("product.txt");
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

int dairy::modify(string key)
{
	int ch;
	if(delete_data(key))
{
	pmod=true;
	// cout<<"\nWhat to modify:\n 1.Product_ID\n2.Product Name\n3.PRICE\n4.Quantity\n";
	cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||     -----  WHAT TO MODIFY -----\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t     1. PRODUCT ID        \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t     2. PRODUCT NAME      \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t     3. PRICE             \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t     4. QUANTITY          \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t     5. EXIT              \t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\tEnter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1: 
				cout << "\n\t\t\t\t\t\t\tPRODUCT_ID : ";
		// cout<<"\nProduct_ID:";
			cin>>Product_ID;
			break;
		case 2: 
		 cout << "\n\t\t\t\t\t\t\tPRODUCT_NAME : ";
		// cout<<"\nProduct Name:";
			cin>>Product_name;
			break;
		case 3: 
			cout << "\n\t\t\t\t\t\t\tPRICE : ";
			// cout<<"\nPRICE:";
			cin>>prce;
            qnt=stoi(Quantity);
            ttl=prce*qnt;
            prdctPrice=to_string(prce);
            TotalPrice=to_string(ttl);
			break;
        case 4: 
			cout << "\n\t\t\t\t\t\t\tQUANTITY : ";
			// cout<<"\nQuantity:";
			cin>>qnt;
            prce=stoi(prdctPrice);
            ttl=prce*qnt;
            Quantity=to_string(qnt);
            TotalPrice=to_string(ttl);
			break;
		case 5:
			return 0;
		default:
			cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
			break;	

	}
	pack();
	write();
}
}

int dairy::dairyfunction()
{
	int ch,i,count;
	string key;
	dairy d1;
	while(1)
	{
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||     *********  MENU *********\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t 1. ADD PRODUCT DETAILS\t\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t 2. DELETE PRODUCT DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t 3. SEARCH PRODUCT DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t 4. MODIFY PRODUCT DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t 5. DISPLAY PRODUCT DETAILS\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t||\t 6. EXIT\t\t\t||\n";
		cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\t==========================================\n";
		cout << "\n\t\t\t\t\t\t\tEnter your choice : ";
		//cout<<"\nMenu\n1.Add Product\n2.Delete Product\n3.Search Product\n4.Modify Product Details\n5.Display \n6.Ext\n";
		cin>>ch;
		switch(ch)
		{
			case 1: 
				cout << "\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\n\t\t\t\t\t\t\tHOW MANY RECORDS : ";
			// cout<<"How many:\n";
				cin>>count;
				for(i=0;i<count;i++)
				{
					d1.read();
					d1.pack();
					d1.write();
				}
				cout << "\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t||\t  Product added Successfully\t||\n";
			cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
			cout << "\n\t\t\t\t\t\t\t==========================================\n";
				break;
			case 2: 
				cout << "\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\n\t\t\t\t\t\t\tENTER THE PRODUCT_ID : ";
				// cout<<"Enter the Product_ID:";
				cin>>key;
				i=d1.delete_data(key);
				if(i==1)
				{
					cout << "\n\t\t\t\t\t\t\t==========================================\n";
				cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
				cout << "\n\t\t\t\t\t\t\t||\t  Product Details Deleted\t||\n";
				cout << "\t\t\t\t\t\t\t||\t\t\t\t\t||";
				cout << "\n\t\t\t\t\t\t\t==========================================\n";
				}
					// cout<<"\nRecord deleted\n";
				break;
			case 3: 
				cout << "\n\t\t\t\t\t\t\t==========================================\n";
				cout << "\n\t\t\t\t\t\t\tENTER THE PRODUCT_ID : ";
			// cout<<"Enter the Product_ID:";
				cin>>key;
				d1.search(key);
				break;
			case 4: 
				cout << "\n\t\t\t\t\t\t\t==========================================\n";
			cout << "\n\t\t\t\t\t\t\tENTER THE PRODUCT_ID : ";
			// cout<<"Enter the Product_ID:";
				cin>>key;
				d1.modify(key);
				if(pmod==true)
				{
					cout<<"\n\t\t\t\t\t\t\t>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
					cout << "\t\t\t\t\t\t\t||\t\t\t\t\t  ||";
					cout << "\n\t\t\t\t\t\t\t||  Product details modified Successfully ||\n";
					cout << "\t\t\t\t\t\t\t||\t\t\t\t\t  ||";
					cout << "\n\t\t\t\t\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n";
				}
				break;
			case 5: d1.display();
				break;
			case 6: return 0;
			default:
				cout << "\n\t\t\t\t\t\t\t       ******** WRONG CHOICE ********\n";
			// cout<<"wrong choice\n";
			break;
		} 
	}
}