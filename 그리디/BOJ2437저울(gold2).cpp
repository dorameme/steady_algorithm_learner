/*
start:8:50
end:9:12
시간복잡도:O(N)
공간복잡도:O(N)
풀이:그리디 + 누적합 문제이다. 총 현재 x 일때 x+1 을 만들 수 있는가? 에대한 물음을 해결하는 문제
*/

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<int> chu;
// long long answer;
queue<long long> q;
int n;
long long weight[1000000];
int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        chu.push_back(num);
    }
    sort(chu.begin(), chu.end());
    int sum=chu[0];
    if(sum>1){cout<<1; return 0;};
    for (int i = 1; i < n; i++)
    {
      if( chu[i]>sum+1)break;
        sum=sum+chu[i];
    }
    cout<< sum+1;
}
