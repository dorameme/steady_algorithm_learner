/*
start:15:02
end:15:16
시간복잡도:O(n)
공간복잡도:O(nm)
풀이: 간단한 문제지만 더 가독성 좋게하려면 
21번쨰줄 조건을 front(),back()함수를 써주면 된다.
ex) words[i-1].back() != words[i].front()
*/

#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set <string> s;
    s.insert(words[0]);
    for(int i=1;i<words.size();i++){
        if(words[i-1][words[i-1].size()-1]!=words[i][0] || s.find(words[i])!=s.end()){
            answer.push_back((n+i)%n+1);
            answer.push_back((i+n)/n);
            return answer;
        }
        s.insert(words[i]);
    }
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}
