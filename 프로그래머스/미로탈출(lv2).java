/*
start:13:40
end:14:04
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이: bfs문제로 간단히 해결가능
*/
import java.util.LinkedList;
import java.util.Queue;
class Solution {
    int dx[]={0,0,-1,1};
    int dy[]={-1,1,0,0};
    class Pair{
        private int x;
        private int y;
        Pair(int x,int y){
            this.x=x;
            this.y=y;
        }
        
        public int X(){
            return x;
        }
        public int Y(){
            return y;
        }
    }
    int answer=0;
    public void bfs(String[] maps,int x,int y,int tx,int ty){
        int vis[][]=new int[101][101];
        Queue<Pair> q=new LinkedList<>();
        q.add(new Pair(x,y));
        vis[x][y]=1;
        while(!q.isEmpty()){
            Pair cur=q.poll();
            
            for(int i=0;i<4;i++){
                int nx=cur.X()+dx[i];
                int ny=cur.Y()+dy[i];
                if(nx<0||ny<0||nx>=maps.length||ny>=maps[0].length())continue;
                if(maps[nx].charAt(ny)=='X' || vis[nx][ny]!=0)continue;
                if(nx==tx && ny== ty){ answer+=vis[cur.X()][cur.Y()]; return ;}
                vis[nx][ny]=vis[cur.X()][cur.Y()]+1;
                q.add(new Pair(nx,ny));
            }
        }answer=-1;
    }
    public int solution(String[] maps) {
        int x=0,y=0,tx=0,ty=0,ex=0,ey=0;
        for(int i=0;i<maps.length;i++){
            for(int j=0;j<maps[0].length();j++){
                if(maps[i].charAt(j)=='S'){
                    x=i;y=j;
                }if(maps[i].charAt(j)=='E'){
                    ex=i;ey=j;
                }if(maps[i].charAt(j)=='L'){
                    tx=i;ty=j;
                }
            }
        }
        bfs(maps,x,y,tx,ty);
        if(answer==-1)return -1;
        bfs(maps,tx,ty,ex,ey);
        if(answer==-1)return -1;
        return answer;
    }
}
