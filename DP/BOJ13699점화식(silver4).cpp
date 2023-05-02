/*
start:20:00
end:20:10
시간복잡도:O(N*N)
공간복잡도:O(N*N)
풀이:문제에 주어진 그대로 dp[0]~dp[N]까지 구해서 풀어준다.
*/
#include <iostream>
using namespace std;
long long dp[36];
int main(){
    int n;
    cin>>n;
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    cout<<dp[n];
}
