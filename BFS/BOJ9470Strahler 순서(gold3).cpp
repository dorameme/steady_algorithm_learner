/*
start:15:05
end:15:44
시간복잡도:O(P)
공간복잡도:O(M)
풀이: 문제의 모든 부분을 구현하는것이 중요하다고 느낀문제. 웬만하면 모든조건을 담고 진행하는게 정확도면에서 우수한것 같다.
나는 조건을 한개 빠뜨려서 조금 애먹었는데 들어오는간선에 대해 이 숫자가 몇번쨰로 들어오는건지 신경써줘야했다. 
*/
#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;

int T, K, M, P;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> K >> M >> P;
        vector<int> in(M + 1);
        vector<int> out[M + 1];
        int last;
        for (int i = 0; i < P; i++)
        {
            int A, B;
            cin >> A >> B;
            in[B]++;
            out[A].push_back(B);
        }
        queue<pair<int, int>> q;

        for (int i = 1; i <= M; i++)
        {
            if (in[i] == 0)
            {
                in[i] = -1;
                q.push({i, 1});
            }
        }
        int answer = 1;
        vector<int> count(M + 1);
        vector<int> totalCount(M + 1);
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            answer = max(answer, cur.Y);
            q.pop();
            for (int i = 0; i < out[cur.X].size(); i++)
            {
                int target = out[cur.X][i];
                in[target]--;
                if (count[target] == 0)
                {
                    totalCount[target] = 1;
                    count[target] = cur.Y;
                }
                else if (count[target] == cur.Y)
                {
                    if (totalCount[target] == 1){
                        count[target]= cur.Y + 1;
                        totalCount[target] = 0;
                    }
                    else{
                    totalCount[target]=1;
                    count[target] = cur.Y;
                    }
                }
                else if (count[target] < cur.Y)
                {
                    totalCount[target]=1;
                    count[target] = cur.Y;
                }
                if (in[target] == 0)
                {
                    in[target] = -1;
                    q.push({target, count[target]});
                }
            }
        }
        cout << K << " " << answer<<"\n";
    }
}
