/*
start:12:25
end:12:33
시간복잡도:O(N)
공간복잡도:O(N)
풀이:기본 dp 연습
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
int answer;
long long dp[30];
int N;

int main()
{
    cin>>N;
    dp[1]=1;
    dp[2]=1;
    for(int i=3;i<=N+1;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<2*dp[N+1]+dp[N]*2<< " ";
}
