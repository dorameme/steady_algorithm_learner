/*
start:10:30
end:11:14
시간복잡도:O(NlgN)-> 정렬때문에
공간복잡도:O(1)
풀이:정렬을 해준뒤 하나씩 순회하며 범위안에 들면 넘기고 아니면 answer++해준다
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(),targets.end());
    int start=0;
    int end=0;
    int answer = 0;
    for(int i=0;i<targets.size();i++){
        if(targets[i][0]<end){
            if (targets[i][1] < end) end = targets[i][1];
        }
        else{
            end=targets[i][1];
            answer++;
        }
    }
    return answer;
}
