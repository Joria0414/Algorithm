#include <stdio.h>
#include <stdlib.h>
int mincost=1000000;
//int MAX=10;
#define MAX 10
int city[MAX]={0};
int citylist[MAX]={0};
int newroad[MAX]={0};
int citycost[MAX][MAX]={0};
void travel(int x,int n,int i,int cost,int *mincostt,int *city,int *citylist,int *newroad); //n��ʾ��������i��ʾ����
int newroad[MAX];
int main()
{
    int n,t;
    int i,j,x,y;
    printf("��������еĸ�����");
    scanf("%d",&n);
    printf("��������м۸����:");
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            scanf("%d",&citycost[i][j]);
            citycost[j][i]=citycost[i][j];
            }
    }
    printf("���м۸����Ϊ:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",citycost[i][j]);
            }
            printf("\n");
    }
    travel(0,n,0,0,&mincost,city,citylist,newroad);
    printf("\n����·��Ϊ��%d ",newroad[n-1]);
    for(t=0;t<n;t++)
    {
        printf("%d ",newroad[t]);
    }
    printf("\n����Ϊ��%d",mincost);
    return 0;
}

void travel(int x,int n,int i,int cost,int *mincostt,int *city,int *citylist,int *newroad)
{
    int j,t,m,nn,q,d;
    if(i<n)
    {
         for(j=0;j<n;j++)
    {
        m=cost;
        nn=city[j];
        q=citylist[i];
        if(i==0)
        {
            city[j]=1;
            citylist[i]=j;
            cost=0;
            citylist[i]=j;
            travel(j,n,i+1,cost,mincostt,city,citylist,newroad);
        }
        else if(city[j]==0&&j!=x)
        {
            cost=cost+citycost[x][j];
            city[j]=1;
            citylist[i]=j;
            if(i==(n-1))
            {
                d=citylist[0];
                cost=cost+citycost[j][d];
                if(cost<mincost)
            {
                mincost=cost;
                for(t=0;t<n;t++)
                {
                    newroad[t]=citylist[t];
                }
            }
            }
            travel(j,n,i+1,cost,mincostt,city,citylist,newroad);
        }
        cost=m;
        city[j]=nn;
        citylist[i]=q;
    }
    }
}
