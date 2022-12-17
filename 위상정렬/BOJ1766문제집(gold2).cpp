/*
start:23:11
end:1:15(2시간풀고 답을 봄)
시간복잡도:O(V+E)
공간복잡도:O(V+E)
풀이: 위상정렬+ priority queue 를 활용한 문제.. 내가 왜틀렸는지는 계속고민하다 2시간 이후
답을 참고하였다. 더 깔끔하니 보기좋다. priority queue 에서 계속 숫자가 낮은가 맨앞으로 오니까 그냥 바로 프린트해주면 된다.
*/
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int main(void)
{
    int N;
    int M;
    cin >> N >> M;
    vector<int> adj[32002];
    int sub1, sub2;
    vector<int> deg(32002);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < M; i++)
    {
        cin >> sub1 >> sub2;
        adj[sub1].push_back(sub2); // sub2를 들으려면 sub1을 들어야해
        // indegree 표시
        deg[sub2]++;
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        if (deg[i] == 0)
        {
            pq.push(i); // 낮은숫자부터!들어감..
        }
    }
    while (!pq.empty())
    {
        int cur = pq.top(); // 번호 순서 그룹
        pq.pop();
        cout<<cur<<" ";
        for (int i = 0; i < adj[cur].size(); i++)
        {
            deg[adj[cur][i]]--;
            if (deg[adj[cur][i]] == 0) // 번호
            {
                pq.push(adj[cur][i]);
            }
        }
    }
}
