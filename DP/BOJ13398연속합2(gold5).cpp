/*
시작:10:50
종료:12:17
시간복잡도:O(N)
공간복잡도:O(N)
풀이:디피로 풀어주는 기본문제
주의:max 나 min은 같은 자료형끼리만 가능하다는 걸 유의
아직까지도 dp에 익숙하지 않은것같다. 좀더 dp를 많이 공부해야겠다
*/
#include <iostream>
#include <algorithm>
using namespace std;

int a[100001];
int d[100001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = a[0];
    d[0][0] = d[0][1] = a[0];
    for (int i = 1; i < n; i++)
    {
        d[i][0] = max(d[i - 1][0] + a[i], a[i]);
        //이전에 삭제안했고/ 이번에도 삭제 x, 혹은 현재부터 다시시작
        d[i][1] = max(d[i - 1][0], d[i - 1][1] + a[i]);
        //이전에 삭제했고/ 이전에 삭제안한거 이번에 삭제, 쭉 이어서 간다
        ans = max(ans, max(d[i][0], d[i][1]));
    }
    cout << ans << '\n';
    return 0;
}
