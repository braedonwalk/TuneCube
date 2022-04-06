// LED Functions

void initLED() {
  strip.begin();
  strip.setBrightness(100);
  strip.clear();
  strip.show();
}

void showLEDs() {
  //MODE 1 - blue
  if (ledMode == 1) {
    //    Serial.println("blue");
    for (int i = 0; i < 5; i++) {
      if (buttonStates1[i] == 1) {
        strip.setPixelColor(i, lightBlue);
      } else {
        strip.setPixelColor(i, blue);
      }
    } strip.show();
    strip.setPixelColor(5, red);  //set pixel 4 to red
    strip.setPixelColor(6, yellow);  //set pixel 5 to yellow
    strip.setPixelColor(7, green);  //set pixel 6 to green
  }
  //MODE 2 - RED
  else if (ledMode == 2) {
    for (int i = 0; i < 5; i++) {
      if (buttonStates2[i] == 1) {
        strip.setPixelColor(i, lightRed);
      } else {
        strip.setPixelColor(i, red);
      }
    } strip.show();
    strip.setPixelColor(5, blue);  //set pixel 4 to blue
    strip.setPixelColor(6, yellow);  //set pixel 5 to yellow
    strip.setPixelColor(7, green);  //set pixel 6 to green
  }
  //MODE 3 - YELLOW
  else if (ledMode == 3) {
    for (int i = 0; i < 5; i++) {
      if (buttonStates3[i] == 1) {
        strip.setPixelColor(i, lightYellow);
      } else {
        strip.setPixelColor(i, yellow);
      }
    } strip.show();
    strip.setPixelColor(5, blue);  //set pixel 4 to blue
    strip.setPixelColor(6, red);  //set pixel 5 to red
    strip.setPixelColor(7, green);  //set pixel 6 to green
  }
  //MODE 4 - GREEN
  else if (ledMode == 4) {
    for (int i = 0; i < 5; i++) {
      if (buttonStates4[i] == 1) {
        strip.setPixelColor(i, lightGreen);
      } else {
        strip.setPixelColor(i, green);
      }
    } strip.show();
    strip.setPixelColor(5, blue);  //set pixel 4 to blue
    strip.setPixelColor(6, red);  //set pixel 5 to red
    strip.setPixelColor(7, yellow);  //set pixel 6 to yellow
  }
}
