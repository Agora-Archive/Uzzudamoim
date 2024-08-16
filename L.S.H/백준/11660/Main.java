import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {

        /*
        //행렬이기 때문에 2차원 배열 사용
        //M번 계산해야하기 때문에 구간합을 이용해 배열을 구성한다. 이 때 행을 기준으로 구간합에 대한 배열을 설계한다.
        여러 수를 입력 받기 위해 bufferreader 사용한다. 출력값을 위해 String Builder을 사용한다
         */

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][]Array = new int[N + 1 ][N+1];//구간합을 담을 2차원 배열 생성
        for(int i = 1; i <= N;i++)//행
        {
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <=N;j++)
            {
                int num = Integer.parseInt(st.nextToken());
                Array[i][j] = Array[i][j-1] + num; // 행의 열에 구간합을 계산 더하는 방식
            }
        }//여기까지 구간합에 대한 배열을 설정하는 방법


        StringBuilder sb  = new StringBuilder();
        int result = 0;
        for(int j=0 ; j<M; j++)
        {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());

            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

            for(int i =x1; i <= x2; i++) //각각의 행에 대해서 합을 구하기
            {
                result+= Array[i][y2] - Array[i][y1-1];
            }

            sb.append(result).append('\n');
            result = 0;
        }
        System.out.println(sb.toString());


        }
    }
