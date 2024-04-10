/*
start:11:40
end:12:04
시간복잡도:O(n)
공간복잡도:O(1)
풀이:문제의 요구사항을 깨닫는데 헷갈렸다 ㅜㅜ.. 그래서 무슨뜻인지 이해하는데 한참걸림 
문제를 해석하자면 그냥 min 중에 max 찾는값 찾기임 .
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int solution(vector<int> citations) {
    
    sort(citations.begin(),citations.end());

    int answer = 0;
    for(int i=0;i<citations.size();i++){
        answer= max(answer,min(int(citations.size())-i,citations[i]));
    }
    return answer;
}
