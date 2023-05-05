/*
start:13:00
end:14:00
시간복잡도:O(N)
공간복잡도:O(N)
풀이:이문제는 투포인터문제다. 포인터를 이용해 풀되 여기서 내가 틀린이유는 system,out.println을 써놓고 제출해놓고는 깜박하고 안지웠다.
그래서 효율성이 0점이 나왔다 이런것도 코테에선 주의해주자 낼때는 코드만 내기!
*/
class Solution {
    public int solution(int n) {
        int left=0,right=1;
        int answer = 0;
        int now=1;
        while(left<right){
            if(right>n)break;
            if(right>(n/2+1)&&left<(n/2-1))break;
            if(now<n){
                now+=++right;
            }
            else if(now>n){
                now-=++left;
                
            }
            else {
               // /  System.out.println(left+" "+right+" "+now);
                answer++;
                now-=++left;
            }
        }
        return answer;
    }
}
