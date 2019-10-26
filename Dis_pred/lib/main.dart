import 'package:flutter/material.dart';
import 'Sospage.dart' as SOS;
import 'login_start.dart' as Login;
void main() {
  runApp(new MaterialApp(
    title: 'Microsoft Project101',
    home : new MyTabs(),
    debugShowCheckedModeBanner : false,
    theme: ThemeData(
        primaryColorDark: Colors.blueAccent)
        )
        
        );
  }

class MyTabs extends StatefulWidget {
@override
MyTabsState createState() => new MyTabsState();
}

class MyTabsState extends State<MyTabs> with SingleTickerProviderStateMixin{
     TabController controller;
@override
void initState(){
super.initState();
controller  = new TabController(vsync:this,length: 2);

}
@override
void dispose(){
  controller.dispose();
  super.dispose();
}

 
  @override
  Widget build(BuildContext context) {
    return new Scaffold(
      appBar: new AppBar(
        title :new Text("Team Hexall v0301",
        style: new TextStyle(
          color:Colors.white,
        ),
        ),
        backgroundColor: Colors.redAccent[700],
        bottom: new TabBar(
          controller: controller,
          tabs: <Tab>[new Tab(text: "SOS"),
          new Tab(text:"Authority Portal"),
          
          ],
        
        ),
      ),
      body: new TabBarView(
        controller: controller,
        children:<Widget>[
          new SOS.Statefu(),
          new Login.MyApp(),
          //new pg3.Iconclass(),
        ]
      )
      );
  }

}
  