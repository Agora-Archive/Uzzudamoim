package Backjun;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int size = scanner.nextInt();
        String num = scanner.next();

        int[] array = new int[size];
        for(int i =0; i<size; i++){
            array[i] = num.charAt(i) - '0';
        }

        int sum = 0;
        for(int i = 0;i<size;i++){
            sum += array[i];
        }
        System.out.println(sum);
      //런타임 에러 발생
    }
}
