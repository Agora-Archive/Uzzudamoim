import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        String Num = scanner.next();
        int sum =0;
        char[] NumArray = Num.toCharArray();

        for(int i = 0 ; i < NumArray.length;i++)
            sum += (NumArray[i] - '0');

        System.out.println(sum);



    }
}