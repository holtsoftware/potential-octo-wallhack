/*
 * StringUtil.java
 *
 * Created on November 27, 2001, 7:49 PM
 */

/**
 *
 * @author  Adam Holt
 * @version 
 */
public class StringUtil {

    /** Creates new StringUtil */
    public StringUtil() {
    }
    
    ////////////////////////////////////////////////////////////////////////////
    // returns the first accurence of ichar in str or -1 if ichar isn't in str
    ////////////////////////////////////////////////////////////////////////////
    public static int instr(String str,char ichar)
    {
        int size=str.length();
        
        for(int i=0;i<size;i++)
        {
            if(str.charAt(i) == ichar)//if we found ichar return whare we did
                return i;
        }
        
        return -1;// we didn't find ichar
    }

    ////////////////////////////////////////////////////////////////////////////
    // deletes all accurences of to_del in str if there arn't two of them right 
    // next to each other
    ////////////////////////////////////////////////////////////////////////////
    public static String DIND(String str,char to_del)//Delete If Not Duplicate
    {
        for(int i=0;i<str.length();i++)
        {
            if(i+1 != str.length())
            {
                if(str.charAt(i) == to_del)
                {
                    if(str.charAt(i+1) != to_del)
                    {
                        if(i != 0)
                        {
                            str= str.substring(0,i) + str.substring(i+1,str.length());
                            i--;
                        }
                        else
                        {
                            str = str.substring(1,str.length());
                            i--;
                        }
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else
            {
                str = str.substring(0,str.length());
            }
        }
        return str;
    }
}
