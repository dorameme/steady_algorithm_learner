/*
start:13:59
end:14:10
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단한 구현문제였다. 사실 이젠 골드5는 쉬워서 금방 풀리는것같다. 문자열자체도 짧아서 완탐으로 풀수있었다
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string S, T;
int answer;
void solve()
{
    if(T.size()<S.size())return;
    if (answer == 1)
        return;
    if (T == S)
    {
        answer = 1;
        return;
    }
    if (T[T.size() - 1] == 'A')
    {
        T.pop_back();
        solve();
        T.push_back('A');
    }
    else if (T[T.size() - 1] == 'B')
    {
        T.pop_back();
        reverse(T.begin(), T.end());
        solve();
        T.push_back('B');
    }
}
int main()
{
    cin >> S >> T;
    solve();
}
