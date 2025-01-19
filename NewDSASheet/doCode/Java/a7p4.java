import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a string: ");
        String input = sc.nextLine();

        int position = input.indexOf("Tech");

        if(position == -1){
            System.out.println("Doesn't Exist!!");
        }else{
            System.out.println("Exist!!");
        }

        sc.close();
    }
}