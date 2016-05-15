/*
 * ReadFile.java
 *
 * Created on November 27, 2001, 6:11 PM
 */
import java.io.*;
import StringUtil;
import SpellChecker;
import java.util.Vector;
import java.util.StringTokenizer;
import cs1.Keyboard;
/**
 *
 * @author  Adam Holt
 * @version 1.0
 */
public class ReadFile {
    
    private boolean ia;
    private Vector vfile;
    private String Spath;
    private String Sext;

    /** Creates new ReadFile */
    public ReadFile(String path,String ext) 
    {
        Spath=path;
        Sext=ext;
        vfile=new Vector();
    }
    
    public void readfile(String file,char start,char stop,char exc)
    {
        ia = false;
        String line,temp,temp2;
        int start_at,start_temp,stop_at,stop_temp,size;
        
        try
        {
            FileReader fr = new FileReader(file);
            BufferedReader inFile = new BufferedReader(fr);
            
            line = inFile.readLine();
            while(line!=null)
            {
                start_at=StringUtil.instr(line,start);//lets see if start is in line
                temp=line;
                size=line.length();
                
                start_temp=0;
                //while the charicter that start_at -1 das not == exc
                while(start_at != 0 && start_at != -1 && (line.charAt(start_at -1) == exc))
                {
                    if(start_at != size-1)
                    {
                        temp=line.substring(start_at + 1);
                        start_temp=StringUtil.instr(temp,start);
                        start_at+=start_temp + 1;
                    }
                }
                
                //if the charicter is in the string and not at the end
                if(start_at != -1 && (start_at != (size -1)))
                {
                   temp=line.substring(start_at + 1);
                   stop_at=StringUtil.instr(temp,stop);
                   
                   temp2=temp;
                   stop_temp=0;
                   while(stop_at != 0 && stop_at != -1 && (temp.charAt(stop_at -1) == exc))
                   {
                       temp2 = temp.substring(stop_at + 1);
                       stop_temp = StringUtil.instr(temp2,stop);
                       stop_at += stop_temp + 1;
                   }
                   
                   if(stop_at != -1 && stop_at != 0)//if stop_at == to 0 it means that start and stop are right next to eachother so why should we check it
                   {
                       String checked_str;
                       temp=line.substring(start_at + 1,start_at + 1 + stop_at);
                       checked_str=temp;
                       if(!ia)
                       {
                            checked_str=CheckSpelling(temp,exc);
                            if(checked_str == null)
                                return;
                            else if(checked_str == "" + ((char)128))
                            {
                                ia = true;
                                checked_str = temp;
                            }
                       }
                           
                       line=line.substring(0,start_at) + start + checked_str
                            + stop + line.substring(start_at + 2 +stop_at,line.length());
                   }
                }
                vfile.addElement(line);
                line = inFile.readLine();
            }
            inFile.close();
            write_file(file);
        }
        catch (FileNotFoundException exception)
        {
            System.out.println("Couldn't find " + file + ".");
        }
        catch (IOException exception)
        {
            System.out.println(exception);
        }
    }
    
    public String CheckSpelling(String str,char esc)
    {
        StringTokenizer token = new StringTokenizer(str);
        SpellChecker spell = new SpellChecker(Sext,Spath);
        String word,temp,to_return=new String();
        while(token.hasMoreTokens())
        {
            word = token.nextToken();   
            temp = remove_specal(word,esc);
            temp=StringUtil.DIND(temp,esc);
            if(!spell.check_word(temp))
            {
                System.out.println("-----------------------------------------------------------------------------------");
                System.out.println("The String at line " + (vfile.size()+1) + " the word " + temp + "("+word+") was not found in the dictanary files.");
                System.out.println("String:\"" + str +"\"");
                System.out.print("The closest words found were : ");
                spell.displaySWords(',');
                System.out.println("What do you wont to change the word to ([none] to keep it the same):");
                temp=Keyboard.readWord();
                System.out.println(temp);
                if(temp.equalsIgnoreCase("[quit]"))
                {
                    System.out.println("Quiting with out saving the changes.");
                    return null;
                }
                else if(temp.equalsIgnoreCase("[i/a]"))
                {
                    System.out.println("Ignoring the rest of the file.");
                    return "" + ((char)128);
                }
                if(!temp.equalsIgnoreCase("[none]"))
                    word=temp;
            }
            to_return+=word + ' ';
        }
        to_return = to_return.substring(0,to_return.length()-1);
        return to_return;
    }
    
    public String remove_specal(String word,char esc)
    {
        int i=0;
        char temp;
        String str = word;
        while(i<str.length())
        {
            temp=str.charAt(i);
            if((temp < 'A' || temp > 'Z') && (temp < 'a' || temp > 'z') && (temp != esc) && (temp != '\''))
            {
                str = str.substring(0,i) + str.substring(i+1,str.length());
            }
            else
            {
                if(temp == esc)
                {
                    i += 2;
                }
                else
                    i++;
            }
        }
        return str;
    }
    
    private void write_file(String file) throws IOException
    {
            FileWriter fr = new FileWriter(file);
            BufferedWriter bw = new BufferedWriter(fr);
            PrintWriter outFile = new PrintWriter(bw);
            
            System.out.println("Writing to file " + file);
            int size = vfile.size();
            
            if(!((String)vfile.elementAt(size-1)).startsWith("// This file was spell checked by holt-software's spell checker"))
            {
                size++;
                vfile.addElement("// This file was spell checked by holt-software's spell checker");
            }
            
            for(int i=0;i<size;i++)
            {
                outFile.println(((String) vfile.elementAt(i)));
            }
            outFile.close();
            
    }
}
