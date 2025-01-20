import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter your first name: ");
        String first_name = sc.nextLine();

        System.out.println("Enter your middle name: ");
        String middle_name = sc.nextLine();

        System.out.println("Enter your last name: ");
        String last_name = sc.nextLine();

        System.out.println("Enter your roll number: ");
        String roll = sc.nextLine();

        StringBuilder password = new StringBuilder();

        password.append(first_name.charAt(0));

        if(!middle_name.isEmpty()){
            password.append(middle_name.charAt(0));
        }

        password.append(last_name.charAt(0));

        password.append(roll.substring(roll.length() - 4));

        System.out.println("the password is: "+password.toString());

        sc.close();

    }
}