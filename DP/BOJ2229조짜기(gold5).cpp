/*
start:12:43
end:13:18
시간복잡도:O(N^2)
공간복잡도:O(N^2)
풀이:dp로 풀수 있다. 각구간의 최댓값과 최솟값 차이를 구해 점수를 합산한뒤 답을 구한다.
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_map>
#define X first
#define Y second
#define INF 2147483647
using namespace std;
int dpB[2001][2001];
int dpS[2001][2001];
int dp[2001][2001];
int answer;
int solve[2001];
int arr[2001];

int main()
{
    int N;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    int num;
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            dpB[i][j] = -1;
            dpS[i][j] = 10001;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i; j <= N; j++)
        {
            for (int k = i; k <= j; k++)
            {
                dpS[i][j] = min(dpS[i][j], arr[k]);
                dpB[i][j] = max(dpB[i][j], arr[k]);
            }
            dp[i][j] = dpB[i][j] - dpS[i][j];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            solve[i] = max(solve[i - j-1] + dp[i - j][i], solve[i]);
        }
    }
    cout << solve[N] << "\n";
}
