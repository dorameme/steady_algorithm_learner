/*
start:5:20
end:5:40
시간복잡도:O(lgN)
공간복잡도:O(lgN)
풀이:두가지 경우의 수가있다.. 1의자리 수를 모두 없애거나 or 1의자리수를 다 올리거나..
그리고 n이 한자리만 남았을때 따로 처리 필요!
*/
#include <string>
#include <vector>

using namespace std;
int answer=987654321;
int solve(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return min(solve(n/10+1)+10-n%10,solve(n/10)+n%10);
}

int solution(int storey) {
    
     return solve(storey);
}
