/*
시간복잡도:O(N!) 모든경우의 수를 탐색하므로 모든 경우의 수가 시간복잡도가 된다.
공간복잡도:O(1) 학생수가 최대 10명이라서 ..엄청 적다. 그냥 O(1)로 봐두 무관!
풀이: 완전탐색으로 가능한 경우의 수를 모두 서치해준다!!
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int make_couple(int student_cnt,int friends[][11],int couple[]){
    bool done=true;
    int first_one=-1;
    for(int i=0;i<student_cnt;i++){
        if(!couple[i]){
            first_one=i;
            break;
        }
     }
    int ret=0;
    if(first_one==-1)return 1;//이부분이 꽤맘에 들었음 따로 done에대한 변수를 둘 필요없이 첫 학생변수를 -1 로 초기화하여 사용
    else{
        for(int i=first_one+1;i<student_cnt;++i){
            if(!couple[i]&&friends[i][first_one]){
                couple[first_one]=couple[i]=1;
                ret+=make_couple(student_cnt,friends,couple);
                couple[first_one]=couple[i]=0;
            }
        }
    }
    return ret;
}
int main(){
    int num;
    cin>>num;
    while(num--){
        int student_cnt;
        int friends_cnt;
        int friends[11][11]={0,};
        int couple[11]={0,};
        cin>>student_cnt>>friends_cnt;
        for(int i=0;i<friends_cnt;++i){
            int friend_A,friend_B;
            cin>>friend_A>>friend_B;
            friends[friend_B][friend_A]=friends[friend_A][friend_B]=1;
        }
       cout<<make_couple(student_cnt,friends,couple)<<"\n";
    }    
}
