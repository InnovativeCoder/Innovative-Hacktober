import 'dart:async';

import 'package:flutter/material.dart';
import 'package:login_demo/home_page.dart';
import 'package:login_demo/login_page.dart';
import 'package:login_demo/auth_provider.dart';

class RootPage extends StatefulWidget {

  @override
  State<StatefulWidget> createState() => _RootPageState();
}

enum AuthStatus {
  notDetermined,
  notSignedIn,
  signedIn,
}


class _RootPageState extends State<RootPage> {
  Timer _timer;
  AuthStatus authStatus = AuthStatus.notDetermined;

  @override
  void didChangeDependencies() {
    super.didChangeDependencies();
    var auth = AuthProvider.of(context).auth;
    auth.currentUser().then((userId) {
      _timer = new Timer(const Duration(milliseconds: 400), () {
      setState(() {
        authStatus =
            userId == null ? AuthStatus.notSignedIn : AuthStatus.signedIn;
      });
    }
      );
    }
    );
  }

  void _signedIn() {
    _timer = new Timer(const Duration(milliseconds: 40), () {
    setState(() {
      authStatus = AuthStatus.signedIn;
    });
    });
  }

  void _signedOut() {
    _timer = new Timer(const Duration(milliseconds: 40), () {
    setState(() {
      authStatus = AuthStatus.notSignedIn;
    });
    });
  }

  @override
  Widget build(BuildContext context) {
    switch (authStatus) {
      case AuthStatus.notDetermined:
        return new Center(
        child: new CircularProgressIndicator(),
      );
      case AuthStatus.notSignedIn:
        return LoginPage(
          message: "Refreshed",
          onSignedIn: _signedIn,
        );
      case AuthStatus.signedIn:
       
       return HomePage(
       onSignedOut: _signedOut,
        );
    }
    return null;
  }
      
}
  