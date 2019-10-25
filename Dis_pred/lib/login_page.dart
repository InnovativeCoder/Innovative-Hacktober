import 'package:flutter/material.dart';
import 'package:fluttertoast/fluttertoast.dart';
import 'package:login_demo/auth_provider.dart';



class EmailFieldValidator {
  static String validate(String value) {
    return value.isEmpty ? 'Email can\'t be empty' : null;
  }
}

class PasswordFieldValidator {
  static String validate(String value) {
    return value.isEmpty ? 'Password can\'t be empty' : null;
  }
}

class LoginPage extends StatefulWidget {
  final String message;

  LoginPage({this.message,this.onSignedIn});
  final VoidCallback onSignedIn;

  @override
  State<StatefulWidget> createState() => _LoginPageState();

}


enum FormType {
  login,
  register,
}

class _LoginPageState extends State<LoginPage> {
  @override
  initState() {
    super.initState();

  }
  
  final formKey = GlobalKey<FormState>();

  String _email;
  String _password;
  FormType _formType = FormType.login;

  bool validateAndSave() {
    final form = formKey.currentState;
    if (form.validate()) {
      form.save();
      return true;
    }
    return false;
  }
  String msg;
  void showColoredToast(msg) {
    Fluttertoast.showToast(
        msg: msg,
        toastLength: Toast.LENGTH_LONG,
        bgcolor: "#e74c3c",
        textcolor: '#ffffff'
    );
  }
  void validateAndSubmit() async {
    if (validateAndSave()) {
      try {
        var auth = AuthProvider.of(context).auth;
        if (_formType == FormType.login) {
          String userId =
              await auth.signInWithEmailAndPassword(_email, _password);
          print('Signed in: $userId');
        } else {
          String userId = await auth
              .createUserWithEmailAndPassword(_email, _password);
          print('Registered user: $userId');
        }
        widget.onSignedIn();
      } catch (StorageException) {
        
        showColoredToast(StorageException.toString());
      }
    }
  }

  void moveToRegister() {
    formKey.currentState.reset();
    setState(() {
      _formType = FormType.register;
    });
  }

  void moveToLogin() {
    formKey.currentState.reset();
    setState(() {
      _formType = FormType.login;
    });
  }
  
  @override
  Widget build(BuildContext context) {
    return Scaffold(
        /*appBar: AppBar(
          title: Text('Flutter login demo'),
        ),*/
        body: 
        new SingleChildScrollView(
        child : new Container(
            padding: EdgeInsets.all(16.0),
            child: Form(
              key: formKey,
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: buildInputs() + buildSubmitButtons(),
              ),
            ),
            ),
        ),
            resizeToAvoidBottomPadding: false,);
  }

  List<Widget> buildInputs() {
    return [
      
      TextFormField(
        key: Key('email'),
        decoration: InputDecoration(labelText: 'Email',
        labelStyle: TextStyle(
          color: Colors.red
        )
        ),
        validator: EmailFieldValidator.validate,
        onSaved: (value) => _email = value,
      ),
      TextFormField(
        key: Key('password'),
        decoration: InputDecoration(labelText: 'Password',
        labelStyle: TextStyle(
          color:Colors.red,
        ),
        ),
        obscureText: true,
        validator: PasswordFieldValidator.validate,
        onSaved: (value) => _password = value,
      ),
    ];
  }

  List<Widget> buildSubmitButtons() {
    if (_formType == FormType.login) {
      return [
        RaisedButton(
          key: Key('signIn'),
          textColor: Colors.white,
          color: Colors.red,
          padding: const EdgeInsets.all(8.0),
          child: Text('Login', style: TextStyle(fontSize: 20.0,
          color: Colors.white,
          ),
          ),
          onPressed: validateAndSubmit,
        ),
        FlatButton(
          child: Text('Create an account',
              style: TextStyle(fontSize: 20.0,
              color:Colors.red),
              ),
          onPressed: moveToRegister,
        ),
      ];
    } else {
      return [
        RaisedButton(
          child: Text('Create an account',
              style: TextStyle(fontSize: 20.0
              ,color:Colors.white,
              ),
              ),
          onPressed: validateAndSubmit,
          color: Colors.red,
        ),
        FlatButton(
          child: Text('Have an account? Login',
              style: TextStyle(fontSize: 20.0,
              color: Colors.red)),
          onPressed: moveToLogin,
        ),
      ];
    }
  }
}

