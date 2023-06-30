/*
start:11:40
end:12:19
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 간단한 위상정렬문제인데 시간초과가 날수있어서 최적화가 필요했다.
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <set>
#include <string>
#include <map>
#define X first
#define Y second
using namespace std;
int N, M, K;
int have[100001];
int canbuild[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    vector<int> need[100001];
    vector<int> v[100001];
    int a, b;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        need[b].push_back(a);
        v[a].push_back(b);
    }
    for (int i = 0; i < K; i++)
    {
        cin >> a >> b;
        if (a == 1)
        {
            for (int j = 0; j < need[b].size(); j++)
            {
                if(canbuild[b]==1){
                    have[b]++;
                    break;
                }
                if (have[need[b][j]] == 0)
                {
                    cout << "Lier!";
                    return 0;
                }
            }
            canbuild[b]=1;
            have[b]++;
        }
        else if (a == 2)
        {
            if (--have[b] < 0 )
            {
                cout << "Lier!";
                return 0;
            }
            if(have[b]==0){
                for (int j = 0; j < v[b].size(); j++){
                    canbuild[v[b][j]]=0;
                }
            }
        }
    }
    cout<<"King-God-Emperor";
}
