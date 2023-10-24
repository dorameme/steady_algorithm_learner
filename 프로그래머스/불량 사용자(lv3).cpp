/*
start:12:20
end:12:59
시간복잡도O(NM)
공간복잡도:O(N)
풀이:완전탐색으로 풀어냈다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
vector<string> user;
vector<string> banned;
set <vector <string>> s;
vector <string> answerSet;
int vis[10];
void Makecase(int idx){
    if(idx==banned.size()){
        vector <string> answer=answerSet;
        sort(answer.begin(),answer.end());////소트하면서 원래의 순서가 바뀌면안된다(pop_back과정이 있으므로) 따라서 새로운 벡터를 선언하였다.
        s.insert(answer);
        return;
    }
    for(int i=0;i<user.size();i++){
        int flag=0;
        if(vis[i])continue;//이미 사용된 유저아이디인지 확인해준다.
        if(user[i].size()!=banned[idx].size())continue;
        else{
            for(int j=0;j<banned[idx].size();j++){
                if(banned[idx][j]=='*' || banned[idx][j]==user[i][j]){continue;}
                else{
                    flag=1; break;
                }
            }
            if(flag==0){
                vis[i]=1;
                answerSet.push_back(user[i]);
                Makecase(idx+1);
                answerSet.pop_back();
                vis[i]=0;
            }
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id)
{
    user=user_id;
    banned=banned_id;
    Makecase(0);
    return s.size();
}
