
import java.net.*;
import java.io.*;
import java.util.*;

public class BroadCastServer {
	protected final ServerSocket serverSocket;
	protected final Vector vect;

	public BroadCastServer(int port) throws Exception {
		try{
			//try to bind the socket if we cant you should change the port
			serverSocket = new ServerSocket(port);
			vect = new Vector();
			System.out.println("Server Listening on port "+port);
		}
		catch(BindException e){
			throw new Exception("Failed to create a server socket: "+ e.getMessage());
		}
	}

	//Start Binding the clients interfaces
	public void run() throws Exception {
		//while the specale command hasn't been sent keep the server going
		boolean b=true;
		while(b){
			try{
				//wait for another client to connect
				Socket clientSocket = serverSocket.accept();
				BroadCastWriter wr = new BroadCastWriter("files/Command.file");
				BroadCastClient cast = new BroadCastClient(vect,clientSocket,wr);

				vect.add(cast);
				//Let a sepret thread handle 
				new Thread(cast).start();

            }
			catch(IOException e){
                throw new Exception("IOException: "+ e.getMessage());
            }
		}
		//we dont need the slocket anymore so just close it
		serverSocket.close();
	}
}

// vim:ts=4
