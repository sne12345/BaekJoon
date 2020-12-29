import java.util.Scanner;

public class BJ10844 {
    static final int MOD = 1000000000;
    static int[][] dp = new int[101][10];
    static int n;
    static long rslt = 0;

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();

        dp[0][0] = 0;
        for(int i = 1; i < 10; i++) dp[0][i] = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < 10; j++) {
                if(j == 0) dp[i][j] = dp[i - 1][j + 1] % MOD;
                else if(j == 9) dp[i][j] = dp[i - 1][j - 1] % MOD;
                else dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }

        for(int i = 0; i < 10; i++) rslt += dp[n - 1][i];

        System.out.println(rslt % MOD);
    }
}
