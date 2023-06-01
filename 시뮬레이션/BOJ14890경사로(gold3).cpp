/*
start:9:00
end:9:32
시간복잡도:O(N*N)
공간복잡도:O(N*N)
풀이:구현문제는 최대한 문제를 정확히 읽고 메서드를 많이 나눠서 보기 깔끔하게해야 잘풀린다.
*/

#include <iostream>
using namespace std;
int N, L;
int arr[101][101];
int row[101][101];
int col[101][101];
int answer;
int used[101][101];
int count(int i, int j)
{
    if (j - L < 0)
        return 0;
    for (int k = j - L; k < j; k++)
    {
        if (arr[i][k] != arr[i][j - 1]||used[i][k])
        {
            return 0;
        }
    }
    for (int k = j - L; k < j; k++)
    {
        used[i][k]++;
    }
    return 1;
}
int count2(int i, int j)
{
    if (j + L - 1 >= N)
        return 0;
    for (int k = j; k < j + L; k++)
    {
        if (arr[i][k] != arr[i][j]||used[i][j])
        {
            return 0;
        }
    }
    for (int k = j; k < j + L; k++)
    {
        used[i][k]++;
    }
    return 1;
}
void solve()
{
    for (int i = 0; i < N; i++)
    {
        int flag = 1;
        int cnt = 0;
        for (int j = 1; j < N; j++)
        {
            if (arr[i][j] == arr[i][j - 1])
            {
                continue;
            }
            else if (arr[i][j] == arr[i][j - 1] + 1)
            {
                if (count(i, j) == 0)
                {
                    flag = 0;
                    break;
                }
            }
            else if (arr[i][j] + 1 == arr[i][j - 1])
            {
                if (count2(i, j) == 0)
                {
                    flag = 0;
                    break;
                }
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            answer++;
        }
    }
}
int main()
{
    cin >> N >> L;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
            col[j][i] = arr[i][j];
        }
    }
    solve();
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            used[i][j]=0;
            arr[i][j] = col[i][j];
        }
    }
    solve();
    cout << answer;
}
