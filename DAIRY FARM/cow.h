#include<string>
using namespace std;
class cow
{
	public:
	string Cow_ID;
	string Breed;
	string Status;
	string Amount;
	string buffer;
	void read();
	void write();
	void pack();
	void unpack();
	void display();
	int delete_data(string);
	int search(string);
	int modify(string);
    int cowfunction();
};

