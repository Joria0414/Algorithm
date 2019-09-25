#include <iostream>
#include<string>
using namespace std;

class place
{
public:
    string name;
    place *next;
    bool ifthere;
    place(string Name)
    {
        name=Name;
        ifthere=false;
        next=NULL;
    }
    void link(place nextt)
    {
        next=&nextt;
    }
    bool operator==(place placee)
    {
        name==placee.name;
    }
};
class pace
{
public:
    place *p1,*p2;
    int price;
    pace(place place1,place place2,int num=0)
    {
        p1=&place1;
        p2=&place2;
        price=num;
    }
    bool operator==(pace pacee)
    {
        if(*p1==*pacee.p1&&*p2==*pacee.p2)
        {
            return true;
        }
        else if(*p2==*pacee.p1&&*p1==*pacee.p2)
        {
            return true;
        }
        else
            return false;
    }
};


int main()
{
    place placelist[5]={place("A"),place("B"),place("C"),place("D"),place("E")};
    pace pacelist[10]={pace(placelist[0],placelist[1],100),pace(placelist[0],placelist[2],105),pace(placelist[0],placelist[3],205),
    pace(placelist[0],placelist[4],55),pace(placelist[1],placelist[2],105),pace(placelist[1],placelist[3],100),
    pace(placelist[1],placelist[4],80),pace(placelist[2],placelist[3],205),pace(placelist[2],placelist[4],400),pace(placelist[3],placelist[4],105)};
    for(int i=0;i<4;i++)
    {
        placelist[i].next=&placelist[i+1];
    }
    place *last=&placelist[0],*then=&placelist[1];
    int wholeprice=0;
    cout<<"路线为："<<last->name;
    last->ifthere=true;
    pace pacenew(*last,*then);
    /*
    if(pacenew==pacelist[0])
        {cout<<"1";}
     for(int i=0;i<10;i++)
     {
         //cout<<"1";
         if(pacenew==pacelist[i])
        {cout<<"1";}
     }
     */
    while(then!=NULL)
    {
        pace pacenew(*last,*then);
        for(int i=0;i<10;i++)
        {
            //cout<<"1";
            if(pacenew==pacelist[i])
            {
                //cout<<"1";
                if(then==pacelist[i].p1)
                {
                    cout<<"-"<<pacelist[i].p1->name;
                    wholeprice+=pacelist[i].price;
                    pacelist[i].p2->ifthere=true;
                    break;
                }
                else
                {

                    cout<<"-"<<pacelist[i].p2->name;
                    wholeprice+=pacelist[i].price;
                    pacelist[i].p1->ifthere=true;
                    break;
                }
            }
        }
        last=then;
        then=then->next;
        while(then!=NULL&&then->ifthere==true)
        {
            then=then->next;
        }
    }
    cout<<endl<<"总费用为："<<wholeprice;
    return 0;
}
