/*
start:16:01
end:16:25
시간복잡도:O(N)
공간복잡도:O(N)
풀이:bfs로 풀어주되 페어로 이동횟수와 위치를 담고 다닌다.
*/
#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int vis[10000001];
int main()
{
    int a, b;
    cin >> a >> b;
    queue<pair<int, int>> q;
    q.push({a, 0});
    int answer = 987654321;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        // cout << cur.X << " " << cur.Y << "\n";
        q.pop();
        if (cur.X == b)
        {
            if (answer > cur.Y)
                answer = cur.Y;
            break;
        }
        if (cur.X * 2 <= 100000 && vis[cur.X * 2]==0)
        {
            q.push({cur.X * 2, cur.Y});
            vis[cur.X * 2] = 1;
        }
        if (cur.X - 1 >= 0 && vis[cur.X - 1]==0)
        {
            q.push({cur.X - 1, cur.Y + 1});
            vis[cur.X - 1] = 1;
        }
        if (cur.X + 1 <= 100000 && vis[cur.X + 1]==0)
        {
            q.push({cur.X + 1, cur.Y + 1});
            vis[cur.X + 1] = 1;
        }
    }
    cout << answer;
}
