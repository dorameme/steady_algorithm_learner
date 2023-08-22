/*
start:11:18
end:14:08 (밥먹고오느라..)
시간복잡도:O(N^3)
공간복잡도:O(M^3)
풀이:dp문제인데 생각해내기 어려웠다 그래서 인터넷을 좀 참고함. 작은막대를 하나씩 더해준다고 생각하고 풀면 잘풀리고
너무 답이 커서 나누는 과정이있는 문제를 주의하자!
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
int na = 1000000007;
int N, L, R;
int dp[101][101][101];

int main()
{
    cin >> N >> L >> R;
    dp[1][1][1] = 1;

    for (int n = 2; n <= N; n++)
    {
        for (int l = 1; l <= n; l++)
        {
            for (int r = 1; r <= n; r++)
            {
                dp[n][l][r] = ((dp[n - 1][l - 1][r]+dp[n - 1][l][r - 1]))%na +((long long )(dp[n - 1][l][r]) * (n - 2))%na ; //이부분
              //모든과정이아닌 중간과정에 %na 라고 써서 틀렸었다! 항상 계산할때 중간에 넣고싶으면 다넣어주거나 
              //최종결과에만 넣어주자!
                dp[n][l][r] %= na;
            }
        }
    }

    cout<<  dp[N][L][R];
}
