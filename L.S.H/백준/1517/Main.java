import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    /*
    백준 1517번(시간 제한 1초)
    해결책 -> 병합 정렬을 이용하여 버블 정렬의 swap 발생 횟수를 파악할 수 있다.
    원리 : 병합 정렬은 분할 정복으로 문제를 가장 작은 단위로 나눈 후 하나 하나 해결해나가면서 전체 문제를 해결 해 나가는 방식
    병합 정렬 과정에서 두 배열을 정렬할 때 오른쪽 값이 작아서 정렬을 먼저 해야하는 경우 swap을  왼쪽에  남아 있는 숫자 개수 만큼
    더해야한다. 
    
    양쪽 배열 모두가 정렬된 상태에서 합치는데 이 때 병합 정렬로 생각하지 않고 버블 정렬로 생각한다.
    오른쪽 배열 앞에 값이 왼쪽 배열의 앞에  값보다 더 작은 경우는 버블 정렬를 관점으로 보면  
    정렬된 왼쪽 배열은 오른쪽 배열의 맨 앞에 값을 기준으로 모두 swap 해서 자리를 옮겨야한다는 애기이다.
    23 18 의 경우 1은 2보다 더 작기 때문에  2와 3은 1과 swap 을 해서 총 2번의 swap 을 한다.
    
    이런 방식으로
    작은 크기의 배열부터 점차 큰 배열로 만들게 될 때 swap 횟수를
     count 해 나가면서 정렬해 나가면 더 큰 배열을 합칠 때 이미 
    정렬된 수들을 정렬하기 때문에 해당 과정에서의 swap만 추가로 해주면 문제는 해결된다.
           
    
     */
    
    

    static  long count =0; //전체 count 값을 세기 위해 static 변수 사용
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N  = Integer.parseInt(br.readLine());
        int []array = new int [N];
        StringBuilder sb = new StringBuilder();
        String Numbers = br.readLine();// 배열 숫자를 한번에 받은 후 공백을 기준으로 string 배열 생성 후 대입
        String []stringArray = Numbers.split(" ");
        for(int i = 0; i < N;i++)
        {
            array[i] = Integer.parseInt(stringArray[i]);
        }
        
        int []imsi = new int[N]; //정렬을 하기 위한 임시 배열 생성
        merge_sort(array,0,N-1,imsi);

        for(int i = 0; i< N;i++)
        {
            sb.append(array[i]+"\n");
        }
        System.out.println(count);

    }

    static  void merge_sort(int []list, int left, int right,int[] imsi)
    {
        int mid;
        if(left < right)
        {
            mid = (left + right) / 2 ;
            merge_sort(list,left,mid,imsi);
            merge_sort(list,mid + 1, right,imsi);
            merge(list, left,mid,right,imsi);

        }

    }

    private static void merge(int[] list, int left, int mid, int right,int[] imsi) {
        int i = left;
        int j = mid +1;
        int k = left;
        while(i <= mid && j <= right)
        {
            if(list[i] <= list[j])
            {
                imsi[k++] = list[i++];
            }
            else
            {
                imsi[k++] = list[j++];
                count += (mid - i +1);
            }

        }

        if(i>mid){
            for(int l=j; l<=right; l++)
                imsi[k++] = list[l];
        }
        else{
            for(int l=i; l<=mid; l++)
                imsi[k++] = list[l];
        }

        for(int l=left; l<=right; l++){
            list[l] = imsi[l];
        }





    }

}
