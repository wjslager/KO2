import oscP5.*;
import netP5.*;

// OSC
OscP5 oscP5;
String oscSign;

// Values retrieved from the puredata patch
//      name                  low    high
int     pdPitch;          // -12     12
int     pdOctave;         //  12     84 
float   pdDelayMS = 899;  //  10     899
float   pdDelayFB = 1;    //  0      1
float   pdAmpL = 0;       //  0      1
float   pdAmpR = 0;       //  0      1
boolean pdFM = false;     //  false  true

// Visual stuff
Cube mainCube;
Cube[] cubes = new Cube[20];

// Text stuff
PGraphics txt;

// ==== ==== ===== S E T U P ==== ==== ==== //

void setup() {
  //size(800, 800, P3D);
  fullScreen(P3D, 2);

  // Start listening to localhost:12000
  oscP5 = new OscP5(this, 12000);

  // Create the maincube
  mainCube = new Cube(height*0.5, 0, -1);
  
  // Create more cubes
  for (int i=0; i<cubes.length; i++) {
    cubes[i] = new Cube(height*0.3, 100, i);
  }
  
  // Initialize the main cubes
  for (int i=0; i<cubes.length; i++) { 
    cubes[i].shake();
  }
  
  // Text stuff
  txt = createGraphics(width, height);
}

// ==== ==== ===== D R A W ==== ==== ==== //

void draw() {
  background(0);
  lightFX();
    

  // Display all the cubes
  for (int i=0; i<cubes.length; i++) {
    cubes[i].display();
  }
  mainCube.display();
  
  //textOverlay();
}