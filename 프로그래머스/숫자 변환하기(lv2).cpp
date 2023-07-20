/*
start:8:30
end:9:00
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 되는 경우의 수를 모두해본다. 근데 살짝 나는 야매로 100넘어가면 멈추도록 해서 풀었다..
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int ans=100;
int solve(int x,int y,int n,int cnt){
    
    if(cnt>=ans)return 100;
    if(x==y){
        ans=cnt;return cnt;
    }
    if(y<x)return 100;
    
    int ans=solve(x,y-n,n,cnt+1);
    
    if(y%3==0)ans=min(ans,solve(x,y/3,n,cnt+1));
    if(y%2==0)ans=min(ans,solve(x,y/2,n,cnt+1));
    return ans;
}
int solution(int x, int y, int n) {

  int answer= solve(x,y,n,0);
    if(answer==100)return -1;
    return answer;
}
