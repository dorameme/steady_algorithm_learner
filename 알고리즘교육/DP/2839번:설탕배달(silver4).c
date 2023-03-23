/*
start:10:50
end:11:01
시간복잡도:O(N)
공간복잡도:O(N)
풀이: min함수를 이용하여 제일 적은답을 구하되 MAX 보다 큰 값이 나오면 -1 을 프린틀한다.
*/
/#include <iostream>
using namespace std;
int bag[5001];
int MAX=987654321;
int solve(int num)
{
    if (bag[num])
        return bag[num];
    if (num >= 5)
    {
        return bag[num] = min(solve(num - 5), solve(num - 3)) + 1;
    }
    else if (num >= 3)
    {
        return bag[num] = solve(num - 3) + 1;
    }
    else if (num == 0)
        return 0;
    else
    {
        return MAX; // 임의의 큰값
    }
}
int main()
{
    int num;
    cin >> num;
    int answer=solve(num);
    if(answer>=MAX)cout<<-1;
    else cout<<answer;
}
