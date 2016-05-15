/* Created on November 22, 2001, 9:54 PM
 * The dictinary files this class uses must be in a sepret file for each letter
 * and named for that letter i.e. (a.*,b.*,c.*) adam would be in the a.* dictinary
 * file and bata would be in b.* and cat would be in c.*
 */
import java.io.*;
import java.util.Vector;
/**
 *
 * @author  Adam Holt
 * @version 1.0
 */
public class SpellChecker 
{
    private final int MAX_CHOICE=10;
    private String file_ext;
    private String path;
    private Vector pwords;
    private int[] mcount;

    /** Creates new SpellChecker */
    public SpellChecker(String f_ext, String the_path) 
    {
        if(f_ext.charAt(0)=='.') //if you seply a . with the ext ill remove it
            file_ext=f_ext.substring(1,f_ext.length());
        else
            file_ext=f_ext;
        if(the_path.charAt(the_path.length()-1)=='\\')//if a \ is sapplyed at the end ill remove it
            path=the_path.substring(0,the_path.length()-1);
        else
            path=the_path;
        //System.out.println(path);//this is for debuging purpasis
        pwords = new Vector();
        mcount = new int[MAX_CHOICE];
    }
    
    ////////////////////////////////////////////////////////////////////////////
    // Function checks to see if the_word is in the function
    ////////////////////////////////////////////////////////////////////////////
    public boolean check_word(String the_word)
    {
        if(the_word.length()==0)
            return true;
        char which_dict=the_word.charAt(0);
        String dict_file=new String(path + '\\' + which_dict + '.' + file_ext);
        String line=new String("");
        int num_match;
        pwords.clear();
        try
        {
            FileReader fr=new FileReader(dict_file);
            BufferedReader inFile=new BufferedReader(fr);
            
            line=inFile.readLine();
            the_word=the_word.toUpperCase();
            while(line!=null)//if there was still suff to read loop agen
            {
                line=line.toUpperCase();
                line=line.trim();
                
                //System.out.println(line);//this was for debuging perpuce
                num_match=num_mach(line,the_word);
                if(line.equalsIgnoreCase(the_word))//if we found a matching word close the file and return true
                {
                    inFile.close();
                    return true;
                }
                else
                {
                    if(num_match>=(the_word.length()/2)+1)//if line matches atleast half the leters in the_word add it to the segestion list
                    {
                        addword(line,num_match);
                    }
                }
                line=inFile.readLine();
            }
            inFile.close();
        }
        catch(FileNotFoundException exception)
        {
            System.out.println("You didn\'t supply a correct path or a correct file extion or the path don't contain any of the right files.");
        }
        catch(IOException exception)
        {
            System.out.println(exception);
        }
        return false;//we wernt able to find the word so return false
    }
    
    ////////////////////////////////////////////////////////////////////////////
    // retuns the number of charicters that are the same in the two words
    ////////////////////////////////////////////////////////////////////////////
    public int num_mach(String fword,String tmach)
    {
        //System.out.println(fword + ",0");
        int length,num_match=0;
        //sets length to the smallist word
        if(tmach.length()>=fword.length())
            length=fword.length();
        else
            length=tmach.length();
        
        for(int i=0;i<length;i++)//loop throw each charicter and if there equil add one to the total
        {
            if(fword.charAt(i)==tmach.charAt(i))
            {
                num_match++;
            }
        }
        return num_match;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    // addes word to pwords in a sortad manner
    ////////////////////////////////////////////////////////////////////////////
    private void addword(String word,int nMatch)
    {
       // System.out.println(word + ",1");
        int first=0,current,
            last=pwords.size(),addat=-1,elemate=-1;
        current=last/2;

        while(addat==-1)//while we havn't found the place that it should be at
        {
            if(first >= last)
                addat = current;
            else if(mcount[current] == nMatch)
                addat = current;
            else if(mcount[current] > nMatch)
            {
                first = current + 1;
                current = (first + last) / 2;
            }
            else
            {
                last = current - 1;
                current = last / 2;
            }
        }
            pwords.add(addat,word);
        if(pwords.size()>=MAX_CHOICE)
        {
            pwords.remove(pwords.size()-1);
        }
        for(int i=pwords.size()-1;i>addat;i--)
        {
            mcount[i]=mcount[i-1];
        }
        mcount[addat]=nMatch;
        //System.out.println("Green");
    }
    
    ////////////////////////////////////////////////////////////////////////////
    //  Displays all the words in pwords with seperator between them
    ////////////////////////////////////////////////////////////////////////////
    public void displaySWords(char seperator)
    {
        int size=pwords.size();
        
        for(int i=0;i<size;i++)
        {
            System.out.print((String)pwords.elementAt(i));
            if((i+1)!=size)//makes shure that we dont include the seperator at the end
                System.out.print(seperator);
        }
        System.out.println("");
    }
}
