class Test{

    Test(){
        System.out.println("Object Created!!");
    }

    static{
        System.out.println("Hello World");
    };

    static{
        System.out.println("Hello World 2");
    }
}

class Main{
    public static void main(String[] args) {
        new Test();
    }
}