#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
string s;
long long dp[101];

int main()
{
    int n;
    cin >> n;
    dp[0]=dp[1]=1;
    for(int i=2;i<=100;i++){
        dp[i]=(dp[i-1]+dp[i-2])%1000000007;    
    }
    int num;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        cout<<dp[num]<<"\n";
    }
}

//내풀이

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;
string s;
long long dp[101];
int tiling(int n){
    if(n<=1)return 1;
    if(dp[n])return dp[n];
    return dp[n]=(tiling(n-1)+tiling(n-2))%1000000007;
}
int main()
{
    int n;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        cout<<tiling(num)<<"\n";
    }
}

//교재풀이
