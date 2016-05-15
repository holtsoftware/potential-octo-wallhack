// Adam Holt
// week7
// exercise 18.2
// wk7 hwk2: 18.2

public class FiniteThreadsMain18_2 {
    public static void main(String[] args){
       new Thread(new FiniteThreadUp()).start();
       new Thread(new FiniteThreadDown()).start();

    }
}

class FiniteThreadUp implements Runnable {
    public void run() {
        for(int i = 1; i < 4000; i++)
        {
            System.out.print(i + ",");
            System.out.flush();
            Thread.yield();
        }
    }
}

class FiniteThreadDown implements Runnable {
    public void run() {
        for(int i = -1; i > -4000; i--)
        {
            System.out.print(i + ",");
            System.out.flush();
            Thread.yield();
        }
    }
}
