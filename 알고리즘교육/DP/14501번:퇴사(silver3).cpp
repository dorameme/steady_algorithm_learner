/*
start:15:10
end:15:33
시간복잡도:O(N)
공간복잡도:O(N)
풀이:현재 이전의 날짜들 중에서 가능한 날짜와 현재 가능한 날을 더한다.
*/
#include <iostream>
#include <algorithm>
#define X first
#define Y second
using namespace std;
long long dp[100];
pair<int, int> p[1001];//배열두개두고 풀어도됨.
int N;
int answer = 0;
int main()
{
    cin >> N;
    int T, P;
    for (int i = 0; i < N; i++)
    {
        cin >> T >> P;
        p[i] = make_pair(T, P);
    }
    for (int i = 0; i < N; i++)
    {
        // 날짜
        if (p[i].X + i > N) // idx start from 0 so it should smaller than N
            continue;
        dp[i] = p[i].Y;
        if (answer < dp[i])
            answer = dp[i];
        for (int j = 0; j <= i; j++)
        {
            // 선택할 회의 날짜
            if (j + p[j].X <= i)
            {
                dp[i] = max(dp[i], p[i].Y + dp[j]); /// i를 선택하면서 이전에 선택할수 있는애들...

                if (answer < dp[i])
                    answer = dp[i];
            }
        }
    }
    cout << answer;
}
