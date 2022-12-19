/*
start:8:20
end:11:45
풀이: 그냥 구현인데 문제해석이 중요했음....
교훈
문제를 똑바로 읽고 해석하자...그냥 구현문제인데 잘못이해해서 3시간씀
*/
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;
int check(string p)
{
    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
        {
            cnt++;
        }
        else
        {
            cnt2++;
        }
        if (cnt == cnt2)
            return i + 1;
    }
    return 0;
}
bool balance(string p)
{
    stack<string> ss;
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] == '(')
        {
            ss.push("(");
        }
        else
        {
            if (ss.empty())
            {
                return false;
            }
            else
            {
                ss.pop();
            }
        }
    }
    if (ss.empty())
        return true;
    return false;
}
string reverse(string s)
{
    string answer = "";
    for (int i = 0; i < s.size(); i++)
    {

        if (s[i] == ')')answer+="(";
        else{answer+=")";}
    }
    return answer;
}
string solve(string p)
{
    cout << p << "p\n";
    if (p.size() == 0)
        return "";
    int idx = check(p);
    string u = p.substr(0, idx);
    string v = p.substr(idx);
    cout << "u" << u << "v" << v << "\n";
    if (balance(u))
    {
        return u + solve(v);
    }
    else
    {
        return "(" + solve(v) + ")" + reverse(u.substr(1, u.size() - 2));
    }
}
string solution(string p)
{
    return solve(p);
}
