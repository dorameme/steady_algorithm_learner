/*
start:14:12
end:14:25
시간복잡도:O(lgN)
공간복잡도:O(1)
풀이:완전탐색으로 쉽게 풀수있다.소수구하는 알고리즘이랑 살짝 비슷
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> helper(int num,int total){
    vector<int> answer;
    for(int i=1;i*i<=num;i++){
        if(num%i==0){
                if(total==(num/i+2)*(2+i)) {
                answer.push_back(num/i+2); 
                answer.push_back(i+2);
                return answer;
            }   
        }
    }
}
vector<int> solution(int brown, int yellow) {
    int total=brown+yellow;
    return helper(yellow,total);
}
