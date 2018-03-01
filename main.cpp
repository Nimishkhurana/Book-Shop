#include <iostream>
#include "class.h"
#include<vector>


using namespace std;

int main()
{
    Books B;
    string pas;
    B.setpass();
    int a;
    do
    {
        cout<<"\n1.Update the Stock\n2.Buy Books\n3.View Stock\n0.Exit\n";
        cin>>a;
        switch(a)
        {
        case 1:
            cout<<"You need owner permission for updating stock.\nEnter password : ";
            cin>>pas;
            if(pas == B.getpass())
               {
                   cout<<"Successfully logged in\n";
                   B.UpdateStock();
               }
            else
                cout<<"\nWrong password\nTry again\n";
            break;
        case 2:
            B.Buy();
            break;
        case 3:
            B.DisplayStock();
            break;
        case 0:
            break;
        default:
            cout<<"Invalid input\n";

        }
    }while(a!=0);
    return 0;
}
