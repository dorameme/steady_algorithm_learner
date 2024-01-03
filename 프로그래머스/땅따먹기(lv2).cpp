/*
start:15:30
end:15:54
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이:dp로 풀수있다. 패딩을 이용하여 쉽게풀어내자
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[100002][6];
int solution(vector<vector<int> > land)
{
    for(int j=1;j<=land.size();j++){
        dp[j][1]=max({dp[j-1][2],dp[j-1][3],dp[j-1][4]})+land[j-1][0];
        dp[j][2]=max({dp[j-1][1],dp[j-1][3],dp[j-1][4]})+land[j-1][1];
        dp[j][3]=max({dp[j-1][1],dp[j-1][2],dp[j-1][4]})+land[j-1][2];
        dp[j][4]=max({dp[j-1][1],dp[j-1][2],dp[j-1][3]})+land[j-1][3];
    }
    return max({dp[land.size()][1],
                dp[land.size()][2],
                dp[land.size()][3],
                dp[land.size()][4]});
}
