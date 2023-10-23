/*
start:14:00
end:14:12
시간복잡도:O(N!)
공간복잡도:O(N!)
풀이:완전탐색으로 풀어주었다.
어차피 케이스가 크지않아서 충분히 가능!
*/
#include <string>
#include <vector>
using namespace std;
int vis[10]={0,};
int prime[9999999]={0,};
int answer = 0;
string number;
bool isPrime(int num){
    if(prime[num]==1)return false;
    prime[num]=1;
    if(num==1|| num==0)return false;
    if(num==2)return true;
    for(int i=2;i*i<=num;i++){
        if(num%i==0)return false;
    }
    return true;
}
void makeNum(int num){
    if(isPrime(num))answer++;
    for(int i=0;i<number.size();i++){
        if(vis[i])continue;
        vis[i]=1;
        makeNum(num*10+number[i]-'0');
        vis[i]=0;
    }
}
int solution(string numbers) {
    number=numbers;
    makeNum(0);
    return answer;
}
