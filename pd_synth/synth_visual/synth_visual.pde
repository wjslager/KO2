import oscP5.*;
import netP5.*;

OscP5 oscP5;

int pdPitch, pdOctave;
float pdDelayMS = 899, pdDelayFB = 1;
float pdAmpL = 0, pdAmpR = 0;
boolean pdFM = false;
String oscSign;
Cube mainCube;
Cube[] cubes = new Cube[20];

void setup() {
  size(800, 800, P3D);
  //fullScreen(P3D);
  //frameRate(25);

  // Start listening to localhost:12000
  oscP5 = new OscP5(this, 12000);

  mainCube = new Cube(height*0.5, 0, -1);

  for (int i=0; i<cubes.length; i++) {
    cubes[i] = new Cube(height*0.3, 100, i);
  }
  for (int i=0; i<cubes.length; i++) { 
    cubes[i].shake();
  }
}


void draw() {
  background(0);

  lightFX();
  
  for (int i=0; i<cubes.length; i++) {
    cubes[i].display();
  }

  mainCube.display();
}