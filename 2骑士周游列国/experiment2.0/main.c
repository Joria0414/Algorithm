#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define MAX 8
int table[MAX][MAX]={0};
void travel(int table[MAX][MAX],int i,int x,int y);


int main()
{
    int m,n,i=0,j=0;
    printf("«Î ‰»Î∆Ô øŒª÷√£®m<8,n<8)£∫");
    scanf("%d%d",&m,&n);
    table[m][n]=1;
    travel(table,2,m,n);
    for(;i<8;i++)
    {
        for(;j<8;j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    return 0;
}
void travel(int table[MAX][MAX],int i,int x,int y)
{
    int p,q,m,n,t;
    if(i<MAX*MAX+1)
    {
        m=x;
        n=y;
        for(q=-2;q<3;q++)
        {
            if(q!=0)
            {
                x=m+q;
                t=3-abs(q);
                //printf("1 ");
            }
            else
                continue;
            for(p=0;p<2;p++)
            {
                t=(-1)*t;
                y=n+t;
                if(x<0||y<0||x>=MAX||y>=MAX)
                    continue;
                if(table[x][y]==0)
                {
                    table[x][y]=i;
                    travel(table,i+1,x,y);
                    if(i!=64)
                        table[x][y]=0;
                    else
                        return;
                }
            }
        }
    }
}
