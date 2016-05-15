import java.net.*;
import java.io.*;
import javax.swing.*;

public class MessageSocket {
	private BufferedWriter writer;
	private MessageReader mes;
	private Socket sock;
	public MessageSocket(){
	}
	
	public void activateSocket(String host,int port,JTextArea txt,JScrollBar b)throws Exception{
		try{
			sock = new Socket(host,port);
			writer = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
			
			//gets all the messeges from the server
			new Thread(mes = new MessageReader(sock.getInputStream(),txt,sock,b)).start();
		}
		catch (UnknownHostException e){
			throw new Exception("Unknown host: "+e.getMessage());
		}
		catch (IOException e){
			throw new Exception("IOException on socket creation: "+e.getMessage());
		}
		
	}

	public void sendLine(String line)throws Exception{
		try{
			writer.write(line);
			writer.newLine();
			writer.flush();
		}
		catch (IOException e){
			throw new Exception("IOException while tring to send line " + line);
		}
	}
}

class MessageReader implements Runnable{
	private final BufferedReader reader;
	private final JTextArea text;
	private final Socket sock;
	private final JScrollBar bar;
	public MessageReader(InputStream inst,JTextArea txt,Socket s,JScrollBar b){
		reader = new BufferedReader(new InputStreamReader(inst));
		text = txt;
		sock = s;
		bar = b;
	}

	public void run(){
		try{
			String msg = reader.readLine();
			while(msg != null){//while are parent still exist lets keep going
				text.append(msg+"\n");
				//bar.setValue(bar.getMaximum());
				System.out.println(msg+"\\n"+bar.getMaximum());
				msg = reader.readLine();
			}
		}
		catch(IOException e){
			text.append("IOException: "+e.getMessage());
		}
	}
}
// vim:ts=4
