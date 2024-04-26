class A {
    int value;

    A(int value) {
        this.value = value;
    }

    void display(A a) {
        System.out.println("Value from object of class A: " + a.value);
    }

    void display(B b) {
        System.out.println("Value from object of class B: " + b.value);
    }
}

class B {
    int value;

    B(int value) {
        this.value = value;
    }
}

public class Main {
    public static void main(String[] args) {
        A a = new A(10);
        B b = new B(20);
        a.display(a);
        a.display(b);
    }
}

