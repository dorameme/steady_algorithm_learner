/*
start:21:00
end:21:18
시간복잡도:O(N)
공간복잡도:O(N)
풀아:깔끔하게 주어진대로 조건 나누어서 풀면 쉽게 풀리는 문제
*/
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    int cnt=1;
    stack <int> s;
    int idx=0;
    while(1){
        if(order[idx]==cnt){
            answer++;
            idx++;
            cnt++;
        }
        else if(!s.empty() && s.top()==order[idx]){
            idx++;
            answer++;
            s.pop();
        }
        else if(idx<order.size() && cnt<order.size() ){
            s.push(cnt);
            cnt++;
        }
        else return answer;
    }
    return answer;
}
