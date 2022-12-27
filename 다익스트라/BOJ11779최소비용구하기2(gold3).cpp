/*
start:12:00
end:13:21
시간복잡도:O(ElgE)
공간복잡도:O(VE)
풀이: 다익스트라로 푸는데 역추적으로 현재 노드에올려면 어디를 거쳐와야하는지를 표시해줘야했고 메모리가 빡세서 44번째 줄에 <=가 아닌 <로 해서 계속 틀렸었다
최대한 연산을 줄이자
*/


#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int v, e,st;
const int INF = 0x3f3f3f3f;
int d[1005]; // 최단거리테이블
int pre[1005];
vector<pair<int, int>> adj[1005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e ; // 정점수 간선수 시작지점
    fill(d, d + v + 1, INF);
    while (e--)
    {
        int u, v, w;
        cin>>u>>v>>w;
        adj[u].push_back({w, v}); // 거리 정점
    }
    int st,en;
    cin>>st>>en;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d[st]=0;
    pq.push({d[st], st});
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (d[cur.Y] != cur.X)continue;
        for (auto nxt : adj[cur.Y])
        { // 현재 정점에서 연결된 애들
            if (d[nxt.Y] <= nxt.X + d[cur.Y])continue; // 현재 정점에서 연결된 애들 거쳐서 가는게 더 느리면 컨틴뉴
            d[nxt.Y] = nxt.X + d[cur.Y];
            pq.push({d[nxt.Y], nxt.Y});
            pre[nxt.Y]=cur.Y;
        }
    }
     cout << d[en] << '\n';
  vector<int> path;
  int cur = en;
  while(cur != st){
    path.push_back(cur);
    cur = pre[cur];
  }
  path.push_back(cur);
  reverse(path.begin(), path.end());
  cout << path.size() << '\n';
  for(auto x : path) cout << x << ' ';
}
