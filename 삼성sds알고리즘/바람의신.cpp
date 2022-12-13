/*
start:10:30
end:11;29
시간복잡도:O(4^N)
공간복잡도:O(N*M*K) 
풀이:순서에따라 결과가 달라지므로 K값에 따라 계속 새로운  이차원 벡터를 만들도록했다.
매개변수로 들어온 이차원 백터를 deepcopy하며 풀어주었다.
*/
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<vector<int>> board(101, vector<int>(101, 0));
int T, N, M, K;
int answer;

void solve(int idx, vector<vector<int>> &new_board)
{
    if (idx == K)
    {
        for (int i = 0; i < N; i++)
        {
            for (int m = 0; m < M; m++)
            {
                if (answer < new_board[i][m])
                    answer = new_board[i][m];
            }
        }
        return;
    }
    vector<vector<int>> lastest = new_board;
    //서에서 동으로
    for (int i = 0; i < N; i++)
    {
        for (int m = 0; m < M - 1; m++)
        {
            if (lastest[i][m])
            {
                lastest[i][m + 1] += lastest[i][m];
                lastest[i][m] = 0;
                break; //한행에 대해서는 한개만 실행
            }
        }
    }
    solve(idx + 1, lastest);

    lastest = new_board;
    //동에서 서로
    for (int i = 0; i < N; i++)
    {
        for (int m = M - 1; m > 0; m--)
        {
            if (lastest[i][m])
            {
                lastest[i][m - 1] += lastest[i][m];
                lastest[i][m] = 0;
                break;
            }
        }
    }
    solve(idx + 1, lastest);

    lastest = new_board;
    //북에서 남으로
    for (int m = 0; m < M; m++)
    {
        for (int i = 0; i < N - 1; i++)
        {
            if (lastest[i][m])
            {
                lastest[i + 1][m] += lastest[i][m];
                lastest[i][m] = 0;
                break;
            }
        }
    }
    solve(idx + 1, lastest);

    lastest = new_board;
    //남에서 북으로
    for (int m = 0; m < M; m++)
    {
        for (int i = N - 1; i > 0; i--)
        {
            if (lastest[i][m])
            {
                lastest[i - 1][m] += lastest[i][m];
                lastest[i][m] = 0;
                break;
            }
        }
    }
    solve(idx + 1, lastest);
}
int main()
{
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> N >> M >> K;
        // make a board
        for (int i = 0; i < N; i++)
        {
            for (int m = 0; m < M; m++)
            {
                cin >> board[i][m];
            }
        }
        answer = 0;
        solve(0,board);
        cout << '#' << i << ' ' << answer << "\n";
    }
}
