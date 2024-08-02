import java.util.Scanner;

public class RemoveDup {
    int removeDup(int[] arr, int n){
        int und = 0;

        for(int i = 0;i<n;i++){
            if(arr[und] != arr[i]){
                ++und;
                arr[und] = arr[i];
            }
        }

        return und+1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n=0;
        System.out.print("Enter the size of the array: ");
        n = sc.nextInt();
        int arr[] = new int[n];

        System.out.println("Enter the array elements: ");
        for(int i = 0;i<n;i++){
            System.out.print("Enter the "+(i+1)+" element of the array: ");
            arr[i] = sc.nextInt();
        }

        RemoveDup R1 = new RemoveDup();

        int und = R1.removeDup(arr, n);

        System.out.println("Total unique elements in the array: "+(und));

        sc.close();
    }
}
