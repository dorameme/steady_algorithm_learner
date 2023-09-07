#include <iostream>
/*
start:15:30
end:16:00
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이: 아... 너무 배울게 많았던 문제 일단 answer=0로 두면 안된다.
왜냐면 표의 크기가 1이면 0이 답으로 반환되어버림 ㅜㅜ 그래서 answer=board[0][0] 으로 두고,
3개의 좌표를 확인해가면서 누적합형식으로 풀어줘야한다.

*/
#include<vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
//     int answer = 0;
    
//     for(int i=1;i<board.size();i++){
//         for(int j=1;j<board[0].size();j++){
//            if(board[i][j]==1) {
//                board[i][j]=1+min({board[i-1][j-1],board[i-1][j],board[i][j-1]});
//                answer=max(board[i][j],answer);
//            }
//          }
//     }
    int answer = board[0][0];
    int r = board.size();
    int c = board[0].size();
    
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
        {
            if(board[i][j]==1){
                board[i][j] = 1 + min({board[i-1][j-1],board[i-1][j],board[i][j-1]});
                answer = max(answer,board[i][j]);
            }
        }
    }
    return answer*answer;
}
