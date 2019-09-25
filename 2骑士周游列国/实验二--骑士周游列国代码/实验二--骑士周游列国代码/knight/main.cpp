#include <iostream>

using namespace std;
const int N = 8;    //���̱߳�
int chessboard [N][N]={0};  //��ά�����ʾ����

bool Move (int x, int y, int step);
int main()
{
    int x, y, i, j;
    cout << "��������ʼλ��(x,y):";
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
        cout <<"�����û�н⣡";
    return 0;
}

 bool Move (int x, int y, int step)
 {
     if (step==64)   //������
     {
         return true;
     }
     if (x<0 || x>N-1 || y<0 || y>N-1)  //Խ��
     {
         return false;
     }
     if (chessboard[x][y]!=0)   //�ѱ�����
     {
         return false;
     }
     step++;
     chessboard[x][y] = step;
     //�˸�����������̽
     if(Move(x+1, y+2, step)) return true;
     if(Move(x+1, y-2, step)) return true;
     if(Move(x+2, y+1, step)) return true;
     if(Move(x+2, y-1, step)) return true;
     if(Move(x-1, y+2, step)) return true;
     if(Move(x-1, y-2, step)) return true;
     if(Move(x-2, y+1, step)) return true;
     if(Move(x-2, y-1, step)) return true;
     //ȫ��������
     chessboard[x][y]=0;
     return false;
 }
