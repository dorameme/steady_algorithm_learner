/*
start:12:10
end:12:37
시간복잡도: 완전탐색으로 풀면 3^N dp 로 풀면 중복이 나오므로 그보다 훨씬줄일 수 있다.
공간복잡도:O(N)
풀이:dp로 몇번째 구슬까지왔는지, 현재 몇 그람인지를 저장해준다. 그리고 음수가 나오는 경우는 절댓값으로 바꾸어주거나 다른 자료구조로 음수를 저장한다.
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int dp[31][15001]; // using // weight
int ball_cnt, cnt;
map<int,int> ball_weight;////이렇게 맵으로 만들어서 음수까지 고려가능
void solve(int idx, int weight, vector<int> &v)
{
    ball_weight[weight]=1;//기록
    if (idx>=ball_cnt){return;}
    if (dp[idx][weight])return;
    dp[idx][weight]=1;
    solve(idx+1,weight,v);
    solve(idx+1,weight+v[idx],v);
    solve(idx+1,weight-v[idx],v);
}
int main()
{
    cin >> ball_cnt;
    vector<int> ball(ball_cnt);
    for (int i = 0; i < ball_cnt; i++)
    {
        cin >> ball[i];
    }
    solve(0,0,ball);
    cin >> cnt;
    int w;
    for(int i=0;i<cnt;i++){
        cin>>w;
        if(ball_weight[w])cout<<"Y ";
        else cout<<"N ";
    }
}
