/*
start:17:50
end:18:15
시간복잡도:O(N)
공간복잡도:O(N)
풀이:DP로 푸는 문제였는데 오랜만에 풀어보는 유형이라 답안을 참고하였다.
0원을 만들수 있는 방법은 1가지 여기서부터 시작한다.
여기서부터 만들수있는 최소금액인 money[i]부터 n까지의 값을 더해준다. 
*/

#include <string>
#include <vector>

using namespace std;
int dp[1000001];
int solution(int n, vector<int> money) {
    int answer = 0;
    dp[0]=1;
    for(int i=0;i<money.size();i++){
        for(int j=money[i];j<=n;j++){
            dp[j]+=dp[j-money[i]];
            dp[j]%=1000000007;
        }
    }
    return dp[n];
}
