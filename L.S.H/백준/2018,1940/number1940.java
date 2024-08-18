import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class number1940 {
    public static void main(String[] args) throws IOException {
        //1940번
        //입력 받아야할 수가 많기 때문에 BufferReader사용
        BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine()); // 수의 개수
        int M = Integer.parseInt(br.readLine());// 조건
        int []Numbers = new int[N]; //각 번호가 고유하기 때문에 Boolean을 사용하여 값이 있나 없나 확인
        int totalCount = 0;
        //배열을 순서대로 저장하는게 아니라 각 숫자가 INDEX 역할을 담당하여 각각 숫자에 inex배열에 true로 설정
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N;i++)
        {
            int number = Integer.parseInt(st.nextToken());
            Numbers[i] = number;
        }
        Arrays.sort(Numbers); //배열을 오름차순으로 정렬
        //투포인터를 사용하여 왼쪽과 오른쪽 끝에서 시작
        int left =0;
        int right = Numbers.length-1;

        while(left < right)
        {
            int sum = Numbers[left] + Numbers[right];
            if(sum == M)
            {
                left++;
                right--;
                totalCount++;
                //값은 고유하기 때문에 양쪽 값을 다 변경 가능
            }
            else if(sum > M)///sum이 큰 경우 sum를 줄이기 위해서 오른쪽 값을 한단계 낮춰서 찾아봄
            {
                right--;
            }
            else
                left++;
        }
        System.out.println(totalCount);

    }
}