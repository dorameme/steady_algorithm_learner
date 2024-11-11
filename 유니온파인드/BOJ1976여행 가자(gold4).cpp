/*
start:17:23
end:17:43
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단하고 정석적인 유니온 파인드문제!
union find
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
#include <map>
using namespace std;
#define X first
#define Y second
int N, M;
int ma[201][201];
int parent[201];
void init()
{
    for (int i = 0; i < 201; i++)
    {
        parent[i] = i;
    }
}
int findParent(int idx)
{
    if (parent[idx] == idx)
        return idx;
    return parent[idx] = findParent(parent[idx]);
}
void merge(int x, int y)
{
    x = findParent(x);
    y = findParent(y);
    if (x != y)
    {
        if (x < y)
        {
            parent[x] = y; // 그룹번호 큰게 부모
        }
        else
        {
            parent[y] = x;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 도시수
    cin >> N;
    // 관광 수
    cin >> M;
    init();
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> ma[i][j];
            if (ma[i][j] == 1)
            {
                merge(i, j);
            }
        }
    }
    int go = 0;
    int next;
    cin >> go;
    for (int i = 1; i < M; i++)
    {
        cin >> next;
        if (findParent(next) != findParent(go))
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
