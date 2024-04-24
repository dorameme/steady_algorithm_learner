/*
start:17:00
end:17:39
시간복잡도:O(n)
공간복잡도:O(n)
풀이: 
1.changeToN로 N진수로 숫자를 바꿔준다.-> 이부분 그냥 배열에 1~F 까지 채워두고 배열인덱스 이용해서 풀어도 되간함. 
2. 나는 구할 수 있는 가짓수 다구해버림..max값 인 t= 1000 * m=100 -> 100000-> 그냥 m*t로도 가능하긴함.
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;
string changeToN(int n,int num){
    if(num==0) return "";
    if(num%n>=10)return changeToN(n,num/n)+char(num%n-10+'A');
    return changeToN(n,num/n)+to_string(num%n);
}
string solution(int n, int t, int m, int p) {
    string helper = "0",answer="";
    for(int i=1;i<=100000;i++){
        helper+=changeToN(n,i);
    }
    for(int i=0;i<t;i++){
        answer=answer+helper[m*i+p-1];
    }
    return answer;
}
