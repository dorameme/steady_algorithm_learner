/*
start:13:45
end:13:53
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이:너무 쉬웠다... 간단한 bfs문제
*/
#include<vector>
#include <queue>
#include <iostream>
#define X first
#define Y second
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
using namespace std;
int bfs(vector<vector<int> > & map){
    queue<pair<int,int>> q;
    q.push({0,0});
    int vis[101][101]={0,};
    vis[0][0]=1;
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=dx[i]+cur.X;
            int ny=dy[i]+cur.Y;
            if(nx<0||ny<0||nx>=map.size()||ny>=map[0].size())continue;
            if(map[nx][ny]==0||vis[nx][ny])continue;
            vis[nx][ny]=vis[cur.X][cur.Y]+1;
            q.push({nx,ny});
            if(nx==map.size()-1 && ny==map[0].size()-1)return vis[nx][ny];
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    vector<vector<int> > map= maps;
    return bfs(map);
}
