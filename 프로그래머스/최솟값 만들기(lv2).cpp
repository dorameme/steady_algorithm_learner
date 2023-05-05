/*
start:11:20
end:12:00
시간복잡도:O(N)
공간복잡도:O(N)
풀이:제일큰수랑 제일작은수를 곱해주기위해 프라이오리티 큐에 넣어준다. 주의할점-> import할때 java.util.* 으로하면 효율성에서 실패가 뜰수 있다. 필요한 애들만 임포트하기!
*/
import java.util.Collections;
import java.util.PriorityQueue;
class Solution
{
    public int solution(int []A, int []B)
    {
        int answer=0;
        PriorityQueue<Integer> a=new PriorityQueue<>();
        PriorityQueue<Integer> b = new PriorityQueue<>(Collections.reverseOrder());

        
        for (int i = 0; i < A.length; i++) {
            a.add(A[i]);
            b.add(B[i]);
        }
       while(!a.isEmpty()){
        answer+=a.poll()*b.poll();
        }return answer;
            
    }
}
