import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");

        String str = sc.nextLine();

        char[] charArray = str.toCharArray();

        System.out.println("Character array: ");
        for(char c: charArray){
            System.out.println(c+" ");
        }

        sc.close();
    }
}