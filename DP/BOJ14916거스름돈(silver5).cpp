/*
start:20:35
end:20:37
시간복잡도:O(N)
공간복잡도:O(N)
풀이:5로 나누어떨어지면 그대로 반환 혹은 2로 계속 빼줌. 어차피 2와 5의 합으로 나누어 떨어지는지를 확인하므로
*/
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int answer=0;
    while(n!=0){
        if(n<0){cout<<-1; return 0;}//음수로 가버림
        if(n%5==0){cout<<answer+n/5; return 0;}//5로 나눠짐
        else{
            answer++; n-=2;//2씩빼줌
        }
    }
    cout<<answer;//2로 나눠떨어져버림
    return 0;
}
