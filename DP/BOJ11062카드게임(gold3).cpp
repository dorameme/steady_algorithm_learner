/*
start:10:50
end:11:18
시간복잡도:O(N)
공간복잡도:O(N)
풀이: dp인데 아이디어를 잘 짜야했다 dp는 근우의 점수이므로, 서로 베스트플레이를 하려면
근우입장에선 max가되도록 명우입장에선 min이 되도록 플레이해야한다.
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int C;
int dp[1001][1001];
int arr[1001];
int total1;
int total2;
int solve(int l,int r,int turn){
    if(l>r)return 0;
    int &ret=dp[l][r];
    if(turn==1){
        if(ret)return ret;
        return ret=max({solve(l+1,r,2)+arr[l],solve(l,r-1,2)+arr[r]});
    }
    else{
        return ret=min({solve(l+1,r,1),solve(l,r-1,1)});
    }
}
int main()
{
    cin>>C;
    while(C--){
        fill(&dp[0][0], &dp[1000][1001], 0);
        int T;
        cin>>T;
        total1=total2=0;    
        for(int i=0;i<T;i++){
            cin>>arr[i];
        }
        cout<<solve(0,T-1,1)<<"\n";
    }
}
