/*
start:13:41
end:15:41
시간복잡도:N^3
공간복잡도:N^2
풀이:플로이드워셜 역추적기법을 사용
초기화조건때문에 고전하였다
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int N;
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
int road[101][101];
int mid[101][101];
void route(vector<int> &helper, int start, int end)
{
    if (mid[start][end] == 0 )
    {
        helper.push_back(start);
        helper.push_back(end);
    }
    else
    {
        route(helper,start, mid[start][end]);/////중간까지가는동안도 빠른길이있는지본다.
        helper.pop_back();
        route(helper, mid[start][end], end);////중간부터 끝까지도 마찬가지
    }
}
int main()
{
    int n, m, a, b, c;
    cin >> n >> m;
    for (int x = 1; x < 101; x++)
    {
        for (int y = 1; y < 101; y++)
        {
            mid[x][y] = 0;
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
        if (road[a][b] > c)
            road[a][b] = c;
    }
    // vetor <vector <int>> middle[n+1];
    // vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            for (int z = 1; z <= n; z++)
            {
                if (road[y][z] > road[y][x] + road[x][z])
                {
                    mid[y][z] = x;
                }
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
            //      cout<<"mid "<<mid[x][y]<<"\n";
        }
        cout << "\n";
    }
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            if (road[x][y] == 987654321||road[x][y]==0)
            {
                cout << 0 << "\n";
                continue;
            }
            if (mid[x][y] == 0)
            {
                cout << 2 << " " << x << " " << y << "\n";
                continue;
            }
            vector<int> helper;
            route(helper, x, y);
            cout << helper.size() << " ";
            for (int r : helper)
            {
                cout << r << " ";
                
            }
            cout << "\n";
            helper.clear();
        }
    }
}
