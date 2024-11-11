/*
start;13:21
end:15:22
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 그냥패턴이 같은그룹중 제일 큰 그룹이 정답이된다..
발상이 개인적으로 어려웠는데 그냥 unordered _map 에 문자열 패턴 하나하나 다 저장해서 몇갠지 세어주면 된다.
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
string arr[51];
unordered_map<string, pair<int, int>> ma;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        ma[arr[i]].X++;
        int cnt = 0;
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == '0')
                cnt++;
        }
        ma[arr[i]].Y = cnt;//이만 큼 눌러야해..
    }
    cin >> K;
   
    for (auto m : ma)
    {
        // cout<<"helper"<<m.X<<" "<<m.Y.X<<" "<<m.Y.Y<<"\n";
        if ((m.Y.Y % 2 == K % 2) && m.Y.Y <= K){
            answer = max(answer, m.Y.X);
        }
    }
    cout << answer;
}
