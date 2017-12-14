class Cube {
  int cX, cY, cZ;
  float cR, cG, cB;
  float cYRotate;
  float cRotateInc;
  float cSize;
  float cRand;
  int cIndex;

  // ==== ==== ===== C O N S T R U C T O R ==== ==== ==== //

  Cube(float sizeArg, float randArg, int indexArg) {
    cX = 0; 
    cY = 0; 
    cZ = 0;
    cYRotate = 0;
    cRotateInc = 0.01;
    cSize = sizeArg;
    cRand = randArg;
    cIndex = indexArg;
  }
  
  // ==== ==== ===== D I S P L A Y ==== ==== ==== //

  void display() {
    pushMatrix();

    // Move
    translate(cX + (width*0.5), cY + (height*0.5), cZ);

    // Rotate
    rotateZ(cIndex * 0.1);                          // Turns each cube slightly to separate all cubes
    rotateY(cYRotate);
    rotateX(pdDelayMS * 0.001);                    // Rotate based on the delay time
    cYRotate += (pdAmpL * 0.02) + (pdAmpR * 0.02);  // Rotating increment based on amplitude

    // Color the box based on it's type
    if (cIndex >= 0) {                              // Array cubes
      stroke(cR, cG, cB, 50);                        // Delay feedback -> stroke brightness
      strokeWeight(1);
      fill(cR, cG, cB, 150);
    } else {                                       // Main cube
      noFill();
      strokeWeight(10 * pdAmpL * pdAmpR);          // Amplitude -> Strokeweight
      stroke(cR, cG, cB, 255);
    }
    
    // Draw
    box(cSize);

    popMatrix();
  }

  // ==== ==== ===== S H A K E ==== ==== ==== //
  
  void shake() {
    cR = random(100);
    cG = random(255);
    cB = 255; 
    cX = int(random(cRand) - (cRand * 0.5));
    cY = int(random(cRand) - (cRand * 0.5));
    cZ = int(random(cRand) - (cRand * 0.5));
  }
}