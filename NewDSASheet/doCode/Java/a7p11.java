import java.util.*;

class A7P11{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String question = "Who is the inventor of java ?";
        String answer = "James Gosling";

        int attempts =0;
        boolean isCorrect = false;

        while(attempts < 3 && !isCorrect){
            System.out.println(question);
            System.out.println("Enter your answer: ");
            String userAnswer = sc.nextLine();
            if(answer.equalsIgnoreCase(userAnswer)){
                System.out.println("Good");
                isCorrect=true;
            }else{
                attempts++;
                if(attempts < 3){
                    System.out.println("Try again");
                }
            }
        }

        if(!isCorrect){
            System.out.println("Correct answer: "+answer);
        }

        sc.close();
    }
}