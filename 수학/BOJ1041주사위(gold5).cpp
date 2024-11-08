/*
start:11:18
end:12:55
시간복잡도:
공긴복집도:
풀이:
백준에서는 각 채점 서버마다 헤더 파일의 포함 관계가 다를 수 있다.
<climits>가 자동으로 포함되지 않는 서버에서는 INT_MAX, LLONG_MAX 등의 상수를 사용할 수 없다.
따라서 ~~ 안전한 코드 작성을 위해서는 명시적으로 필요한 헤더를 모두 포함하는 것이 좋다
또는 하드코딩(매직 넘버)하는 것도 좋음
ex) long long minVal = 51;  // 문제 조건에서 주어진 최댓값(50)보다 큰 수
백준에서는 후자의 방법(매직 넘버 사용)이 더 안전할 수 있음.
이유-->
컴파일 환경에 영향을 받지 않음
문제의 제약 조건에 맞춰 적절한 값을 사용할 수 있음
불필요한 헤더 포함을 줄일 수 있음
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
unsigned long long show(int cnt, long long arr[])
{

    long long minVal = INT_MAX;
    if (cnt == 1)
    {
        for (int i = 0; i < 6; i++)
        {
            minVal = min(minVal, arr[i]);
        }
    }
    if (cnt == 2)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (i == j || i + j == 5)
                    continue;
                minVal = min(minVal, arr[i] + arr[j]);
            }
        }
    }
    if (cnt == 3)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                for (int z = 0; z < 6; z++)
                {
                    if (j == z || i == z || i == j)
                        continue;
                    if (i + j == 5 || j + z == 5 || z + i == 5)
                        continue;
                    minVal = min(minVal, arr[i] + arr[j] + arr[z]);
                }
            }
        }
    }
    return minVal;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    unsigned long long answer = 0;
    long long arr[6] = {};
    int maxVal = 0;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    if(N==1){
        sort(arr,arr+6);
        cout<<arr[4]+arr[3]+arr[2]+arr[1]+arr[0];
        return 0;
    }
    // cout << show(1, arr) * (N - 2) * (N - 2)*5<< "\n";// 가운데 5개 
    // cout << show(1, arr) * (N - 2) * 4 << "\n"; //한면만 보이는 맨 밑 기둥4 개
    // cout << show(2, arr) * (N - 2) * 8 << "\n";//옆으로 2면씩 보이는 기둥
    // cout << show(2, arr) * 4 << "\n";//맨아래 내게
    // cout << show(3, arr) * 4 << "\n";//멘위에 네개 
    answer = 
    show(1, arr) * (N - 2) * (N - 2)*5
    +  show(1, arr) * (N - 2) * 4 
    + show(2, arr) * (N - 2) * 8 
    + show(2, arr) * 4 
    + show(3, arr) * 4;
    cout << answer;
    return 0;
}
