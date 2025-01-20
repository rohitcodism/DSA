class MyRunnable implements Runnable{
    MyRunnable(){
        System.out.println("Runnable thread is running.");
    }

    @Override
    public void run(){
        try {
            System.out.println("Thread: "+ Thread.currentThread());
            Thread.sleep(500);
        } catch (InterruptedException e) {
            // TODO: handle exception
            System.out.println(Thread.currentThread() + " is interrupted.");
        }
    }

    public static void main(String[] args) {
        MyRunnable runnable = new MyRunnable();

        Thread thread = new Thread(runnable, "CustomRunnable");
        thread.start();

        for(int i = 0;i<3;i++){
            System.out.println("Main thread is running.");
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                // TODO: handle exception
                System.out.println("Main thread is interrupted.");
            }
        }
    }
}

