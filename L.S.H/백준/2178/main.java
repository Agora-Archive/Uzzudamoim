import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class jon2178 {

    static  int [][]board = new int[100][100];
    static  boolean [][] visited =  new boolean[100][100];
    static  int[][] count = new int[100][100];
    static int [] dx = {1,0,-1,0};
    static int [] dy = {0,1,0,-1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer sr = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(sr.nextToken());
        int m = Integer.parseInt(sr.nextToken());
        LinkedList<Pair> queue = new LinkedList<>();//큐생성
        for(int i =0 ; i< n;i++)
        {
            String imsi = br.readLine();
            char []numbers = imsi.toCharArray();
            for(int j = 0 ; j < m;j++)
            {
                board[i][j] =numbers[j] - '0';
            }

        }
        visited[0][0] = true;
        count[0][0] = 1;
        Pair start = new Pair(0,0);
        queue.add(start);
        while (!queue.isEmpty())
        {
            Pair imsi  = queue.poll();
            for(int dir = 0; dir < 4;dir++)
            {
                int nx = imsi.x + dx[dir];
                int ny = imsi.y +dy[dir];
                if(nx < 0 || nx >= n || ny<0 || ny >=m )continue;
                if(visited[nx][ny] || board[nx][ny] != 1)continue;
                visited[nx][ny] = true;
                count[nx][ny] = 1 + count[imsi.x][imsi.y];
                queue.add(new Pair(nx,ny));

            }

        }
        System.out.println(count[n-1][m-1]);


    }

    public static class Pair{
        int x;//행
        int y;//열

        public Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int getX() {
            return x;
        }
        public int getY() {
            return y;
        }
    }

}
