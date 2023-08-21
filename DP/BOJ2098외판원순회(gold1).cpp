/*
start:12:02
end:12:21
시간복잡도:O(N^2*2^N)
공간복잡도:O(N^2*2^N)
풀이: dp를 풀땐 결과에 영향을 미치는 요소를 잘 파악해야함
그리고 이 문제는 애초에 넣어줄때 dp[start][now][state]를 안해줘서 처음에 테케가 잘안돌아갔었음 밑에 깜박한 부분이 어딘지 표시해둠
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define MAX 16
using namespace std;

/// 우선 결과에 영향을 미치는 요소를 알아보자
int dp[MAX][MAX][1 << MAX]; // 처음시작지점, 현재지점, 몇번쨰인지, 정도?...
int MAP[MAX][MAX];
int N;
int solve(int start, int now, int state, int cnt)
{
    if (cnt == N - 1)
    {
        if (MAP[now][start] == 0)
        {
            return 987654321;
        }
        else
        {
            return MAP[now][start];
        }
    }
    if (dp[start][now][state] != 0)
        return dp[start][now][state];

    dp[start][now][state] = 987654321;

    for (int i = 0; i < N; i++)
    {
        if (i != now)
        {
            // cout<<MAP[now][i]<<"MAP "<<state <<"state\n" ;
            if ((state & (1 << i)) == 0 && (MAP[now][i] != 0))
            {
                int newState = state | (1 << i);
                dp[start][now][state] = min(dp[start][now][state], solve(start, i, newState, cnt + 1) + MAP[now][i]);
            }
        }
    }
    return dp[start][now][state];
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
        {
            cin >> MAP[i][j];
        }
    }
    int answer = 987654321;
    for (int i = 0; i < N; i++)
    {
        dp[i][i][0]= solve(i, i, 1 << i, 0) ;//이부분이 필요했음!
        answer = min(answer, solve(i, i, 0, 0));
    }
    cout << answer;
}
