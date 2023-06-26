//새로안것.. 동적계획법은 특정값을 넘어설때 나눠주는 조건이 있으면 주의해야한다!!

#include <algorithm>
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
int C;
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
long long board[501][501];
int sX=250;
int sy=250;
int dp[101][101];
int poly(int n,int back){
    int& ret=dp[n][back];
    if(n==0)return 1;
    if(ret!=0)return ret;
    ret=0;
    for(int i=1;i<=n;i++){
        ret=ret+(poly(n-i,i)*(i+back-1))%10000000;
        ret%=10000000;
    }
    return ret%10000000;
}
int main()
{
    cin >> C;
    while (C--)
    {
        int answer=0;
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
        int add=(poly(n-i,i))%10000000 ;
        answer+=add%10000000;
        answer%=10000000;
        }cout<<answer<<"\n";
    }
}
