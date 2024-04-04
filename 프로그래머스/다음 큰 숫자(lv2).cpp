/*
start:13:30
end:14:07
시간복잡도:O(n)
공간복잡도:O(1)
풀이: 처음에는 이런저런함수를 만들어서 풀어보려했다
하지만일단은 완전탐색으로 충분히 가능한 사이즈라서 
그냥 n보다 큰수를 하나하나 makeBinary라는 binary로 표현했을때 1의 수가 같은지 비교하여 찾아주었다.
*/
#include <string>
#include <iostream>
#include <vector>
using namespace std;
int makeBinary(int n){
    if(n==0)return 0;
    if(n%2==0){
        return makeBinary(n/2);        
    }
    return  makeBinary(n/2)+1;
}
int solution(int n) {
    int cnt=makeBinary(n);
    for(int i=n+1;;i++){
        if(makeBinary(i)==cnt)return i;
    }
}
