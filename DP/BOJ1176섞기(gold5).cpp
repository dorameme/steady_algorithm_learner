/*
start:14:53
end:15:46
시간복잡도:O(2^N*N)
공간복잡도:O(2^N*N)
풀이:비트필드를 이용한 dp기본문제
내가 구하는건 최댓값이 아닌 경우의수이므로 max 함수는 쓸필요없다...전부더해주자!
배열의 합이 int 범위를 넘어갈 수 있단것도 주의 (함수 리턴값을 int 로 두어서 자꾸 틀렸었다;;)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
long long N, K;
long long dp[1 << 17][17];
long long MAP[17];
long long solve(long long cnt, long long state, long long last)
{
    if (cnt == N)
        return 1;
    if (dp[state][last])
        return dp[state][last];
    for (int i = 0; i < N; i++)
    {
        if ((state & (1 << i)) == 0 && abs(MAP[last] - MAP[i]) > K)
        {
                dp[state][last] += solve(cnt + 1, (state | (1 << i)), i);
         }
    }
    return dp[state][last];
}
int main()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> MAP[i];
    }

    long long answer=0;
    for (int i = 0; i < N; i++)
    {
        answer+= solve(1, 1<<i, i);
    }
    cout<<answer;
}
