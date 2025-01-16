import java.util.*;

class Cylinder{

    int r;
    int h;

    Cylinder(int r, int h){
        this.r = r;
        this.h = h;
    }

    void circum(){
        System.out.println("Circumference is: "+(2*Math.PI*this.r));
    }

    void area(){
        double x = 2*Math.PI*this.r*this.h;
        double y = 2*Math.PI*Math.pow(r, 2);

        System.out.println("Area is: "+(x+y));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int r = 0;
        int h = 0;

        System.out.println("Enter the radius of the cylinder: ");
        r = sc.nextInt();
        
        System.out.println("enter the height of the cylinder: ");
        h = sc.nextInt();

        Cylinder c1 = new Cylinder(r, h);

        c1.area();

        c1.circum();

        sc.close();
    }
}