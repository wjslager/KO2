import oscP5.*;
import netP5.*;

OscP5 oscP5;

int pitch, octave;
float delayMS = 899, delayFB = 1;
float hz;
String oscAddrPat;
Cube mainCube;
Cube[] cubes = new Cube[10];

void setup() {
  size(800, 800, P3D);
  frameRate(25);

  // Start listening to localhost:12000
  oscP5 = new OscP5(this, 12000);

  mainCube = new Cube(350, 0, -1);

  for (int i=0; i<cubes.length; i++) {
    cubes[i] = new Cube(300, 100, i);
  }
  for (int i=0; i<cubes.length; i++) { 
    cubes[i].shake();
  }
}


void draw() {
  background(0);

  lightFX();

  for (int i=0; i<cubes.length; i++) {
    cubes[i].display(delayFB);
  }

  mainCube.display(1);
}

void lightFX() {
  //lights();
  spotLight(50, delayFB*255, delayFB*255, width*0.5, height*0.5, 400, 0, 0, -1, PI, 1);
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
  } else if (oscAddrPat.equals("/delay")) {
    delayMS = theOscMessage.get(0).floatValue();
    delayFB = theOscMessage.get(1).floatValue();
    println(delayMS+" "+delayFB);
  } else if (oscAddrPat.equals("/shake")) {
    for (int i=0; i<cubes.length; i++) { 
      cubes[i].shake();
    }
    mainCube.shake();
    println("");
  }
}