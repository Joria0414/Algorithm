#include <iostream>
#include<cstring>

using namespace std;

class city
{
public:
    bool arrive=false;
    string name;
    string next;
    city(string Name,string Next)
    {
        name=Name;
        next=Next;
    }
    operator ==(city &b)
    {
        name=b.name;
    }
};

class pace
{
public:
    int price;
    string place1,place2;
    pace(int num,string p1,string p2)
    {
        price=num;
        place1=p1;
        place2=p2;
    }
};

int main()
{
    //city a(A,B),b(B,C),c(C,D),d(D,E),e(E,A);
    //city citylist[5]={a,b,c,d,e};
    city citylist[5]={city("A","C"),city("B","A"),city("C","D"),city("D","E"),city("E","B")};
    pace pacelist[10]={pace(10,"A","B"),pace(20,"A","C"),pace(30,"A","D"),pace(40,"A","E"),pace(20,"B","C"),pace(40,"B","D"),pace(30,"B","E"),pace(10,"C","D"),pace(10,"C","E"),pace(20,"D","E")};
    int wholeprice=0;
    city *last=&citylist[0],*next=NULL;
    for(int i=0;i<5;i++)
    {
        if(last->next==citylist[i].name)
        {
            next=&citylist[i];
        }
    }
    cout<<"Â·ÏßÎª£º"<<last->name;
    last->arrive=true;
    for(int i=0;i<10;i++)
        {
            if((pacelist[i].place1==last->name&&pacelist[i].place2==next->name)||(pacelist[i].place2==last->name&&pacelist[i].place1==next->name))
            {
                wholeprice+=pacelist[i].price;
                cout<<"-"<<next->name;
                break;
            }
        }
    for(int i=0;i<5;i++)
    {
        if(placelist[i].name==next->name)
        {
            last=&placelist[i];

        }
    }
    while(last->name!="A")
    {
        cout<<"a";
        for(int i=0;i<10;i++)
        {
            if((pacelist[i].place1==last->name&&pacelist[i].place2==next->name)||(pacelist[i].place2==last->name&&pacelist[i].place1==next->name))
            {
                wholeprice+=pacelist[i].price;
                cout<<"-"<<next->name;
                break;
            }
        }
        break;

    }
    return 0;
}
