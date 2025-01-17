class Box{
    double volume;

    void volume(double side){
        System.out.println("Volume of the cube: "+(Math.pow(side, 3)));
    }

    void volume(double radius, double height){
        System.out.println("Volume of the cone: "+((Math.PI*Math.pow(radius, 2)*height)/3));
    }

    void displayVolume(){
        System.out.println("Volume: "+(this.volume));
    }

    public static void main(String[] args) {
        Box b1 = new Box();
        Box b2 = new Box();

        b1.volume(5);

        b2.volume(4.3,5.7);
    }
}