/*
start:10:20
end:10:45
시간복잡도:O(N)
공간복잡도:O(N)
풀이: dp를 이용해서 풀어준다 
*/
#include <iostream>
using namespace std;
int zero, one;
int fibo[41][2];

int fibonacci(int num, int idx)
{
    if (num < 0)
        return 0;///종료되는 조건
    if (fibo[num][idx])
        return fibo[num][idx]; // 이미 계산되어있으면
    if (num == 0)
    {
        if (idx == 0)
            return 1;
        return 0;
    }
    else if (num == 1)
    {
        if (idx == 1)
            return 1;
        return 0;
    }
    return fibo[num][idx] = fibonacci(num - 1, idx) + fibonacci(num - 2, idx);
   
}
int main()
{
    int T;
    cin >> T;
    int num;
    while (T--)
    {
        cin >> num;
        cout << fibonacci(num, 0) << " " << fibonacci(num, 1) << "\n";
    }
}
