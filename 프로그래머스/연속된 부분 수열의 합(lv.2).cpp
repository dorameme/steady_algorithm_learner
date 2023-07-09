/*
start:11:45
end:12:03
시간복잡도:O(N)
공간복잡도:O(N)
풀이:투포인터 문제였다. 주의할점은 모든 가능한 답을 찾고 그중 제일 짧은걸 반환해야한다는점!
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start=0,end=0;
    int helper=0;
    int size=987654321;
    while(start<=end){
        if(helper==k){
            if(size>end-start){
                size=end-start;
             answer.clear();
                answer.push_back(start);
                answer.push_back(end-1);
            }
            helper-=sequence[start++];
            continue;
        }else if(helper>k){
            if(start<sequence.size())
            helper-=sequence[start++];
            else break;
        }
        else{
            if(end<sequence.size())
            helper+=sequence[end++];
            else break;
        }
    }
    
    return answer;    
}
