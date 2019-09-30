package com.example.reckit.Helper;

import android.os.AsyncTask;

import java.net.InetSocketAddress;
import java.net.Socket;

public class InternetCheck extends AsyncTask<Void,Void,Boolean> {
    //protected static String server_Host = "google.com";
    //private static final int server_Port = 80 ;
    //private  static final int timeout = 1500;
    public interface Consumer{
        void accept(boolean internet);  //accept the internet conn
    }

    Consumer consumer;

    public InternetCheck(Consumer consumer) {
        this.consumer = consumer;
        execute();
    }

    @Override
    protected Boolean doInBackground(Void... voids) {
        try {
            Socket socket = new Socket();
            socket.connect(new InetSocketAddress("google.com",80),1500);
            socket.close();
            return true;
        }
        catch (Exception e) {
            return false;
        }
    }

    @Override
    protected void onPostExecute(Boolean aBoolean) {
        super.onPostExecute(aBoolean);
        consumer.accept(aBoolean);
    }
}


