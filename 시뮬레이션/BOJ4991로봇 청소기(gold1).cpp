/*
start:13:00
end:16:30
시간복잡도:O(N*M)
공간복잡도:O(N*M)
풀이: 구현문제인데 진짜 엄청 어려웠다; 대략 3시간30분걸림 ㅠ
 쓰레기하나하나 마다 bfs를 해주어 거기를 계산한뒤 또다시 solve라는 함수내에서 dfs돌려서 풀었다.. ㄷ ㄷ 이렇게 티어높은 문제는 어떻게 풀지 정리하고 푸는게 매우 중요하다 
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int N, M;
vector<string> v;
int x, y;
int cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int answer = 987654321;
int vis[30][30][11] = {
    0,
};
vector<pair<int, int>> dust;
int used[11];
void solve(int idx, int s, int e, int D, int total)
{ // idx는 현재위치
    // cout<<"\n"<<idx<<"idx\n";
    if (cnt == D)
    {
        if (total < answer)
            answer = total;
        return;
    }
    for (int i = 0; i < dust.size(); i++)
    { // 0~dustsize
        if (used[i] == 0)
        {
            used[i] = 1;
            // cout<<"s"<<s<<"e"<<e<<" "<<dust[i].X<<" :"<<dust[i].Y<<" total:"<<total<<" vis:"<<vis[s][e][i]
            // <<" dust:"<<D+1<<"\n";
            solve(i, dust[i].X, dust[i].Y, D + 1, total + vis[s][e][i]);
            used[i] = 0;
        }
    }
}
void clean(int i)
{

    queue<pair<int, int>> q;
    int x = dust[i].X;
    int y = dust[i].Y;
    q.push({x, y});
    vis[x][y][i] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int a = 0; a < 4; a++)
        {
            int nx = dx[a] + cur.X;
            int ny = dy[a] + cur.Y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (vis[nx][ny][i] || v[nx][ny] == 'x')
                continue; // 4일 수도 있음.
            vis[nx][ny][i] = vis[cur.X][cur.Y][i] + 1;
            q.push({nx, ny}); // x,y,dust,walk
        }
    }
}
int canGo()
{
    int counting = 0;
    int helper[21][21]={0,};
    queue<pair<int, int>> help;
    help.push({x, y});
    helper[x][y] = 1;
    while (!help.empty())
    {
        pair<int, int> cur = help.front();
        help.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (helper[nx][ny] == 1 || v[nx][ny] == 'x')
                continue;
            helper[nx][ny] = 1;
            if (v[nx][ny] == '*')
                counting++;
            help.push({nx, ny});
        }
    }
    // cout<<counting<<cnt<<"\n";
    return counting == cnt;
}
int main()
{
    while (1)
    {
        answer = 987654321;
        cnt = 0;
        v.clear();
        cin >> M >> N;
        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                for (int k = 0; k < 11; k++)
                {
                    vis[i][j][k] = 0;
                }
            }
        }
        if (M == 0)
            return 0;
        string s;
        dust.clear();
        int k = 1;
        for (int i = 0; i < N; i++)
        {
            cin >> s;
            v.push_back(s);

            for (int m = 0; m < M; m++)
            {
                if (v[i][m] == 'o')
                {
                    x = i, y = m;
                }
                if (v[i][m] == '*')
                {

                    dust.push_back({i, m});
                    cnt++;
                }
            }
        }
        if (!canGo())
        {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < dust.size(); i++)
        {
            clean(i);
        }
        solve(-1, x, y, 0, 0);
        if (cnt == 0)
        {
            cout << 0 << "\n";
        }
        else if (answer == 0)
        {
            cout << -1 << "\n";
        }
        else
            cout << answer - cnt << "\n";
    }
}
