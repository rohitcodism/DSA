import java.util.*;

class Test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str = "Hello";

        str.concat("World");

        System.out.println("String immutable: "+str);

        StringBuffer sb = new StringBuffer("Hello");

        sb.append("Java.");

        System.out.println("String mutable: "+sb);
    }
}