/*
run:14:10~14:32
시간복잡도:O(N)
공간복잡도:O(N)
풀이:각각 앞이 3 인지 2 인지 1인지 경우를 구한뒤 다 더해풀어준다. 주의할 점은 중복이 나올수 있으므로 1이 앞인경우 나머지다 1로 2가 앞인경우 1,2만 3인경우 1,2,3 만 쓸수 
있다는 걸 명심해준다.
*/
#include <stdio.h>
#include <string.h>
long long dp[1000001][4];
long long solve(int n, int front)
{
    if(n<=0)return 0;
    if (dp[n][front])
        return dp[n][front];
    for (int i = 1; i <=front; i++)
    {
        dp[n][front] += solve(n - front, i);// 1 or 2 or 3;
    }
    return dp[n][front];
}
int main()
{
    int n;
    scanf("%d", &n);
    int num;
    dp[1][1] = 1;
    dp[2][2]=1;
    dp[2][1]=1;
    dp[3][1]=1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        printf("%lld\n", solve(num,1)+solve(num,2)+solve(num,3));
    }
}
