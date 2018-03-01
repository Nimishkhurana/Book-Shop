#include<vector>
#include <iostream>
using namespace std;

class Books
{
    vector <string> title;
    vector <string> author;
    vector <int> edition;
    vector <int> isbn_no;
    vector <float> price;
    vector <int> qty;
    string password;
    int Calcprice(int);
public:
    void setpass(){password="bookshop";}
    void UpdateStock();
    void Buy();
    string getpass();
    void Displaybook(int);
    void DisplayStock();


};
