import java.util.*;

public class a7p10 {
    String deleteMe(String input, int pos){

        if( pos < 0 || pos > input.length()){
            return input;
        }



        return input.substring(0, pos)+input.substring(pos+1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter any string: ");
        String input = sc.nextLine();

        System.out.println("Enter the position to be deleted: ");
        int pos = sc.nextInt();

        a7p10 test = new a7p10();

        String afterDeletion = test.deleteMe(input, pos);
        
        System.out.println("String after deletion: "+afterDeletion);

        sc.close();
    }
}