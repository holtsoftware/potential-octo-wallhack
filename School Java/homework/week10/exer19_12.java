// Adam Holt
// exercise 19.12
// week 10
// wk10 hwk3: 19.12
// Answer
// The biger the message didn't seem to efect the time of response.

import java.net.*;
import java.io.*;
import java.lang.Long;

public class exer19_12 {
    public static void main(String[] args){
        try{
            new Thread(new server(1240)).start();
            client cl = new client("photo.holt-software.com",1240);
            cl.execute();
        }
        catch(Exception e){
            System.err.println("Exception: " + e.getMessage());
        }
    }
}

// the client that actualy does all the work
class client {
    public client(String hostname,int serverport) throws Exception {
        try{
            socket = new Socket(hostname, serverport);
        }
        catch(UnknownHostException e){
            throw new Exception("Unknown host: " + e.getMessage());
        }
        catch(IOException e){
            throw new Exception("IOException on socket creation" + e.getMessage());
        }
    }

    public void execute(){
        try{
            BufferedReader reader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));

            String response,tosend;
            long tmpnum,tmpnum2;
            long resolts = 0, loopcount= 0;
            final int numtimes = 20, resettime = 10;

            for(int i = 0; i < numtimes; i++)
            {
                // get the time just before we send the data
                tmpnum = System.currentTimeMillis();
                
                tosend = "im going to just send jiborus.afdkajsl;fdjaslkdjflajsdl;fjals;kdjfl;kasjdkfgjsaldfjlasjdlfkjasldfjlaskdjflkasjdlfkjsadlflkasdjflkjsadlkfgjsaldflksadjfljsadlkfgjlasdjflksajdflkjsadlkfgjasldjflksaaaaaaaaaadjlksjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjdhqddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd";
                // send just a stream of data we dont need to do any thing with it
                writer.write(tosend);
                // prints out the datat we sent while were whating for a reply
                System.out.println("Sent: " + tosend);
                writer.newLine();
                writer.flush();

                response = reader.readLine();// stop here tell the server replys
                tmpnum2 = System.currentTimeMillis();// get that time we get a reply for the server
                tmpnum = tmpnum2 - tmpnum;// minus the current time from the time that we sent the data
                System.out.println("The response was: " + response);
                System.out.println("The Current Time is: " + tmpnum2);
                System.out.println("It took: " + tmpnum + " milliseconds");
                if(loopcount >= resettime)
                {
                    System.out.println("The mean this cycle is: " + (resolts/loopcount));
                    resolts = 0;
                    resolts += tmpnum;
                    loopcount = 0;
                }
                else
                {
                    resolts += tmpnum;
                    loopcount++;
                }
                System.out.println("------------------------------------");
            }
            resolts /= numtimes;
            System.out.println("The mean of them all is: " + resolts);
            socket.close();
        }
        catch(IOException e){
            System.err.println(e.getMessage());
        }
    }    

    private final Socket socket;
}
// A simple server that just replys with a "1"
class server implements Runnable{
    public server(int port) throws Exception {
        try{
            serverSocket = new ServerSocket(port);
        }
        catch(BindException e){
            throw new Exception("Failed to create a server socket: " + e.getMessage());
        }
    }

    public void run() {
        Socket clientSocket = null;
        try{
            System.out.println("Listening for a client on port: " + serverSocket.getLocalPort());

            clientSocket = serverSocket.accept();//what for a 

            System.out.println("A client has arrived.");

            BufferedReader reader = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            BufferedWriter writer = new BufferedWriter(
                                                   new OutputStreamWriter(clientSocket.getOutputStream()));

            String request = reader.readLine();//the inital read 
            while(request != null){
                // only had to change the line below to make it echo
                writer.write(request);//send a "1" nomater what the client sent
                writer.newLine();
                writer.flush();
                request = reader.readLine();// read a line that the client sent and ignore it

            }
            
            if(clientSocket != null){
                System.out.println("The client has gone.");
                clientSocket.close();
            }
        }
        catch(IOException e){
            System.err.println("IOException talking to the client: " + e.getMessage());
        }
    }

    private final ServerSocket serverSocket;
}

