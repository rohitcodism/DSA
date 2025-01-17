class Box{
    double volume;

    Box(double side){
        this.volume = side*side*side;
    }

    Box(double radius, double height){
        this.volume = ((Math.PI*radius*radius*height)/3);
    }

    void displayVolume(){
        System.out.println("Volume: "+(this.volume));
    }

    public static void main(String[] args) {
        Box b1 = new Box(5);
        Box b2 = new Box(4.2, 5.6);

        b1.displayVolume();

        b2.displayVolume();
    }
}