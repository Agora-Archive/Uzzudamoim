package Backjun;

import java.util.Scanner;

public class Backjun_11660 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        int[][] array = new int[N][N];
        int[][] sum_array = new int[N][N];

        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                array[i][j] = scanner.nextInt();
                if(i==0){
                    if(j==0){
                        sum_array[0][0] = array[0][0];
                    }else{
                        sum_array[0][j] = array[0][j]+sum_array[0][j-1];
                    }
                } else if (j == 0) {
                    sum_array[i][0] =  array[i][0]+sum_array[i-1][0];
                } else{
                    sum_array[i][j] = array[i][j] + sum_array[i-1][j] + sum_array[i][j-1] - sum_array[i-1][j-1];
                }
            }
        }



        int[] result = new int[M];
        for(int i =0; i<M; i++){
            int a = scanner.nextInt()-1;
            int b = scanner.nextInt()-1;
            int c = scanner.nextInt()-1;
            int d = scanner.nextInt()-1;

            if(a==0 && b==0){
                result[i] = sum_array[c][d];
            } else if (a==0) {
                result[i] = sum_array[c][d] - sum_array[c][b-1];
            } else if (b==0){
                result[i] = sum_array[c][d] - sum_array[a-1][d];
            } else{
                result[i] = sum_array[c][d] - sum_array[c][b-1] - sum_array[a-1][d] + sum_array[a-1][b-1];
            }
        }

        for(int i =0; i<M; i++){
            System.out.println(result[i]);
        }
    }
}
