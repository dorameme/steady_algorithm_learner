/*
start:16:54
end:17:13
시간복잡도:O(N*N)
공간복잡도:O(N*N)
풀이:평범한 bfs문제인데 후처리가 좀 필요했다. bfs로 각 섬을 다른 인덱스로 표현해준뒤,
좀 독특하게 풀었는데 각 섬 i의 둘레를 다 v[i]에다가 저장해서 섬마다 둘레에서 가장 가까운곳을 비교해줬다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int m[101][101];
vector<pair<int, int>> v[100000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> m[i][j];
        }
    }
    int cnt = 0;
    int island = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (m[i][j] == 1)
            {
                cnt--;
                island++; // 섬의 번호
                queue<pair<int, int>> q;
                q.push({i, j});
                m[i][j] = cnt;
                while (!q.empty())
                {
                    int visit[101][101] = {
                        0,
                    };
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int z = 0; z < 4; z++)
                    {
                        int nx = dx[z] + cur.X;
                        int ny = dy[z] + cur.Y;
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (m[nx][ny] == 0 && visit[nx][ny] == 0)
                        {
                            visit[nx][ny] = 1;
                            v[island].push_back({nx, ny});
                        }
                        if (m[nx][ny] != 1)
                            continue;
                        m[nx][ny] = cnt;
                        q.push({nx, ny});
                    }
                }
            }
        }
    } 
    int answer = 9874321;
    for (int i = 0; i <= island; i++)
    {
        for (auto v1 : v[i])
        {
            for (int j = i + 1; j <= island; j++)
                for (auto v2 : v[j])
                {
                    if (v1.X != v2.X && v1.Y != v2.Y)
                    {
                        if (abs(v1.X - v2.X) + abs(v1.Y - v2.Y) < answer)
                        {
                            cout << v1.X << v1.Y << " " << v2.X << v2.Y << "\n";
                            answer = abs(v1.X - v2.X) + abs(v1.Y - v2.Y);
                        }
                    }
                }
        }
        cout << answer;
    }
