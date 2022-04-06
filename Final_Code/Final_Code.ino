// MIXI Test
// Zane Cochran
// Set Up Arduino IDE for Arduino Pro Mini: https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide
// Install MIDIUSB Library

// Buttons
#include <Bounce2.h>
int numButtons = 8;
int buttonPins[8] = {2, 3, 4, 5, 6, 7, 8, 9};
Bounce * buttons = new Bounce[8];
boolean buttonStates1[8] = {false, false, false, false, false, false, false, false};
boolean buttonStates2[8] = {false, false, false, false, false, false, false, false};
boolean buttonStates3[8] = {false, false, false, false, false, false, false, false};
boolean buttonStates4[8] = {false, false, false, false, false, false, false, false};

// Potentiometers
int numPots = 4;
int potPins[4] = {0, 1, 2, 3};
int potStates[4] = {0, 0, 0, 0};

// LEDs
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 10, NEO_RGB + NEO_KHZ800);
int numLED = 8;

uint32_t red = strip.Color(255, 0, 0);
uint32_t lightRed = strip.Color(255, 50, 100);
uint32_t orange = strip.Color(255, 100, 0);
uint32_t yellow = strip.Color(220, 220, 0);
uint32_t lightYellow = strip.Color(220, 220, 50);
uint32_t green = strip.Color(0, 220, 0);
uint32_t lightGreen = strip.Color(0, 255, 50);
uint32_t blue = strip.Color(0, 0, 255);
uint32_t lightBlue = strip.Color(100, 100, 255);
uint32_t purple = strip.Color(100, 0, 255);
uint32_t lightPurple = strip.Color(200, 200, 220);

// MIDI
#include "MIDIUSB.h"

// Switch Case
int mode = 0;           //DEFAULT IS 0
int buttonMode = 1;
int ledMode = 0;        //DEFAULT IS 0

void setup() {
  Serial.begin(9600);
  initButtons();
  initLED();
}

void loop() {
  switch (mode) {
    case 0: //startup sequence
      startUp();
      break;
    case 1: //base code happens
      checkButtons();
      buttonModes();
      showLEDs();
      break;
  }

  checkPots();
  showLEDs();
  strip.show();
}

//STARTUP
int brightness = 0;
int startUpStart = 0;
int startUpInterval = 250;
int startUpMode = 0;

int redLED = -1;
int orangeLED = -2;
int yellowLED = -3;
int greenLED = -4;
int blueLED = -5;
int nextMode = -10;

void startUp() {
  //BOTTOM ROW PURPLE
  for (int i = 4; i < numLED; i++) {
    strip.setPixelColor(i, purple);
  }
  if (millis() - startUpStart >= startUpInterval) {
    if (redLED < 3) {
      redLED++;
    }
    if (orangeLED < 3) {
      orangeLED++;
    }
    if (yellowLED < 3) {
      yellowLED++;
    }
    if (greenLED < 3) {
      greenLED++;
    }
    if (blueLED < 3) {
      blueLED++;
    }
    nextMode++;

    strip.setPixelColor(redLED, red);
    strip.setPixelColor(orangeLED, orange);
    strip.setPixelColor(yellowLED, yellow);
    strip.setPixelColor(greenLED, green);
    strip.setPixelColor(blueLED, blue);

    startUpStart = millis();
  }

  if (nextMode >= 0) {
    Serial.println("here");
    delay(1000);
    for (int i = 0; i < 4; i++) {
      strip.setPixelColor(i, purple);
      strip.setPixelColor(i - 1, blue);
      strip.show();
      delay(250);
    }
    strip.setPixelColor(3, blue);
    strip.show();
    delay(1000);
    strip.clear();
    strip.show();
    delay(1000);
    mode++;
    ledMode++;
  }
}
