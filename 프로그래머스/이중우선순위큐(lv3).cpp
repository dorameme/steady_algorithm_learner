/*
start:15:00
end:15:32
시간복잡도:O(lgN)
공간복잡도:O(N)
풀이: 큐로 푸는 문제인데 그냥 벡터로 풀었다.
큐로푸는방법은 따로 찾아볼거임
새로알게된거는 
vector.begin()/.end() ->처음요소의/ 마지막요소다음의 이터레이터 반환
vector.front()/.back() ->맨앞/ 맨뒤 요소 반환
또 cctype 을 인클루드하면 isdigit함수로 쉽게 숫자인지 아닌지 비교가능

*/

#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int makeNum(string s){
    int num=0;
    for(int i=1;i<s.size();i++){
        if(isdigit(s[i])){
            num=num*10+s[i]-'0';
            // cout<<num<<"\n";
        }
    }
    if(s[2]=='-')
       return -num;
    else return num;
}
vector<int> solution(vector<string> operations) {
    map<int,int> m;
    vector<int> answer;
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            int num=makeNum(operations[i]);
            answer.push_back(num);
        }
        else{
            if(answer.empty())continue;
            sort(answer.begin(),answer.end());
            if(operations[i][2]=='1')answer.pop_back();
            else{ answer.erase(answer.begin());}
        }
    }
    if(answer.empty()){answer.push_back(0);answer.push_back(0);
                     
    return answer;
                      }
    else{
        sort(answer.begin(),answer.end());
         vector <int> newV;
        newV.push_back(answer.back());
        newV.push_back(answer[0]);
        return newV;
    }
}
