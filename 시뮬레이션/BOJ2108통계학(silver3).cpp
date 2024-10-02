/*
start:16:00
end:16:44
시간복잡도:O(N)
공간복잡도:O(N)
풀이: 아니 띠용스로운 문제가 아닐수 없었다.
C++ 에는 -0이 존재한다고 한다.. 부동소수점 연산에서 발생할 수있다고 함..
0이나 -0은 프로그래밍 할땐 상관없는데, 이걸 출력할때 앞에 -가 붙는경우가 있으니 이럴경우 0.0을 더해주거나(IEEE 754 표준은 -0 + 0 = +0으로 정의하므로)
abs를 사용해주면 된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int two, three, four;
    double one = 0;
    two = three = four = 0;
    int num = 0;
    vector<int> v;
    vector<int> offen;
    int arr[8002] = {};
    int time = 0;
    int max = -4000;
    int min = 4000;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        one += num;
        v.push_back(num);
        arr[num + 4000]++;
        if (arr[num + 4000] == time)
        {
            offen.push_back(num);
        }
        else if (arr[num + 4000] > time)
        {
            offen.clear();
            offen.push_back(num);
            time = arr[num + 4000];
            three = num;
        }
        if (max < num)
            max = num;
        if (min > num)
            min = num;
    }
    sort(v.begin(), v.end());
    sort(offen.begin(), offen.end());
    if (offen.size() == 1)
    {
        three = offen[0];
    }
    else
    {
        three = offen[1];
    }
    // if(abs((int(one*10)/N))%10 >= 5){if(one<0)one=one/N-1;else one= one/N+1;}
    // else{one=one/N;}
    cout << round(one/N)+0.0 << "\n"
         << v[N / 2] << "\n"
         << three << "\n"
         << max - min;
}
