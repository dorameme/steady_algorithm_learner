/*
start=11:00
end=13:48
시간복잡도O(N^3)
공간복잡도:(N*N)
풀이:
1.현재위치에서 먹을수있는 물고기를 bfs 로 모두찾은뒤 그중 가장 거리가 가까운애를잡는다.
2-1.현재위치를 먹을수 있는 물고기위치로 갱신시킨다.
2-2.혹은 먹을수 있는 애가 없다면 종료 
3.다시반복
*/
#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int board[22][22];
int visit[22][22];
int N;
int dx[] = {0, -1, 1, 0}; 
int dy[] = {-1, 0, 0, 1};
queue<pair<int, int>> fish;
int answer = 0;
pair<pair<int,int>,int> bfs(int x,int y,int fishSize)
{ // 먹잇감과 거리
    vector <pair< int,pair<int,int>>> eatable;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y},0});
    while (!q.empty())
    {
        pair<pair<int, int>, int> cur = q.front();//위치 거리
        visit[x][y] = 1;
        q.pop();
        for (int i = 0; i < 4; i++) // 상좌우하 
        {
            int nx = cur.X.X + dx[i];
            int ny = cur.X.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (visit[nx][ny]||board[nx][ny] > fishSize)
                continue;
            if (board[nx][ny]!=0&&board[nx][ny] < fishSize)
            {   
                visit[nx][ny]=1;
                eatable.push_back( {cur.Y+1,{nx, ny}});
            }
            else
            {
                
                visit[nx][ny]=1;
                q.push({{nx, ny}, cur.Y + 1});
            }
        }
    }
    if(eatable.empty()){
    return {{0, 0}, 0};
    }
    else{
       sort(eatable.begin(),eatable.end());
       board[eatable[0].Y.X][eatable[0].Y.Y]=0;
    return  {{eatable[0].Y.X,eatable[0].Y.Y},eatable[0].X};
    }
}
int main()
{
    cin >>N;
    int bx=0;
    int by=0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                bx = i; // 상어 시작 위치
                by = j;
                board[i][j] = 0;
            }
        }
    }
    int fish_eat = 0;
    int fishSize = 2;
    int answer=0;
    pair<pair<int, int> ,int> cur = bfs(bx, by, 2);
    while (cur != make_pair(make_pair(0, 0), 0))
    {
        for(int i=0;i<N;i++){
            for(int m=0;m<N;m++){visit[i][m]=0;}
        }
        answer += cur.Y;
        fish_eat++;
        if (fish_eat == fishSize)
        {
            fishSize++;
            fish_eat = 0;
        }
        board[cur.X.X][cur.X.Y]=0;
        cur = bfs(cur.X.X, cur.X.Y,fishSize);
    }
    cout << answer;
    return 0;
}
