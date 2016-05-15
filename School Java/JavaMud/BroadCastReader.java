import java.io.*;

/** 
* @author Adam Holt
* @version 1
* Class is used to read a file from the hard drive and return it as a string
*/

public class BroadCastReader{

	/** Cunstructs a new BroadCastReader
	*/
	public BroadCastReader(){
	}

	/** reads the content of a file and returns it as a string
	* @param fl The file to be returned as a string.
	* @return The the file as a string. null if it cant be loaded.
	*/
	public static String readFile(String fl){
		String str="";
		int tstr=(int)' ';
		try{
			FileReader in = new FileReader(fl);
			tstr = in.read();
			while(tstr != -1){
				str +=(char)tstr;
				tstr = in.read();
			}
			in.close();
		}
		catch(FileNotFoundException e){
			System.err.println(e.getMessage());
			return null;
		}
		catch(IOException e){
			System.err.println(e.getMessage());
			return null;
		}
		return str;
	}
}
	
// vim:ts=4
