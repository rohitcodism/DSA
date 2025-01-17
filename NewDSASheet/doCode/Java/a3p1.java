class Test{

    void add(int a, int b){
        System.out.println(a+b);
    }

    // void add(int a, int b){
    //     System.out.println(a+b);
    // }

    void add(double a, double b){
        System.out.println(a+b);
    }

    public static void main(String[] args) {
        

        Test t1 = new Test();

        t1.add(3.1,5.5);

    }
}