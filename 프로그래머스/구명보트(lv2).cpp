/*
start:9:20
end:9:36
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 또 문제 제대로 안읽어서 틀림. 구명보트에 2명까지밖에 못타는게 포인트!
*/
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int> pq;
    priority_queue<int, vector <int>, greater<int>> pq2;
    for(int i=0;i<people.size();i++){
        pq.push(people[i]);
        pq2.push(people[i]);
    }
    int cnt=0;
    while(cnt<people.size()){
        answer++;
        int w=pq.top();
        pq.pop();
        cnt++;
       if(cnt<people.size() ){
            if(w+pq2.top()<=limit){
                w+=pq2.top();
                pq2.pop();
                cnt++;
            }
        }
    }
    return answer;
}
