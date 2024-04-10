/*
start:13:06
end:13:00
시간복잡도:O(n)
공간복잡도:O(1)
풀이:오.. 역시나 더 좋은 풀이 발견 주석으로 남기겠음.
*/
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
   if(a>b)return solution(n,b,a);
    
    int answer = 1;
    int turn=1;
    while(turn<=n){
      if(a%2==1 && b%2==0 && b-a==1 )break;
        a = (a>>1) + a%2;
        b = (b>>1) + b%2;               
        turn<<=1;
        answer++;
    }
    return answer;
} 
//더나은 풀이 -> 결국엔 둘이 인덱스 하나 차이나야하는뎅 .. 1/2==9 이나오는 경우를 무시하기 위해 1을 더해주는듯? 
#include <iostream>
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    while (a != b) {
        a = (a + 1) >> 1;   // 2 1 1
        b = (b + 1) >> 1;   // 4 2 1
        ++answer;
    }

    return answer;
}
