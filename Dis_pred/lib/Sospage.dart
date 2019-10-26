import 'package:flutter/material.dart';
import 'package:flutter/widgets.dart';
import 'package:flutter/services.dart';

import 'package:url_launcher/url_launcher.dart';

class Statefu extends StatefulWidget {
  @override
  StatefuState createState() => new StatefuState();
}

class StatefuState extends State<Statefu> {
   static const platform = const MethodChannel('sendSms');
   _textMe() async {
     // Android
     const uri = 'sms:+1 315 387 4357';
     if (await canLaunch(uri)) {
       await launch(uri);
     } else {

     }
   }

  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      /*appBar: new AppBar(
        title: new Text("StatefulWidget",
        style: new TextStyle(
          color:Colors.white,
        ),),
        backgroundColor: Colors.redAccent[700]),*/
      
      body: new Container(
        decoration: new BoxDecoration(
          gradient: new LinearGradient(
            begin: Alignment.topLeft,
            end: Alignment.bottomRight,
            stops: [1.0, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1],
            colors: [
              Colors.white,
              Colors.black87,
              Colors.black54,
              Colors.black45,
              Colors.black38,
              Colors.black26,
              Colors.black12
            ],
          ),
        ),
        child: new Opacity(
          opacity: 1.0,
          child: new Center(
            child: new Column(
              children: <Widget>[
                new Expanded(
                  child: new Align(
                    alignment: FractionalOffset.center,
                    child: new RaisedButton(
                      child: new Text(
                        "SOS",
                        style: new TextStyle(fontSize: 100.0,color: Colors.white),
                      ),
                      color: Colors.redAccent[700],
                      elevation: 4.0,
                      splashColor: Colors.blue,
                      onPressed: () => _textMe()//, child: const Text("Send SMS"),
                                              

                    ),
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
