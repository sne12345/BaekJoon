import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int SIZE = 5;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int[][] map = new int[SIZE][SIZE];

    static int[][] rslt = new int[1000000][6];
    static int[] temp = new int[6];

    static int cnt = 0;

    public static void Input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        for (int i = 0; i < SIZE; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < SIZE; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }

    public static void checkDuplicated() {
        for(int i = 0; i < cnt; i++) {
            int flag = 1;
            for(int j = 0; j < temp.length; j++) {
                if(temp[j] != rslt[i][j]) flag = 0;
            }
            if(flag == 1) return;
        }

        for(int i = 0; i < temp.length; i++) {
            rslt[cnt][i] = temp[i];
        }
        cnt++;
    }

    public static void DFS(int x, int y, int c) {
        if(c == temp.length) {
            checkDuplicated();
            return;
        }

        temp[c] = map[x][y];

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;

            DFS(nx, ny, c + 1);
        }
    }

    public static void main(String args[]) throws IOException {
        Input();
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                DFS(i, j, 0);
            }
        }
        System.out.println(cnt);
    }
}
