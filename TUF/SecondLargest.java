import java.util.*;

class SecondLargest{
    void secondLargest(int[] arr, int n){
        int largest = arr[0];
        int secondLargest = -1;
    
        for(int i = 0;i<n;i++){
            if(arr[i]>largest){
                secondLargest = largest;
                largest = arr[i];
            }
        }
    
        if(secondLargest != -1){
            System.out.println("Second largest element in the array: "+(secondLargest));
        }
        else{
            System.out.println("There is no second largest number in the array.");
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.println("Enter the size of the array: ");
        n = sc.nextInt();

        int arr[] = new int[n];

        for(int i = 0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        SecondLargest sc1 = new SecondLargest();

        sc1.secondLargest(arr, n);

        sc.close();
    }
}