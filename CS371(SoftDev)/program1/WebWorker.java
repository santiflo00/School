/**
* Web worker: an object of this class executes in its own new thread
* to receive and respond to a single HTTP request. After the constructor
* the object executes on its "run" method, and leaves when it is done.
*
* One WebWorker object is only responsible for one client connection. 
* This code uses Java threads to parallelize the handling of clients:
* each WebWorker runs in its own thread. This means that you can essentially
* just think about what is happening on one client at a time, ignoring 
* the fact that the entirety of the webserver execution might be handling
* other clients, too. 
*
* This WebWorker class (i.e., an object of this class) is where all the
* client interaction is done. The "run()" method is the beginning -- think
* of it as the "main()" for a client interaction. It does three things in
* a row, invoking three methods in this class: it reads the incoming HTTP
* request; it writes out an HTTP header to begin its response, and then it
* writes out some HTML content for the response content. HTTP requests and
* responses are just lines of text (in a very particular format). 
*
**/

import java.net.Socket;
import java.lang.Runnable;
import java.io.*;
import java.util.Date;
import java.text.DateFormat;
import java.util.TimeZone;
import java.lang.String;

public class WebWorker implements Runnable
{

private Socket socket;
private String url;       //get from http request
private String file; //parsed file
private String filetype; //pares file to find the type of file
private boolean status = true; //test server status
private boolean image; //boolean to see if it is an image or not
private String contentType; //default content type will change depending on filetype
/**
* Constructor: must have a valid open socket
**/
public WebWorker(Socket s)
{
   socket = s;
}

/**
* Worker thread starting point. Each worker handles just one HTTP 
* request and then returns, which destroys the thread. This method
* assumes that whoever created the worker created it with a valid
* open socket object.
**/
public void run()
{
   System.err.println("Handling connection...");
   try {
      InputStream  is = socket.getInputStream();
      OutputStream os = socket.getOutputStream();
      readHTTPRequest(is);
   
   //if the filetype is not html chage content to an image else keep as as text
   if( !(filetype.equals("html")) ){contentType = "image/"+filetype; image = true;}
   else{contentType = "text/html"; image = false;}

      writeHTTPHeader(os,contentType);
      writeContent(os);
      os.flush();
      socket.close();
   } catch (Exception e) {
      System.err.println("Output error: "+e);
   }
   System.err.println("Done handling connection.");
   return;
}

/**
* Read the HTTP request header.
**/
private void readHTTPRequest(InputStream is)
{  
   boolean first = false;
   String line;
   BufferedReader r = new BufferedReader(new InputStreamReader(is));
   while (true) {
      try {
         while (!r.ready()) Thread.sleep(1);
         line = r.readLine();

	 if(first == false){
		url = line;
   		String[] f = url.split(" ");
   		file = f[1];//remove spaces
   		String[] a = file.split("/");
		file = a[1];
		filetype = file.substring( (file.indexOf(".")+1), (file.length()) );//get the file type 
		first = true; 
	 }//if

         System.err.println("Request line: ("+line+")");
         if (line.length()==0) break;
      } catch (Exception e) {
         System.err.println("Request error: "+e);
         break;
      }
   }
   return;
}

/**
* Write the HTTP header lines to the client network connection.
* @param os is the OutputStream object to write to
* @param contentType is the string MIME content type (e.g. "text/html")
**/
private void writeHTTPHeader(OutputStream os, String contentType) throws Exception
{
   //try and find file in current directory else 404 error
	boolean found = true;
try{
	String line = "";
	FileReader fr = new FileReader( file );
	BufferedReader br = new BufferedReader(fr);
	line = br.readLine();
	}
	catch(FileNotFoundException ex) {//file not found
        status = false;
        os.write("404 Not Found\n".getBytes());
	found = false;
	}// of catch

if(found){
   Date d = new Date();
   DateFormat df = DateFormat.getDateTimeInstance();
   df.setTimeZone(TimeZone.getTimeZone("GMT"));
   os.write("HTTP/1.1 200 OK\n".getBytes());
   os.write("Date: ".getBytes());
   os.write((df.format(d)).getBytes());
   os.write("\n".getBytes());
   os.write("Server: Jon's very own server\n".getBytes());
   //os.write("Last-Modified: Wed, 08 Jan 2003 23:11:55 GMT\n".getBytes());
   //os.write("Content-Length: 438\n".getBytes()); 
   os.write("Connection: close\n".getBytes());
   os.write("Content-Type: ".getBytes());
   os.write(contentType.getBytes());
   os.write("\n\n".getBytes()); // HTTP header ends with 2 newlines
}//if
   return;
}

/**
* Write the data content to the client network connection. This MUST
* be done after the HTTP header has been written out.
* @param os is the OutputStream object to write to
**/
private void writeContent(OutputStream os) throws Exception
{  
if(status){//only read file if it has been found else 404
   Date d = new Date();
   DateFormat df = DateFormat.getDateTimeInstance();
   df.setTimeZone(TimeZone.getTimeZone("GMT"));
  System.err.println(filetype);
  System.err.println(image);
  if(image) {   
        System.err.println("IS an image file");
	int b; 
	File f = new File(file);
	FileInputStream fis = new FileInputStream(file);
	BufferedInputStream bis = new BufferedInputStream(fis);
	byte[] fileData = new byte[10000];

	while((b = bis.read(fileData)) != -1) {
		os.write(fileData, 0, b);
	}
	bis.close();
  }//if it is an image

  else{
   //read file and write it back to the client network
   try{
	String line = "";
	FileReader fr = new FileReader( file );
	BufferedReader br = new BufferedReader(fr);
  
	while((line = br.readLine()) != null){
        	if(line == "{{cs371date}}"){os.write( (df.format(d)+"\n").getBytes());}
        	else if(line == "{{cs371server}}") {os.write("Santi's Server id\n".getBytes());}
        	else
            		os.write(line.getBytes());
	}//while

      }//try
	catch(FileNotFoundException ex) {
		System.err.println("Unable to open file '" + file + "' ");
		}// of catch
	catch(IOException ex) {
		System.err.println("Error reading file '" + file + "'");
	}// of catch
  }//of else
}//end of if status ok

else{

    os.write("<html><head></head><body>\n".getBytes());
    os.write("<h3>404 Not Found</h3>\n".getBytes());
    os.write("</body></html>\n".getBytes());

    }//of else

}

} // end class
