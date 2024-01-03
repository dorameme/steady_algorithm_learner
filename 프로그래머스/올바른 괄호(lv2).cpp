/*
start:9:20
end:9:29
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단한 스택문제 보통 스택처음접할때 많이 푸는문제로 기초임 기초!
*/
#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for(int i=0;i<s.size();i++){
        if(s[i]==')'){
            if(stk.empty())return false;
            else{stk.pop();}
        }
        else{
            stk.push('(');
        }
    }
    if(!stk.empty()){
        return false;
    }
    
    return true;
}
