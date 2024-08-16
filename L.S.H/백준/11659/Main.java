import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {
        //숫자의 범위는 최대 1억  int 형 변수 사용
        // 입력 받는 N의 개수는  10만이기 때문에 Scanner 말고 reader 사용
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int [] sumArray =  new int[N +1]; //합 배열
        st = new StringTokenizer(br.readLine());
        for(int i =1;  i <= N ; i++) // 입력을 받으면서 구간합 배열 바로 생성 //0의 경우 if문을 사용하지 않기 위해 밖에서 한번만 처리.
        {
            int num = Integer.parseInt(st.nextToken());
            sumArray[i] = sumArray[i -1] + num;
        }
        //여기까지 합 배열 계산

        //값을 M번 사용하기 때문에 배열 보다는  StringBuilder을 사용하는 것이 유용
        StringBuilder sb = new StringBuilder();
        for(int  j = 0 ; j < M ;j++)
        {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int result = sumArray[end] - sumArray[start - 1];
            sb.append(result).append('\n');
        }

        System.out.println(sb.toString());



        }
    }
