
import java.net.*;
import java.io.*;
import java.util.*;

public class BroadCastClient implements Runnable{
	private Socket socket;
    private BufferedReader reader;
    private BufferedWriter writer;
	private BroadCastWriter wr;
	private Vector vect;
	private boolean message;
	private String name;
	
	public BroadCastClient(Vector v,Socket s,BroadCastWriter r)throws Exception{
		vect = v;
		wr = r;
		message=false;
		setSocket(s);
		name = "Not Chosen";		
	}
	
	private boolean NameTaken(String na){
		//by default the request is set to ""
		if(na.equalsIgnoreCase("")){
			return true;
		}
		for(int i=0;i<vect.size();i++){
			if(((BroadCastClient)vect.elementAt(i)).getName().equalsIgnoreCase(na)){
				return true;
			}
		}
		return false;
	}

	public void run(){
		String request = "";
		try{
			System.out.println("New client arrived.\nThere are now "+vect.size()+" clients on.");
			message = true;//make it so the client reseaves this message
			sendLine(BroadCastReader.readFile("files/BeginMessage.file"));//show the welcome file
			while(NameTaken(request)){
				message = true;
				sendLine("Please enter your screen name.");
				message = false;//the client shouldn't reseave any more messages
				request = reader.readLine();
			}

			name = request;//read the name
			message = true;//ok now were on we can reseave all messages
			sendLine("Welcome "+name+".");

			request = reader.readLine();
			while( !request.equalsIgnoreCase(":close")){
				if(request.length() <= 0){
					sendLine("No message to send.");
				}
				else if(request.charAt(0) == ':'){
					executeCmd(request);
				}
				else{
					sendAll(name+": "+request);
					//Just to let the server know whats being typed
					System.out.println(name+": "+request);
					//wait for the cliant to send some thing
				}
				request = reader.readLine();
			}
	
			sendLine("Closing Connection.");


        }catch(IOException e){
            System.err.println("IOException: "+e.getMessage());
        }
		catch(NullPointerException e){
			System.err.println("NullPointerException: "+e.getMessage());
		}
		//gess its time to close are connection and remove are selfs form the vector
		close();
		vect.remove(this);
		System.out.println("Client closed");
		System.out.println("Number of clients "+vect.size()+".");
	}

	public void close(){
		try{
			socket.close();
		}
		catch(IOException e){
			//nothing much we can do
		}
	}
	
	//Sends line to all the users loged on
	public void sendAll(String line) throws IOException{
		for(int i=0;i<vect.size();i++){
			((BroadCastClient)vect.elementAt(i)).sendLine(line);
		}
	}

	//Execute the command for the user
	public void executeCmd(String cmd)throws IOException{
		String command,com2;
		int in=cmd.indexOf(" ");
		if(in != -1)
			command = cmd.substring(0,cmd.indexOf(" "));
		else
			command = cmd;
		if(cmd.equalsIgnoreCase(":adam close the server")){
			sendAll("Closing the server.");
			System.exit(0);
		}
		else if(command.equalsIgnoreCase(":who")){
			sendLine("----------");
			sendLine("There is currently "+vect.size()+" user(s) on.");
			for(int i=0;i<vect.size();i++){
				sendLine(((BroadCastClient)vect.elementAt(i)).getName());
			}		
			sendLine("----------");
		}
		else if(command.equalsIgnoreCase(":write") && in != -1){
			wr.writeLine(cmd.substring(in).trim());
			sendLine("Thank you for your comment.");
		}
		else{
			sendLine("Invalide command "+cmd+".");
			System.out.println("Invalid command "+cmd+" by "+name);
		}
	}

	//Sets the Socket and creates input and output streams
	protected void setSocket(Socket s) throws Exception {
		if(s != null){
			socket = s;
			//Wrap the input stream in a BufferedReader.
			reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
		}
		else{
			throw new Exception("Null socket passed to setSocket.");
		}
	}

	//sends a line to the client
	public synchronized void sendLine(String line) throws IOException{
		if(message){//if we arnt actsepting messages dont display them
			writer.write(line);
			writer.newLine();
			writer.flush();
		}
	}

	//Gets the name the client chose when he loged on
	public final String getName(){
		return name;
	}
}

// vim:ts=4
