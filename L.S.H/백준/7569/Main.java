import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class jon7569 {
    static  int[]dx = {1,0,-1,0,0,0};
    static  int[]dy = {0,1,0,-1,0,0};
     static int[]dz = {0,0,0,0,1,-1};//z행렬 하나 더 추가
    static  int[][][]board;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer sr = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(sr.nextToken());//열
        int N = Integer.parseInt(sr.nextToken());//행
        int H = Integer.parseInt(sr.nextToken());
        board = new int[H][N][M];//N행 M열
        Queue<int[]>queue = new LinkedList<>();
        int tomato = 0;
        int day = 0;
        for(int k = 0; k < H;k++)
        {
            for(int i = 0;  i < N;i++)
            {
                sr = new StringTokenizer(br.readLine());

                for(int j = 0; j < M;j++)
                {
                    board[k][i][j] = Integer.parseInt(sr.nextToken());
                    if( board[k][i][j] == 1)//익은 토마토 인경우
                    {
                        queue.add(new int[]{k,i,j});
                    }
                   else if( board[k][i][j] == 0)
                    {
                        tomato++;
                    }
                }
            }

        }
        while(tomato >0 && !queue.isEmpty())
        {
            for(int i = queue.size();i>0;i--)
            {
                int[] now = queue.poll();
                for(int dir =0; dir<6;dir++)
                {
                    int z = now[0] + dz[dir];
                    int x = now[1] + dx[dir];
                    int y = now[2] + dy[dir];
                    if(z <0 || z >= H|| x <0 || x >= N || y <0 || y >= M || board[z][x][y] != 0)continue;
                    board[z][x][y] = 1;
                    tomato--;
                    queue.add(new int[]{z,x,y});


                }


            }
            day++;

        }

        if(tomato == 0)
        {
            System.out.println(day);
        }
        else {
            System.out.println(-1);
        }







    }

}
