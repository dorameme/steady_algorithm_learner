/*
start:14:07
end:14:03
시간복잡도:O(N)
공간복잡도:O(N)
풀이:쉬운 동적계획법문제인데 주의할 점은 dp는 누적이 되므로 int 형이아닌 long long 타입이 필요하다는 점 dp 문제에서 답이안나오면 마지막값이나 처음값을 넣어 답이 잘나오는지 확인필요!
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define X first
#define Y second
using namespace std;
long long dp[100][2];
int N;
int main()
{
    cin>>N;
    dp[1][1]=1;
    for(int i=2;i<=N;i++){
        dp[i][1]=dp[i-1][0];
        dp[i][0]=dp[i-1][1]+dp[i-1][0];
    }
    cout<<dp[N][0]+dp[N][1];
}
