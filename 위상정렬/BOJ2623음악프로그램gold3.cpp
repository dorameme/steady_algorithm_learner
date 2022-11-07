/*
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 위상정렬로 풀어주되.... 여러값이 들어오므로 주의해준다. 
정석대로 queue에 indgreee가 0 인 값을 찾아가며 스택에 정답을 하나씩넣어서 나중에 거꾸로 프린트해주었다.
*/

#include <iostream>
#include <queue>
#include <stack>   
#include <string>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> deg(N + 1);
    vector<queue<int>> row(N + 1);
    int cnt, num1, num2;
    queue<int> q;
    stack<int> answer;
    for (int i = 0; i < M; i++)
    {
        cin >> cnt;
        cin >> num1;
        for (int n = 1; n < cnt; n++)
        {
            cin >> num2;
            deg[num1]++;
            row[num2].push(num1); // num2가 가리키고있는 애들
            num1 = num2;
        }
    }
    cnt = 0;
    int visit[100001] = {
        0,
    };
    while (cnt < N)
    {
        bool can_do=false;
        for (int i = 1; i <= N; i++)
        {
            if (visit[i] == 0 && deg[i] == 0)
            {
                can_do=true;
                visit[i]=1;
                cnt++;
                answer.push(i);
                q.push(i);
                while (!q.empty())
                {
                    int cur = q.front();
                    q.pop();
                    while (!row[cur].empty())
                    {
                        deg[row[cur].front()]--;
                        row[cur].pop();
                    }
                }
            }
        }
            if(can_do==false){
                cout<<0;
                return 0;
            }
    }
    while (!answer.empty())
    {
        cout << answer.top() << "\n";
        answer.pop();
    }
    return 0;
}