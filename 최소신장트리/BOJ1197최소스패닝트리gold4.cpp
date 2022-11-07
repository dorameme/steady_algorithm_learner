/*
시간복잡도:O(Elg(E))왜냐면 ....간선들을 찾아다니면서 priority -queue에 넣는데 push한번에 lg(n)의 시간이 들기 때문
공간복잡도:O(V+E)
풀이:프림알고리즘을 풀어준 최소스패닝트리
adj벡터에 페어를이용하여 그래프정보를 넣어주고
priority queue를 이용하여 문제를 해결해 준다.
*/
#include <iostream>
#include <queue>
#include <tuple>
#include <stack>
#include <string>
#include <vector>
#define X first
#define Y second
using namespace std;
int main()
{
    int V,E;
    int A,B,C;
    cin>>V>>E;
    vector <int> chk(1000001);
    vector <pair<int,int>> adj[100001];
    priority_queue <tuple<int,int,int>, vector <tuple<int,int,int>> ,
        greater<tuple<int,int,int>>> pq;

    for(int i=0;i<E;i++){
        cin>>A>>B>>C;
        adj[A].push_back({C,B});
        adj[B].push_back({C,A});
    }   
    chk[1]=1;
    for(auto nxt: adj[1]){
        pq.push({nxt.X,1,nxt.Y});
    }
    int cnt=1;
    long long answer=0;
    while(cnt<V){
        int cost,a,b;
        tie(cost,a,b)=pq.top();
        pq.pop();
        if(chk[b])continue;
        answer+=cost;
        chk[b]=1;
        cnt++;
        for(auto nxt:adj[b]){
            if(!chk[nxt.Y]){
                pq.push({nxt.X,b,nxt.Y});
            }
        }
    }
    cout<<answer;
}