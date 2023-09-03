/*
start:10:03
end:10:08
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 해시로 가볍게 풀수있는 문제
*/
#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> m;
int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i=0;i<clothes.size();i++){
        m[clothes[i][1]]++;
    }
    
    for(auto wear:m){
        answer*=(wear.second+1);
    }
    return --answer;
}
