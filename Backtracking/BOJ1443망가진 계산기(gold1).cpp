/*
start:9:00
end:10:10
시간복잡도:O(N)
공간복잡도:O(N)
풀이:8를 곱하는경우 4를 곱하는경우 2를곱하는경우 순으로 (idx)가 증가하므로 배치가 중요하다.
9, 3 도 마찬가지 ... 그리고 메모리가 128MB이라 부족해서 풀지못한방식이있는데
메모리만 더있으면 used[2에대한 인덱스][3에대한인덱스][5에대한인덱스][7에대한인덱스][현재 쓴 숫자수] 이렇게 5차원으로 두면 그냥 풀린다. 
*/
#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
long long D, P;
long long MAXI = 100000000;
// 2/3/5/7/
//  4 6 8 9
long long need[] = {2, 3, 5, 7};
long long used[31][31][31][31];
long long answer = -1;
bool check(long long now)
{
    for (long long i = 0; i < D; i++)
    {
        now /= 10;
    }
    if (now)
        return true;
    return false;
}
void solve(long long now, long long idx, int a, int b, int c, int d)
{

    if (check(now))
        return;

    if (idx == P)
    {
        if (answer < now)
            answer = now;
        return;
    }
    if (used[a + 3][b][c][d]<idx+1)
      
    {
        used[a + 3][b][c][d]++;
        solve(now * 8, idx + 1, a + 3, b, c, d);
    }

    if (used[a + 2][b][c][d]<idx + 1)
    {
        used[a + 2][b][c][d]++;
        solve(now * 4, idx + 1, a + 2, b, c, d);
    }
    if (used[a][b + 2][c][d]<idx + 1)
    {
        used[a][b + 2][c][d]++;
        solve(now * 9, idx + 1, a, b + 2, c, d);
    }
    if (used[a + 1][b][c][d]<idx+1)
    {
        used[a + 1][b][c][d]++;
        solve(now * 2, idx + 1, a + 1, b, c, d);
    }

    if (used[a][b + 1][c][d]<idx + 1)
    {
        used[a][b + 1][c][d]++;
        solve(now * 3, idx + 1, a, b + 1, c, d);
    }

    if (used[a][b][c + 1][d]<idx + 1)
    {
        used[a][b][c + 1][d]++;
        solve(now * 5, idx + 1, a, b, c + 1, d);
    }

    if (used[a][b][c][d + 1]<idx + 1)
    {
        used[a][b][c][d + 1]++;
        solve(now * 7, idx + 1, a, b, c, d + 1);
    }
    if (used[a + 1][b + 1][c][d]<idx + 1)
    {
        used[a + 1][b + 1][c][d]=idx+1;
        solve(now * 6, idx + 1, a + 1, b + 1, c, d);
    }

}
int main()
{
    cin >> D >> P;
    solve(1, 0, 0, 0, 0, 0);
    cout << answer;
}
