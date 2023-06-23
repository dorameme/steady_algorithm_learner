/*
start:9:00
end:9:40
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단히 dp 문제! fill함수를 써보는건 거의 처음이다. 자주애용하자
Fill의 마지막 인덱스는 포함안되는거 주의
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define X first
#define Y second
using namespace std;
int dp[101][10001]; // idx,choose, score ,time
int N, T, K, S;
pair<int, int> arr[101];
int solve(int idx, int time)
{
    if(time<0)return -1e8;
    if (idx == N+1)
        return 0;
    if (dp[idx][time]!=-1)
        return dp[idx][time];
    return dp[idx][time] =max(solve(idx+1,time-arr[idx].X)+arr[idx].Y,solve(idx+1,time));
    
}
int main()
{
	fill(&dp[0][0], &dp[100][10001], -1);

    cin >> N >> T;
    for (int i = 0; i < N; i++)
    {
    
        cin >> K >> S;
        arr[i] = {K, S};
    }
    cout<<solve(0,T);
}
