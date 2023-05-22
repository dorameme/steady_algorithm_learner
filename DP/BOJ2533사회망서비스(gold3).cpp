/*
start:10:30
end:12:00
시간복잡도:O(N)
공간복잡도:O(N)
풀이:dp로 푸는 문제였는데 재귀로 타고내려가서 제일 끝에있는 자식들부터 dp값을 차곡 차곡 쌓아올라가 푸는 문제였다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1000001][2];
int vis[1000001];
int N;
int a, b;
vector<int> v[1000001];
int deep;
void solve(int num)
{
    vis[num] = 1;
    dp[num][1] = 1;
    for (int i = 0; i < v[num].size(); i++)
    {
        if (vis[v[num][i]])
            continue;
        solve(v[num][i]);
        dp[num][0]+= dp[v[num][i]][1];
        dp[num][1]+=min(dp[v[num][i]][0],dp[v[num][i]][1]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    N--;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    solve(1);
    cout << min(dp[1][0], dp[1][1]);
}
