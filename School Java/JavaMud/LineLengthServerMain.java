        // An example of a simple server that reads lines from
        // clients and sends back the length of each line
        // it receives.
public class LineLengthServerMain {
    public static void main(String[] args){
        try{
            // An arbitrary port number to listen on. This should be
            // larger than 1024 for user-written servers.
            final int port = 24101;
            LineLengthServer server = new LineLengthServer(port);
            server.run();
        }
        catch(Exception e){
            System.err.println("Exception: "+e.getMessage());
        }
    }
}
