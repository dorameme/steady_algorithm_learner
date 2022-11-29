
/*
시작:12:00
종료:2:27 (밥먹고오느라.. 아마 한 1시간정도 구현한듯 하다.)
시간복잡도:O(1)//최대 10번 시도가능
시간복잡도:O(1)//최대 10번 시도가능
공간복잡도:O(row*col)
풀이: 골드1의 구현문제였다.
좀 어려웠던게 고려해야할 예외사항이 꽤나 많았다 ㅠㅠ
예외사항이 많았던거 뺴면 그다지 구현이 어렵진않다.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#define X first
#define Y second
using namespace std;
int answer = -1;
int row, col;
int visit[11][11];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<string> board(11);
pair<int, int> roll(int x, int y, int i)
{
    int nx = x;
    int ny = y;
    while (1)
    {
        nx += dx[i];
        ny += dy[i];
        if (nx >= 0 && ny >= 0 && nx < row && ny < col)
        {
            if (board[nx][ny] == '.'||board[nx][ny]=='B'||board[nx][ny]=='R')
            {
                continue;
            }
            else if (board[nx][ny] == 'O')
            {
                return make_pair(-1, -1);
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
    return make_pair(nx - dx[i], ny - dy[i]);
}
void solve(int rX, int rY, int bX, int bY, int cnt)
{
    
    if (cnt == 10)
    {
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {

            pair<int, int> curB = roll(bX, bY, i);
            pair<int, int> curR = roll(rX, rY, i);
            if (curB == make_pair(-1, -1))
            {
                continue;
            }
            if (curR == make_pair(-1, -1))
            {
                board[rX][rY] = '.';
                if (curB == make_pair(-1, -1))
                {
                    board[rX][rY] = 'R';
                    continue;
                }
                board[rX][rY] = 'R';
                if (answer == -1 || answer > cnt + 1)
                {
                    answer = cnt + 1;
                }
                return;

            }
            if(curB==curR){
                if(i==0&&rY>bY){curR.Y+=1;}
                if(i==0&&rY<bY){curB.Y+=1;}
                if(i==1&&rY>bY){curB.Y-=1;}
                if(i==1&&rY<bY){curR.Y-=1;}
                if(i==2&&rX<bX){curB.X+=1;}
                if(i==2&&rX>bX){curR.X+=1;}
                if(i==3&&rX<bX){curR.X-=1;}
                if(i==3&&rX>bX){curB.X-=1;}
            }
            board[rX][rY] = '.';
            board[bX][bY] = '.';
            board[curR.X][curR.Y] = 'R';
            board[curB.X][curB.Y] = 'B';
            solve(curR.X, curR.Y, curB.X, curB.Y, cnt + 1);
            board[curR.X][curR.Y] = '.';
            board[curB.X][curB.Y] = '.';
            board[rX][rY] = 'R';
            board[bX][bY] = 'B';//이거 순서도 중요함!!!! 만일 '.'을 넣는걸 뒤에 두면 구슬이 사라질 수도 있다.
        }
    }
    return;
}
int main()
{
    cin >> row >> col;
    for (int x = 0; x < row; x++)
    {
        cin >> board[x];
    }
    int rX = 0, rY = 0, bX = 0, bY = 0;
    for (int x = 0; x < row; x++)
    {
        for (int y = 0; y < col; y++)
        {
            if (board[x][y] == 'R')
            {
                rX = x;
                rY = y;
            }
            if (board[x][y] == 'B')
            {
                bX = x;
                bY = y;
            }
        }
    }
    solve(rX, rY, bX, bY, 0);
    cout << answer;
}
