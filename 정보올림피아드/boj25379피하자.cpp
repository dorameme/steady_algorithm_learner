/*
start:13:14
end:15:07
시간복잡도:O(N)
공간복잡도:O(N)
풀이:틀린이유는 자료형을 long long 으로 안해줘서 틀렸다. 들어올수있는 N 의 수가 1,000,000이었으므로
스왑되는 수는 훨씬 많아 long long자료형이 필요했다.
*/
#include <iostream>
#include <vector>
using namespace std;
int n;
long long putEvenLeft(vector<int> &v)
{
    int even = 0;
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i]%2 == 0)
        {
            even++;
        }
        break;
    }
    for (int i = even; i < n; i++)
    {
        if (v[i]%2== 0)
        {
            total += i-even;
            even++;
        }
    }
    return total;
}
long long putOddLeft(vector<int> &v)
{
    int now = n - 1;
    int odd = 0;
    long long total = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i]%2 == 1)
        {
            odd++;
        }
        break;
    }
    for (int i = odd; i < n; i++)
    {
        if (v[i]%2 == 1)
        {
            total += i-odd ;
            odd++;
        }
    }
    return total;
}
int main()
{

    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << min(putEvenLeft(v) , putOddLeft(v));
}
