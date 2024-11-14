/*
start:9:00
end:9:14
사간복잡도:O(N)
공간복잡도:O(N)
풀이:칭찬받을때마다 dfs를 돌리면 시간초과가 뜬다 따라서 
이문제의 포인트는 칭찬을 모두 저장한뒤 dfs를 한번 돌리는 것이다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#define X first
#define Y second
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int super;
    int root;
    vector<int> compliments(n + 1);
    vector<int> answer(n + 1);
    vector<int> arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> super;
        if (super == -1)
        {
            root = i;
            continue;
        }
        arr[super].push_back(i); // 상사 -> 직원1, 직원2...
    }
    int employee, compliment;
    for (int i = 0; i < m; i++)
    {

        cin >> employee >> compliment;
        compliments[employee] += compliment;
    }
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
       int cur = q.front();
        q.pop();
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i];
            compliments[next] += compliments[cur];
            q.push(next);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << compliments[i] << "\n";
    }
}
