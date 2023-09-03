/*
start:10:20
end:10:31
시간복잡도:O(N)
공간복잡도:O(N)..잘모르겠음
풀이:map(헤시)와 priority_queue(힙)을 이용해 간단히 풀어낼수 있었다. 주의할 점은 자을당 고유번호가 1개일수 있다는 점. -> 예외 처리필요
*/
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
map<string, int> m;////총 재생량
//map<string, int> m2;///고유번호재생량,고유번호,이름 (재생량은 큰 순,고유번호는 작은순)
priority_queue <pair<pair<int,int>,string>> q3;
priority_queue <pair<int,string>>q1;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        m[genres[i]]+=plays[i];
    }//장르별-총 재생수
    for(auto i:m){
        q1.push({i.second,i.first});
    }///총 재생수 , 이름 (내림차순)
    
    while(!q1.empty()){
        priority_queue <pair<int,int>>q2;//고유번호당 재생수,-고유번호
        for(int i=0;i<genres.size();i++)
        {
            if(genres[i]==q1.top().second){
                q2.push({plays[i],-i});
            }
        }
        answer.push_back(-q2.top().second);
        q2.pop();
        if(!q2.empty())
        answer.push_back(-q2.top().second);
        q1.pop();
    }
    
    return answer;
}
