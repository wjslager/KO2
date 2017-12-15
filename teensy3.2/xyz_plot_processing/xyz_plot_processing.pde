import processing.serial.*;

Serial teensySerial;
String portName;
String serialInput;
String[] xyzValues = {"-1", "0", "0", "0", "1"};
float halfPI = PI * 0.5;
int moveGain = 100;

void setup()
{
  size(500, 500, P3D);

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
  stroke(255);
}

void draw() 
{
  // Store new values if there are any
  if (teensySerial.available() > 0) {
    serialInput = teensySerial.readStringUntil('\n');
    xyzValues = split(serialInput, ' ');
    //println(xyzValues[1]+" "+xyzValues[2]+" "+xyzValues[3]);
  }

  // Draw the data
  background(0);

  pushMatrix();
  translate(width*0.5, height*0.5);
  //translate(float(xyzValues[1])*moveGain, float(xyzValues[2])*moveGain, float(xyzValues[3])*moveGain);
  rotateX(float(xyzValues[1])*halfPI);
  rotateY(float(xyzValues[2])*halfPI);
  rotateZ(float(xyzValues[3])*halfPI + halfPI);
  box(50, 10, 100);
  //box(10);
  popMatrix();
  
  println(frameRate);
}