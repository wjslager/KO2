import processing.serial.*;

// Serial communication
Serial teensySerial;
String portName;
String serialInput;
String[] xyzValues = {"-1", "0", "0", "0", "1"};

float x = 0, y = 0, z = 0;


// ==== ==== ==== Setup ==== ==== ==== //

void setup()
{
  size(600, 600, P3D);

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
}

// ==== ==== ==== Draw ==== ==== ==== //

void draw() 
{
  background(0);
  getSerialValues();

  // Drawing
  pushMatrix();
  isometricFov();
  plotAxes();
  plotSerial();
  popMatrix();
}

// ==== ==== ==== Serial ==== ==== ==== //

void getSerialValues() 
{
  // Store new values if there are any
  if (teensySerial.available() > 0) {
    serialInput = teensySerial.readStringUntil('\n');
    xyzValues = split(serialInput, ' ');
    x = float(xyzValues[1]);
    y = float(xyzValues[2]);
    z = float(xyzValues[3]);
  }
}

// ==== ==== ==== Plotting ==== ==== ==== //

void isometricFov() 
{
  ortho();
  translate(width*0.5, height*0.5);
  rotateX(PI/6);
  rotateY(PI/6);
}

void plotAxes() 
{
  strokeWeight(1);
  stroke(100);
  line(-width, 0, -1, width, 0, -1);
  line(0, -height, -1, 0, height, -1);
  line(0, -1, -height, 0, -1, height);
}

void plotSerial() 
{
  // Plot the received values
  strokeWeight(width*0.02);

  stroke(255, 0, 0); // X, Red
  line(0, 0, 0, x*100, 0, 0);

  stroke(0, 255, 0); // Y, Green
  line(0, 0, 0, 0, y*100, 0);

  stroke(0, 0, 255); // Z, Blue
  line(0, 0, 0, 0, 0, z*100);
}