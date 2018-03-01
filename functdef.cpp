#include "class.h"
#include <iostream>
#include<vector>

using namespace std;
string Books::getpass()
{
    return(password);
}
void Books::UpdateStock()
    {
        char ch='y';
        cout<<"\nEnter books to update stock :-\n";
        while(ch=='y')
        {
        string t,a;
        int e,isbn,q,i;
        float p;
        cout<<"\nTitle :";
        cin>>ws;
        getline(cin,t);

        cout<<"Author :";
        cin>>ws;
        getline(cin,a);

        cout<<"Edition :";
        cin>>ws;
        cin>>e;

        cout<<"Isbn no.";
        cin>>ws;
        cin>>isbn;

        cout<<"Price :";
        cin>>ws;
        cin>>p;

        cout<<"Quantity :";
        cin>>q;
        for(i=0;i<title.size();i++)
          if(title[i]==t && author[i]==a && edition[i]==e)
          {
              cout<<"Book was present already...stock updated .\n";
              qty[i]+=q;
              break;
          }
        if(i==title.size())
        {
        title.push_back(t);
        author.push_back(a);
        edition.push_back(e);
        isbn_no.push_back(isbn);
        price.push_back(p);
        qty.push_back(q);
        }
        cout<<"Do you want to add another book [y/n] : ";
        cin>>ch;
        }
    }
    void Books::Buy()
    {
        int i,k,pricetemp = 0;
        string auth,titl;
        char ch='y';
        cout<<"\n\n\n";
        while(ch == 'y')
        {
        cout<<"\n\nEnter details of book which you want to buy :-\n";
        cout<<"Enter Book Title: ";
        cin>>ws;
        getline(cin,titl);
        cout<<"Enter Book Author : ";
        cin>>ws;
        getline(cin,auth);
        for(i=0;i<title.size();i++)
        {
            if(titl==title[i] && auth==author[i])
            {
                cout<<"Book found:-\n";
                Displaybook(i);
                pricetemp+= Calcprice(i);
                break;
            }
        }
        if(i==title.size())
            cout<<"\nBook not found\n";
        cout<<endl;
         for(k=0;k<10;k++)
            cout<<"__";
        cout<<"\nDo you want to continue shopping [y/n] :";
        cin>>ch;
        }
        cout<<"\t\t\t";
        for(k=0;k<20;k++)
            cout<<"__";

        cout<<"\n\n\t\t\t\tGRAND TOTAL = Rs."<<pricetemp<<endl;
        cout<<"\n\t\t\t\tThanks for visiting !!\n\n\n";
        //bug here
    }
    void Books::Displaybook(int ind)
    {
        cout<<"\nTitle:"<<title[ind]<<endl;
        cout<<"Author:"<<author[ind]<<endl;
        cout<<"ISBN No. :"<<isbn_no[ind]<<endl;
        cout<<"Edition :"<<edition[ind]<<endl;
        cout<<"Price :"<<price[ind]<<endl;
        cout<<"Available pieces :"<<qty[ind]<<endl;

    }
    int Books ::Calcprice(int ind)
    {
        int no;
        char ch;
        int total=0;
        cout<<"\nEnter no. of pieces you want to buy :-";
        cin>>no;
        if(no>qty[ind])
        {
            cout<<"Sorry, Only "<<qty[ind]<< " pieces are available\nWill you like to buy available no. of pieces[y/n] :";
            cin>>ch;
            if(ch=='y')
            {
                total = price[ind]*qty[ind];
                cout<<"Your order is being processed....\nTotal : "<<price[ind] <<" * "<<qty[ind]<<" = "<<price[ind]*qty[ind];
                qty[ind]=0;
            }
            else
                cout<<"Hope to serve you again !!\n";

        }
        else
        {
            total = price[ind]*no;
            cout<<"Your order is being processed....\nTotal: "<<price[ind] <<"* "<<no<<" ="<<price[ind]*no;
            qty[ind]-=no;
        }
        return(total);
    }
    void Books::DisplayStock()
    {
        int ind;
        cout<<"\n\n\nUpdated Stock :-\n\n";
        for(ind=0;ind<title.size();ind++)
        {
        cout<<"\n\n"<<ind+1<<".Title:"<<title[ind]<<endl;
        cout<<"  Author:"<<author[ind]<<endl;
        cout<<"  ISBN No. :"<<isbn_no[ind]<<endl;
        cout<<"  Edition :"<<edition[ind]<<endl;
        cout<<"  Price :"<<price[ind]<<endl;
        cout<<"  Available pieces :"<<qty[ind]<<endl;
        }
    }
