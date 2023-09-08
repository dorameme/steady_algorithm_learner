/*
start:14:48
end:15:08
시간복잡도:O(N)
공간복잡도:O(N)
풀이:새로알게된것 빈문자열에는 문자를 더할 수없다 ㅠㅠ 그래서 
string s="";
s+='c'; 하면 에러남,,
s,push_back('c')로 해줘야함!!
*/

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
char alpa(char c){
    if(c>='a'&& c<='z'){
        return c- ('a'-'A');
    }
    else if (c>='A' && c<='Z'){
        return c;
    }
    else{
        return '-';
    }
}
vector <string> make(string s){
    vector <string> helper;
    for(int i=0;i+1<s.size();i++){
        string s2="";
        if(alpa(s[i])=='-'|| alpa(s[i+1])=='-')continue;
        s2.push_back(alpa(s[i]));
        s2.push_back(alpa(s[i+1]));
        helper.push_back(s2);
    }
    return helper;
}
double solve(string s1,string s2){
    vector <string> v1=make(s1);
    vector <string> v2=make(s2);
    int all=v1.size()+v2.size();
    if(all==0)return 1;
    map <string ,int> m1;
    map <string ,int> m2;
    map <string, int >  m3;
    for(int i=0;i<v1.size();i++){
        m1[v1[i]]++;
    }
    for(int j=0;j<v2.size();j++){
        m2[v2[j]]++;
    }//요소들의 갯수를 저장함.
    
    int cnt=0;
    for(auto i:m1){
        if(m2[i.first])
            cnt+= min(m2[i.first],i.second);//겹침
    }
    return (double)cnt/(all-cnt);
}
int solution(string str1, string str2) {
    int answer = 0;
    return floor(solve(str1,str2)*65536);
}
