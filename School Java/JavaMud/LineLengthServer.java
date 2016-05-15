import java.net.*;
import java.io.*;

        // A simple server that accepts a client connection
        // and sends back the length of the strings it
        // receives from the client.
class LineLengthServer {
    public LineLengthServer(int port) throws Exception {
        try{
            // Listen on the given port.
            serverSocket = new ServerSocket(port);
        }
        catch(BindException e){
            throw new Exception("Failed to create a server socket: "+
                        e.getMessage());
        }
    }

        // Read strings and return their length (as a String)
        // to the client.
    public void run() throws Exception {
        ServerSocket serverSocket = getServerSocket();
        Socket clientSocket = null;
        try{
            System.out.println("Listening for a client on port: "+
                               serverSocket.getLocalPort());
            // Wait for a client to make contact.
            clientSocket = serverSocket.accept();
            // Contact ...
            System.out.println("A client has arrived.");

            // Wrap the input stream in a BufferedReader.
            BufferedReader reader = new BufferedReader(
                    new InputStreamReader(clientSocket.getInputStream()));
            // Wrap the output stream in a BufferedWriter.
            BufferedWriter writer = new BufferedWriter(
                    new OutputStreamWriter(clientSocket.getOutputStream()));

            // Read lines until the client terminates.
            String request = reader.readLine();
            while(request != null){
                // Write the length of the line as a String.
                writer.write(String.valueOf(request.length()));
                writer.newLine();
                writer.flush();
                request = reader.readLine();
            }
        }
        catch(IOException e){
            throw new Exception("IOException talking to the client: "+
                                e.getMessage());
        }
        finally{
            if(clientSocket != null){
                System.out.println("The client has gone.");
                // Close the socket to the client.
                clientSocket.close();
            }
        }
        serverSocket.close();
    }

    protected ServerSocket getServerSocket(){
        return serverSocket;
    }

    // The socket on which the listening is done.
    private final ServerSocket serverSocket;
}

// vim:ts=4
