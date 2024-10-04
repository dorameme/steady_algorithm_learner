/*
start:20:07
end:20:39
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이:간단한 BFS문제인데, 주의할 점은 두 도시를 잇는 간선이 여러개일 수 있다는 점이다. 이때문에 중복된 count가 생기지 않도록
set을 사용해주었다.
*/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define X first
#define Y second
using namespace std;

int solution(int N, vector<vector<int> > road, int K) {

    set<int> s;
    vector <pair<int,long>> v[2001];
    for(int i=0;i<road.size();i++){
        v[road[i][0]].push_back({road[i][1],road[i][2]});
        v[road[i][1]].push_back({road[i][0],road[i][2]});
    }
    queue<pair<int,long>> q;
    q.push({1,0});
    long vis[51]={};
    for(int i=0;i<51;i++){
        vis[i]=99999999999;
    }
    vis[1]=0;
    s.insert(1);
    while(!q.empty()){
        pair<int,long> cur = q.front();
        q.pop();
        for(int j=0;j<v[cur.X].size();j++){
            pair <int,long> next= v[cur.X][j];
            if(vis[next.X]<= next.Y+cur.Y || next.Y+cur.Y>K)continue;
            vis[next.X]=next.Y+cur.Y;
            q.push({next.X,next.Y+cur.Y});
            s.insert(next.X);
        }
    }
    
    return s.size();
}
