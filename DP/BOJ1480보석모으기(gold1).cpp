/*
start:12:32
end:12:51
시간복잡도:O(C*M*2^N)
공간복잡도:O(C*M*2^N)
풀이: 비트필드를 이용한 다이나믹 프로그래밍 문제였는데 생각보다 쉬웠다. 주의할 점이라면,,, 보석무게한개 자체가 가방의 용량인 C를 넘어서면 아예못넣는다는것!
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
// #define MAX 13// 보석수...
using namespace std;

int dp[15][25][1 << 13]; // 현재 몇번째 가방..//쓴 용량..//현재 상태..
int N, M, C;
int MAP[15];

int solve(int bagNum, int w, int state)
{
    if (dp[bagNum][w][state] != 0)
        return dp[bagNum][w][state];
    for (int i = 0; i < N; i++)
    {
        if ((state & (1 << i)) == 0)
        {
            int newState = state | (1 << i);
            if(w+MAP[i]<=C){
            dp[bagNum][w][state] = max(dp[bagNum][w][state],1+solve(bagNum,w+MAP[i],newState));
            }
            else if(w+MAP[i]>C&& MAP[i]<=C && bagNum+1<M){
             dp[bagNum][w][state]= max(dp[bagNum][w][state],1+solve(bagNum+1,MAP[i],newState));
            }
        }
    }
    return dp[bagNum][w][state];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> C;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> MAP[i];
    }
    dp[0][0][0] = solve(0, 0, 0);
    cout << dp[0][0][0]; // 이부분이 필요했음!
}
