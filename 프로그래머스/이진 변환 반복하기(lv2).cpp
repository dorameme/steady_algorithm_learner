/*
start:14:00
end:14:11
시간복잡도:O()
공간복잡도:O()
풀이: 너무 쉬워서 할말이.. 그냥 구현!
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;
string makeS(int num){
    string s="";
    while(num){
        if(num%2==1)s="1"+s;
        else{s="0"+s;}//제일 최근연산이 앞으로 가야한다.
        num=num/2;
    }
    return s;
}
vector<int> solution(string s) {
    vector<int> answer;
    int cnt0=0;
    int cnt1=0;
    int replay=0;
    while(s.size()!=1){
        replay++;
        cnt1=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                cnt0++;
            }
            else{
              cnt1++;
            }
        }
        s=makeS(cnt1);
        cout<<s<<"\n";
    }
    answer.push_back(replay);
    answer.push_back(cnt0);
    return answer;
}
