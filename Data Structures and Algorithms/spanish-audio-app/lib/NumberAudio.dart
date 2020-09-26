import 'package:flutter/material.dart';

//helper class
class NumberAudio{
  String audioUri;
  MaterialColor buttonColor;
  String buttonText;

  NumberAudio(String aU, MaterialColor bC, String bT){
    this.audioUri = aU;
    this.buttonColor = bC;
    this.buttonText = bT;
  }
}