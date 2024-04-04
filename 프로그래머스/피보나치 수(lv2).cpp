/*
start: 15:20
end:15:27
시간복잡도:O(n)
공간복잡도:O(1)
풀이:n번째 피보나치수를 구한다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int one=0,two=1,three;
    for(int i=2;i<=n;i++){
        three=(one+two)%1234567;
        one=two;
        two=three;
    }
    return three;
}
