import processing.serial.*;

Serial teensySerial;
String portName;
String serialInput;
String[] xyzValues = {"-1", "0", "0", "0", "1"};
float halfPI = PI * 0.5;
int moveGain = 100;
float x = 0, y = 0, z = 0;

void setup()
{
  size(300, 300, P3D);

  // Start listening to serial communication
  try {
    portName = Serial.list()[0];
  } 
  catch (ArrayIndexOutOfBoundsException exception) {
    println("No serial port found");
    exit();
  } 
  teensySerial = new Serial(this, portName, 9600);

  noFill();
  strokeWeight(width*0.01);
}

void draw() 
{
  // Store new values if there are any
  if (teensySerial.available() > 0) {
    serialInput = teensySerial.readStringUntil('\n');
    xyzValues = split(serialInput, ' ');
    //println(xyzValues[1]+" "+xyzValues[2]+" "+xyzValues[3]);
    x = float(xyzValues[1]);
    y = float(xyzValues[2]);
    z = float(xyzValues[3]);
  }

  // Draw the data
  background(0);

  pushMatrix();
  ortho();
  translate(width*0.5, height*0.5);
  rotateX(PI/6);
  rotateY(PI/6);

  // X
  stroke(255, 0, 0);
  line(0, 0, 0, x*100, 0, 0);

  // Y
  stroke(0, 255, 0);
  line(0, 0, 0, 0, y*100, 0);

  // Z
  stroke(0, 0, 255);
  line(0, 0, 0, 0, 0, z*100);

  popMatrix();
}