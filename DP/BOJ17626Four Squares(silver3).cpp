/*
start:14:10
end:14:47
시간복잡도:O(N)
공간복잡도:O(N)
풀이:큰 제곱수부터 채워나가면서 dp배열을 만들었다! 어차피 많이 돌아봤자 중복은 제거되므로 N숫자의 답은 N번만 돌리면 된다.
*/
#include <iostream>
using namespace std;
int dp[1000001];
int n;
int i;
bool answer = 0;
void solve(int num, int cnt)
{
    if (dp[num] != 0 && dp[num] <= cnt)
    {
        return;
    }
    dp[num] = cnt;
    if (num >=n)
    {
        return;
    }
    for (int u = i; u * u >= 1; u--)
    { 
        solve(u * u+num, cnt+1);
    }
}
int main()
{
    cin >> n;
    for (i = 1; i * i < n; i++);
  
    for(int u=i;u*u>=1;u--){
        solve(u*u,1);
    }
    cout << dp[n];
}
