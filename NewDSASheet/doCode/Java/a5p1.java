interface Shape {
    public double pie = Math.PI;

    public double calculateArea();
}

class Rectangle implements Shape{
    double length, breadth;
    
    Rectangle(double l, double b){
        this.length = l;
        this.breadth = b;
    }

    @Override
    public double calculateArea(){
        return (this.length*this.breadth);
    }
}

class Circle implements Shape{
    double radius;

    Circle(double r){
        this.radius = r;
    }

    @Override
    public double calculateArea(){
        return (Shape.pie*this.radius*this.radius);
    }
}

class Test{
    public static void main(String[] args) {
        Circle c1 = new Circle(5.6);

        Rectangle r1 = new Rectangle(4.5,3.8);

        System.out.println("Rectngle Area: "+(r1.calculateArea()));

        System.out.println("Circle Area: "+(c1.calculateArea()));
    }
}