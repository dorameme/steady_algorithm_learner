/*
start:12:00
end:12:35
시간복잡도:O(NlgN)
공간복잡도:O(N)
풀이:
comp함수 넘길 때 그냥 복사하는형식으로 넘겨도되지만 주소로 넘기는게 더 낫다
근데 주소로 넘기면 .... 
주의할 점은 & 만 있고 const가 없으면 원본 데이터가 실수로 변경될 수 있어서, 
보통은 const & 형태로 같이 사용
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define X first
#define Y second
bool comp(const pair<int, int> &x, const pair<int, int> &y)
{
    if (x.X == y.X)
    {
        return x.Y < y.Y;
    }
    else
    {
        return x.X < y.X;
    }
}
int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    int num;
    for (int i = 0; i < N; i++)
    {
        cin >> num >> v[i].X >> v[i].Y;
    }
    sort(v.begin(), v.end(), comp);
    priority_queue<int, vector<int>, greater<int>> end;
    end.push(0);
    for (int i = 0; i < N; i++)
    {
        if (end.top() <= v[i].X)
        {
            end.pop();
            end.push(v[i].Y);
        }
        else
        {
            end.push(v[i].Y);
        }
    }
    cout<<end.size();
}
