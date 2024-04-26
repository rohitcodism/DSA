public class Cylinder {
    private double radius;
    private double height;

    Cylinder(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    double calculateSurfaceArea() {
        return 2 * Math.PI * radius * (radius + height);
    }

    double calculateCircumference() {
        return 2 * Math.PI * radius;
    }

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Please provide radius and height of the cylinder as command line arguments.");
            return;
        }
        double radius = Double.parseDouble(args[0]);
        double height = Double.parseDouble(args[1]);
        Cylinder cylinder = new Cylinder(radius, height);
        System.out.println("Surface Area: " + cylinder.calculateSurfaceArea());
        System.out.println("Circumference: " + cylinder.calculateCircumference());
    }
}