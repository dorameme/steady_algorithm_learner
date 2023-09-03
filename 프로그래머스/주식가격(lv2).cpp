/*
start:10:40
end:10:55
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 힙을 사용해 간단하게 풀어낼 수 있다.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
priority_queue<pair<int,int>> pq;
    //제일 작은..가격 ,가격의 위치 인덱스
    vector<int> answer(prices.size());
    pq.push({prices[0],1});//가격 인덱스..
    for(int i=1;i<prices.size();i++){
        while(!pq.empty()){
          
            if(pq.top().first>prices[i]){
                answer[pq.top().second-1]=i+1-pq.top().second;
                pq.pop();
            }
            else {
                break;
            }
        }
        pq.push({prices[i],i+1});
    }
    for(int i=0;i<prices.size();i++){
        if(answer[i]==0){
            answer[i]=prices.size()-1-i;
        }
    }
    return answer;
}
