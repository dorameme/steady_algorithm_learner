/*
start:15:00
end:15:30
시간복잡도:O(N*N)
공간복잡도:O(N*N)
풀이:유의할 점이 있다... 밑에서부터 쭉 채워나가는 형식을하면.... 예외처리때문에 힘들다..그냥 재귀로 더해나가는형식으로 하자
*/
#include <iostream>
#include <algorithm>
using namespace std;
int arr[101][101];
int dp[101][101];
int n;
int solve(int x, int y)
{
    if (x >= n - 1)
    {
        return arr[x][y];
    }
    if (dp[x][y]!=0){
           return dp[x][y];
    }
    return dp[x][y] = max(solve(x + 1, y + 1), solve(x + 1, y)) + arr[x][y];
}
int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> arr[i][j];
                dp[i][j] = 0;
            }
        }
        
        cout << solve(0, 0) << "\n";
    }
}
