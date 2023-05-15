/*
start:8:58
end:9:40
시간복잡도:O(N*M)
공간복잡도:O(N*M)
풀이:dfs 로 풀었는데 dfs는 최단거리를 보장해주지않는다 따라서 이문제에서는 vis배열을 쓸 수 없었다.

*/
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
string board[22];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int answer = 11;
vector<pair<int, int> > ball;
int vis[22][22][22][22];
int n, m;
string s;
bool getOut(int x, int y)
{
    if (x >= n || y >= m || x < 0 || y < 0)
        return true;
    return false;
}
int canGo(int x, int y) // 판을 벗어남 1 벽임 2 갈 수 있음 3
{
    if (getOut(x, y))
        return 1; // 순서주의
    if (board[x][y] == '#')
        return 2;
    return 3;
}

void bfs(int x1, int y1, int x2, int y2, int cnt)
{
    // vis[x1][y1][x2][y2] = 1;
    if (cnt > 10)
        return;
    if (cnt > answer)
        return;
    for (int i = 0; i < 4; i++)
    {
        int nx1 = x1 + dx[i];
        int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i];
        int ny2 = y2 + dy[i];
        if (canGo(nx1, ny1) == 1 && canGo(nx2, ny2) == 1)
        {
            continue;
        }
        else if(canGo(nx1, ny1) == 1||canGo(nx2,ny2)==1){

            if (cnt + 1 < answer)
                answer = cnt + 1;
        }
        else 
        {
            if(canGo(nx1,ny1)==2){
                nx1=x1;
                ny1=y1;
            }
            if(canGo(nx2,ny2)==2){
                nx2=x2;
                ny2=y2;
            }
            // if (vis[nx1][ny1][nx2][ny2])
            //     continue;
            bfs(nx1, ny1, nx2, ny2, cnt + 1);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'o')
            {
                ball.push_back(make_pair(i, j));
            }
        }
    }
    // vis[ball[0].X][ball[0].Y][ball[1].X][ball[1].Y] = 1;
    bfs(ball[0].X, ball[0].Y, ball[1].X, ball[1].Y, 0);
    if (answer > 10)
        cout << -1;
    else
        cout << answer;
}
