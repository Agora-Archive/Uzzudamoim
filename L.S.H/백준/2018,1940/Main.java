import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        if(N == 1 ) //1의 경우 해당 논리가 맞지 않아 예외 케이스로 바로 출력
        {
            System.out.println(1);
            return;
        }


        int endNumber;
        if(N % 2 == 0)
        {
            endNumber = N / 2;
        }
        else
            endNumber = N / 2 + 1;

        int [] Array = new int[endNumber];

        for(int i = 0; i < endNumber;i++)
        {
            Array[i] =  i+1;
        }


        int left = 0, right = 0;
        int sum = 0;
        int Count =0;

        for(;right < endNumber;right++)
        {
            sum += Array[right];

            while(sum > N && left <= right) //sum의 합이 주어진 N의 값보다 클 경우 left 포인터로 해당 sum을 줄여주고
                //N범위 안에 값을 다시 만족하면 right를 다시 늘려나가는 방식으로 연속된 수의 합의 개수를 찾아나간다.
                //때문에 sum도 초기화 X
                //이 때 left 는 right의 범위를 넘어갈 수 없게 제약을 둔다
            {
                sum -= Array[left];
                left++;
            }

            if(sum == N)
            {
                Count++;
            }


        }
        Count++; //N의 절반 범위만 돌았기 때문에 자기자신이 포함되지 않았음
        System.out.println(Count);






    }
}