import java.util.Scanner;

public class B1062 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while(T-- >0){
            int len = sc.nextInt();
            String s = sc.next();
            String t = sc.next();
            int[] Arr = new int[26];
            int i=0;
            for(i=0; i<len; i++){
                Arr[s.charAt(i) - 'a'] ++;
            }
            for(i=0; i<len; i++){
                Arr[t.charAt(i)-'a']--;
                if(Arr[t.charAt(i)-'a'] <0){
                    System.out.printf("No\n");
                    break;
                }
            }
            if(i==len){
                System.out.printf("Yes\n");
            }

        }
        sc.close();
    }

}
