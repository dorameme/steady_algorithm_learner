/*
start:16:00
end:16:21
시간복잡도:O(N)
공간복잡도:O(N)
풀이:완전탐색 stack 활용
*/

#include <string>
#include <vector>
#include <stack>
using namespace std;
int answer=0;
int flag=0;
int isRight(string s){
    stack<char> stk;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            stk.push('(');
        }
        else if(s[i]=='['){
            stk.push('[');}
        else if(s[i]=='{'){
            stk.push('{');
        }
        else if(s[i]==')'){
            if(!stk.empty() &&stk.top()=='('){
                stk.pop();}
            else{return false;}
        }
        else if(s[i]==']'){
            if(!stk.empty()  && stk.top()=='['){
                stk.pop();}
            else{return false;}
        }
        else if(s[i]=='}'){
            if(!stk.empty()  && stk.top()=='{'){
               stk.pop();}
            else{return false;}
        }
    }if(stk.empty())return true;
    else return false;
}
int tryCnt=0;
void solve(string s){
    tryCnt++;
    if(tryCnt==s.size())return;
    if(isRight(s)){answer++;}
    solve(s.substr(1)+s[0]);
}
int solution(string s) {
    solve(s);
    return answer;
}
