import javax.net.ssl.HttpsURLConnection;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.net.URL;
import java.nio.channels.ReadableByteChannel;

public class Downloader implements Runnable {

    private String url;
    private int num;
    private long start;
    private long end;
    ReadableByteChannel rbc;
    private static final int BUFFER_SIZE = 4096;

    public Downloader(String url, int num, long start, long end, ReadableByteChannel rbc) {
        this.url = url;
        this.num = num;
        this.start = start;
        this.end = end;
        this.rbc = rbc;
    }

    @Override
    public void run() {
        download();
    }

    private void download(){
        try {
            System.out.println(num + " is executing with range "+start+"-"+end);
            URL file = new URL(url);
            HttpsURLConnection urlConnection = (HttpsURLConnection) file.openConnection();
            urlConnection.setRequestProperty("Range", "bytes=" + start + "-" + end);
            urlConnection.connect();
            System.out.println("Response Code: " + urlConnection.getResponseCode());
            InputStream inputStream = urlConnection.getInputStream();
            FileOutputStream stream = new FileOutputStream("tmp_"+num);
            int bytesRead = -1;
            byte[] buffer = new byte[BUFFER_SIZE];
            while ((bytesRead = inputStream.read(buffer)) != -1) {
                stream.write(buffer, 0, bytesRead);
            }
            stream.close();
            inputStream.close();
            System.out.println("Finished "+num);
        } catch (Exception e) {
            System.out.println("Error: "+e.getMessage());
        }
    }
}