/*
start:16:20
end:17:20
시간복잡도:O(N*M)
공간복잡도:O(N*M)
풀이:중복된 계산을 막기위해 vis배열을 두는데, 이미 방문했으면 다시 방문하지 않는게 아닌, vis[cur.X][cur.Y]>cnt 이렇게 더 빠른 방법으로 왔으면 허락해주는게 포인트
vis[cur.X][cur.Y]=cnt+1;로 값도 업데이트 필요
*/
#include <string>
#include <vector>
#include <iostream>
#define X first
#define Y second
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
using namespace std;
vector<string> b;
int vis[101][101];
pair<int,int> move(int x,int y,int num){
    int nx=x+dx[num];
    int ny=y+dy[num];
    while(1){
       if(nx<0||ny<0||nx>=b.size()||ny>=b[0].size())return {nx-dx[num],ny-dy[num]}; 
       if(b[nx][ny]=='D')return {nx-dx[num],ny-dy[num]}; 
       nx=nx+dx[num];//여기서 실수함..;;
       ny=ny+dy[num];
    }
    return {0,0};
}

int answer=98765321;
void sol(int x,int y,int cnt){
  //  cout<<"x"<<x<<" y"<<y<<" cnt"<<cnt<<"\n";
    if( answer<=cnt)return ;
    
    
    pair<int,int> cur=move(x,y ,0);
    if(b[cur.X][cur.Y]=='G'){
        if(answer>cnt){
         //   cout<<cur.X<<" "<<cur.Y<<b[cur.X][cur.Y]<<"ans="<<cnt<<"\n";
            answer=cnt;
        }
        return;
    }
    else{
        if(vis[cur.X][cur.Y]>cnt){
            vis[cur.X][cur.Y]=cnt+1;
            sol(cur.X,cur.Y,cnt+1);
        }
    }
    
    cur=move(x,y ,1);
    if(b[cur.X][cur.Y]=='G'){
         if(answer>cnt){
        //    cout<<cur.X<<" "<<cur.Y<<b[cur.X][cur.Y]<<"ans="<<cnt<<"\n";
            answer=cnt;
        }
        return;
    }
    else{
        if(vis[cur.X][cur.Y]>cnt){
            vis[cur.X][cur.Y]=cnt+1;
            sol(cur.X,cur.Y,cnt+1);
        }
    }
    cur=move(x,y ,2);
    if(b[cur.X][cur.Y]=='G'){
         if(answer>cnt){
         //   cout<<cur.X<<" "<<cur.Y<<b[cur.X][cur.Y]<<"ans="<<cnt<<"\n";
            answer=cnt;
        }
        return;
    }
    else{
        if(vis[cur.X][cur.Y]>cnt){
            vis[cur.X][cur.Y]=cnt+1;
            sol(cur.X,cur.Y,cnt+1);
        }
    }
    cur=move(x,y ,3);
    if(b[cur.X][cur.Y]=='G'){
         if(answer>cnt){
           // cout<<cur.X<<" "<<cur.Y<<b[cur.X][cur.Y]<<"ans="<<cnt<<"\n";
            answer=cnt;
        }
        return;
    }
    else{
        if(vis[cur.X][cur.Y]>cnt){
            vis[cur.X][cur.Y]=cnt+1;
            sol(cur.X,cur.Y,cnt+1);
        }
    }
}


int solution(vector<string> board) {
    b=board;
    
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            vis[i][j]=98765321;
        }
    }
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            if(board[i][j]=='R'){
                vis[i][j]=1;
                sol(i,j,1);
                if(answer==98765321)return -1;
                else return answer;
            }
        }
    }
}
