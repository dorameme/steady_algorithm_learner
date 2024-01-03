/*
start:9:10
end:9:15
시간복잡도:O(N)
공간복잡도:O(N)
풀이:간단히 스택으로 구현가능한 문제! 너무 쉬워서 설명은 생략.
*/
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
int helper(string s){
    stack<char> stk;
    stk.push(s[0]);
    for(int i=1;i<s.size();i++){
        if(stk.empty()){
            stk.push(s[i]);
        }
        else{
            if(stk.top()==s[i]){
                stk.pop();
            }
            else{
                stk.push(s[i]);
            }
        }
    }
    if(stk.empty())return 1;
    return 0;
}
int solution(string s)
{
    return helper(s);
}
