/*
start:13:00
end:14:00
시간복잡도:O(N)
공간복잡도:O(N)
풀이:혼자풀긴했지만 조금 버벅거린문제....
 answer[i][k] = max(answer[i-M][k - 1]+dp[i], answer[i-1][k]); 이 방정식을 세우는데 애먹었는데
바로 이전 객차까지가 최대값을 가지고 있으므로 걔를 데려가거나 아니면 하나더 적은데 지금 현재에 i번째를 데려가느냐 로 max로 더큰값을 구했다
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int arr[50001];
int dp[50001];
int solve;
int answer[50001][4];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    cin >> M;
    for (int i = M; i <= N; i++)
    {
        for (int j = i; j >= i - M + 1; j--)
        {
            dp[i] += arr[j];
        }
    }
    for (int i = M; i <= N; i++)
    {
            answer[i][1] = max(dp[i], answer[i-1][1]); /// answer i번쨰 위치까지 1개고름-> 그기차 + 그기차
            // cout << dp[i] << " ";
        
    }//m이 시작
    for (int k = 2; k <= 3; k++)
    {
        for (int i = M; i <= N; i++) /// 현재위치
        {                            // 현재 인덱스는 i고 ...
                answer[i][k] = max(answer[i-M][k - 1]+dp[i], answer[i-1][k]);
                if (answer[i][k] > solve)
                    solve = answer[i][k];
        }
    }
    cout << solve;
}
