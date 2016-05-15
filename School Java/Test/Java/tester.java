/*
 * tester.java
 *
 * Created on November 26, 2001, 12:07 AM
 */
import SpellChecker;
import ReadFile;
import StringUtil;
import cs1.Keyboard;
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
        char contin = 'y',esc,begin,end;
        String file;
        ReadFile spelling = new ReadFile("E:\\dicts","dict");
        
        while(contin != 'n' && contin != 'N')
        {
            println("Enter the full path of the file to spell check.");
            file=Keyboard.readString();
            println("Enter the escape charicter for this language.");
            esc=Keyboard.readChar();
            println("Enter the charicter to begin a string in this language.");
            begin=Keyboard.readChar();
            println("Enter the charicter to end a string in this language.");
            end = Keyboard.readChar();
            spelling.readfile(file,begin,end,esc);
            println("Spell Check another file? (Y)es/(N)o");
            contin = Keyboard.readChar();
        }
    }
    
    public static void println(Object str)
    {
        System.out.println(str);
    }
}
