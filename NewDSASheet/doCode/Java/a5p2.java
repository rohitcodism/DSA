class Outer{
    int x;

    Outer(int x){
        this.x = x;
    }

    class Inner{
        int y;

        Inner(){
            this.y = 15;

            System.out.println("The value of outer class is: "+x);
        }
    }

    void assignment(){
        this.x = new Inner().y;

        System.out.println("The value of inner class is: "+this.x);
    }
}

class Main{
    public static void main(String[] args) {
        Outer o1 = new Outer(25);

        o1.assignment();
    }
}