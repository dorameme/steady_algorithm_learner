/*
start:10:10
end:12:30
시간복잡도:O(N*M) 배열의 모든윈소 순회
공간복잡도:O(N*M)
풀이: DP 누적합을 이용해 푸는 문제였다.
2차원누적합문제로 접근방식을 몰라 헤메었다
누적합을 구할때 마지막에 처음에 특정수를 더한뒤 마지막 뺴주는건 하나큰 배열에서 해줘야한다는것 주의!
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill)
{
    int answer = 0;
    int dp[1001][1001] = {
        0,
    };
    for (int i = 0; i < skill.size(); i++)
    {
        int score = skill[i][5];
        score = skill[i][0] == 1 ? -1 * score : score;
        dp[skill[i][1]][skill[i][2]] += score;
        dp[skill[i][3]+1][skill[i][4]+1]+=score;
        dp[skill[i][3]+1][skill[i][2]]-=score;
        dp[skill[i][1]][skill[i][4]+1]-=score;
    }
    for (int i = 0; i < board.size(); i++)
    {
        for (int m = 1; m < board[0].size(); m++)
        {
            dp[i][m] += dp[i][m - 1];
        }
    }

    for (int i = 0; i < board[0].size(); i++)//왼쪽에서 오른쪽으로 누적합을 구해준다.
    {
        for (int m = 1; m < board.size(); m++)
        {
            dp[m][i] += dp[m - 1][i];
        }
    }
    for (int i = 0; i < board.size(); i++)//위에서 아래로 누적합을 구해준다.
    {
        for (int m = 0; m < board[0].size(); m++)
        {
            if(board[i][m] + dp[i][m]>0)answer++;
            
        }
    }
    return answer;
}
