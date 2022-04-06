// Event Horizon Starter
// Zane Cochran
// 27 March 2022

boolean isBroadcast = false;       // Toggles Visualization On/Off
String ipAddress = "10.40.4.115";  // Event Horizon IP Address

void setup() {
  size(480, 480);
  initBroadcast();
  initAudio();
}

void draw() {
  background(0);
  getLoud();
  //getWave();

  //colorMode(HSB, 255);
  //fill(25,255,255);
  //ellipse(width/2, height/2, soundSize, soundSize);

  display();

  if (isBroadcast) {
    broadcast();
  }
}

void display() {
  int rectW = 15;
  int centerX = width/2;
  float farOutFill = map(soundSize, sizeMin, sizeMax, 0, 75);
  float outsideFill = map(soundSize, sizeMin, sizeMax, 15, 125);
  float insideFill = map(soundSize, sizeMin, sizeMax, 30, 200);
  float centerFill = map(soundSize, sizeMin, sizeMax, 45, 275);
  rectMode(RADIUS);

  colorMode(HSB, 255);
  //FAR OUT LEFT RECT
  fill(farOutFill, 255, 255);
  rect(centerX - width/7*3, height/2, rectW, soundSize/3 );
  //FAR LEFT RECT
  fill(outsideFill, 255, 255);
  rect(centerX - width/7*2, height/2, rectW, soundSize/2 );
  //MIDDLE LEFT RECT
  fill(insideFill, 255, 255);
  rect(centerX - width/7, height/2, rectW, soundSize/1.5 );
  //CENTER RECT
  fill(centerFill, 255, 255);
  rect(centerX, height/2, rectW, soundSize );  
  //RIGHT RECT
  fill(insideFill, 255, 255);
  rect(centerX + width/7, height/2, rectW, soundSize/1.5 );
  //FAR RIGHT RECT
  fill(outsideFill, 255, 255);
  rect(centerX + width/7*2, height/2, rectW, soundSize/2 );
  //FAR OUT RIGHT RECT
  fill(farOutFill, 255, 255);
  rect(centerX + width/7*3, height/2, rectW, soundSize/2 );
}
