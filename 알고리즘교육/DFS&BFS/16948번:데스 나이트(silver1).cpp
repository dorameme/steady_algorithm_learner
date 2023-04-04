/*
start:16:50
end:17:02
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단하게 최단거리이므로 bfs풀어준다. 근데 visit 으로 표시해줘야 중복으로 안들어가는거 주의!!
*/
#include <queue>
#include <iostream>
#define X first
#define Y second
int dx[] = {-2, -2, 0, 0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int visit[201][201];
using namespace std;
int n;
int main()
{
    cin >> n;
    int rx, cx, ry, cy;
    cin >> rx >> cx >> ry >> cy;
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(rx, cx), 0));
    visit[rx][cx] = 1;
    while (!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = cur.X.X+dx[i];
            int ny = cur.X.Y+dy[i];
            int num = cur.Y;
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (visit[nx][ny])
                continue;   
            if (nx == ry && ny == cy)
            {
                cout << num + 1;
                return 0;
            }
            else
            {
                q.push(make_pair(make_pair(nx, ny), num + 1));
                visit[nx][ny] = 1;
            }
        }
    }cout<<-1;
}
