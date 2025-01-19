import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter s string: ");
        String input = sc.nextLine();

        String[] words = input.split("\\s+");

        Arrays.sort(words);

        for(String word : words){
            System.out.println(word+" ");
        }

        sc.close();
    }
}