import java.net.*;
import java.io.*;

        // This class can be used raw if the URL already contains a
        // GET query.
        // Alternatively, it can be used as a superclass for GET and
        // POST clients by maintaining the URLConnection attribute for them,
        // and providing a getResponse method.
public class CGIClient {
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

