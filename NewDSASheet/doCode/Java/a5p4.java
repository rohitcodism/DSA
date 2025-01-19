class SuperClass{
    void hello(){
        System.out.println("Hello from super class.");
    }
}

interface MyInterface{
    void hello();
}

class Main{
    public static void main(String[] args) {
        SuperClass S1 = new SuperClass(){
            @Override
            public void hello(){
                System.out.println("Hello from Superclass through annonymous inner class.");
            }
        };

        S1.hello();

        MyInterface m1 = new MyInterface() {
            @Override
            public void hello(){
                System.out.println("Hello from my interface through annonymous inner class.");
            }
        };

        m1.hello();
    }
}