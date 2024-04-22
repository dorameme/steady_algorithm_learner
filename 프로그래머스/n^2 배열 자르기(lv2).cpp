/*
start:13:24
end:13:38
시간복잡도:O(n*n)
공간복잡도:O(n*n)
풀이: 간단하게 같은 행이면 값이 다 같다는걸 이용하면 된다.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int mapNum(int x,int y){
    if(x<y)return mapNum(y,x);
    return x+1;
}
vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    for(long long i=left;i<=right;i++){
        answer.push_back(mapNum(i/n,i%n));
    } 
    return answer;
}
