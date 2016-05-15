/*
 * BugMain.java
 *
 * Created on June 10, 2002, 5:09 PM
 */

/**
 *
 * @author  adam
 * @version 
 */
public class BugMain {

    /** Creates new BugMain */
    public BugMain() {
    }

    /**
    * @param args the command line arguments
    */
    public static void main (String args[]) {
        BugFraim bf = new BugFraim();
        bf.addWindowListener(new WindowCloser());
        bf.show();
    }

}
