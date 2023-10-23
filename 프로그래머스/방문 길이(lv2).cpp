/*
start:15:30
end:15:50
시간복잡도:O(N)
공간복잡도:O(1)
풀이:주의할점이있음.. 길은 어느방향에서 오든 같으므로 왼쪽에서 오른쪽이든 오른쪽에서 왼쪽이든 둘다 처리해줘야함!!
*/

#include <string>
using namespace std;
int vis[20][20][20][20];
int solution(string dirs) {
    int answer = 0;
    int x=0;int y=0;
    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
        if(x>-5){
            x--;
        if(vis[x+6][y+5][x+5][y+5]==1||vis[x+5][y+5][x+6][y+5]==1)continue;
        vis[x+6][y+5][x+5][y+5]=1; answer++;
        }
        }
        else if(dirs[i]=='D'){
            if(x<5){
            x++;
        if(vis[x+4][y+5][x+5][y+5]==1||vis[x+5][y+5][x+4][y+5]==1)continue;
        vis[x+4][y+5][x+5][y+5]=1; answer++;
        }
        }
        else if(dirs[i]=='L'){
            if(y>-5){
            y--;
        if(vis[x+5][y+5][x+5][y+6]==1||vis[x+5][y+6][x+5][y+5]==1)continue;
        vis[x+5][y+5][x+5][y+6]=1; answer++;
        }
        }
        else {
            if(y<5)
            {  y++;
        if(vis[x+5][y+5][x+5][y+4]==1||vis[x+5][y+4][x+5][y+5]==1)continue;
        vis[x+5][y+5][x+5][y+4]=1; answer++;
        }
        }
    }
    return answer;
}
