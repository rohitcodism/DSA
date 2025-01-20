class Myrunnable implements Runnable{
    String name;

    Myrunnable(String n){
        this.name = n;
    }

    @Override
    public void run(){
        for(int i = 0;i<3;i++){
            System.out.println(name + " is running with priority "+ Thread.currentThread());
        }
    }

    public static void main(String[] args) {
        for(int i = 0;i<5;i++){
            Thread thread = new Thread(new Myrunnable("Thread-"+i));
            thread.setPriority(i+1);
            thread.start();
        }
    }
}