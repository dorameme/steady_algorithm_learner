/*
start:12:56
end:14:16
시간복잡도:O(1<<N)
공간복잡도:O(1<<N)
풀이: 비트필드를 이용한 다이나믹 프로그래밍인데 if()조건문에서 == 라 써야하는데 = 라고 써서 틀렸음;
*/

#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define INF 987654321
using namespace std;
int answer=INF;
int MAP[16][16];
int N, P;
int dp[1 << 16]; // state
int solve(int state, int cnt)
{
    if (cnt >= P)
    {
        return 0;
    }
    if (dp[state] != -1)
    {
        return dp[state];
    }
    dp[state] = INF;
    for (int i = 0; i < N; i++)
    {
        if ((state & (1 << i)) == 0)
            continue;

        for (int j = 0; j < N; j++)
        {
            if ((state & (1 << j)) == 0)
            {
                int newState = state | (1 << j);
                dp[state] = min(dp[state], solve(newState, cnt + 1) + MAP[i][j]);
            }
        }
    }
    return dp[state];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> MAP[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cin >> s >> P;
    int state = 0;
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == 'Y')
        {
            total++;
            state = state | (1 << (i));
        }
    }
    answer = solve(state, total);
    if (answer ==INF)
        cout << -1;
    else
        cout << answer;
}
