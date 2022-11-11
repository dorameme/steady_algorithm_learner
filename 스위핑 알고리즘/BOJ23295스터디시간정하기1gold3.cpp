#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;
long long dp[200002];
long long study[200001];
int main(){
    long long big=0;
    long long num,time;
    cin>>num>>time;//참가자 수, 스터디 시간
    for(int i=0;i<num;i++){
        long long a,n1,n2;//사람마다 몇시간 가능한지 , 몇시부터, 몇시
        cin>>a;//몇시간 가능한지
        for(int m=0;m<a;m++){
            cin>>n1>>n2;//몇시부터 몇시
            if(big<n2)big=n2;
            study[n1]+=1;
            study[n2]+=-1;
        }
    }
    dp[0]=study[0];
    long long where=0;
    long long answer=0;
 //   cout<<dp[0]<<" ";
    for(int i=1;i<=big;i++){
        dp[i]=dp[i-1]+study[i];
//        cout<<dp[i]<<" ";
    }
    
    for(int i=0;i<time;i++){
        answer+=dp[i];
    }
    long long total=answer;
    for(int i=1;i<big;i++){
        total=total-dp[i-1]+dp[i+time];
        if(answer<total){answer=total; where=i;}
    }
    cout<<where<<" "<<where+time;
}
