/*
start:21:20
end:21:40
시간복잡도:O(nm)
공간복잡도:O(n)
풀이: deque를 써서 풀었다. 캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
주의할 점은 이미 있던거를 쓰면 위치를 대량 변경해줘야한다는 점이다 그게 귀찮아서 디큐씀.
ㅇㅇㅇxㅁㅁㅁ 만일 x 를 쓰면 위치를
ㅇㅇㅇㅁㅁㅁx 이런식으로 바꾸어줘야함.
*/
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <deque>
using namespace std;
string citiesName(string s){
    string s2="";
    for(int i=0;i<s.size();i++){
        s2=s2+(char(toupper(s[i])));
    }
    return s2;
}
int solution(int cacheSize, vector<string> cities) {
    
    int answer = 0;
    deque<string> dq;
    if( cacheSize==0 )return cities.size()*5;
    for(int i=0;i<cities.size();i++){
        int where=-1;
        for(int j=0;j<dq.size();j++){
            if(dq.at(j)==citiesName(cities[i])){
                where=j;
                break;
            }
        }
        if(where==-1){//만일 없으면
            answer+=5;
            if(dq.size()==cacheSize){
                dq.pop_front();
            }
        }   
        else{//있으면
            answer+=1;
            dq.erase(dq.begin()+where);
        }      
        dq.push_back(citiesName(cities[i]));
    }
    return answer;
}
