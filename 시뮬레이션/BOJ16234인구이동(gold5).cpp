/*
start:17:30
end18:27
시간복잡도:O(N^4)//bfs로 모든구간을 돌렸다....따라서 N*N*N*N
공간복잡도:O(N*N)
풀이:단순 구현문제인데 개인적으로 좀 빡셌다 특별한 알고리즘없이 구현해주면 된다.아 아니네 bfs 도 사용된다.
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int arr[51][51];
int visit[51][51];
int N, L, R;
int solve()
{
    int answer = 0;
    int cnt = 0;
    queue<pair<pair<int, int>, int> > q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (visit[i][j])
            {
                continue;
            }
            q.push(make_pair(make_pair(i, j), ++cnt));
            while (!q.empty())
            {
                int x = q.front().first.first;
                int y = q.front().first.second;
                int cur = q.front().second;
                visit[x][y] = cur;
                q.pop();
                for (int z = 0; z < 4; z++)
                {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                        continue;
                    if (visit[nx][ny])
                        continue;
                    if (abs(arr[nx][ny] - arr[x][y]) <= R && abs(arr[nx][ny] - arr[x][y]) >= L)
                    {
                        visit[nx][ny] = cur;
                        q.push(make_pair(make_pair(nx, ny), cur));
                        answer = 1;
                    }
                }
            }
        }
    }
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < N; j++)
    //     {
    //         cout << visit[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cnt = 1;
    vector<pair<int, int> > v[2501];
    int total[2501] = {
        0,
    };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            v[visit[i][j]].push_back(make_pair(i, j));
            total[visit[i][j]] += arr[i][j];
        }
    }
    for (int x = 0; x < 2501; x++)
    {
        for (int i = 0; i < (int)v[x].size(); i++)
        {
            arr[v[x][i].first][v[x][i].second] = total[x] / v[x].size();
        }
    }
    return answer;
}

int main()
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    int answer = 0;
    while (solve())
    { // 인구이동시 1 아닐시 0 반환
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                visit[i][j] = 0;
            }
        }
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < N; j++)
        //     {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        answer++;
    }
    cout << answer;
}
