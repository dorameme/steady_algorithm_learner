//내풀이가 우연히 맞았는데 n==3 일때 대칭타일수가 왜 2개인지 나도 모르겠다 ;
#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
long long na = 1000000007;
int C;
long long dp[101];///대칭 타일 수
long long dp2[101];//모든 타일수 
long long solve(int n)
{
    if(n<0)return 0;
    if(n<=1)return 1;
    if(n==2)return 2;
    if(n==3)return 2;
    long long &ret = dp[n];
    if (ret != -1)
        return dp[n];
    return ret = (solve(n - 4)+ solve(n - 2))%na;
}
long long solve2(int n)
{
    if(n<=1)return 1;
    long long &ret = dp2[n];
    if (ret != -1)
        return dp2[n];
    return ret = (solve2(n - 2) + solve2(n - 1))%na;
}
int main()
{
    for (int i = 0; i < 101; i++)
        dp[i] =dp2[i]= -1;
    int C;
    cin >> C;
    int n;
    
    while (C--)
    {
        cin >> n;
        cout<<(solve2(n)-solve(n)+na)%na<<"\n";//빼줄 때는 나눠지는 값을 한번 더해주므로써 음수로 가는걸 막는다 
    }
}


//책 풀이
#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
long long na = 1000000007;
int C;
long long dp[101];///대칭 타일 수
long long solve(int n)
{
    if(n<=1)return 1;
    long long &ret = dp[n];
    if (ret != -1)
        return dp[n];
    return ret = (solve(n - 2) + solve(n - 1))%na;
}
long long answer(int n)
{
    if(n%2==1){return (solve(n)-solve(n/2)+na)%na;}
    else return (solve(n)-solve(n/2-1)-solve(n/2)+2*na)%na;
}
int main()
{
    for (int i = 0; i < 101; i++)
        dp[i]= -1;
    int C;
    cin >> C;
    int n;
    while (C--)
    {
        cin >> n;
        cout<<answer(n)<<"\n";
    }
}
