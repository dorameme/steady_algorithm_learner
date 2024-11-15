package 배열;
/*
 * start:14:41
 * enㅇ:15:05
 * 시간복잡도:O(N^2)
 * 공간복잡도:O(N)
 * 풀이: LIS문제인데 이제 감이 좀 잡혔다.
 그리고 나는 answer 을 1로 뒀다가 틀렸었는데.. 초기값을 잘 설정해주자.
 * */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] dp = new int[1001];
        int[] nums = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        dp[0] = 1;
        int answer=1;
        for (int i = 1; i < N; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
            answer = Math.max(answer, dp[i]);
        }
        System.out.println(answer);
    }
}
