/*
start:12:00
end:12:30
시간복잡도:O(N)
공간복잡도:O(N)
풀이:문자열을 파싱해준다. 근데 내가 이문제를 여러번 틀린이유는 if문과 if~else if 문을 혼동해써서 중복처리가 이루어진것이다 주의하자.
*/
import java.util.*;
class Solution {
    public String solution(String s) {
        String answer = "";
        String[] array = new String[201];
        int cnt=0;
        
        StringTokenizer tokenizer = new StringTokenizer(s," ",true);
        while(tokenizer.hasMoreTokens()){

            String str=tokenizer.nextToken();
            System.out.println(str+"|");
            for(int j=0;j<str.length();j++){
             if(j==0&&str.charAt(0)>='a'&&str.charAt(0)<='z'){
                   answer+=(char)(str.charAt(0)-32);
                   continue;
               }
               if(j!=0&&str.charAt(j)>='A'&&str.charAt(j)<='Z'){
                   answer+=(char)(str.charAt(j)+32);
               }
               else{   answer+=(char)str.charAt(j);
               }
                   
            }
        }
        return answer;
    }
}
