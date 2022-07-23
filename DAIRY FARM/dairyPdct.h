#include<string>
using namespace std;

class dairy
{
	public:
	string Product_ID;
	string Product_name;
    int qnt;
    int prce;
    int ttl;
	string Quantity;
	string prdctPrice;
    string TotalPrice;
	string buffer;
	void read();
	void write();
	void pack();
	void unpack();
	void display();
	int delete_data(string);
	int search(string);
	int modify(string);
    int dairyfunction();
};