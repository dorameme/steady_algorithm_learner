/*
start:11:35
end:11:49
시간복잡도:O(N*M)
공간복잡도:O(N*M)
풀이:BFS로 간단히 풀수있는 문제
*/
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#define X first
#define Y second
using namespace std;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int vis[101][101];
vector <string> m;
int solve(int x,int y){
    int total=m[x][y]-'0';
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y]=1;
    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cur.X+dx[i];
            int ny=cur.Y+dy[i];
            if(nx<0||ny<0||nx>=m.size()||ny>=m[0].size())continue;
            if(vis[nx][ny]==1 || m[nx][ny]=='X')continue;
            vis[nx][ny]=1;
            total+=m[nx][ny]-'0';
            q.push({nx,ny});
        }
    }
    return total;
}
vector<int> solution(vector<string> maps) {
    m=maps;
    vector<int> answer;
    for(int i=0;i<maps.size();i++){
        for(int j=0;j<maps[0].size();j++)
        {
            if(maps[i][j]!='X' && vis[i][j]==0){
                vis[i][j]=1;
                answer.push_back(solve(i,j));
            }
        }
    }
    sort(answer.begin(),answer.end());
    if(answer.empty())answer.push_back(-1);
    return answer;
}
