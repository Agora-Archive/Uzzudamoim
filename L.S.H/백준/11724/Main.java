import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {/*
1. 인접 리스트로 데이터 저장
2. while문의 조건을 임시 boolean 값을 기준으로 false일 경우 즉 다 돌지 않았을 경우 계속 하도록 설정
3. static 변수로 count, 와 booolean 설정
 */
    static  int count = 0;
    static  boolean[] booleans;
    static  boolean find = false;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer sr = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(sr.nextToken());
        int M = Integer.parseInt(sr.nextToken());
        booleans = new boolean[N+1]; //0번은 사용하지 않는다.
        List<List<Integer>> list = new ArrayList<>(); //배열은 0부터 생성되지만 1번부터 사용할 것이다. 직접 숫자를 인덱스로 사용하기 위해
        //ArrayList는 가변 배열 list이다.
        for(int i = 0; i<=N;i++) //각 리스트 안에 리스트를 하나 더 만듬 인접 리스트를 만들기 위함
        {
            list.add(new ArrayList<>());
        }
        for(int i = 0 ; i< M;i++)
        {
            sr = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(sr.nextToken());
            int v = Integer.parseInt(sr.nextToken());
            addEdge(u,v,list);//간선 추가

        }
        DFSUtil(1,booleans,list);
        count++;
        if(!find)
        {
            int start = 2;
            for(int i =2; i<=N;i++)
            {
                if(!booleans[i])
                {
                    DFSUtil(i,booleans,list);
                    count++;
                }
            }
        }


        System.out.println(count);


    }

    public  static  void addEdge(int u , int v, List<List<Integer>> list)
    {
        list.get(u).add(v);
        list.get(v).add(u);
        // 무방향이기 때문에 양쪽에 추가
    }
    public static void DFSUtil(int start, boolean[] visted,List<List<Integer>> list) // 해당 메서드가 한번 돌 때 마다 요소를 다 돔 123 456 있으면 두번 돌려야함(연결되어 있는것 만 보기 때문)
    {
        visted[start] = true;

        for (int number : list.get(start)) {
            if(!visted[number])
            {
                DFSUtil(number,visted,list);
            }

        }


    }


}
