import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter any string: ");
        String input = sc.nextLine();

        char[] input2 = input.toCharArray();

        Arrays.sort(input2);

        System.out.println("Sorted string: "+String.valueOf(input2));

        sc.close();
    }
}