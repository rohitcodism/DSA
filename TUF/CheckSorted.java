import java.util.Scanner;


public class CheckSorted {
    boolean checkSorted(int arr[], int n){

        for(int i = 0;i<n-1;i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.println("Enter the size of the array: ");
        n = sc.nextInt();

        int arr[] = new int[n];

        System.out.println("Enter the array elements:");
        for(int i = 0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        CheckSorted C1 = new CheckSorted();

        boolean flag = C1.checkSorted(arr, n);

        System.out.println(flag);

        sc.close();
    }
}
