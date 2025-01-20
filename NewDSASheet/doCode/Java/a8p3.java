class MyThread extends Thread {
    MyThread(String name){
        super(name);
        System.out.println("Thread "+name+" is runnning.");
    }

    @Override
    public void run(){
        for(int i = 0;i<3;i++){
            System.out.println(getName() + " is currently running with priority "+ getPriority());
        }
    }
}

class Main{
    public static void main(String[] args) {
        for(int i = 0; i<5;i++){
            MyThread thread = new MyThread("Thread"+i);
            thread.setPriority(i+1);
            thread.start();
        }
    }
}