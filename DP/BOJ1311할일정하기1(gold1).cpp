/*
풀이 -> 답안을 참고하였음
비트필드를 이용한 다이나믹 프로그래밍 기본문제인데 할줄몰라서 답안을 참고하며 연습중이다.ㅜㅜ 너무 어렵다 오늘 하루종일 "비트필드를 이용한 다이나믹 프로그래밍"만 풀예정
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#define MAX 21
using namespace std;

int MAP[MAX][MAX], dp[1 << MAX];
int N, chk;
void Input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
int func(int x, int cost,int cnt) {//x 몇개했는지
    if (x == N) {
       if(N == cnt){
            return 0;
        }    
        else return 987654321;
    }
    int &ret = dp[cost];
    if (ret){
        return ret;
    }ret = 987654321;
    
    for (int i = 0; i < N; i++) {
        if (cost & (1 << i)) continue;//이미 해결했으면 넘어가
        ret = min(ret, func(x + 1, cost | (1 << i),cnt+1) + MAP[x][i]);//해결안했으면 해결해야지..
    }
 
    return ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    Input();
    int answer = 987654321;
    cout<<func(0,0,0);
    return 0;
}
