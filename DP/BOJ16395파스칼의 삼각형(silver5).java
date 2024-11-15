/*
 * start:15:08
 * enㅇ:15:35
 * 시간복잡도:O(N^2)
 * 공간복잡도:O(N^2)
 * 풀이: 기저조건에 n==1 k==1을 실수로 넣었는데 0일때만 넣어주면 된다.

 * */

import java.io.IOException;
import java.util.Scanner;

class Main {

    static long[][] dp = new long[31][31];

    static public long  C(int n, int k) {
        if (n == k) {
            return 1;
        }
        if ( n == 0 || k == 0 ) {
            return 1;
        }
        if (dp[n][k] != 0) {
            return dp[n][k];
        }
        return  dp[n][k] = C(n - 1, k) + C(n - 1, k - 1);
    }

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        int K = s.nextInt();
        dp[1][1] = dp[1][0] = 1;
        System.out.println(C(N, K));
    }
}
