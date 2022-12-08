 /*
 시간복잡도:O(nlg(n))   분할하는 과정 + 계산하는 과정
 공간복잡도:O(n) 울타리수만큼 공간필요
 풀이:울타리가 왼쪽에서 잘랐을때, 오른쪽에서 잘랐을때, 오른쪽 왼쪽겹칠때 모두를 분할고려하여 풀어준다!
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int solve(vector <int>& fence, int left,int right ){
    if(left==right){return fence[left];}
    int mid=(left+right)/2;
    int ret=max(solve(fence,left,mid),solve(fence,mid+1,right));
    int lo=mid,hi=mid+1;
    int height=min(fence[lo],fence[hi]);
    //mid,mid+1 의 크기부터시작
    ret=max(ret,height*2);
    while(left<lo||hi<right){
        if(hi<right&&(left==lo||fence[lo-1]<fence[hi+1])){
            hi++;
            height=min(fence[hi],height);
        }
        else{
            lo--;
            height=min(fence[lo],height);
        }
        ret=max(ret,height*(hi-lo+1));
    }
    return ret;
}
int main(){
    int C;
    cin>>C;
    while(C--){
        int N;
        cin>>N;
        vector <int> fence(N);
        for(int i=0;i<N;i++){
            cin>>fence[i];
        }
        cout << solve(fence,0,N-1)<<"\n";
    }
}
