/*
start:17:00
end:17:39
시간복잡도:O(N)
공간복잡도:O(N)
풀이:dp문제인데 vis을 처~음 solve를 돌릴때 vis[루트]=1 과정을 까먹어서 틀렸었다!!
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int dp[100001];
vector<int> nodes[100001];
int vis[100001];
int64_t solve(int n)
{
    if (dp[n]!=1)
    {
        return dp[n];
    }
    for (int i = 0; i < nodes[n].size(); i++)
    {
        if (vis[nodes[n][i]])
            continue;
        vis[nodes[n][i]] = 1;
        dp[n] += solve(nodes[n][i]);
    }
    return dp[n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, R, Q;
    int a, b;
    cin >> N >> R >> Q;
    for(int i=1;i<=N;i++)dp[i]=1;
    for (int i = 0; i < N-1; i++)
    {
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    vis[R]=1;
    solve(R);
    int start;
    for (int i = 0; i < Q; i++)
    {
        cin >> start;
        cout <<dp[start] << "\n";
    }
}
