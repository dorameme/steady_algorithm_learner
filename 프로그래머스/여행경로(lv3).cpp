/*
start:15:54
end:16:09
시간복잡도:O(N!)
공간복잡도:O(N)
풀이: 깊이우선탐색의 쉬운문제인데 조건을 제대로 안읽어서 틀렸다...;;; 시작은 무조건 ICN부터다.
*/
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
vector<string> answer;
int need;
vector <vector <string>> list;
int used[10001];
vector<vector<string>> T;

void dfs(int idx,int cnt){
    if(need==cnt){
        answer.push_back(T[idx][1]);
        list.push_back(answer);
        answer.pop_back();
        return;
    }
    for(int i=0;i<T.size();i++)
    {
        if(T[idx][1]==T[i][0]){
            if(used[i]==0){
                used[i]=1;
                answer.push_back(T[i][0]);
                dfs(i,cnt+1);
                answer.pop_back();
                used[i]=0;
            }
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    need=tickets.size();
    T=tickets;
    for(int i=0;i<tickets.size();i++)
    {
        if(T[i][0]!="ICN")continue;
        used[i]=1;
        answer.push_back(T[i][0]);
        dfs(i,1);
        answer.pop_back();
        used[i]=0;
    }
    sort(list.begin(),list.end());
    return list[0];
}
