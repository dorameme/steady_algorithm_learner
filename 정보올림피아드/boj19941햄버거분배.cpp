/*
start:18:40
end:18:59
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 너무 쉬운문젠데 혹시나 해서 고민을 좀했다.. 사실 덱도 필요없는데 덱을씀. 그냥 queue로 푸는게 나을듯.
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
int n, k;
string s;
int main()
{
    deque<int> hamberger;
    deque<int> people;
    cin >> n >> k >> s;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == 'H')
            hamberger.push_back(i);
        else
        {
            people.push_back(i);
        }
    }
    int answer = 0;
    while (!people.empty() && !hamberger.empty())
    {
        int p = people.front();
        int h = hamberger.front();
        if (p - k <= h)
        {
            if (p + k >= h)
            {  
                answer++;
                people.pop_front();
                hamberger.pop_front();
            }
            else{
                people.pop_front();
            }
        }
        else
        {
            hamberger.pop_front();
        }
    }
    cout << answer;
}
