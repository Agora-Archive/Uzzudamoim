package Backjun;

import java.util.Scanner;

public class Backjun_1546 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] grade = new int[N];

        int max = 0;
        int sum = 0;

        for(int i =0; i< N; i++){
            grade[i] = scanner.nextInt();
            sum += grade[i];
            if(max < grade[i]){
                max = grade[i];
            }
        }

        System.out.println(sum*100.0/max/N);
    }
}
