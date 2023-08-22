/*
start:2:30
end:2:48
시간복잡도:O(N^5)
공간복잡도:O(N^5)
풀이:dp문제인데 이게 gold1이라고? 싶을정도로 쉬웠다. 고려해줘야할것은 A,B개수 , 현재 string 길이 , 그리고 지금까지 받은 si<sj관계수  항상 동적계획법은 어떤것이
정답에 영향을 미치는지가 중요하다.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
string answer;
int N,K;
int dp[31][31][31][451]; ////i ~ j 까지 'a' 가 몇개?// 'b' 몇개?
void solve(string s, int A, int B, int C, int cnt)
{
    if(answer!="")return;
    if(s.size()==N){
        if(A==0||B==0||C==0)return;
        if(cnt==K)answer=s;
        return;
    }
    if(dp[A][B][s.size()][cnt])return ;
    dp[A][B][s.size()][cnt]=1;
    if(cnt>K)return;
    solve(s+"C",A,B,C+1,cnt+A+B);
    solve(s+"B",A,B+1,C,cnt+A);
    solve(s+"A",A+1,B,C,cnt);
}
int main()
{
    cin >> N >> K;
    solve("",0,0,0,0);
    if(answer==""){
        cout<<-1;
         return 0;
    }
    cout<<answer;
}
