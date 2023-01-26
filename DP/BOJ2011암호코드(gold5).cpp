/*
start:12:25
end:12:56
시간복잡도:O(N)
공간복잡도:O(N)
풀이:dp로 경우의 수를 나누어 풀어주면 된다
주의:문제가 무엇을 요구하는지 정확하게 판단하는 습관을 가져야한다. 나누는걸 깜박해서 계속틀렸다
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_map>
#define X first
#define Y second
#define INF 2147483647
using namespace std;
long long dx[] = {0, 0, -1, 1};
long long dy[] = {-1, 1, 0, 0};
string s;
int dp[5001];
int solve(int idx)
{
    if (idx == s.size())
        return 1;
    else if (idx > s.size())
        return 0;
    if (dp[idx])
        return dp[idx];
    if (s[idx] == '0')
        return 0;
    else if (s[idx] == '1')
    {
        return dp[idx] = (solve(idx + 2) + solve(idx + 1))%1000000;
    }
    else if (s[idx] == '2' && s[idx + 1] <= '6' && s[idx + 1] >= '0')
    {
        return dp[idx] = (solve(idx + 2) + solve(idx + 1))%1000000;
    }
    else
    {
        return dp[idx] = (solve(idx + 1))%1000000;
    }
}

int main()
{
    cin >> s;
    cout << (solve(0))%1000000;
}
