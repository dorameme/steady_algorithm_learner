/*
start:11:00
end:11::29
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 간단 다이나믹프로그래밍 문제 ..실수가 좀있어서 써놨다.
*/

#include <iostream>
using namespace std;
int dp[15][15];
int solve(int a, int b)
{
    if (dp[a][b])
    {
        return dp[a][b];
    }
    for (int i = 1; i <= b; i++)
    {
     // 오답 체크->  return dp[a][b] += solve(a - 1, i); 리턴을 둬서 틀렸었음
        dp[a][b]+=solve(a-1,i);
    }
    return dp[a][b];
}
int main()
{
    int T;
    int k, c;
    cin >> T;
    for (int i = 1; i < 15; i++)
    {
        dp[0][i] = i;
    }

    while (T--)
    {
        cin >> k >> c;
        cout << solve(k, c) << "\n";
    }
}
