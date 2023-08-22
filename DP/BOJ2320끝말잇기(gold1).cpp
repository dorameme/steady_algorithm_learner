/*
start:10:45
end:11:10
시간복잡도:O(2^N)
공간복잡도:O(2^N)
풀이:비트필드를 이용한 다이나믹 프로그래밍문제였고 주의할 점은 dp값정할 때 char가 들어가니까 outofbound 나오지않도록 해야한다 ㄸ;; 
*/
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
long long N;
string word[16];
int dp[1 << 16][300]; // 사용한 단어 ->(1<<16) 끝문자 AEIOU
int solve(int state, char last)
{
    if (dp[state][last])
        return dp[state][last];
    for (int i = 0; i < N; i++)
    {
        if ((state & (1 << i)) == 0)
        {
            if (word[i][0] == last || last==0)
            {
                int newState = state | (1 << i);
                dp[state][last] = max(dp[state][last], (int)word[i].size() + solve(newState, word[i][word[i].size() - 1]));
            }
        }
    }
    return dp[state][last];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> word[i];
    }
    int ans = 0;
    ans=solve(0,0);
    cout << ans;
}
