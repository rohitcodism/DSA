class SharedResource{
    synchronized void printMessage(String message){
        System.out.println("[" + message);
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            // TODO: handle exception
            System.out.println("Thread interrupted.");
        }
        System.out.println("]");
    }
}

class MyThread extends Thread{
    private SharedResource resource;
    private String message;

    MyThread(SharedResource resource, String message){
        this.resource = resource;
        this.message = message;
    }

    @Override
    public void run(){
        resource.printMessage(message);
    }

    public static void main(String[] args) {
        SharedResource resource = new SharedResource();

        MyThread t1 = new MyThread(resource, "Thread-1");
        MyThread t2 = new MyThread(resource, "Thread-2");
        MyThread t3 = new MyThread(resource, "Thread-3");

        t1.start();

        t2.start();

        t3.start();

    }
}