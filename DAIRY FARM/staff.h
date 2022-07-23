#include<string>
using namespace std;
class staff
{
	public:
	string Staff_ID;
	string Staff_name;
	string Designation;
	string Contact;
	string buffer;
	void read();
	void write();
	void pack();
	void unpack();
	void display();
	int delete_data(string);
	int search(string);
	int modify(string);
    int staffFunction();
};