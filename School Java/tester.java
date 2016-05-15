/*
 * tester.java
 *
 * Created on November 26, 2001, 12:07 AM
 */
import SpellChecker;
import ReadFile;
import StringUtil;
/**
 *
 * @author  Adam Holt
 * @version 
 */
public class tester
{

    /** Creates new tester */
    public tester() {
    }

    /**
    * @param args the command line arguments
    */
    public static void main (String args[]) 
    {
        ReadFile file = new ReadFile("E:\\dicts","dict");
        
        file.readfile("E:\\SpellChecker.java",'\"','\"','\\');
    }

}
