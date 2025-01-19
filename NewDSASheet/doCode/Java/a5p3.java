interface A{
    public void helloA();
}

interface B{
    public void helloB();
}

interface C extends A,B{
    public void helloC();
}

class D{
    D(){
        System.out.println("Hello D");
    }
}


class Test extends D implements C{
    @Override
    public void helloC() {
        System.out.println("Hello from C through Test class.");
    }

    @Override
    public void helloA() {
        System.out.println("Hello from A through Test class.");
    }

    @Override
    public void helloB() {
        System.out.println("Hello from B through Test class");
    }
}

class Main{
    public static void main(String[] args) {
        Test t1 = new Test();

        t1.helloA();

        t1.helloB();

        t1.helloC();
    }
}
