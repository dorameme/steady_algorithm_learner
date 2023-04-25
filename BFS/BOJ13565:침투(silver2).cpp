/*
start:20:20
end:20:41
시간복잡도:O(N*M)
공간복잡도:O(N*M)
풀이:BFS로 풀되 행으론 숫자가 1000자리까지 한줄로 들어오므로 string으로 받은뒤 string하나하나가 '1' 인경우만 배열에 1로 표시해준다.
*/#include <iostream>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int arr[1001][1001];
int visit[1001][1001];
int main()
{
    int n, m;
    cin >> n >> m;
    string num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        for (int j = 0; j < m; j++)
        {
            if(num[j]=='1')
            arr[i][j]= 1;
        }
    }
    queue<pair<int, int>> q;

    for (int j = 0; j < m; j++)
    {
        if (arr[0][j] == 0 && visit[0][j] == 0)
            q.push({0, j});
            visit[0][j] = 1;
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int z = 0; z < 4; z++)
            {
                int nx = dx[z] + cur.X;
                int ny = dy[z] + cur.Y;
                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;
                if (visit[nx][ny] || arr[nx][ny])
                    continue;
                if (nx == n - 1)
                {
                    cout << "YES";
                    return 0;
                }
                visit[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }

    cout << "NO";
    return 0;
}
