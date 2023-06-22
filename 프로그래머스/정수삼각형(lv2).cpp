/*
start:16:40
end:17:04
시간복잡도:N*N
공간복잡도:N*N
풀이: 처음에 재귀형식으로 짰는데 재귀는 1만번이상반복하면 스택오버플로우가난다..
그래서 틀렸었고 그냥 재귀없이 반복문으로도 쉽게풀수있는 문제였디.
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501];
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    dp[0][0]=triangle[0][0];
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<=i;j++){
            if(j==0)
                dp[i][j]=max(dp[i][j],dp[i-1][j])+triangle[i][j];
            else
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i-1][j-1]})+triangle[i][j];
            
            if(answer<dp[i][j])answer=dp[i][j];
        }   
    }
    return answer;
}
