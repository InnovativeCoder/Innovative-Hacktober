package com.flutter.logindemo;
/*
import android.os.Bundle;

import io.flutter.app.FlutterActivity;
import io.flutter.plugins.GeneratedPluginRegistrant;

public class MainActivity extends FlutterActivity {
  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    GeneratedPluginRegistrant.registerWith(this);
  }
}
*/

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.util.Log;
import io.flutter.app.FlutterActivity;
import io.flutter.plugin.common.MethodCall;
import io.flutter.plugin.common.MethodChannel;
import io.flutter.plugins.GeneratedPluginRegistrant;


public class MainActivity extends FlutterActivity {
  private static final String CHANNEL = "sendSms";

  // private MethodChannel.Result callResult;

  @Override
  protected void onCreate(Bundle savedInstanceState) {
    super.onCreate(savedInstanceState);
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
      if (checkSelfPermission(
              Manifest.permission.SEND_SMS)
              != PackageManager.PERMISSION_GRANTED) {

        // Should we show an explanation?
        if (shouldShowRequestPermissionRationale(
                Manifest.permission.SEND_SMS)) {

          // Show an explanation to the user *asynchronously* -- don't block
          // this thread waiting for the user's response! After the user
          // sees the explanation, try again to request the permission.

        } else {

          // No explanation needed, we can request the permission.

          requestPermissions(
                  new String[]{Manifest.permission.SEND_SMS},
                  0);

          // MY_PERMISSIONS_REQUEST_SEND_SMS is an
          // app-defined int constant. The callback method gets the
          // result of the request.
        }
      }
    }
    GeneratedPluginRegistrant.registerWith(this);
    new MethodChannel(getFlutterView(), CHANNEL).setMethodCallHandler(
            new MethodChannel.MethodCallHandler() {
              @Override
              public void onMethodCall(MethodCall call, MethodChannel.Result result) {
                if (call.method.equals("send")) {
                  String num = call.argument("phone");
                  String msg = call.argument("msg");
                  sendSMS(num, msg, result);
                } else {
                  result.notImplemented();
                }
              }
            });
  }

  private void sendSMS(String phoneNo, String msg, MethodChannel.Result result) {
    try {
      SmsManager smsManager = SmsManager.getDefault();
      smsManager.sendTextMessage(phoneNo, null, msg, null, null);
      result.success("SMS Sent");
    } catch (Exception ex) {
      ex.printStackTrace();
      result.error("Err", "Sms Not Sent", "");
    }
  }


  @Override
  public void onRequestPermissionsResult(int requestCode,
                                         String permissions[], int[] grantResults) {
    switch (requestCode) {
      case 0: {
        // If request is cancelled, the result arrays are empty.
        if (grantResults.length > 0
                && grantResults[0] == PackageManager.PERMISSION_GRANTED) {

          // permission was granted, yay! Do the
          // contacts-related task you need to do.

        } else {

          // permission denied, boo! Disable the
          // functionality that depends on this permission.
        }
        return;
      }

      // other 'case' lines to check for other
      // permissions this app might request.
    }
  }
}