/*
start:?
end:15:37 (꽤오래걸림)
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이:...이런경우 패딩을 더해주자! nm이 내가 생각한거랑 다른것도 주의(행열이 아니라 열행임)
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int Map[105][105];
int vis[105][105];
int solution(int m, int n, vector<vector<int>> puddles) {
    int X=n;
    int Y=m;
    for(int i=0;i<puddles.size();i++){
        Map[puddles[i][1]][puddles[i][0]]=1;
    } 
    if(Map[1][2]==0)
        vis[1][2]=1;
    if(Map[2][1]==0)
        vis[2][1]=1;
    
    for(int i=1;i<=X;i++){
        for(int j=1;j<=Y;j++){
            if(Map[i][j]==0)
            {
                if(Map[i-1][j]==0){
                    vis[i][j]+=vis[i-1][j];
                }
                vis[i][j]%=1000000007;
                if(Map[i][j-1]==0){
                    vis[i][j]+=vis[i][j-1];
                }
                vis[i][j]%=1000000007;
            }        
        }
    }
    return vis[X][Y];
}
