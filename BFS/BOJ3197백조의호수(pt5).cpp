/*
start:11:15
end:15:16
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이:중간중간 검사하지말고! 내생각에 일단 vis배열로 다 물로바뀌는 시간기록하고 그다음에 최소날짜로 vis 배열로 서로 닿는날짜 계산한다!
이가정까진맞았는데 내가 bfs로 시간줄인방법 알려드림.
그냥 큐가아니라 우선순위큐써서 최대한 작은 경로로 움직이게함!!! 이게 정말 중요했는데 오름차순으로 바꿔줘야할걸 내림차순(기본 디폴트값)으로 풀어서 자꾸틀렸음
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#define X first
#define Y second
using namespace std;
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int answer = 987654321;
queue<pair<pair<int, int>, int>> q;
priority_queue< pair<int, pair<int, int>> , vector <pair<int, pair<int, int>>> , greater<pair<int, pair<int, int>>> > b;
vector<pair<int, int>> bird;

string MAP[1501];
int vis[1501][1501];
int visB[1501][1501];

void canReach()
{
    int answer = 987654321;
    visB[bird[0].X][bird[0].Y] = 1;
    b.push({0, bird[0]});
    while (!b.empty())
    {
        pair<int, pair<int, int>> cur = b.top();
        b.pop();
        if (cur.Y == bird[1] && cur.X < answer)
        {
            answer = cur.X;
            cout << answer << "\n";
            return ;
        } // 답나옴..
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.Y.X + dx[i];
            int ny = cur.Y.Y + dy[i];
            if (nx < 0 || ny < 0 || ny >= m || nx >= n)
                continue;
            if (visB[nx][ny] )
                continue; // 방문해봄?...
            visB[nx][ny]=1;
            b.push({max(cur.X, vis[nx][ny]), {nx, ny}});
            
        }
    }
    cout << answer;
}
void BFS()
{
    while (!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X.X + dx[i];
            int ny = cur.X.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (MAP[nx][ny] == 'X' && vis[nx][ny] == 0)
            {
                vis[nx][ny] = cur.Y + 1;
                q.push(make_pair(make_pair(nx, ny), cur.Y + 1));
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> MAP[i]; ////입력을 전부받은후 계산해줘야지! 아니면 실수할수이음
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (MAP[i][j] == 'L')
            {
                bird.push_back(make_pair(i, j));
            }
            if (MAP[i][j] == 'X' && vis[i][j] == 0)
            {
                for (int z = 0; z < 4; z++)
                {
                    int nx = dx[z] + i;
                    int ny = dy[z] + j;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                        continue;
                    if (MAP[nx][ny] == '.' || MAP[nx][ny] == 'L') // 하나라도..주변이 물이거나 백조면..
                    {
                        vis[i][j] = 1;
                        q.push(make_pair(make_pair(i, j), 1));
                        break;
                    }
                }
            }
        }
    }
    BFS();
    canReach();
}
