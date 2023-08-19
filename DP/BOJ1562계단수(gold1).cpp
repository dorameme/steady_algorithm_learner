/*
start:7:00
end:7:54
시간복잡도:O(N) 왜냐면,,, dp[10][N][1<<10] 으로 고정임..
공간복잡도:O(N)
풀이: 역시나 비트마스킹으로 풀수있었음 왜냐면 있다vs없다 두가지만 존재하므로.. 근데 3차원 dp 라는게 헷갈렸음.. ㅠㅠ 
중요한것은 분석! 일단 필수적으로 마지막 숫자를 알아야 다음에 +/- 의기준을 세울수 있고
몇자리인지 필요하고
또 10자리 모두 사용되었는지 알아야함 그래서 3차원임 ㅇㅇ
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define MAX 11
using namespace std;
int dp[10][101][1 << 10];

int N, B;
long long solve(int last, int State, int cnt)
{
    if (cnt == N)
    {
        if (State == (1 << 10) - 1)
        {
            return 1;
        }
        else
            return 0;
    }
    if (dp[last][cnt][State])
    {
        return dp[last][cnt][State];
    }
    else
    {
        if (last < 9)
            dp[last][cnt][State]+= solve(last+1, State | (1 << (last+1)), cnt + 1);
        dp[last][cnt][State]%=1000000000;
        if (last > 0)
            dp[last][cnt][State]+= solve(last-1, State |(1 << (last-1)), cnt + 1);
        dp[last][cnt][State]%=1000000000;
       
    }
    return dp[last][cnt][State];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    long long answer = 0;
    for (int i = 1; i <= 9; i++)
    {
        answer += solve(i, (1 << i), 1);
        answer %= 1000000000;
    }
    cout << answer;
    return 0;
}
