/*
start:12일에 시작함 
end:13일 9:51 아마 2시간정도 소요 
시간복잡도:O(N!) 모든경우를 다 확인하지만 첫번째 숫자를 고정하고 시작하므로 정확히는 (N-1)! 정도이다
N이 10이하이므로 충분히 돌아간다.
공간복잡도:O(N)
풀이: Square root 함수를 써서 is_sqrt에서 양옆을 더한숫자가 제곱수인지 아닌지 판단한다.
visit 함수를 두지않고 그냥 numbers값을 수정하는 식으로 풀어내었다
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int T,N,num;///다시ㅜ풀떄는 마지막에만 계산하도록
vector <int> numbers(11); 
int answer;
int is_sqrt(int num){
    if(sqrt(num)-(int)sqrt(num)){
         return 0;
    }
    return 1;
}
void solve(int cnt,int total,int latest){//
    if(cnt==N){
        total=total+is_sqrt(numbers[0]+latest);
        if(answer<total){
            answer=total;
        }
        return;
    }
    for(int i=1;i<N;i++){//항상 0 부터시작하므로 0은 제외
        if(numbers[i]<0)continue;
        int re=numbers[i];
        numbers[i]=-1;
        solve(cnt+1,total+is_sqrt(latest+re),re);
        numbers[i]=re;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    for(int x=1;x<=T;x++){
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>numbers[i];
        }
        answer=0;//초기화
        solve(1,0,numbers[0]);//인덱스 0부터 시작한다고 가정.
        cout<<"#"<<x<<" "<<answer<<"\n";
    }
}
