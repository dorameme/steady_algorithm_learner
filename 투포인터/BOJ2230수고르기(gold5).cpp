/*
start:14:00
end:14:20
시간복잡도O(N)
공간복잡도:O(N)
풀이: 투포인터는 항상 양방향에서 가까워지는 형식으로 풀어야되는줄 알았는데 아니였다.. ㅋㅋ그리고 주의할 점은 두 수가 같아도 된다는것! 다시말해 조건을 잘보자!
*/

#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#define X first
#define Y second
using namespace std;
long long N;
long long M;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    long long num;
    for (long long i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    long long s = 0;
    long long e = 1;
    long long answer = v[N-1]-v[0];
    while (s <= e && e<N)
    {
        if (v[e] - v[s] > M)
        {
            if(v[e]-v[s]<answer)
            {
                answer=v[e]-v[s];
            }
            s++;
        }
        else if (v[e] - v[s] < M)
        {
            e++;
        }
        else
        {
            cout << M;
            return 0;
        }
    }
    cout<<answer;
}
