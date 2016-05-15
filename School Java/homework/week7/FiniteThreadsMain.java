// Adam Holt
// week7
// exercise 18.1
// wk7 hwk1: 18.1

public class FiniteThreadsMain {
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
