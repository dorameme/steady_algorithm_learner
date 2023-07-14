/*
start:10:20
end:11:00
시간복잡도:O(4^n) n은 이모티콘수
공간복잡도:O(n)
풀이: 이 문제는 완전탐색으로 모든 경우의 수에 대해서 해봐도 이모티콘이 7개 까지밖에 없어서 4^7로 풀리므로
충분히 시간안에 해결가능했다.
다만 헷갈렸던거는 SALE을 적용할 때 X*(100-SALE)/100 을 해줘야하는데 X*(sALE)/100로 세일가를 계산해버려서 자꾸 틀렸다 ㅋㅋ
*/
#include <string>
#include <vector>
#include <iostream>

#define X first
#define Y second
using namespace std;
  
vector <int> sale;
int len;
int ans_money;
int ans_user;
vector<vector<int>> use;
vector<int> emo;
pair<int,int> cal(){
    int money=0;
    int newUser=0;
    for(int i=0;i<use.size();i++){
        int newMoney=0;
        for(int j=0;j<emo.size();j++){///항상 인덱스 실수
            if(use[i][0]<=sale[j])
            {
                newMoney+=emo[j]*(100-sale[j])/100;
            }
        }
        if(newMoney>=use[i][1]){newUser++;}
        else{ money+=newMoney;}
    }
    
    return {money,newUser};
}
void emo_sale(){
    if(len==sale.size()){
        pair<int,int> cur=cal();   
        if(cur.second>ans_user)
        {ans_user=cur.second;ans_money=cur.first;}
        else if(cur.second==ans_user && cur.first>ans_money &&cur.second==ans_user)
        {ans_user=cur.second;ans_money=cur.first;}
     
        return;
    }
    else{
    sale.push_back(10);
    emo_sale();
    sale.pop_back();
        
    sale.push_back(20);
    emo_sale();
    sale.pop_back();
        
    sale.push_back(30);
    emo_sale();
    sale.pop_back();
        
    sale.push_back(40);
    emo_sale();
    sale.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    use=users;
    emo=emoticons;
    len=emoticons.size();
    
    emo_sale();
    vector <int >answer;
    answer.push_back(ans_user);
    answer.push_back(ans_money);
    return answer;
}
