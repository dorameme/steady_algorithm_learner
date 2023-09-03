/*
start:9:50
end:9:54
시간복잡도:O(lgN)
공간복잡도:O(N)
풀이: priority_queue 즉 힙으로 쉽게 풀리는 문제
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue <long long,vector<long long>,greater<long long>> q;
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        q.push(scoville[i]);
    }
    while(q.top()<K ){
        if(q.size()<2){return -1;}
        long long mixed1=q.top();
        q.pop();
        long long mixed2=q.top();
        q.pop();
        q.push(mixed2*2+mixed1);
        answer++;
    }
    return answer;
}
