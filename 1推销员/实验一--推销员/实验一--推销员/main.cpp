#include <stdio.h>
#define Max 10

int cost[Max][Max];
int city[Max] = {-1};
int ans[Max] = {-1};
int mincost = 1000000;
bool Check (int x, int y, int city[]);
void dfs (int x, int cost[][Max], int city[], int ans[], int n);
void compared (int city[], int ans[], int cost[][Max], int& mincost, int n);

int main()
{
    int n, i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            cost[i][j] = 100000;
        }
    }
    printf("请输入城市数(<10):");
    scanf("%d",&n);
    printf("请输入价格矩阵\n");
    for (i=0; i<n; i++)
    {
        for (j=i; j<n; j++)
        {
            scanf("%d", &cost[i][j]);
            cost[j][i] = cost[i][j];
        }
    }
    printf("价格矩阵为:\n");
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%d ",cost[i][j]);
        }
        printf("\n");
    }
    dfs(0, cost, city, ans, n);
    printf("最优解为:");
    for (i=0; i<n; i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n最少花费为:%d",mincost);
    return 0;
}

bool Check (int x, int y, int city[])
{
    for (int i=0; i<x; i++)
    {
        if((y-city[i])==0) return false;
    }
    return true;
}

void dfs (int x, int cost[][Max], int city[], int ans[], int n)
{
    if(x==n)
    {
        compared(city, ans, cost, mincost, n);
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(Check(x,i,city))
            {
                city[x]=i;
                dfs(x+1, cost, city, ans, n);
                city[x]=-1;
            }
        }
    }
}

void compared (int city[], int ans[], int cost[][Max], int& mincost, int n)
{
    int sumcost=0;
    for (int i=0; i<n-1; i++)
    {
        sumcost += cost[city[i]][city[i+1]];
    }
    if( sumcost < mincost)
    {
        mincost = sumcost;
        for (int i=0; i<n; i++)
        {
            ans[i] = city[i];
        }
    }
}

