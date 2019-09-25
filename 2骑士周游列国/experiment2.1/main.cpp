#include <iostream>
#include<stdio.h>
using namespace std;
int N=8;
int chess[100][100];
int ans[100][100];
int x[8]={-2,-1,1,2,2,1,-1,-2};
int y[8]={-1,-2,-2,-1,1,2,2,1};
int flag = 0;

int getnum(int m,int n)
{
    int num = 0;
     for(int k = 0;k < 8;k++){
            if(chess[m+x[k]][n+y[k]]==0&&m+x[k]>=1&&m+x[k]<=N&&n+y[k]>=1&&n+y[k]<=N){
                num++;
            }
        }
    return num;
}

int update(int m,int n)
{
    int minroad = 10000;
    int minnum = 10000;
    int k;
    for(k = 0;k < 8;k++){
            if(chess[m+x[k]][n+y[k]]==0&&m+x[k]>=1&&m+x[k]<=N&&n+y[k]>=1&&n+y[k]<=N){
                if(getnum(m+x[k],n+y[k]) < minroad){
                    minroad = getnum(m+x[k],n+y[k]);
                    minnum = k;
                }
            }
        }
    return minnum;
}

int main()
{
    int m,n,m1,n1;
    int j = 1;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
        chess[i][j] = 0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<N*N;i++)
    {
        chess[m][n] = j;
        int temp = update(m,n);
        m += x[temp];
        n += y[temp];
        j++;
        if(j == 63){
            m1=m;n1=n;
        }
    }
    for(int k = 0;k < 8;k++){
            if(chess[m1+x[k]][n1+y[k]]==0&&m1+x[k]>=1&&m1+x[k]<=N&&n1+y[k]>=1&&n1+y[k]<=N){
                chess[m1+x[k]][n1+y[k]]=64;
            }
        }
    for(int i=1;i<=N;i++){
        for(int k=1;k<=N;k++){
            printf("%3d",chess[i][k]);
        }
        printf("\n");
    }
    return 0;
}
