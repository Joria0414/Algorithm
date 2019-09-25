#include <iostream>

using namespace std;
const int N = 8;    //棋盘边长
int chessboard [N][N]={0};  //二维数组表示棋盘

bool Move (int x, int y, int step);
int main()
{
    int x, y, i, j;
    cout << "请输入起始位置(x,y):";
    cin >> x >> y;
    if(Move(x, y, 0))
    {
        for (i=0; i<N; i++)
        {
            for (j=0; j<N; j++)
            {
                cout.width(3);
                cout << chessboard[i][j] <<" ";
            }
            cout << endl;
        }
    }
    else
        cout <<"此起点没有解！";
    return 0;
}

 bool Move (int x, int y, int step)
 {
     if (step==64)   //走完了
     {
         return true;
     }
     if (x<0 || x>N-1 || y<0 || y>N-1)  //越界
     {
         return false;
     }
     if (chessboard[x][y]!=0)   //已被访问
     {
         return false;
     }
     step++;
     chessboard[x][y] = step;
     //八个方向依次试探
     if(Move(x+1, y+2, step)) return true;
     if(Move(x+1, y-2, step)) return true;
     if(Move(x+2, y+1, step)) return true;
     if(Move(x+2, y-1, step)) return true;
     if(Move(x-1, y+2, step)) return true;
     if(Move(x-1, y-2, step)) return true;
     if(Move(x-2, y+1, step)) return true;
     if(Move(x-2, y-1, step)) return true;
     //全部不可行
     chessboard[x][y]=0;
     return false;
 }
