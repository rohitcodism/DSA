import java.util.Scanner;

public class LeftRotate {
    void leftRotate(int[] arr, int k) {
        int n = arr.length;
        int[] temp = new int[n - k + 1];

        for (int i = 0; i < n - k + 1; i++) {
            temp[i] = arr[i];
        }

        for (int i = k; i < n; i++) {
            arr[i - k] = arr[i];
        }

        for (int i = n - k; i < n; i++) {
            arr[i] = temp[i - (n - k)];
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;

        System.out.print("Enter the size of the array: ");
        n = sc.nextInt();

        int[] arr = new int[n];

        System.out.print("Enter the array elements: ");
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        System.out.print("Enter the roation mark: ");
        int k = sc.nextInt();

        LeftRotate LR1 = new LeftRotate();

        LR1.leftRotate(arr, k);

        System.out.print("After rotation the array is: ");
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i]);
        }

        sc.close();
    }
}