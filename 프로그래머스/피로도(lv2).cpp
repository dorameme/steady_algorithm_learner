/*
start:12:44
end:12:48
시간복잡도:O(N)
공간복잡도:O(N)
풀이:엄청 쉬운완전탐색문제!
*/
#include <string>
#include <vector>

using namespace std;
int vis[10];
vector<vector<int>> d;
int ans=0;
void solve(int k,int num,int cnt){
    if(ans<cnt)ans=cnt;
    if(cnt==d.size()){
        return ;
    }
    for(int i=0;i<d.size();i++){
        if(vis[i]==0 && k>=d[i][0]){
            vis[i]=1;
            solve(k-d[i][1],i,cnt+1);
            vis[i]=0;      
       }
    }

}
int solution(int k, vector<vector<int>> dungeons) {
     d=dungeons;
    int answer = -1;
    for(int i=0;i<dungeons.size();i++){
        vis[i]=1;
        if(k>=d[i][0])
        solve(k-d[i][1],i,1);
        vis[i]=0;
    }
    
    return ans;
}
