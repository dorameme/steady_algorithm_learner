#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
double dp[1001][1001];
int C;
int n,t;
double solve(int deep,int m){
    if(m>t)return 0;
    if(deep<=0){
        return 1.0;
    }
    double &ret= dp[deep][m];
    if(ret!=-1)return ret;
    return ret=solve(deep-2,m+1)*3/4+solve(deep-1,m+1)*1/4;
}
int main()
{
    
    cin>>C;
    while(C--){
        for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
        dp[i][j]=-1;
        }
    }
    cin>>n>>t;
	cout.precision(10);
    cout<<solve(n,0)<<"\n";
    }
}
