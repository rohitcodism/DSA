class Cone {
    double radius, height;

    Cone(double r,double h){
        this.radius = r;
        this.height = h;
    }

    void area(){
        System.out.println("Area: "+(Math.PI*this.height*this.radius));
    }

    void volume(){
        double x = Math.PI*Math.pow(this.radius, 2.0)*this.height;
        System.out.println("Volume: "+((0.33)*x));
    }

    public static void main(String[] args) {
        double r = Double.parseDouble(args[0]);
        double h = Double.parseDouble(args[1]);

        Cone c1 = new Cone(r,h);

        c1.area();

        c1.volume();
    }
}
