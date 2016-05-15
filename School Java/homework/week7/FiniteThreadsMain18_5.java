// Adam Holt
// week7
// exercise 18.5
// wk7 hwk3: 18.5

public class FiniteThreadsMain18_5 {
    public static void main(String[] args){
       Thread t1 = new Thread(new FiniteThreadUp());
       Thread t2 = new Thread(new FiniteThreadDown());

       t1.start();
       t2.start();

       for(int i = 0; i< 5;i++)
       {
           t1.setPriority(t1.getPriority() - 1);
           t2.setPriority(t2.getPriority() - 1);
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
