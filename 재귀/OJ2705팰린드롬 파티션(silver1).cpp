/* 
start:11:00
end:12:00
시간복잡도:O(N)
공간복잡도:O(N)
풀이:재귀문제인데 가운데가 0~n까지 오는경우를 모두 고려!
*/


#include <iostream>
using namespace std;
int dp[1001];
int solve(int n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return 1;
    if (dp[n])
        return dp[n];
    for (int i = 0; i < n; i++)
    {
        if (n - i % 2 == 0)
        {
            dp[n] = solve(i) + dp[(n - i / 2)];
        }
        else
        {
            dp[n] = solve(i / 2);
        }
    }
    return dp[n];
}
int main()
{
    int n;

    do
    {
        cin >> n;
        cout << solve(n);
        cout << '\n';
    } while (getc(stdin) == '\n');
}
