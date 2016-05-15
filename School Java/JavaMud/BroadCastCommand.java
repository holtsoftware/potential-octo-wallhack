import java.util.*;
import java.io.*;

public class BroadCastCommand{
	private Vector vect;
	public BroadCastCommand(Vector v){
	}

	public synchronized int DoCommand(String cmd,BroadCastClient bcc){
		if(cmd.charAt(0) == ':'){
			System.out.println("Command reseaved");
		}
		else{
			try{
				for(int i =0;i<vect.size();i++){
					((BroadCastClient)vect.elementAt(i)).sendLine(bcc.getName()+": "+cmd);
				}
			}
			catch(IOException e){
				System.err.println("IOException: "+e.getMessage());
			}
		}
		return 1;
	}
}
// vim:ts=4
