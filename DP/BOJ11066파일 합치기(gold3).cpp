/*
start:13:00
end:15:36
시간복잡도:O(N^3)
공간복잡도:O(N^2)
풀이:진짜 오래걸렸다... 너무 어려웠음 ㅠㅠ  dp[i][j]는 i~j까지의 합 중 최소이고 이걸 3중 포문을만들어서 해결!
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num;
int sum[501];
int K;
int dp[501][501];//dp[i][i]는 0이어야하므로 전역에 두어야한다. 그리고 이후에 dp[i][i]는 변하지않으므로 ㄱㅊ
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int file;
        cin >> K;
        for (int i = 1; i <= K; i++)
        {
            cin >> file;
            sum[i] = sum[i - 1] + file;
        }
        for (int i = 1; i <= K; i++)
        { // file cnt
            for (int j = 1; j <= K-i; j++)
            { // start idx
                dp[j][i + j] = 1000000000;
                for (int k = j; k < j + i; k++)
                // divide
                {
                    dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][j + i] + sum[i + j] - sum[j - 1]);
                }
            }
        }
        cout << dp[1][K] << "\n";
    }
}
