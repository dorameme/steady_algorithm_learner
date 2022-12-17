/*
start:22:48
end: 23:00
시간복잡도:O(V+E)
공간복잡도:O(V+E)-> 그래프관계를 모두 나타내므로 안나타내고 indegree만 이용하면 V
풀이: deg벡터에 indegree를 저장해두고 간단하게 위상정렬을 이용해 풀어주면 된다. 넘나 쉽기에 따로할말이없다
전형적인 위상정렬문제!
*/
#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int main(void)
{
    int N; int M;
    cin >> N >> M;
    queue<pair<int,int>> q;
    vector<int> adj[N + 1];
    int sub1, sub2;
    vector<int> deg(N + 1);
    vector<int> answer(N + 1);
    int cnt = 1;
    for (int i = 0; i < M; i++)
    {
        cin >> sub1 >> sub2;
        adj[sub1].push_back(sub2); // sub2를 들으려면 sub1을 들어야해
        //indegree 표시
        deg[sub2]++;
    }
    for (int i = 1; i <= N; i++)
    {
        if (deg[i] == 0)
        {
            q.push({i,1});
            answer[i] = 1;
        }
    }
    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur.X].size(); i++)
        {
            deg[adj[cur.X][i]]--;
            if (deg[adj[cur.X][i]] == 0)
            {
                q.push({adj[cur.X][i],cur.Y+1});
                answer[adj[cur.X][i]] = cur.Y+1;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout<<answer[i]<<" ";
    }
}
