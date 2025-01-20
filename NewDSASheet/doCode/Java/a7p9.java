import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String input = sc.nextLine();

        System.out.println("Enter the starting index: ");
        int n = sc.nextInt();

        System.out.println("Enter the number of characters to extract: ");
        int m = sc.nextInt();

        String extracted = input.substring(n, Math.min(n+m, input.length()));

        System.out.println("Extracted string: "+extracted);

        sc.close();
    }
}