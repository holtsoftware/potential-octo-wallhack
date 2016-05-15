// Adam Holt
// week7
// exercise 18.6
// wk7 hwk4: 18.6

public class FiniteThreadsMain18_6 {
    public static void main(String[] args){
       Thread t1 = new Thread(new FiniteThreadUp());
       Thread t2 = new Thread(new FiniteThreadDown());

       t1.start();
       t2.start();

       while(t1.isAlive() || t2.isAlive())
       {
           t1.setPriority((int)(Math.round(Math.random()*Thread.MAX_PRIORITY+1)+ Thread.MIN_PRIORITY));
           t2.setPriority((int)(Math.round(Math.random()*Thread.MAX_PRIORITY+1)+ Thread.MIN_PRIORITY));
           Thread.yield();
       }
    }
}

class FiniteThreadUp implements Runnable {
    public void run() {
        for(int i = 1; i < 4000; i++)
        {
            System.out.print(i + ",");
            System.out.flush();
        }
    }
}

class FiniteThreadDown implements Runnable {
    public void run() {
        for(int i = -1; i > -4000; i--)
        {
            System.out.print(i + ",");
            System.out.flush();
        }
    }
}
