/*
start:15:23
end17:06
시간복잡도:O(N^3)
공간복잡도:O(N^2)
풀이: 나는 유니온 파인드를 써본적이없다.. ㅠㅠ 왤까 ,..
union find로 풀면 O(N)이다..
이다음문제로는 유니온 파인드 문제를 풀어봐야겠다. 테스트 셋이 적어서 플로이드워셜러도 풀수있었지만 운이좋았을뿐..
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
int N, M, K;
int answer = 0;
int linked[51][51];
int know[51];
int party[51][51];
unordered_map<int, int> map;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 사람수 파티수
    cin >> N >> M;

    // 아는애들
    cin >> K;

    // 아는애들
    int num;
    for (int i = 0; i < K; i++)
    {
        cin >> num;
        know[num] = 1;
    }

    // 각 파티인원
    for (int i = 1; i <= M; i++)
    {
        vector<int> v;
        int person;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            cin >> person;
            v.push_back(person);
            party[i][person] = 1;
        }
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
            {
                if (v[i] != v[j])
                    linked[v[i]][v[j]] = linked[v[j]][v[i]] = 1;
            }
        }
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i != j && linked[i][k] == 1 && linked[k][j] == 1)
                {

                    linked[i][j] = 1;
                }
            }
        }
    }
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
            if (know[k] == 1 && linked[k][i] == 1)
            {
                know[i] = 1;
            }
    }

    // 파티 i번쨰 에서
    int answer = 0;
    for (int i = 1; i <= M; i++)
    {
        bool flag = true;
        // 아는애 j가있나? 아니면 연결되어서 아는애가 있냐?..
        for (int j = 1; j <= N; j++)
        { // j 가 참가하는데 j 랑친구중에 아는애가 있냐?
            if (party[i][j] == 1 && know[j] == 1)
            {
                flag = false;
                break;

                // }
            }
        }
        if (flag)
        {
            answer++;
        }
    }
    cout << answer;
}
