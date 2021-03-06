import oscP5.*;
import netP5.*;

OscP5 oscP5;

int pitch, octave;
float delayMS, delayFB;
String oscAddrPat;

void setup() {
  size(800, 800);
  frameRate(25);
  // Start listening to localhost:12000
  oscP5 = new OscP5(this, 12000);

  //textAlign(CENTER);
  textSize(width*0.1);
}


void draw() {
  background(0);

  text("Pitch: "+pitch, width*0.05, height*0.1);
  text("Octave: "+octave, width*0.05, height*0.2);
  text("ms: "+delayMS, width*0.05, height*0.3);
  text("fb: "+delayFB, width*0.05, height*0.4);
}

void oscEvent(OscMessage theOscMessage) {
  // Retreive the address
  oscAddrPat = theOscMessage.addrPattern(); 
  print(oscAddrPat+" ");

  // Execute certain actions based on addres
  if (oscAddrPat.equals("/pitch")) {
    pitch = theOscMessage.get(0).intValue();
    octave = theOscMessage.get(1).intValue();
    println(pitch+" "+octave);
  }
  else if (oscAddrPat.equals("/delay")) {
    delayMS = theOscMessage.get(0).floatValue();
    delayFB = theOscMessage.get(1).floatValue();
    println(pitch+" "+octave);
  }
}