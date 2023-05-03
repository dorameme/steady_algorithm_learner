/*
start:14:30
end:15:03
시간복잡도:O(N*M)
공간복잡도:O(N*M)
풀이:동적계획법으로 풀지않아도 풀리는 동적계획법 문제다. 나는 맵을 써서 중복되는 값을 줄였다. 그리고 초반에 둘다 ? 혹은 * 가나올수있는줄알고 엄청 어려운문젠줄알았는데 
생각보다 쉬웠다.
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
string S;
string target;
int answer;
map<pair<string, string>, int> m;
void solve(string A, string B)
{
    // cout << "\nA: " << A << " B: " << B << "\n";
    if (answer || m[make_pair(A, B)])
        return;
    if (A.empty())
    {
        if (B.empty())
        {
            answer = 1;
        }
        else
            return;
    }
    if (A.size() > 0 && B.size() > 0)
    {
        if (A[A.size() - 1] == '*')
        {
            while (A[A.size() - 1] == '*')
            {
                A.pop_back();
            }
            solve(A, B);
            while (B.size())
            {
                B.pop_back();
                solve(A, B);
            }
        }
        else if (A[A.size() - 1] == '?' || A[A.size() - 1] == B[B.size() - 1])
        {
            A.pop_back();
            B.pop_back();
            solve(A, B);
        }
    }
    while (A[A.size() - 1] == '*')
        A.pop_back();
    if (A.empty()&&B.empty())
        answer = 1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> v;
        cin >> target;
        reverse(target.begin(), target.end());
        int n;
        cin >> n;
        while (n--)
        {
            answer = 0;
            cin >> S;
            reverse(S.begin(), S.end());

            solve(target, S);
            if (answer)
            {

                reverse(S.begin(), S.end());
                v.push_back(S);
            }
        }
        sort(v.begin(), v.end());
        for (auto str : v)
        {
            cout << str << "\n";
        }
    }
}
