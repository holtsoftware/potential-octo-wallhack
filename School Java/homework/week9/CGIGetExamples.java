        // Examples of using the CGI GET method to send a
        // string to a server and have it echoed back.
        // The string to send is the concatenation of the program
        // arguments, separated by newlines, and the key name it is sent with
        // is "Echo". The URL expecting this is
        // http://www.cs.ukc.ac.uk/people/staff/djb/cgi-bin/echo.pl

import java.io.*;
import java.net.*;

public class CGIGetExamples {
    public static void main(String[] args) {
        if(args.length < 1){
            System.err.println("Usage: java CGIGetExamples string ... ");
            System.exit(1);
        }

        // Form the string to send from the command line arguments.
        // Each argument is separated from the others by a newline.
	String request = args[0]; // Append the rest. 
	for(int i = 1; i < args.length; i++)
	{
	    request += "\n"+args[i]; 
        } // The key expected by the script. 
        final String key = "Echo"; // Encode the request for sending and prefix the key.
        request = key+"="+URLEncoder.encode(request);

        try{
            System.out.println("Sending: "+request);
            // Encode the request as part of the URL.
            CGIClient client = new CGIClient(
                "http://www.cs.ukc.ac.uk/people/staff/djb/cgi-bin/echo.pl"+
                "?"+request);
            System.out.println(client.getResponse());

            // Send the request as a Request Property with GET to the server.
            CGIGetClient getter = new CGIGetClient(
                "http://www.cs.ukc.ac.uk/people/staff/djb/cgi-bin/echo.pl");
            System.out.println(getter.get(request));
        }
        catch(Exception e){
            System.err.println(e);
        }
    }
}

