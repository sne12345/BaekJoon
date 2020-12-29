import java.util.Scanner;

public class BJ1743 {
    static final int MAX = 101;
    static int N, M, K, maxWaste = 0, subWaste = 0;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int[][] map = new int[MAX][MAX];
    static int[][] chk = new int[MAX][MAX];

    private static void DFS(int x, int y) {
        chk[x][y] = 1;
        subWaste++;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > M) continue;

            if(chk[nx][ny] == 0 && map[nx][ny] == 1) DFS(nx, ny);
        }
    }

    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        N = scan.nextInt();
        M = scan.nextInt();
        K = scan.nextInt();

        int x, y;
        for(int i = 0; i < K; i++) {
            x = scan.nextInt();
            y = scan.nextInt();

            map[x][y] = 1;
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                if(map[i][j] == 1 && chk[i][j] == 0) {
                    subWaste = 0;
                    DFS(i, j);
                    maxWaste = subWaste > maxWaste ? subWaste : maxWaste;
                }
            }
        }
        System.out.println(maxWaste);
    }
}
