#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    int num, k;
    cin >> num >> k;
    for (int i = 1; i <= num; i++)
    {
        q.push(i);
    }
    int cnt = 1;
    printf("<");
    while (!q.empty())
    {
        if (cnt == k)
        {
            cnt = 0;
            if (q.size() == 1)
            {
                printf("%d> ", q.front());
            }
            else
                printf("%d, ", q.front());
        }
        else
        {
            q.push(q.front());
        }
        q.pop();
        cnt++;
    }
}
