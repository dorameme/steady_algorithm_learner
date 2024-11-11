/*
start:12:35
end:13:20
시간복잡도: O(2^N) - 하노이탑 재귀함수의 시간복잡도
공간복잡도: O(N) - 재귀 호출 스택의 깊이만큼 필요
풀이:
N = 3일 때:
1. pow(2, 3) = 8.000000
2. to_string으로 변환 -> "8.000000"
3. '.' 위치 찾기 -> 1
4. 소수점 앞부분만 자르기 -> "8"
5. 마지막 숫자 1 감소 -> "7"
문제가 답이아니면 자료형을 의심해보자
이문제는 숫자자료형으로는 표현이불가능해서 문자열 사용..
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>
using namespace std;
#define X first
#define Y second
int N;
int answer=0;
void hanoi(int N, int from, int by, int to)
{
    if (N==0)
    {
        return;
    }
    hanoi(N-1,from, to, by);
    cout << from << " " << to << "\n";
    hanoi(N-1,by, from, to);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    unsigned long long cnt=0;
    string a = to_string(pow(2, N));
	int x = a.find('.');				//pow 함수 결과가 실수형이기에 소수점 찾기
	a = a.substr(0, x);				//소수점 앞자리만 나오게하기
	a[a.length() - 1] -= 1;	 
    cout<<a<<"\n";
    if(N>20){
        return 0;
    }
    else{
        hanoi(N,1,2,3);
    }
}
