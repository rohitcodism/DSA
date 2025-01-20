class MyThread extends Thread{
    MyThread(String name){
        super(name);

        System.out.println("Thread"+name+" is starting.");
    }

    @Override
    public void run(){
        try {
            for(int i = 0;i<3;i++){
                System.out.println("Thread "+getName()+" is running.");
                Thread.sleep(500);
            }
        } catch (InterruptedException e) {
            // TODO: handle exception
            System.out.println("Thread "+getName()+" interrupted.");
        }
    }
}

class Main{
    public static void main(String[] args) {
        MyThread thread = new MyThread("Custom Thread");
        thread.start();

        for(int i = 0;i<3;i++){
            System.out.println("main thread is runnning.");
            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                // TODO: handle exception
                System.out.println("Main thread is interrupted.");
            }
        }
    }
}