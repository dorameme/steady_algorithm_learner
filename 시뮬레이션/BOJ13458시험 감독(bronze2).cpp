/*
start:9:00
end:9:20
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 그냥 구현문제인데주의 할 점이 몇개 있다.
1. ceil((v[i] - B) /(double) C); 이부분에서 doubled 안넣어주면 정수값이 나와서 ceil이 적용이 안됨
2. ceil은 cmath 헤더에 있음
3. 답은 long long 타입임
4. 음수일때 연산이 되면 안되므로 양수일때 나누기를 해줘야함.
5. 결론적으로 쉬운문제 답이 안풀릴땐 세부조건을 많이 넣어주자..
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int v[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    int B, C;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    cin >> B >> C;
    long long answer = N;
    for (int i = 0; i < N; i++)
    {
        if (v[i] - B > 0){
            answer += ceil((v[i] - B) /(double) C);
        }
    }
    cout << answer;
}
