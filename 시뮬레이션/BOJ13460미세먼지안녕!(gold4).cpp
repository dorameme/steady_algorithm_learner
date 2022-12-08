
/*
start:18:00
end:20:00
시간복잡도:O(R*C*T)
공간복잡도:O(R*C)
풀이:그냥 좀 노가다...ㅋㅋ 어렵진않음 근데 헷갈림! 

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define X first
#define Y second
using namespace std;
int R, C, T;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int air1 = -1, air2 = -1;
int board[51][51];
void diffuse()
{

    queue<pair<pair<int, int>,int>> q;
    for (int i = 0; i < R; i++)
    {
        for (int m = 0; m < C; m++)
        {
            if (board[i][m] >= 5)
            {
                q.push({{i, m},board[i][m]});
            }
        }
    }
    while (!q.empty())
    {
        pair<pair<int,int >,int>cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx=cur.X.X+dx[i];
            int ny=cur.X.Y+dy[i];
            if(nx<0||ny<0||ny>=C||nx>=R||(nx==air1&&ny==0)||(nx==air2&&ny==0))continue;
            board[nx][ny]+=cur.Y/5;
            board[cur.X.X][cur.X.Y]-=cur.Y/5;
        }
    }
}

void clean()
{
    int dirt1 = board[0][0];
    int dirt2= board[air1][C - 1];
    int dirt3 = board[air2][C - 1];
    int dirt4 = board[R-1][0];
 //   cout<<dirt4<<"d3";
    for (int i = 0; i + 1 < C; i++)
    {
        board[0][i] = board[0][i + 1];
        board[R - 1][i] = board[R - 1][i + 1];
    }
    for (int i = C - 1; i > 0; i--)
    {
        board[air1][i] = board[air1][i - 1]; // r
        board[air2][i] = board[air2][i - 1]; // r
    }
    for (int i = air1 - 1; i > 1; i--)
    {
        board[i][0] = board[i - 1][0];
    }
    for (int i = 0; i < air1 - 1; i++)
    {
        board[i][C - 1] = board[i + 1][C - 1];
    }
    for (int i = air2 + 1; i< R-2; i++)
    {
        board[i][0] = board[i + 1][0];
    }
    for (int i = R - 1; i > air2; i--)
    {
        board[i][C - 1] = board[i - 1][C - 1];
    }
    board[1][0] = dirt1;
    board[air1-1][C-1] = dirt2;
    board[air2+1][C - 1] = dirt3;
    if(R-2>=0&&R-2!=air2)
    board[R-2][0] = dirt4;
    board[air1][1]=0;
    board[air2][1]=0;
    board[air1][0]=board[air2][0]=-1;
}
int main()
{
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
    {
        for (int m = 0; m < C; m++)
        {
            cin >> board[i][m];
            if (air1 == -1 && board[i][m] == -1)
            {
                air1 = i;
                air2 = i + 1;
            }
        }
    }
    while (T--)
    {
        diffuse();
        clean();
    }
    int answer=0;
        for (int i = 0; i < R; i++)
        {
            for (int m = 0; m < C; m++)
            {
                answer+=board[i][m];
          //      cout << board[i][m]<<" ";
            }
        //    cout << "\n";
        }
       // cout << "\n";
        cout<<answer+2;
}
