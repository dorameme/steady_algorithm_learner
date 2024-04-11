/*
start:12:10
end:13:00
시간복잡도:O(lgn)
공간복잡도:O(1)
풀이:밑의 풀이는 쉬운문젠데 내가 너무 어렵게 푼듯하다. 거꾸로생각해보자..
어차피 최소로 갈려면 순간이동을 최대한 많이해야함
0에서 부터 출발한다고 생각하면 고민해야할 것이 굉장히 많지만, 반대로 생각해서 도착지점에서 거꾸로 되감기 해본다고 생각하면 문제를 좀 더 쉽게 해결할 수 있다는 것이 핵심이다.
그러니 함수 따로 뺼 필요없이 그냥 나누기랑 빼기로 풀면 됨~!
*/
#include <iostream>
using namespace std;
int answer;
void solve(int now,int cnt){
    if(answer!=0)return;
    if(now==0){
        answer=cnt;
        return;
    }
    if(now%2==0)
    {
        solve(now/2 , cnt);
    }
    else{
        solve(now-1,cnt+1);
    }
        
}
int solution(int k)
{
    solve(k,0);
    return answer;
}
