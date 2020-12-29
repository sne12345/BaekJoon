import java.util.Scanner;

public class BJ11048 {
    static final int MAX = 1001;

    static int N, M, maxNum, temp;
    static int[][] map = new int[MAX][MAX];

    private static int get_max(int a, int b, int c) {
        int max = 0;
        if (max < a) max = a;
        if (max < b) max = b;
        if (max < c) max = c;
        return max;
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        M = scan.nextInt();

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                temp = scan.nextInt();
                maxNum = get_max(map[i-1][j-1], map[i-1][j], map[i][j-1]);
                map[i][j] = temp + maxNum;
            }
        }
        System.out.println(map[N][M]);
    }
}
