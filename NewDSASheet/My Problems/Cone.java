public class Cone {
    private double radius;
    private double height;

    Cone(double radius, double height) {
        this.radius = radius;
        this.height = height;
    }

    double calculateSurfaceArea() {
        double slantHeight = Math.sqrt(radius * radius + height * height);
        return Math.PI * radius * (radius + slantHeight);
    }

    double calculateVolume() {
        return (Math.PI * radius * radius * height) / 3;
    }

    public static void main(String[] args) {
        if (args.length < 2) {
            System.out.println("Please provide radius and height of the cone as command line arguments.");
            return;
        }
        double radius = Double.parseDouble(args[0]);
        double height = Double.parseDouble(args[1]);
        Cone cone = new Cone(radius, height);
        System.out.println("Surface Area: " + cone.calculateSurfaceArea());
        System.out.println("Volume: " + cone.calculateVolume());
    }
}

