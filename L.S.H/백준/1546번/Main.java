import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int []array = new int[N];
        int max = 0;
        double sum = 0;


        for(int i = 0; i< N;i++) //max 값을 구하고 배열에 각 숫자를 대입
        {
            array[i] = scanner.nextInt();
            if(max < array[i])
                max = array[i];
        }

        for ( int score : array)
        {
            sum += (score * 100.0 / max);
        }
        System.out.println( sum / N);



    }
    }
