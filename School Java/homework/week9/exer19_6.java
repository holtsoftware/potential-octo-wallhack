//Adam HOlt
// week 9
// exercise 19.6
// wk9 hwk1: 19.6

        // Examples of using the CGI GET method to send a
        // string to a server and have it echoed back.
        // The string to send is the concatenation of the program
        // arguments, separated by newlines, and the key name it is sent with
        // is "Echo". The URL expecting this is
        // http://www.cs.ukc.ac.uk/people/staff/djb/cgi-bin/echo.pl

import java.io.*;
import java.net.*;

public class exer19_6 {
    public static void main(String[] args) {
        try{
            // Send the request as a Request Property with GET to the server.
            CGIGetClient getter = new CGIGetClient(
                "http://www.cs.ukc.ac.uk/people/staff/djb/cgi-bin/whoAmI.pl");
            if(args.length < 1)
                System.out.println(getter.getResponse());
            else
                System.out.println(getter.get("Env=" + URLEncoder.encode(args[0])));
        }
        catch(Exception e){
            System.err.println(e);
        }
    }
}


        // Use the GET method to send a string to a CGI script.
       // This involves setting a request property sent as part of
        // the resource retrieval.
class CGIGetClient extends CGIClient {
    CGIGetClient(String resource) throws Exception {
        super(resource);
    }

        // 
    public String get(String whatToSend) throws IOException {
        URLConnection connection = getConnection();
        // Send the query. The script will pick this up
        // as HTTP_QUERY_STRING.
        connection.setRequestProperty("QUERY_STRING",whatToSend);
        return getResponse();
    }
}

        // This class can be used raw if the URL already contains a
        // GET query.
        // Alternatively, it can be used as a superclass for GET and
        // POST clients by maintaining the URLConnection attribute for them,
        // and providing a getResponse method.
class CGIClient {
        // Set up the URL connection.
    public CGIClient(String resourceURL) throws MalformedURLException,
                                             IOException {
        URL url = new URL(resourceURL);
        connection = url.openConnection();
        // Indicate that we shall wish to read the script's response.
        connection.setDoInput(true);
    }

        // Get the response from the connection.
    public String getResponse() throws IOException {
        // Read back the response;
        BufferedReader reader = new BufferedReader(
                    new InputStreamReader(getConnection().getInputStream()));

        String response = "";
        String line = reader.readLine();
        while(line != null){
            response += line+"\n";
            line = reader.readLine();
        }
        reader.close();
        return response;
    }

    protected URLConnection getConnection(){
       return connection;
    }

    private final URLConnection connection;
}

