/*
start:8:00
end:10:04
시간복잡도:O(V+E) 모든노드는 3번이상 방문하지않는다.
공간복잡도:O(V)
풀이: 또또 오기때문에 약 2시간을 썼다.
한 노드에 재방문할수있고 그 횟수는 3을 넘지 않으므로 세번까지 방문할수있도록하고 풀었다
재방문의 경우는 양이나 늘대 숫자를 셀필요가 없으므로 방문횟수가 양+1 or 늑대+1일때만 신경써줬다.
+ 더 좋은코드를 찾았다 주석을 달아놨으니 확인해보자!
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> connected[17];
int answer;

void count_sheep(int *visited, vector<int> &info, int sheep, int fox, int now)
{

    if (sheep > answer)
        answer = sheep;

    int len = connected[now].size();
    
    for (int i = 0; i < len; i++)
    {
        int where = connected[now][i];

        if (visited[where] > 3)
            continue;

        if (visited[where] == 0)
        {
            if (info[where] == 0)
            { // sheep
                visited[where]++;
                count_sheep(visited, info, sheep + 1, fox, where);
                visited[where]--;
            }
            else // fox
            {
                if (sheep == fox + 1)
                    continue;
                visited[where]++;
                count_sheep(visited, info, sheep, fox + 1, where);
                visited[where]--;
            }
        }
        else
        {
            if (info[where] == 0)
            { // sheep

                visited[where]++;
                count_sheep(visited, info, sheep, fox, where);
                visited[where]--;
            }
            else // fox
            {
                if (sheep == fox + 1)
                    continue;

                visited[where]++;
                count_sheep(visited, info, sheep, fox, where);
                visited[where]--;
            }
        }
    }
 }
int solution(vector<int> info, vector<vector<int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        connected[edges[i][0]].push_back(edges[i][1]);
        connected[edges[i][1]].push_back(edges[i][0]);
    }
    int visited[17] = {
        0,
    };
    visited[0] = 1;
    count_sheep(visited, info, 1, 0, 0);
    return answer;
}


#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> info_g;

int ans = 0;

void DFS(int cur, int sheep, int wolf, queue<int> q) {
    
    if (info_g[cur] == 0) {
        sheep++;
    } else {
        wolf++;
    }
    
    if (wolf >= sheep) return;
    if (ans < sheep) ans = sheep;
    
    // add new candid
    for (int i = 0; i < graph[cur].size(); i++) {
        q.push(graph[cur][i]);
    }
    
    for (int i = 0; i < q.size(); i++) {
        int next = q.front();
        q.pop();
        DFS(next, sheep, wolf, q);
        q.push(next);//모든 경우를 순서를 바꾸어 다 방문할 수 있도록 다시넣어준다 //현재 노드에대해 중복되어 세는 경우도 없다!! 너무 좋은코드
    }
}


int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    
    graph.assign(n, vector<int>({}));
    info_g.assign(info.begin(), info.end());
    
    for (int i = 0; i < n-1; i++) {
        int pi = edges[i][0];
        int ci = edges[i][1];
        graph[pi].push_back(ci);/
    }
    queue<int> q;
    DFS(0, 0, 0, q);
    return ans;
}
