import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String input = sc.nextLine();

        System.out.println("String length with spaces: "+input.length());

        System.out.println("String length without spaces: "+input.trim().length());

        sc.close();
    }
}