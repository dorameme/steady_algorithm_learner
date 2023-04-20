/*
start:20:00
end:20:30
시간복잡도:O(N)
공간복잡도:O(N)
풀이:공간을 분할해가며 두번째로 작은 숫자를 찾아낸다. 재귀적을 구성한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2000][2000];

int solve(int x, int y, int x2, int y2)
{
    vector<int> v;
    if(x==x2){return arr[x][y];}
    
    else
    {
        int mid = (x + x2) / 2;
        int mid2 = (y + y2) / 2;
        v.push_back(solve(x, y, mid, mid2));      /// 상 왼
        v.push_back(solve(mid + 1, y, x2, mid2)); // 하 왼
        v.push_back(solve(x, mid2+1, mid, y2));     // 상 오
        v.push_back(solve(mid+1, mid2+1, x2, y2));    //하 오
        sort(v.begin(), v.end());
        return v[1];
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << solve(0, 0, n - 1, n - 1);
}
