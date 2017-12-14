void oscEvent(OscMessage theOscMessage) {
  // Retrieve the address
  oscSign = theOscMessage.addrPattern(); 

  // Execute certain actions based on addres
  if (oscSign.equals("/pitch")) {                // pitch
    pdPitch = theOscMessage.get(0).intValue();
    pdOctave = theOscMessage.get(1).intValue();
  } else if (oscSign.equals("/delay")) {         // delay
    pdDelayMS = theOscMessage.get(0).floatValue();
    pdDelayFB = theOscMessage.get(1).floatValue();
  } else if (oscSign.equals("/shake")) {         // shake trigger
    for (int i=0; i<cubes.length; i++) { 
      cubes[i].shake();
    }
    mainCube.shake();
  } else if (oscSign.equals("/amp")) {           // amp values
    pdAmpL = theOscMessage.get(0).floatValue() * 3;
    pdAmpR = theOscMessage.get(1).floatValue() * 3;
  } else if (oscSign.equals("/fmon")) {
    pdFM = true;
  } else if (oscSign.equals("/fmoff")) {
    pdFM = false;
  }
}