import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String input = sc.nextLine();

        char[] charArray = {'A', 'B', 'C', 'D'};

        StringBuilder sb = new StringBuilder();

        for(char c: charArray){
            sb.append(c);
        }

        sb.append(input);

        System.out.println("Appended string: "+sb.toString());

        sc.close();
    }
}