class Cube {
  int x, y, z;
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

  void display(float cubeGain) {
    pushMatrix();

    // Move
    translate(x + (width*0.5), y + (height*0.5), z);

    // Rotate
    rotateX(0.1);
    rotateZ(index * 0.1);
    rotateY(yRotate);
    yRotate += (delayMS * -0.0005) + 0.46;

    // Draw

    if (index >= 0) {
      noStroke();
      fill(c);
    } else {
      noFill();
      strokeWeight(2);
      stroke(c);
    }
    box(size);

    popMatrix();
  }

  void shake() {
    x = int(random(rand) - (rand * 0.5));
    y = int(random(rand) - (rand * 0.5));
    z = int(random(rand) - (rand * 0.5));
    if (index >= 0) {
      // Array cubes
      c = color(random(100), random(255), 255, 150);
    } else {
      // The main cube
      c = color(random(100), random(255), 255, 255);
    };
  }
}