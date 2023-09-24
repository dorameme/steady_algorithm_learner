
/*
start:13:20
end:14:31
시간복잡도:O(N*N*NlgN)
공간복잡도:O(N*N)
풀이: 그냥 구현하면되는데 주의 할 점은 heap을 사용하지 않고 구현해야한다는 점이다 heap 을 쓰면 시간초과남.. ㅠㅠ
Priority Queue의 삽입(push) 및 삭제(pop) 연산은 일반적으로 O(log N)의 시간 복잡도를 가지기 때문!!
*/
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int N, M, K;
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, -1, 1, 0, -1, 1};
vector<int> map[101][101];
int A[101][101];
int food[101][101];
void winter()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            food[i][j] += A[i][j];
        }
    }
}
void fall()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            vector<int> tree;
            for(int cur:map[i][j])
            {
                tree.push_back(cur);
                if (cur % 5 == 0)
                {
                    for (int k = 0; k < 8; k++)
                    {
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                            continue;
                        else
                        {
                            map[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
void springAndSummer()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            vector<int> live;
            int dead = 0;
            sort(map[i][j].begin(),map[i][j].end());
           for(auto cur:map[i][j])
                if (food[i][j] >= cur)
                {
                    food[i][j] -= cur;
                    live.push_back(cur + 1);
                }
                else
                {
                    dead += cur / 2;
                }
            map[i][j].clear();
            for (int tree : live)
            {
                map[i][j].push_back(tree);
            }
            food[i][j] += dead;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
            food[i][j] = 5;
        }
    }
    int x, y, age;
    while (M--)
    {
        cin >> x >> y >> age;
        map[x - 1][y - 1].push_back(age);
    }
    int answer=0;
    while (K--)
    {
        springAndSummer();
        fall();
        winter();
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // cout<<map[i][j].size()<<" ";
            answer += map[i][j].size();
        }//cout<<"\n";
    }//cout<<"\n";
    cout << answer;
}
