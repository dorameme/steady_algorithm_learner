/*
start:17:00
end:17:38
시간복잡도:O(NM)
공간복잡도:O(NM)_
풀이: bfs 문제였는데 x좌표,y좌표,이동횟수,가진 key 가 같은 애들은 맵에다 저장해서 중복을 막았다
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, M;                // 크기
int x, y;                // 시작
int destx, desty;        // 목적지
char arr[100][100];      // 배열
pair<int, int> key[300]; // 키의 위치
int keyCnt;              // 키의 수
char keyHave[300];
pair<int, int> vis[100][100];
int answer = -1;
map < pair < pair<int, int>,  int >, int > m;
int num(char a)
{
    if (a == 'a' || a == 'A')
    {
        return 1;
    }
    else if (a == 'b' || a == 'B')
    {
        return 10;
    }
    else if (a == 'c' || a == 'C')
    {
        return 100;
    }
    else if (a == 'd' || a == 'D')
    {
        return 1000;
    }
    else if (a == 'e' || a == 'E')
    {
        return 10000;
    }
    else if (a == 'f' || a == 'F')
    {
        return 100000;
    }
    return 0;
}
bool canGo(int x, int y, int y2)
{
    auto item = m.find({{x, y}, y2});
    if (item != m.end())
        return false;
    else
        m[{{x, y},y2}]=1;
        return true;
}

void findroute()
{
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{x, y}, {0, 0}});
    m[{{x,y},0}]=1;
    while (!q.empty())
    {
        pair<pair<int, int>, pair<int, int>> cur = q.front(); // 위치 위치 걸은 수
        q.pop();
        m[{{cur.X.X, cur.X.Y},  cur.Y.Y}]++;
        // cout << cur.X.X << " " << cur.X.Y << " " << cur.Y.X << " " << cur.Y.Y << "\n";
        if (answer != -1 && answer < cur.Y.X)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.X.X + dx[i];
            int ny = cur.X.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue; // index out
            if (arr[nx][ny] == '1')
            { // 목적지 도착
                if (answer == -1 || answer > cur.Y.X + 1)
                    answer = cur.Y.X + 1;
                break;
            }
            // 이렇게 하자 방문은 5번까지 가능한데 그러려면 키의 수가 더 늘어나야됨.
            if (arr[nx][ny] == '#' || canGo(nx, ny,  cur.Y.Y) == false)
            {
                /// 방문한적은 더 큰데 열쇠는 더 적으면...
                continue; // 벽이거나 방문기록이 너무 많으면...cut
            }
            if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'F') /// door
            {
                if ((cur.Y.Y / num(arr[nx][ny])) % 10 == 0) /// 키가 없으면
                    continue;
                else
                {
                    q.push({{nx, ny}, {cur.Y.X + 1, cur.Y.Y}});
                    // m[{{x,y},{cur.Y.X+1,cur.Y.Y}}]++;
                    continue;
                }
            }
            if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'f')
            {
                int flag = (cur.Y.Y / num(arr[nx][ny])) % 10;
                if (flag == 0)
                { // 나한테 없던 거...
                    // cout<<cur.Y.Y + num(arr[nx][ny])<<" here\n";
                    q.push({{nx, ny}, {cur.Y.X + 1, cur.Y.Y + num(arr[nx][ny])}});
                    // m[{{x,y},{cur.Y.X+1,cur.Y.Y + num(arr[nx][ny])}}]++;
                }
                else
                {
                    q.push({{nx, ny}, {cur.Y.X + 1, cur.Y.Y}});
                    // m[{{x,y},{cur.Y.X+1,cur.Y.Y}}]++;
                }
                continue;
            }
            if (arr[nx][ny] == '0' || arr[nx][ny] == '.')
            {
                q.push({{nx, ny}, {cur.Y.X + 1, cur.Y.Y}});
                // m[{{x,y},{cur.Y.X+1,cur.Y.Y}}]++;
                continue;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int n = 0; n < M; n++)
        {
            arr[i][n] = s[n];
            if (arr[i][n] == '0')
            {
                x = i, y = n;
            }
            if (arr[i][n] == '1')
            {
                destx = i, desty = n;
            }
            if (arr[i][n] >= 'a' && arr[i][n] <= 'f')
            {
                keyCnt++;
                key[arr[i][n]] = make_pair(i, n);
            }
        }
    }
    findroute(); // 과정상 필요한 열쇠를 찾는다.
    cout << answer;
}
