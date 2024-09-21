/*
start: 16:40
end: 17:23
시간복잡도: O(N*N)
공긴복잡도: O(N*N)
풀이: 이 알고리즘은 매 순간 ‘뒤집어야 하는 칸의 뒤집는 횟수를 최소화한다’는 점에서 그리디 알고리즘으로 분류된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N, M;
int A[51][51];
int B[51][51];
bool isSame()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (A[i][j] != B[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    string helper;
    for (int i = 0; i < N; i++)
    {
        cin >> helper;
        for (int j = 0; j < M; j++)
        {
            A[i][j] = helper[j] - '0';
        }
    }
    for (int i = 0; i < N; i++)
    {
        cin >> helper;
        for (int j = 0; j < M; j++)
        {
            B[i][j] = helper[j] - '0';
        }
    }
    int answer = 0;
    if (isSame())
    {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < N - 2; i++)
    {
        for (int j = 0; j < M - 2; j++)
        {
            if (isSame())
            {
                cout << answer;
                return 0;
            }
            if (A[i][j] != B[i][j])
            {
                answer++;
                for (int x = 0; x <= 2; x++)
                {
                    for (int y = 0; y <= 2; y++)
                    {
                        A[i + x][j + y] = A[i + x][j + y] == 1 ? 0 : 1;
                    }
                }
            }
        }
    }
    if (isSame())
    {
        cout << answer;
        return 0;
    }
    cout << -1;
}
