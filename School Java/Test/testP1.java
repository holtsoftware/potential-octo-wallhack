// Adam Holt
// week 12
// problem 1 
// test lab part

/* output from code
 * aA0bB1cC2D3dE4ef5ghF6iG7jH89IJ
 * a0A1bB2c34dC5eDfE6gF7hG8H9iIjJ
 * ab0cAdB1eC2D3fE4F5gG6h7i8jH9IJ
 */
public class testP1{
    static public void main(String[] args){
	new Thread(new StringIterator(dorange('a','j'))).start();
	new Thread(new StringIterator(dorange('A','J'))).start();
	new Thread(new StringIterator(dorange('0','9'))).start();
    }

    static public String dorange(char c1,char c2)
    {
	String toreturn = "";
        for(int i = c1; i <=c2; i++)
        {
	    toreturn += (char)i;
	}
	return toreturn;
    }

}

class StringIterator implements Runnable{
    public StringIterator(String str){
        topstr = str;
    }

    public void run(){
        for(int i = 0; i < topstr.length(); i++)
        {
            System.out.print(topstr.charAt(i));
	    Thread.yield();
	}
    }
    private String topstr;
}

