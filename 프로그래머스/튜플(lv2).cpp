/*
start:13:20
end:13:30
시간복잡도:O(N)
공간복잡도:O(N)
풀이:등장하는 숫자 수 n*(n+1)/2 , 1번째요소가 n , 두번째요소가 n-1번.... 1번 등장 
이 규칙으로 풀어주면 아주 나이스. 
slice는 처음써본 함수였다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(501);
    map<int,int>  m;
    int num=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            num=num*10+s[i]-'0';
        }
        else{
            if(num!=0){
                m[num]++;
                cnt++;
                num=0;
            }
        }
    }
    for(int i=1;i<=cnt;i++){
        if(i*(i+1)/2==cnt){
            cnt=i;
        }
    }
    for(auto iter : m){
        answer[cnt-iter.second]=iter.first;
    } 
    vector <int> slice(answer.begin() , answer.begin() + cnt);
    return slice;
}
