/*
start:15:10
end:15:26
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이: 이거 그냥 보면 어려울수 있는데 완전탐색으로 풀어주면 됨!! 노드수도 많지않아서 보면 당황하지말고 그냥 BFS돌려서 풀어버려~~
*/
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;
vector<vector<int>> w;
int N;
vector <int>together[101];
int bfs(int a,int b)
{
    int used[101]={0,};
    used[a]=1;
    used[b]=1;
    int cnt=1;
    queue<int>q;
    q.push(a);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
    for(int i=0;i<together[cur].size();i++){
        if(used[together[cur][i]]==0){
            used[together[cur][i]]=1;
            q.push(together[cur][i]);
            cnt++;
        }
    }
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    w=wires;
    N=n;
    for(int i=0;i<wires.size();i++){
        together[wires[i][0]].push_back(wires[i][1]);
        together[wires[i][1]].push_back(wires[i][0]);
    }
    for(int i=0;i<wires.size();i++){
        answer=min(answer,abs(bfs(wires[i][0],wires[i][1])-bfs(wires[i][1],wires[i][0])));
    }
    return answer;
}
