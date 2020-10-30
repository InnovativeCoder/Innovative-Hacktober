import sun.net.www.protocol.http.HttpURLConnection;

import java.io.File;
import java.io.FileOutputStream;
import java.net.URL;
import java.net.URLConnection;
import java.nio.channels.Channels;
import java.nio.channels.ReadableByteChannel;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

public class DManager {
    private String url,fileName;

    public DManager(String url, String fileName) {
        this.url = url;
        this.fileName = fileName;
    }

    // Download Manager Function..
    public void execute() {
        try {
            if(url!=null && fileName!=null) {
                int size=getFileSize(url);
                System.out.println("File Size: "+size+" bytes");
                int start,end;
                String parts=PartitionAlgo.execute(size,6);
                String[] ranges=parts.split(";");
                URL file;
                ReadableByteChannel rbc;
                file = new URL(url);
                rbc = Channels.newChannel(file.openStream());
                ExecutorService pool = Executors.newFixedThreadPool(ranges.length);
                for(int i=0; i<ranges.length; i++) {
                    start = Integer.valueOf(ranges[i].split(":")[0]);
                    end = Integer.valueOf(ranges[i].split(":")[1]);
                    pool.submit(new Downloader(url, i, start, end, rbc));
                }
                pool.shutdown();
                pool.awaitTermination(Long.MAX_VALUE, TimeUnit.MILLISECONDS);
                System.out.println("All Parts Downloaded!");
                System.out.println("Combining All Parts!");
                List<byte[]> bytesList = new ArrayList<>();
                for (int i = 0; i <= ranges.length; i++) {
                    File tmpFile = new File("tmp_" + i);
                    if (tmpFile.exists()) {
                        byte[] fileContent = Files.readAllBytes(tmpFile.toPath());
                        bytesList.add(fileContent);
                        tmpFile.delete();
                    }
                }
                FileOutputStream fos = new FileOutputStream(fileName);
                for (byte[] data: bytesList) {
                    fos.write(data);
                }
                System.out.println("File Downloaded Successfully!");
            }
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
        }
    }

    //Function to get bytes of file...
    private int getFileSize(String link) {
        URLConnection conn = null;
        try {
            URL url=new URL(link);
            conn = url.openConnection();
            if(conn instanceof HttpURLConnection) {
                ((HttpURLConnection)conn).setRequestMethod("HEAD");
            }
            conn.getInputStream();
            return conn.getContentLength();
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            if(conn instanceof HttpURLConnection) {
                ((HttpURLConnection)conn).disconnect();
            }
        }
    }
}
