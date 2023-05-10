/*
start:19:45*
end:19:58
시간복잡도:O(N^2)
공간복잡도:O(N^2)
풀이: 단순 dp인데 브루트포스도 사용했다
*/
#include <iostream>
using namespace std;
int a, b;
bool solve(int val1, int val2)
{
    int dp[31]={};
    dp[0]=val1;
    dp[1]=val2;
    for(int i=2;i<a;i++){
        dp[i]=dp[i-1]+dp[i-2];
        if(dp[i]>b)return 0;
    }
    if(dp[a-1]==b){
        return 1;
    }
    return 0;
}
int main()
{
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    { // 첫날준떡
        for (int j = 1; j <= b - i; j++)
        { // 다음날 준떡
            if(solve(i, j)){
                cout<<i<<"\n"<<j;
                return 0;
            }
        }
    }
}
