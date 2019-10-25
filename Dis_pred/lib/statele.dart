import 'package:flutter/material.dart';
  class Iconclass extends StatelessWidget{

    @override
      Widget build(BuildContext context) {
      return new Scaffold(
        /*appBar: new AppBar(title: new Text("Test1"),
      ),*/
       body: new Container(
         child: new Column(
           crossAxisAlignment: CrossAxisAlignment.stretch,
           children: <Widget>[
             new Flash(
               title: new Text("Hello you there",
               style: new TextStyle(
                 fontSize:36.0
               )
               ),
               icon: new Icon(Icons.extension,size: 70.0,color:Colors.greenAccent)
             ),
             new Flash(
             title: new Text("IS"),
             icon: new Icon(Icons.explore,size: 70.0,color:Colors.redAccent)
             ),
             new Flash(
               title: new Text("Last check"),
               icon: new Icon(Icons.thumb_down,size: 70.0,color:Colors.yellowAccent)
             )
           ]
         )
       ) 
      );
      }
}
class Flash extends StatelessWidget{
  final Widget title;
  final Widget icon;
  Flash({this.title,this.icon});

  @override
  Widget build(BuildContext context) {
    return new Container(
      padding: new EdgeInsets.all(55.0),
        child: new Card(
          child:new Container(
            padding: new EdgeInsets.all(0.0),
          child: new Column(
            children: <Widget>[
              this.title,
              this.icon
            ]
          )
          ),
        )
    );
  }

}