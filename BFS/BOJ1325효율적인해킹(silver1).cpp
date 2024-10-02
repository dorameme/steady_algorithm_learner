/*
start:17:20
end:17:40
시간복잡도:O(NM)
공간복잡도:O(NM)
풀이:너비우선탐색으로 풀어주었다. 어려운문제는 아니였다. 
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    cin >> N >> M;
    vector<int> v[N + 1];
    int num1, num2;
    for (int i = 0; i < M; i++)
    {
        cin >> num1 >> num2;
        v[num2].push_back(num1);
    }
    vector<int> answer;
    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        int vis[10001] = {};
        queue<int> q;
        int helper = 0;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            helper++;
            int cur = q.front();
            if (cnt < helper)
            {
                cnt = helper;
                answer.clear();
                answer.push_back(i);
            }
            else if (cnt == helper)
            {
                answer.push_back(i);
            }
            q.pop();
            for (int i = 0; i < v[cur].size(); i++)
            {
                if (vis[v[cur][i]] != 1)
                {
                    vis[v[cur][i]] = 1;
                    q.push(v[cur][i]);
                }
            }
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
}
