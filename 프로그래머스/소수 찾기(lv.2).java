/*
start:14:10
end:14:49
시간복잡도O(N!)
공간복잡도:O(N!)
풀이:어차피 값이 적어서 dfs로 다 돌려보면 된다!
*/
import java.util.HashSet;
import java.util.Set;
class Solution {
     Set <Integer> map=new HashSet<Integer>();
     int answer = 0;
     static int [] used=new int[10];
    boolean isTrue(int num){
        if(num==0 || num ==1)return false;
        if(num==2)return true;
        for(int i=2;i*i<=num;i++){
            if(num%i==0)return false;
        }
        return true;
    }
    void dfs(String numbers,int num){
        System.out.println(num);
        
        if(isTrue(num) && map.contains(num)==false){map.add(num);answer++;
        }
        for(int i=0;i<numbers.length();i++){
            if(used[i]==1)continue;
            used[i]=1;
            dfs(numbers,num*10+numbers.charAt(i)-'0');
            used[i]=0;
        }
    }
    public int solution(String numbers) {
        for(int i=0;i<numbers.length();i++){
            used[i]=1;
            dfs(numbers,numbers.charAt(i)-'0');
            used[i]=0;
        }
        return answer;
    }
}
