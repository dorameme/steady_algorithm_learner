/*
start:15:20
end:16:06
시간복잡도:O(N*N)
공간복잡도:O(N*N)
풀이:엄~청 헤멧다 근데 좀 이런문제들에 해결방법에 대한윤곽이 잡히는것같다.
항상느끼지만 최소로 도착하는거 풀려면 그냥 우선순위큐+BFS로 풀면된다. 초큼 문제가 지저분하긴하지만

            if(dp[nx][ny].Y<=MAX && dp[nx][ny].X>=MIN ) -> 즉 최대 최소가 더 늘어나는 경우를 제외해주고 풀면 된다!
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
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int N;
int answer = 987654321;
pair<int,int> dp[101][101]; // 이전번호 지금번호
int MAP[101][101];
pair<int,int> visit[101][101];
void BFS()
{
    priority_queue<pair<int, pair<pair<int, int>, pair<int, int>>>,
                   vector<pair<int, pair<pair<int, int>, pair<int, int>>>>,
                   greater<pair<int, pair<pair<int, int>, pair<int, int>>>>>
        pq;
    pq.push(make_pair(0, make_pair(make_pair(MAP[0][0], MAP[0][0]), make_pair(0, 0)))); //
    dp[0][0] = make_pair(MAP[0][0],MAP[0][0]);
    // visit[0][0]=make_pair(MAP[0][0],MAP[0][0]);
    while (!pq.empty())
    {
        pair<int, pair<pair<int, int>, pair<int, int>>> cur = pq.top();
        if (cur.Y.Y.X == cur.Y.Y.Y && cur.Y.Y.Y == N - 1)
        {
            cout <<-cur.Y.X.X+cur.Y.X.Y<<"\n" ;
            return ;
        }
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.Y.Y.X + dx[i];
            int ny = cur.Y.Y.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            int MAX = max(cur.Y.X.Y,MAP[nx][ny]);
            int MIN = min(cur.Y.X.X,MAP[nx][ny]);
            int new_val=MAX-MIN;
            if(dp[nx][ny].Y<=MAX && dp[nx][ny].X>=MIN )
                continue;
            dp[nx][ny] =make_pair(MIN,MAX);
            pq.push(make_pair(new_val, make_pair(make_pair(MIN, MAX), make_pair(nx, ny)))); //
    }
    }
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dp[i][j]={-1,987654321};
            cin >> MAP[i][j];
        }
    }
    BFS();
}
