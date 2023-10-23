/*
start:17:30
end:17:46
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 그냥 단순 구현 엄청 쉬움 분배해주면 됨
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> answer;
void makeSet(int n,int s){
    int put=s/n;
    for(int i=0;i<n;i++){
        answer.push_back(put);
    }
    for(int i=0;i<s%n;i++){
        answer[i]++;
    }
}
vector<int> solution(int n, int s) {
    makeSet(n,s);
    sort(answer.begin(),answer.end());
    if(answer[0]==0){answer.clear(); answer.push_back(-1);}
    return answer;
}
