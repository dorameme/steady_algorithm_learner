/*
start:13:00
end:14:00
시간복잡도:O(2*N)
공간복잡도:O(2*N)
풀이: 이문제를 통해 내가 dp에 대한 개념이 좀더 잡혔다 나는 처음 풀때 solve 가 결과값을 들고다니게 짰는데 그렇게하면 에러가 난다.
 따라서 
    return dp[x][y][idx] = min(solve(dir, y, idx + 1, power + cal(x, dir)),//power+cal() 로 정답을 들고다님 이러면 안
                               solve(x, dir, idx + 1, power + cal(y, dir))); 이게 틀린점화식
                               
                               
    return dp[x][y][idx] = min(solve(dir, y, idx + 1)+ cal(x, dir),
                               solve(x, dir, idx + 1)+ cal(y, dir));이렇게 짜줘야한다.
*/
#include <iostream>
#include <vector>
#define X first
#define Y second
using namespace std;
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, -1, 0, 1};
vector<int> v;
int dp[5][5][100001];
int cal(int x, int y)
{
    if (x == 0)
        return 2;
    else if (abs(x - y) == 1 || abs(x - y) == 3)
        return 3;
    else if (abs(x - y) == 2)
        return 4;
    else if (x == y)
        return 1;
}
int solve(int x, int y, int idx)
{
    if (x == y && x != 0)
    {
        return 987654321;
    }
    if (idx == (int)v.size())
    {
        return 0;
    }
    if (dp[x][y][idx])
    {
        return dp[x][y][idx];
    }

    int dir = v[idx];

    return dp[x][y][idx] = min(solve(dir, y, idx + 1)+ cal(x, dir),
                               solve(x, dir, idx + 1)+ cal(y, dir));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int num;
    cin >> num;
    while (num)
    {
        v.push_back(num);
        cin >> num;
    }
    cout << solve(0, 0, 0);
}
