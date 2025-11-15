import java.util.Scanner;

public class A1062 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        for(int i=0; i<T; i++){
            int[] numArr = new int[4];
            for(int j=0; j<4; j++){
                numArr[j] = sc.nextInt();
            }
            if(numArr[0] == numArr[1] && numArr[1] ==numArr[2] && numArr[3] == numArr[2]){
                System.out.printf("Yes\n");
            }else{
                System.out.printf("No\n");
            }
        }
        sc.close();
    }
}
/* 
public class A2167 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        for(int i = 0; i<num ; i++){
            int[] numArr = new int[4];
            for(int j=0; j<4; j++){
                numArr[j] = sc.nextInt();
                int tempN = j;
                for(int k = tempN-1; k >=0 ; k--){
                    if(numArr[tempN] < numArr[k]){
                        int temp = numArr[tempN];
                        numArr[tempN] = numArr[k];
                        numArr[k] = temp;
                        tempN = k;
                    }
                }
            }
            if(numArr[0] == numArr[1] && numArr[1] == numArr[2] &&  numArr[2] == numArr[3]){
                System.out.printf("Yes\n");
            }else{
                System.out.printf("No\n");
            }
        }
        sc.close();
    }

}*/
