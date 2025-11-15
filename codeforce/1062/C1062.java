import java.util.Scanner;

public class C1062 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- > 0){
            int n = sc.nextInt();
            int[] arr = new int[n];
            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }
            for(int i=0; i<n;){
                int min = arr[i];
                int p = i;
                for(int j=i+1; j<n; j++){
                    if(min > arr[j] && arr[i]%2 != arr[j]%2){
                        min = arr[j];
                        p = j;
                    }
                }
                if(p!=i){
                    int temp = arr[i];
                    arr[i] = arr[p];
                    arr[p] = temp;
                }else{
                    i++;
                }   
            }
            for(int i=0; i<n; i++){
            System.out.printf("%d ", arr[i]); 
            }
            System.out.printf("\n");
        }
        sc.close();
    }

}