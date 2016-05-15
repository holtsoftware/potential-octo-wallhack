import java.io.*;
import java.net.*;

        // Use the GET method to send a string to a CGI script.
        // This involves setting a request property sent as part of
        // the resource retrieval.
public class CGIGetClient extends CGIClient {
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
