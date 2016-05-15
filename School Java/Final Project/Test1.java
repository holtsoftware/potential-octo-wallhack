/*
 * Test1.java
 *
 * Created on July 13, 2002, 10:28 AM
 */
import java.lang.*;
/**
 *
 * @author  adam
 * @version 
 */
public class Test1 {

    /** Creates new Test1 */
    public Test1() {
    }

    /**
    * @param args the command line arguments
    */
    public static void main (String args[]) {
        Matrix m = new Matrix(5,5);
		int i,j,tmp;
        
	    for(i=0;i<5;i++){
	        for(j=0;j<5;j++){
				tmp=(int)(Math.random()*10);
				System.out.print(tmp+",");
				m.setAt(i,j,new Integer(tmp));
			}
			System.out.println();
		}
		System.out.println("\n\n\n");

		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				System.out.print(
						((Integer)m.getAt(i,j)).intValue()+",");
			}
			System.out.println();
		}
	
    }

}

// vim:ts=4
