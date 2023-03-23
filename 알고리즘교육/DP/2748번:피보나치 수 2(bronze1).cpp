/*
start:11:30
end:11:34
시간복잡도: O(N)
공간복잡도:O(N)
풀이: 주의할점이 있다. 간단 dp 지만 값이 매우 커지므로 long long을 써줘야 한다는것!
*/
#include <iostream>
using namespace std;
long long dp[91];
long long fibo(int num)
{
    if (num == 0)
        return 0;
    else if (num == 1)
        return 1;
    if (dp[num])
        return dp[num];
    return dp[num] = fibo(num - 1) + fibo(num - 2);
}
int main(){
    int n;
    cin >> n;
    cout << fibo(n);
}
