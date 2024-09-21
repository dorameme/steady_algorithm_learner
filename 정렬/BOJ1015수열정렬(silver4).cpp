/*
start:18:30
end:18:53
시간복잡도:O(NlgN)
공간복잡도:O(N)
풀이: 정렬로 쉽게 풀수 있는 문제였다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int main(){
    ios::sync_with_stdio(0);
    vector<pair<int,int>>  v;
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    int num;
    int answer[1001]={};
    
    for(int i=0;i<N;i++){
        cin>>num;
        v.push_back({num,i});
    }
    sort(v.begin(),v.end());
    
    for(int i=0;i<N;i++) {
        answer[v[i].second]=i;
    }
    for(int i=0;i<N;i++){
       cout<< answer[i]<<" ";
    }
}
