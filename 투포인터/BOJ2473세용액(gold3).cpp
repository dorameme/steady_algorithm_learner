/*
start:5:50
end:8:49
시간복잡도:O(N*N)
공간복잡도:O(N)
풀이: 투포인터를 이용해서 푸는 문제였다 중간을 고정시키고 포인터를 이동하는 방법으로 풀어냈다!
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#define X first
#define Y second
using namespace std;
long long N;
vector<long long> v;
long long a1 = 0, a2 = 1, a3 = 2;
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());

    int total = 1e18;
    for (int i = 1; i + 1 < N; i++)
    {
        long long l = i - 1, r = i + 1;
        while (r < N && l >= 0)
        {
            if (abs(v[i] + v[r] + v[l]) < abs(v[a1] + v[a2] + v[a3]))
            {
                a1 = l;
                a2 = i;
                a3 = r;
            }
            if (v[i] + v[r] + v[l] < 0)
            {
                r++;
            }
            else if (v[i] + v[r] + v[l] > 0)
            {
                l--;
            }
            else
            {
                cout << v[l] << " " << v[i] << " " << v[r];
                return 0;
            }
        }
    }
    cout << v[a1] << " " << v[a2] << " " << v[a3];
}
