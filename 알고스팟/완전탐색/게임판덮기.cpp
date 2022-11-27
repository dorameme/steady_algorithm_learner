/*
시간복잡도:O(4^m)
공간복잡도:O(NM) 판의 크기만큼 공간를 차지한다.
풀이:완전탐색은 보통 O(N^m)의 시간복잡도를 가진다. N은 선택의 가지수, m은 선택해야 하는 수이다.
여기서 N=4, m=16이다. (m = 흰색 칸 수 // 3이며, 흰색 칸 수는 3으로 나누어 떨어져야 한다) 2*32은 아주 큰 수라서 불가능할 것 같지만
현실적으로는 이것보다 아주 작다.왜냐하면 블록을 쌓으면서 밑이나 오른쪽을 방해하기 때문이다.
그래서 이 문제를 완전탐색으로 풀 수 있다.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int cnt;
int answer;
int dx[] = {0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1};
int dy[] = {0, 1, 1, 0, 0, 1, 0, 1, 0, 0, -1, 0};

bool can_put(int x, int y, vector<string> &board, int num)/////위치에 넣을 수 있는 블록이 있는가
{
    for (int i = num; i < num + 3; i++)
    {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size())
            return false;
        if (board[nx][ny] != '.')
            return false;
    }
    return true;
}
void make_board(int x, int y, vector<string> &board)//불록을 넣어 판을 완성시키자!
{
    if (cnt <= 0)
        return;
    for (int i = 0; i < 12; i += 3)
    {
        if (can_put(x, y, board, i))
        {
            board[x + dx[i]][y + dy[i]] = board[x + dx[i + 1]][y + dy[i + 1]] = board[x + dx[i + 2]][y + dy[i + 2]] = '#';
            cnt -= 3;
            if (cnt == 0)
            {
                answer++;
            }
            bool done = false;
            for (int X = x; X < board.size(); X++)
            {
                if (done)
                    break;
                for (int Y = 0; Y < board[0].size(); Y++)
                {
                    if (board[X][Y] == '.')
                    {
                        (make_board(X, Y, board));
                        break;
                    }
                }
            }
            board[x + dx[i]][y + dy[i]] = board[x + dx[i + 1]][y + dy[i + 1]] = board[x + dx[i + 2]][y + dy[i + 2]] = '.';
            cnt += 3;
        }
    }
    return;
}

int main()
{
    int C;
    cin >> C;
    while (C--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        cnt = 0;
        answer=0;
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            for (int x = 0; x < m; x++)
            {
                if (s[i][x] == '.')
                    cnt++;
            }
        }
        bool done = false;
        for (int x = 0; x < n; x++)
        {
            if (done || cnt == 0)
                break;
            for (int y = 0; y < m; y++)
            {
                if (s[x][y] == '.')
                {
                    make_board(x, y, s);
                    cout<<answer << "\n";
                    done = true;
                    break;
                }
            }
        }
    }
}


/*
시간복잡도:O(4^m)
공간복잡도:O(NM) 판의 크기만큼 공간를 차지한다.
풀이:완전탐색은 보통 O(N^m)의 시간복잡도를 가진다. N은 선택의 가지수, m은 선택해야 하는 수이다.
여기서 N=4, m=16이다. (m = 흰색 칸 수 // 3이며, 흰색 칸 수는 3으로 나누어 떨어져야 한다) 2*32은 아주 큰 수라서 불가능할 것 같지만
현실적으로는 이것보다 아주 작다.왜냐하면 블록을 쌓으면서 밑이나 오른쪽을 방해하기 때문이다.
그래서 이 문제를 완전탐색으로 풀 수 있다.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;
int cnt;
int answer;
const int coverType[4][3][2] = {
    {{0, 0}, {1, 0}, {0, 1}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}}};
bool set(vector<vector<int>> &board, int y, int x, int type, int delta)
{ // y=row x=column
    bool ok = true;
    for (int i = 0; i < 3; i++)
    {
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size())
            ok = false;
        if ((board[ny][nx] += delta) > 1)
            ok = false;
        // false 라 해서 바로 리턴하지 않는 이유는 판에 놓을지
        //없을지 여부를 판단하는것 외에 놓을 수 있을때 놓거나 다시 원래대로 복구하는 역할도 이함수가 하기때문
    }
    return ok;
}
int cover(vector<vector<int>> &board)
{
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0)
            {
                y = i;
                x = j;
                break;
            }
            if (y != -1)
                break;
        }
    }
    if (y != -1)
        return 1;
    int ret = 0;
    for (int type = 0; type < 4; type++)
    {
        if (set(board, y, x, type, 1)) /// true라면..
            ret += cover(board);       //재귀
        set(board,y,x,type,-1);
    }
    return ret;
}
