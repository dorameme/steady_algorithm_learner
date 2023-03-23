/*
start:14:20
end:14:32
시간복잡도:O(1)
공간복잡도:O(1)
풀이:주어진 문제조건을 잘 확인해서 푸는게 중요하다! 쉬운데 틀리면 문제다시읽어보기!
*/
#include <iostream>
#include <queue>
using namespace std;
int card[101];
int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }
    int answer = 987654321;
    for (int i = 0; i < N; i++)
    {
        for (int m = i + 1; m < N; m++)
        {
            for (int j = m + 1; j < N; j++)
            {
                int sum = card[i] + card[m] + card[j];
                if (sum <= M && abs(answer - M) > abs(sum-M))
                {
                    answer = sum;
                }
            }
        }
    }
    cout << answer;
}
