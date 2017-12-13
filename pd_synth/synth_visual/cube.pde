class Cube {
  int x, y, z;
  float r, g, b;
  float yRotate;
  float rotateInc;
  color c;
  float size, rand;
  int index;

  Cube(float sizeArg, float randArg, int indexArg) {
    x = 0; 
    y = 0; 
    z = 0;
    yRotate = 0;
    rotateInc = 0.01;
    c = color(random(100), random(100), 255, 150);
    size = sizeArg;
    rand = randArg;
    index = indexArg;
  }

  void display() {
    pushMatrix();

    // Move
    translate(x + (width*0.5), y + (height*0.5), z);

    // Rotate
    rotateZ(index * 0.1);                          // Turns each cube slightly to separate all cubes
    rotateY(yRotate);
    rotateX(pdDelayMS * 0.001);                    // Rotate based on the delay time
    yRotate += (pdAmpL * 0.02) + (pdAmpR * 0.02);  // Rotating increment based on amplitude

    // Color the box based on it's type
    if (index >= 0) {                              // Array cubes
      stroke(r, g, b, 50);                        // Delay feedback -> stroke brightness
      strokeWeight(1);
      fill(r, g, b, 150);
    } else {                                       // Main cube
      noFill();
      strokeWeight(10 * pdAmpL * pdAmpR);          // Amplitude -> Strokeweight
      stroke(r, g, b, 255);
    }
    
    // Draw
    box(size);

    popMatrix();
  }

  void shake() {
    r = random(100);
    g = random(255);
    b = 255; 
    x = int(random(rand) - (rand * 0.5));
    y = int(random(rand) - (rand * 0.5));
    z = int(random(rand) - (rand * 0.5));
  }
}