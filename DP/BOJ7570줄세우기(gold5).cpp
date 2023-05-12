/*
start:11:20
end:11:53
시간복잡도:O(N/P+N/Q)
공간복잡도:O(N/P+N/Q)
풀이: 범위가 엄청크므로 모든 값을 다 탐색할 수는 없다 따라서 필요한 애들만 찾아서 계산해줘야한다. 자료형을 실수로 int 로 둬서 틀렸다 ㅜㅜ
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> m;
long long N, P, Q;
long long solve(long long  n)
{
    if (n == 0)
        return 1;
    if (m[n])
        return m[n];
    return m[n] = solve(n / P) + solve(n / Q);
} // 필요한 dp 인덱스 구하기
int main()
{
    cin >> N >> P >> Q;
    m[0] = 1;
    cout<<   solve(N);

}
