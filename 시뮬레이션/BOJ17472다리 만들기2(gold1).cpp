/*
start:?
end:?
시간복잡도:O(N*M)
공간복잡도:O(N*M)
풀이:진짜 빡센 구현이었다. 몇시간을 푼건지 나도 모르겠음..;
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int N, M;
int arr[20][20];
int cntIsland = 0;
int vis[20][20];
int answer = 987654321;
int AllDone = 0;
int helper = 0;
int cntarr[20][20];
int conn[20]; //
int islandArr[20][20];
int place[20][20];
vector<pair<int, int > > v[20]; // 1~
vector <int> choose;
vector <pair<int,int>> vvv;
void island(int x, int y)
{
    cntIsland++;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    v[cntIsland].push_back(make_pair(x, y));
    islandArr[x][y] = cntIsland;
    vis[x][y] = 1;
    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = dx[i] + cur.X;
            int ny = dy[i] + cur.Y;
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (vis[nx][ny] == 1 || arr[nx][ny] == 0)
                continue;
            vis[nx][ny] = 1;
            v[cntIsland].push_back(make_pair(nx, ny));
            q.push(make_pair(nx, ny));
            islandArr[nx][ny] = cntIsland;
        }
    }
}
bool checkX(int y, int x1, int x2)
{
    if (x1 > x2)
    {
        return checkX(y, x2, x1);
    }
    for (int i = x1 + 1; i < x2; i++)
    {
        if (arr[i][y] == 1)
            return false;
    }
    return true;
}
int checkY(int x, int y1, int y2)
{
    if (y1 > y2)
    {
        return checkY(x, y2, y1);
    }
    for (int i = y1 + 1; i < y2; i++)
    {
        if (arr[x][i] == 1)
            return false;
    }
    return true;
}
int connect(int a, int b)
{

    int answer = 987654321;
    for (int i = 0; i < v[a].size(); i++)
    {
        for (int j = 0; j < v[b].size(); j++)
        {
            if (v[a][i].X == v[b][j].X)
            {
                if (abs(v[a][i].Y - v[b][j].Y) > 2 && checkY(v[a][i].X,v[a][i].Y ,v[b][j].Y))
                {
                    answer = min(answer, abs(v[a][i].Y - v[b][j].Y) - 1);
                }
            }
            else if (v[a][i].Y == v[b][j].Y)
            { 
                if (abs(v[a][i].X - v[b][j].X) > 2 && checkX(v[a][i].Y,v[a][i].X,v[b][j].X))
                {
                    answer = min(answer, abs(v[a][i].X - v[b][j].X) - 1);
                }
            }
        }
    }
    return answer;
}

int chooseBFS(){
    int pool[10][10]={0,};
    int much=0;
    for(int i=0;i<choose.size();i++){
        pool[vvv[choose[i]].X][vvv[choose[i]].Y]=pool[vvv[choose[i]].Y][vvv[choose[i]].X]=1;
        much+=cntarr[vvv[choose[i]].X][vvv[choose[i]].Y];
    }/////연결관게를 모두 붙여
    // cout<<"\n";
    // for(int i=1;i<6;i++){
    //     for(int j=1;j<6;j++){
    //         cout<<pool[i][j]<<" ";
    //     }cout<<"\n";
    // }
    int countIsland=0;
    for(int j=2;j<=cntIsland;j++){
            if(pool[1][j]==1){
                int used[10][10]={0,};
                used[1][j]=used[j][1]=1;
                int cnted[10]={0,};///섬사용?
                cnted[1]=cnted[j]=1;
                countIsland=2;
                queue<int> qqq;
                qqq.push(1);
                qqq.push(j);
                while(!qqq.empty()){
                    int cur=qqq.front();
                    qqq.pop();
                    for(int k=1;k<=cntIsland;k++){
                        if(pool[cur][k]==1 && used[cur][k]==0){
                            // cout<<cntarr[cur][k]<<" "<<cur<<" cur" <<k<<" k\n";
                            used[cur][k]=used[k][cur]=1;
                            if(cnted[k]==0){
                                // cout<<cnted[k]<<"ct "<<k<<"k ";
                                cnted[k]=1;
                                countIsland++;
                            }
                            qqq.push(k);
                        }
                    }
                }
                break;
            }
        }
    // cout<<"\n"<<countIsland<<" "<<much<<"much\n";
     if(countIsland==cntIsland){
         return much;
         
     }
     return 0;
}
void final(int idx)
{
    int tt=chooseBFS();
    if(tt){
        if(answer>tt)answer=tt;
        return;
    }
     for(int i=idx;i<vvv.size();i++){
        choose.push_back(i);
        // cout<<"\nchoose size"<<choose.size()<<"\n";
        // for(int j=0;j<choose.size();j++){
        //     cout<<" "<<choose[j];
        // }cout<<"\n";
        final(i+1);
        choose.pop_back();
    }    
}
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (size_t m = 0; m < M; m++)
        {
            cin >> arr[i][m];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int m = 0; m < M; m++)
        {
            if (arr[i][m] == 1 && vis[i][m] == 0)
            {
                island(i, m);
            }
        }
    }
    for(int i=1;i<=cntIsland;i++){
        for(int m=i+1;m<=cntIsland;m++){
             cntarr[i][m]=cntarr[m][i]=connect(i,m);
            //  cout<<cntarr[i][m]<<"i,m="<<i<<" "<<m<<"\n" ;
             if(cntarr[i][m]!=987654321){
                 vvv.push_back(make_pair(i,m));//연결관계가 있음.
             }
        }
    }
    final(0);
    if(answer==987654321)cout<<-1;
    else
    cout << answer;
}
