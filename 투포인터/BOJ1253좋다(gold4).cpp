/*
start:16:00
end:16:20
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 투포인터문제 역시나 조건만 잘읽으면 쉽게풀수있다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>
#define X first
#define Y second
using namespace std;
long long N;
vector<long long> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    long long num;
    for (long long i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    long long answer = 0;
    for (int i = 0; i < N; i++)
    {
        long long s = 0;
        long long e = N - 1;
        while (s < e ) 
        {
            if(i==s){s++;continue;}
            if(i==e){e--;continue;}//두수가 주어진 수랑 같으면 안된다.
            if (v[e] + v[s] > v[i])
            {
                e--;
            }
            else if (v[e] + v[s] < v[i])
            {
                s++;
            }
            else
            {
                answer++;
                break;
            }
        }
    }
    cout << answer;
}
