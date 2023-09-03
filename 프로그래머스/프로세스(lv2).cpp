
/*
start:11:30
end:12:52
시간복잡도:O(N^2)
공간복잡도:O(N)
풀이: 처음에 좀 헤멨는데 항상 중요한건 입력값이 크지않으면 지문에 나와있는 그대로 푸는게 중요하다. 만일 최적화가 필요하면 그때 고려
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define X first
#define Y second
using namespace std;

int solution(vector<int> priorities, int location) {
    priority_queue<pair<int,int>> q;//큰것중 제일 작은것 의 제일 큰 인덱스 필요//
     queue<pair<int,int>> solve;
     for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],-i});
        solve.push({priorities[i],i});
    }
    int answer=1;
    while(1){
        if(solve.front().X<q.top().X){
            solve.push(solve.front());
            solve.pop();
        }
        else{
            if(solve.front().Y==location )return answer;
            answer++;
            solve.pop();
            q.pop();
        }
    }
}
