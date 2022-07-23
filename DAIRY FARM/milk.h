#include<string>
#include<ctime>
using namespace std;
class milk
{
	public:
	string milk_ID;
    int ltr;
    string liters;
    int ppl;
    string price_per_ltr;
    int ans;
    string total;
    string dy,mn,yr;
	string buffer;
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::string day = to_string(now->tm_mday);
    std::string mon = to_string((now->tm_mon + 1));
    std::string year = to_string((now->tm_year + 1900) );
	void read();
	void write();
	void pack();
	void unpack();
	void display();
	int delete_data(string);
	int search(string);
	int modify(string);
    int milkfunction();
};