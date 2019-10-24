package com.example.finqrcode;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Bitmap;
import android.support.annotation.Nullable;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

import com.google.zxing.BarcodeFormat;
import com.google.zxing.MultiFormatWriter;
import com.google.zxing.common.BitMatrix;
import com.google.zxing.integration.android.IntentIntegrator;
import com.google.zxing.integration.android.IntentResult;
import com.journeyapps.barcodescanner.BarcodeEncoder;

public class MainActivity extends AppCompatActivity {

    private Button generate,scan;
    private EditText mytext;
    private ImageView qr_code;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        generate=findViewById(R.id.generate);
        scan=findViewById(R.id.scan);
        mytext=findViewById(R.id.text);
        qr_code=findViewById(R.id.qrcode);
        qr_code.setVisibility(View.GONE);

        generate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String text=mytext.getText().toString().trim();
                if(qr_code.getVisibility()!=View.VISIBLE) {
                    qr_code.setVisibility(View.VISIBLE);
                }

                if(text!=null){
                    try{
                        MultiFormatWriter multiformatwriter =new MultiFormatWriter();
                        BitMatrix bitmatrix =multiformatwriter.encode(text, BarcodeFormat.QR_CODE,300,300);
                        BarcodeEncoder barcodeEncoder=new BarcodeEncoder();
                        Bitmap bitmap=barcodeEncoder.createBitmap(bitmatrix);
                        qr_code.setImageBitmap(bitmap);
                    }
                    catch(Exception e){
                        e.printStackTrace();
                    }
                }
            }
        });

        scan.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                IntentIntegrator intentIntegrator=new IntentIntegrator(MainActivity.this);
                intentIntegrator.setDesiredBarcodeFormats(IntentIntegrator.QR_CODE_TYPES);
                intentIntegrator.setCameraId(0);
                intentIntegrator.setOrientationLocked(false);
                intentIntegrator.setPrompt("Scanning");
                intentIntegrator.setBeepEnabled(true);
                intentIntegrator.setBarcodeImageEnabled(true);
                intentIntegrator.initiateScan();
            }
        });

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {

        final IntentResult result=IntentIntegrator.parseActivityResult(requestCode,resultCode,data);
        if(result!=null && result.getContents()!=null){

            new AlertDialog.Builder(MainActivity.this)
                    .setTitle("Scanned Result")
                    .setMessage(result.getContents())
                    .setPositiveButton("Copy", new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            ClipboardManager manager= (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
                            ClipData data=ClipData.newPlainText("result",result.getContents());
                            manager.setPrimaryClip(data);
                        }
                    }).setNegativeButton("cancel", new DialogInterface.OnClickListener() {
                @Override
                public void onClick(DialogInterface dialog, int which) {
                    dialog.dismiss();
                }
            }).create().show();
        }

        super.onActivityResult(requestCode, resultCode, data);

    }
}
