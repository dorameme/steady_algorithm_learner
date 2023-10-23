/*
start:16:50
end:17:20
시간복잡도:O(N^2)
공간복잡도:O(N)
풀이:꽤나 애먹은 문제 풀이를 참고하였다.
1. sort함수를 만든다
2. 원호보다 큰애들중에 제외되는 애들을 뺴준다
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool compare(vector <int> v1,vector <int> v2){
    return v1[0]+v1[1]>v2[1]+v2[0];
}
int solution(vector<vector<int>> scores) {
    map<vector<int>,int> del;
    int answer=1;
    int w1=scores[0][0];
    int w2=scores[0][1];
    sort(scores.begin()+1,scores.end(),compare);
    for(int i=2;i<scores.size();i++){
        if(scores[i][0]+scores[i][1]<=w1+w2)continue;//원호보다 작으면 무시
        if(scores[i][0]>w1 && scores[i][1]>w2)return -1;
        for(int j=1;j<i;j++){
            if(scores[j][0]>scores[i][0] && scores[j][1]>scores[i][1])del[scores[i]]=1;
        }
    }
    for(int i=1;i<scores.size();i++){
        if(del[scores[i]]==1)continue;
        if(w1+w2<(scores[i][0]+scores[i][1]))answer++;
    }
    return answer;
}
