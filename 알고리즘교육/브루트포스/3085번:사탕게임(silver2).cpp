/*
start:13:22
end:14:00
시간복잡도:O(N*N*N)모든 사탕에 대해.. 하나하나확인!
공간복잡도:O(N*N)
풀아: 단순구현 하지만 주의할점이 많음 밑에 주석참고
*/

#include <iostream>
#include <string>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int arr[51][51];
int visit[51][51];
int N;
int answer = 0;
void solve()
{
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < N; i++)
    {
        int now = arr[i][0];//가로로 
        int now2 = arr[0][i];//세로로 확인
        cnt = 0;
        cnt2 = 0; // 행이나 열이 바뀔때마다 0으로 시작해야한다 안그러면 이전 행열과 이어질수있음.!
        for (int j = 0; j < N; j++)
        {
            // 가로로 연속하게 확인
            if (now == arr[i][j])
            {
                cnt++;

                if (answer < cnt)
                {
                    answer = cnt;
                } // 꼭 다르지않더라도 행이나 열의 끝에 도달하면 확인필요.
            }
            else
            {
                if (answer < cnt)
                {
                    answer = cnt;
                }
                now = arr[i][j];
                cnt = 1;
            }
            if (now2 == arr[j][i])
            {
                cnt2++;
                if (answer < cnt2)
                {
                    answer = cnt2;
                } // 꼭 다르지않더라도 행이나 열의 끝에 도달하면 확인필요.
            }
            else
            {
                if (answer < cnt2)
                {
                    answer = cnt2;
                }
                now2 = arr[j][i];
                cnt2 = 1;
            }
        }
    }
}
int main()
{
    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            arr[i][j] = s[j];
        }
    }
    solve(); // 원래 판에대해서도 확인
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int z = 0; z < 4; z++)
            { // 동서남북으로 다른 사탕이있는지본다
                int nx = x + dx[z];
                int ny = y + dy[z];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                    continue; // 판을 넘어서면 넘어가
                if (arr[x][y] != arr[nx][ny])//두사탕이 다르다면
                {
                    int tmp = arr[x][y];
                    arr[x][y] = arr[nx][ny];
                    arr[nx][ny] = tmp; // 두 사탕의 위치를 바꾼다,
                    solve();
                    tmp = arr[x][y];
                    arr[x][y] = arr[nx][ny];
                    arr[nx][ny] = tmp; // 다시 원상복귀
                }
            }
        }
    }
    cout << answer;
}
