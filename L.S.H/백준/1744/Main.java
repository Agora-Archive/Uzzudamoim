
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        //양수에 대한 우선순위 큐 //내림차순
        PriorityQueue<Integer>queuePlus = new PriorityQueue<>(Collections.reverseOrder());
        //0과 음수에 대한 운선위 큐 //오른차순 0 곱할거면 음수에 곱해야한다.
        PriorityQueue<Integer>queueMinus = new PriorityQueue<>();

        if(N ==1)
        {
            int number = Integer.parseInt(br.readLine());
            System.out.println(number);
            return;
        }
        for(int i =0;i<N;i++) {
            int n = Integer.parseInt(br.readLine());
            if(n >0)
            {
                queuePlus.offer(n);
            }
            else {
                queueMinus.offer(n);
            }
        }

        int sum = 0;
        while(queuePlus.size() > 1) //홀수면 1일 때 걸리고 짝수면 0일 때 걸림
        {
            int a = queuePlus.poll();
            int b = queuePlus.poll();
            if(a == 1 || b == 1 )// 1인 경우 그냥 더하는게 더 크다. // 양수가 다 1인 것도 고려
            {
                sum+= a+ b;
            }
            else
            {
                sum+= a*b; //1이 아닌 나머지 경우는 곱하는게 더 큼.
            }
            

        }
        if(queuePlus.size() == 1)
            sum += queuePlus.poll();

        while(queueMinus.size() > 1)
        {
            int a = queueMinus.poll();
            int b = queueMinus.poll();
            sum+=  a *b; 
        }
        if(queueMinus.size() == 1)
            sum+=queueMinus.poll();




        System.out.println(sum);







    }
}
