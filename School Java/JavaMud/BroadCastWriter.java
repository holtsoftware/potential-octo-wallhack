
import java.io.*;
/**
* @author Adam Holt
* @version 1
* Class is used to write to log files or comment file.
*/

public class BroadCastWriter{
	private BufferedWriter out;
	private File file;

	/** Cunstructs a new BroadCastWriter
	* @param str The file to be writen to.
	*/
	public BroadCastWriter(String str){
		try{
			file = new File(str);
			out = new BufferedWriter(new FileWriter(file,true));
		}
		catch(FileNotFoundException e){
			System.err.println(e.getMessage());
		}
		catch(IOException e){
			System.err.println(e.getMessage());
		}
	}
	
	/** Writes a line to the file
	* @param line The line to add to the end of the file
	*/
	public synchronized void writeLine(String line){
		try{
			System.out.println("File Length: "+file.length());
			if(file.length() < 5000000){
				out.write(line);
				out.newLine();
				out.flush();
			}
			else{
				System.out.println("File To Big.");
			}
		}
		catch(IOException e){
			System.err.println("IOException: "+e.getMessage());
		}
	}
}

// vim:ts=4
