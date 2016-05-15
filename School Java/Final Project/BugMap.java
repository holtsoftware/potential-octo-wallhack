/*
 * BugMap.java
 *
 * Created on June 10, 2002, 6:02 PM
 */
import java.util.StringTokenizer;
import java.io.*;
import java.lang.Integer;
/**
 *
 * @author  adam
 * @version 1.1
 */
public class BugMap {
    private Matrix Mmap;
    private String FileName;

    /** Creates new BugMap */
    public BugMap() {
    }

    /** Creates new BugMap and loads the a string map */
    public BugMap(String map){
	    LoadMap(map);
    }
    
    /** Loads the map */
    public boolean LoadMap(String map){
        StringTokenizer tokenizer;
        String line,IFF = new String("Invalid File format in " + map);
        int cols,rows;
        try
        {
            FileReader fr = new FileReader(map);
            BufferedReader inFile = new BufferedReader(fr);
            
            line = inFile.readLine();
            tokenizer = new StringTokenizer(line,",");
            //verify that the files formated right 
            if(tokenizer.countTokens() != 2)
            {
                inFile.close();
                System.out.println(IFF);
                return false;
            }
            //get the cols and rows of the map
            cols = Integer.parseInt(tokenizer.nextToken());
            rows = Integer.parseInt(tokenizer.nextToken());
            
            Mmap = new Matrix(rows,cols);
            
            //load the map from the file
            for(int i=0;i<rows;i++){
                line = inFile.readLine();
                tokenizer = new StringTokenizer(line,",");
                
                //verfiy file format
                if(tokenizer.countTokens() != cols)
                {
                    inFile.close();
                    System.out.println(IFF);
                    return false;
                }
                
                for(int j=0;j<cols;j++)
                {
                    Mmap.setAt(i,j,tokenizer.nextToken());
                }
            }
            inFile.close();
        }
        catch(FileNotFoundException exception)
        {
            System.out.println("The file "+map+" was not found.");
            return false;
        }
        catch(IOException exception)
        {
            System.out.println(exception);
            return false;
        }
        FileName = map;
        return true;
    }
    
    /** calles SaveMap with the set file if it exists */
    public boolean SaveMap(){
        if(FileName == null){
            return false;
        }
        return SaveMap(FileName);
    }
    
    /** writes the map to the file */
    public boolean SaveMap(String File)
    {
        try{
            int rows=Mmap.getRows(),cols=Mmap.getCols();
            FileWriter fw = new FileWriter(File);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter outFile = new PrintWriter(bw);

            outFile.println(Mmap.getCols()+","+Mmap.getRows());

            for(int i=0;i<rows;i++){
                for(int j=0;j<cols;j++){
                    outFile.print((String)Mmap.getAt(j,i));
                    if(j != (cols-1)){
                        outFile.print(",");
                    }
                }
                outFile.println();
            }
            outFile.close();
        }
        catch(FileNotFoundException exception)
        {
            System.out.println("The file "+File+" was not found.");
            return false;
        }
        catch(IOException exception)
        {
            System.out.println(exception);
            return false;
        }
        
        FileName = File;
        return true;
    }
    
    /** returns the map as a matrix */
    public Matrix getMap(){
        return Mmap;
    }
    
    public void setMap(Matrix m){
        Mmap = m;
    }
    
    public String getFileName(){
        return FileName;
    }
    
    public void setFileName(String fn){
        FileName = fn;
    }

}
