/*
start:19:00
end:19:46
시간복잡도:O(N)
공간복잡도:O(N)
풀이:dp 문제인데 인덱스설정을 잘못해서 틀렸다. 왜틀렸나 한참 둘러본문제!
*/
#include <algorithm>
#include <iostream>
#define X first
#define Y second
using namespace std;
int arr[51];
int dp[51][1001]; // 값 인덱스
int answer = -1;
int N, M, S;
void solve(int idx, int number)
{
    if (idx==N)//마지막에 도착했을때 비로소...
    {
        if (number > answer)
            answer = number;
        return;
    }
    if (dp[idx][number]==1){
        return;
    }//이미 방문헀으면 다시볼필요없겠지
    dp[idx][number] = 1;
    if (number + arr[idx] <= M)
    {
        solve(idx + 1, number + arr[idx]);
    }

    if (number - arr[idx] >= 0)
    {
        solve(idx + 1, number - arr[idx]);
    }
}

int main()
{
    cin >> N >> S >> M; // 갯수 시작 최대
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    solve(0, S);
    dp[0][S]=1;
    cout << answer << "\n";
}
