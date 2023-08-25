/*
start:14:51
end:3시간걸림;
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이: 좀 특이한게... 위아래를 한번에 다 탐색해줘야했다!!! ㅜㅜㅜ너무어려워서 답지참고함;
*/
#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#define X first
#define Y second
using namespace std;

// dp=이동가능칸수.. 영향을 미치는건 현재좌표 어차피 bfs 로 구하면 L,R몇번이 거기로 이동가능한최소인지 알수있음 + 근데 방법이 여러개일수 있잖아 ;
int MAP[1001][1001];
int vis[1001][1001];
int N, M;
int L, R;
int x, y;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int answer = 0;
void bfs()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push(make_pair(make_pair(x, y), make_pair(L, R)));
    MAP[x][y] = 0;
    
    while (!q.empty())
    {
        pair<pair<int, int>, pair<int, int>> cur = q.front();
        q.pop();
        if (MAP[cur.X.X][cur.X.Y] == 1)
            continue;
        if(vis[cur.X.X][cur.X.Y]) continue;
        vis[cur.X.X][cur.X.Y]=1;
        answer++;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X.X + dx[i];
            int ny = cur.X.Y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) // 경로이탈
                continue;
            if (MAP[nx][ny] == 1) // 벽
                continue;
            if (i == 0 || i == 1)
            {
                for (int j = 0; j < N; j++)
                {
                    int nnx =nx+ dx[i]* j;
                    if (nnx < 0 || ny < 0 || nnx >= N || ny >= M) // 경로이탈
                      continue;
                    if (MAP[nnx][ny] == 1)break;
                    q.push(make_pair(make_pair(nnx, ny), make_pair(cur.Y.X, cur.Y.Y)));
                }
                for (int j = 0; j < N; j++)
                {
                    int nnx =nx+ dx[i]* j;
                    if (nnx < 0 || ny < 0 || nnx >= N || ny >= M) // 경로이탈
                      continue;
                    if (MAP[nnx][ny] == 1)break;
                    q.push(make_pair(make_pair(nnx, ny), make_pair(cur.Y.X, cur.Y.Y)));
                }
            }
            if (i == 3) //&& cur.Y.Y > 0)
            {

        if(vis[nx][ny]==1)continue;
                if (cur.Y.Y <= 0)
                    continue;
                q.push(make_pair(make_pair(nx, ny), make_pair(cur.Y.X, cur.Y.Y - 1)));
            }
            if (i == 2)
            {

        if(vis[nx][ny]==1)continue;
                if (cur.Y.X <= 0)
                    continue;
                q.push(make_pair(make_pair(nx, ny), make_pair(cur.Y.X - 1, cur.Y.Y)));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    cin >> L >> R;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            MAP[i][j] = s[j] - '0';
            if (MAP[i][j] == 2)
            {
                x = i;
                y = j;
            }
        }
    }
    bfs();
    cout << answer;
}
