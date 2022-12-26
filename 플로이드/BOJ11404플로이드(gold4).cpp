/*
start:13:35
end:13:42
시간복잡도:O(n^3)
공간복잡도:O(n^2)
풀이:플로이드 알고리즘으로 쉽게 풀리는 문제다.
3번의 for문을 통해 해결가능하다
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int board[22][22];
int visit[22][22];
int N;
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    int road[101][101];
    for (int x = 1; x < 101; x++)
    {
        for (int y =1; y < 101; y++)
        {
            if (x == y)
            {
                road[x][y] = 0;
                continue;
            }
            road[x][y] = 987654321;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        if(road[a][b]>c)road[a][b] = c;
    }

    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int z = 1; z <= n; z++)
            {
                road[y][z] = min(road[y][z], road[y][x] + road[x][z]);
            }
        }
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (road[x][y] == 987654321)
            {
                cout << 0 << " ";
                continue;
            }
            cout << road[x][y] << " ";
        }cout<<"\n";
    }
}
