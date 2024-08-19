package Backjun;

import java.util.Scanner;

public class Backjun_11659 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int[] array = new int[N];
        int[] sum_array = new int[N];

        for(int i = 0; i < N; i++){
            array[i] = scanner.nextInt();
            if(i==0){
                sum_array[i] = array[i];
            }else{
                sum_array[i] = array[i] + sum_array[i-1];
            }
        }

        int[] result = new int[M];
        for(int i = 0; i<M;i++){
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            if(a==1){
                result[i] = sum_array[b-1];
            }else {
                result[i] = sum_array[b - 1] - sum_array[a - 2];
            }

        }

        for(int i =0; i<M;i++){
            System.out.println(result[i]);
        }

    }
}
