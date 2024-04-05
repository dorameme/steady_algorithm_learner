/*
start:19:45
end:19:49
시간복잡도:O(n)
공간복잡도:O(1)
풀이: 너무너무 쉬운 dp유형. 그냥 이전값 두개를 더해주며 값들을 업데이트해주면됨
*/
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long before1 =1;
    long long before2=1;
    long long now=1;
    for(int i=2;i<=n;i++){
        now= before1 + before2;
        before1=before2%1234567;
        before2=now%1234567;
    }
   
    
    return now%1234567;
}
