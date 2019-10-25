import 'package:flutter/material.dart';
import 'package:login_demo/auth_provider.dart';
import 'package:url_launcher/url_launcher.dart';
//import 'package:flutter_webview_plugin/flutter_webview_plugin.dart';

class HomePage extends StatelessWidget {

  HomePage({this.onSignedOut});
  
  final VoidCallback onSignedOut;
  
  void _signOut(BuildContext context) async {
    try {
      var auth = AuthProvider.of(context).auth;
      await auth.signOut();
      onSignedOut();
    } catch (e) {
      print(e);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
         body: new Center(
           child: new Column(
         mainAxisAlignment: MainAxisAlignment.spaceEvenly,
         children: <Widget>[
        new RaisedButton(
        onPressed: _launchURL,
        textColor: Colors.white,
          color: Colors.red,
          padding: const EdgeInsets.all(8.0),
          child: Text('Show Maps', style: TextStyle(fontSize: 20.0,
          color: Colors.white,
          ),
          ),
        ),
        new RaisedButton(
          onPressed: _launchURL1,
          textColor: Colors.white,
          color: Colors.blue,
          padding: const EdgeInsets.all(8.0),
          child: Text('Calculate Probablity ', style: TextStyle(fontSize: 20.0,
          color: Colors.white,
          ),
          ),
        ),
        FlatButton(
          child: Text('Logout',
          style: TextStyle(fontSize: 34.0, color: Colors.red)),
          onPressed: () => _signOut(context))
        ],
        ),
       ),
    );
  }
}

_launchURL() async {
  const url = 'https://www.rajatshenoy.com/hexall-disaster-helpline/maps/aftershock.html';
  if (await canLaunch(url)) {
    await launch(url);
  } else {
    throw 'Could not launch $url';
  }
}
_launchURL1() async{
  const url = 'https://teamhexall.azurewebsites.net';
  if (await canLaunch(url)) {
    await launch(url);
  } else {
    throw 'Could not launch $url';
  }
}