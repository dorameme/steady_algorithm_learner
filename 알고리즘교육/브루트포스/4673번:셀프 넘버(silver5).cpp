/*
start:12:00
end:12:14
시간복잡도:O(1)
공간복잡도:O(1)
풀이:10000까지의 셀프넘버를 구한다. 근데 주의할점.. 자기자신은 셀프넘버로 넣으면 안된다!..다른쪽에서 파생된 번호만 넣어야해서
arr에 새로생성된 애들만 표시해준다. 자기자신제외!!
*/
#include <iostream>
#include <queue>
using namespace std;
int arr[10001];
void solve(int num)
{
    if (num > 10000)
        return;
    if (arr[num])
        return;
    int newNum = num;
    while (num)
    {
        newNum += num % 10;
        num/=10;
    }
    solve(newNum);
    arr[newNum]=1;
    
}
int main()
{
    for (int i = 1; i < 10000; i++)
    {
        solve(i);
    }
    for (int i = 1; i < 10001; i++)
    {
        if (!arr[i])
        {
           cout << i << "\n";
        }
    }
}
