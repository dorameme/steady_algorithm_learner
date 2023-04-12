/*
start:18:10
end:18:40
시간복잡도:O(4^N)
공간복잡도:O(4^N)
풀이:
시간복잡도가 크지만 어차피 14까지밖에 N이 없기도하고 어차피 중간에 단순경로가 아니여서 탈락하는 경우가 많으므로 상관없었다.
전체경우를 bfs을 이용해서 단순경로인 경우를 전부 확률을 구해 답에 더해주었다.
*/
#include <iostream>
#include <queue>
using namespace std;
int visit[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
double dir[4];
int N;
double answer = 0; // 단순하지 않은경우 다구해줌..
void bfs(int x, int y, int cnt,double percent)
{
    if (cnt == N)
    {//단순경로
        answer+=percent;
        return;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (visit[x + dx[i]][y + dy[i]]==0)
            {
                visit[x + dx[i]][y + dy[i]] = 1;
                bfs(x + dx[i], y + dy[i], cnt+1,percent*dir[i]);
                visit[x + dx[i]][y + dy[i]] = 0;
            }
        }
    }
}
int main()
{
    cin >> N;
    for(int i=0;i<4;i++){
        cin>>dir[i];
        dir[i]/=100;
    }
    visit[50][50]=1;
    bfs(50,50,0,1.0);
    cout.precision(10);
    cout<<(double)answer;
}
