/*
start:15:40
end:15:51
시간복잡도: DFS 함수는 가능한 모든 경로를 탐색하는 방식으로 동작하게 되며, 
이 경우에는 최악의 경우 모든 순열을 시도해보아야 한다.
따라서 DFS 함수의 시간 복잡도는 O(n!) 됨.여기서 n은 words 리스트 내의 단어 수
공간복잡도:O(N)
풀이: dfs로 풀어낼수 있다. 근데 주의할게 answer을 넘어서면 dfs메서드를 스탑해야함
만일 그냥 answer값이 나오자마자 stop하면 최적의 값이 안구해질수 있음..
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> W;
string B; string T;
int used[51];
int answer=987654321;
bool diff(string s,string s2){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=s2[i]){cnt++;}
    }
    if(cnt==1)return true;
    return false;
}
void dfs(string s,int cnt){
    if(answer<=cnt)return;
    if(s==T){answer=cnt;return;}
    
    for(int i=0;i<W.size();i++)
    {
        if(diff(s,W[i]) && used[i]==0){
            // cout<<diff(s,W[i]);
            used[i]=1;
            dfs(W[i],cnt+1);
            used[i]=0;
        }
    }
    
}
int solution(string begin, string target, vector<string> words) {
    W=words;
    B=begin;
    T=target;
    dfs(B,0);
    if(answer==987654321)return 0;
    return answer;
}
