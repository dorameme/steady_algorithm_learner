/*
start:14:00
end:14:40
시간복잡도:O(2^N)
공간복잡도:O(2^N)
풀이:짧은string에서 긴string 으로 가는 과정은 너무 경우의수가많아지므로 긴쪽애서 짧은string으로 규칙을 이용해 변형 
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S, T;
int answer = 0;
void solve(string s)
{
    if (s == S)
    {
        answer=1;
        return;
    }
    if (s.size() <= S.size())
    {   return;
    }
    if (s[s.size() - 1] == 'A')
    {
        string t = s;
        t.pop_back();
        solve(t);
    }
    if (s[0] == 'B')
    {
        string t = s;
        reverse(t.begin(), t.end());
        t.pop_back();
        solve(t);
    }

}
int main()
{
    cin >> S >> T;
    solve(T);
    cout << answer;
}
