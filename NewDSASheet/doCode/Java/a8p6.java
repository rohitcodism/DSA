class MyThread extends Thread{
    MyThread(String name){
        super(name);
    }

    @Override
    public void run(){
        for(int i = 0;i<3;i++){
            System.out.println(getName() + " is running.");
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                // TODO: handle exception
                System.out.println(getName() + " is interrupted.");
            }
        }
    }

    public static void main(String[] args) {
        MyThread t1 = new MyThread("Thread-1");
        MyThread t2 = new MyThread("Thread-2");

        t1.start();
        t2.start();

        try {
            t1.join();
        } catch (Exception e) {
            // TODO: handle exception
            System.out.println("Main thread is interrupted.");
        }

        System.out.println("Thread-1 is alive: " + t1.isAlive());

        System.out.println("Thread 2 is alive: "+ t2.isAlive());
    }
}