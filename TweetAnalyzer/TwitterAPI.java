// import java.net.HttpURLConnection;
// import java.net.URL;

// public class TwitterAPI
// {
//     private static HttpURLConnection connection;
//     public static void main(String[] args)
//     {
//         try
//         {
//         //use java.net.HttpURLConnection API 
//         URL url = new URL("https://api.twitter.com/1.1/statuses/user_timeline.json");

//         // try to connect
//         connection = (HttpURLConnection)url.openConnection();
//         connection.setRequestMethod("GET");
//         //connection.setRequestProperty("user_id", "realDonaldTrump"); // set userId its a sample here
        
//         // timeout if it doesn't connect
//         connection.setConnectTimeout(5000);
//         connection.setReadTimeout(5000);
        
//         // check status of connection
//         int status = connection.getResponseCode();
//         System.out.println(status);

        
//         }
//         catch(Exception e)
//         {
//             e.printStackTrace();
//         }

//     }
// }
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.io.IOException;

public class TwitterAPI {

	private static HttpURLConnection connection;
	
	public static void main(String[] args) {
		BufferedReader reader;
		String line;
		StringBuffer responseContent = new StringBuffer();
		
		try {
			// Create connection
            // URL url = new URL("https://api.twitter.com/1.1/statuses/user_timeline.json?screen_name=realDonaldTrump");
            
            URL url = new URL("https://api.twitter.com/1.1/statuses/user_timeline.json");
		    connection = (HttpURLConnection) url.openConnection();
		    
		    connection.setRequestMethod("GET");
		    
		    connection.setConnectTimeout(5000);
		    connection.setReadTimeout(5000);
		    
		    int status = connection.getResponseCode();
		    
		    if(status > 299) {
		    	reader = new BufferedReader(new InputStreamReader(connection.getErrorStream()));
		    	while((line = reader.readLine()) != null)
		    		responseContent.append(line);
		    	reader.close();
		    }else {
		    	reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
		    	while((line = reader.readLine()) != null)
		    		responseContent.append(line);
		    	reader.close();
		    }
		    System.out.println(responseContent.toString());
		    
		}catch(IOException e) {
			e.printStackTrace();
		}
	}
}