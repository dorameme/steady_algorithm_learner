/*
start:20:30
end:21:12
시간복잡도: O(N)
공간복잡도:O(N)
풀이: 시간초과가 좀났는데 dp를 계속 초기화해주어서그랬다. dp는 매 테스트케이스마다 재활용이 가능하다.
*/
#include <iostream>
using namespace std;
long long dp[100001][4];
long long answer;
long long solve(int n, int back)
{
    if (n == 0)
    {
        return 1;
    }
    if (dp[n][back]!=0)
    {
        return dp[n][back];
    }
    if (back != 1 && n - 1 >= 0)
    {
        dp[n][back] += solve(n - 1, 1)%1000000009 ;
    }
     if (back != 2 && n - 2 >= 0)
    {
        dp[n][back] += solve(n - 2, 2)%1000000009 ;
    }
    if (back != 3 && n - 3 >= 0)
    {
        dp[n][back] += solve(n - 3, 3)%1000000009 ;
    }
    return dp[n][back]%1000000009;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        answer = 0;
        // for (int i = 0; i <= n; i++)
        // {
        //     for(int j=1;j<=3;j++)
        //         dp[i][j] = 0;
        // }
        cout << solve(n,0) << "\n";
    }
}
