void lightFX() {
  spotLight(50, pdAmpL*255, pdAmpL*255, width*0.1, height*0.5, 400, 0.4, 0, -1, PI, 1);            // Left spot
  spotLight(50, pdAmpR*255, pdAmpR*255, width*0.9, height*0.5, 400, -0.4, 0, -1, PI, 1);           // Right spot
  if (pdFM) spotLight(500 * (pdAmpL + pdAmpR), 0,0, width*0.5, height*0.5, 400, 0, 0, -1, PI, 1);  // Middle
}

void textOverlay() {

  txt.beginDraw();
  txt.background(0);
  txt.textSize(32);
  txt.textAlign(CENTER, CENTER);
  txt.text("FIETS", width*0.5, height*0.5);
  txt.endDraw();
  
  /*  
  image(txt, 0, 0);
  */
  pushMatrix();
  translate(width / 2, height / 2);
  beginShape();
  texture(txt);
  vertex(-100, -100, 300, 0,   0);
  vertex( 100, -100, 300, 400, 0);
  vertex( 100,  100, 300, 400, 400);
  vertex(-100,  100, 300, 0,   400);
  endShape();
  popMatrix();
}