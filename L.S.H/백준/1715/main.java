import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        /*
         해당 문제의 경우 최소 비교 횟수를 묻는 문제로 최소로 비교하기 위해서는 두 수를 비교할 때 최대한 작은 수끼리 비교해야한다.
       그래서 우선 순위 큐를 사용해서 값을 입력 받는다.
       우선순위 큐의 앞의 두수를 poll 하여 합치고 다시 집어 넣는다. 이렇게 하면 알아서 오름차순으로 정렬되기 때문에 최대한 작은 수 끼리 비교할 수 있다.
        비교가 N-1번이면 비교를 다 한 것이고 누적 합을 출력한다. N이 1인 경우는 비교할 필요 없기 때문에 0을 출력한다.
         */

        PriorityQueue<Integer>queue = new PriorityQueue<>();
        for(int i = 0; i < N; i++){
            queue.add(Integer.parseInt(br.readLine()));
        }
        if(N ==1 )
        {
            System.out.println(0);
            return;
        }
        //우선 순위 큐에 삽입
        int sum=0;
        int count = 0;
        while(!queue.isEmpty()){
            int a = queue.poll();
            int b = queue.poll();
            int c = a+b;
            count++;
            sum += c;
            if(count !=(N-1)) //N의 N-1번 비교를 해야한다.
                queue.add(c);
        }

        System.out.println(sum);

    }


}
