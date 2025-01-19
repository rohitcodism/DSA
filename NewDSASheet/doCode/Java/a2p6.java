class Test1{
    Test1(){
        System.out.println("Test 1 is initiated");
    }
}

class Test2{
    Test2(){
        System.out.println("Test 2 is initiated.");
    }

    void obj(Test1 t1){
        System.out.println("Received Object from t1");
    }

    void obj2(Test2 t2){
        System.out.println("Received Object from t2");
    }

    Test1 retObj(){
        return new Test1();
    }

    Test2 retObj2(){
        return new Test2();
    }

    public static void main(String[] args) {
        // Test1 t1 = new Test1();

        Test2 t2 = new Test2();

        // t2.obj(t1);

        // t2.obj2(t2);

        Test1 x = t2.retObj();

        System.out.println(x);

        Test2 y = t2.retObj2();

        System.out.println(y);
    }
}

//*Output of this code */

/* 
    Test 2 is initiated.
    Test 1 is initiated
    Test1@123772c4
    Test 2 is initiated.
    Test2@2d363fb3
 */