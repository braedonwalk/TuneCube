int curVal0;
int curVal1;
int curVal2;
int curVal3;
int pastVal0;
int pastVal1;
int pastVal2;
int pastVal3;
int potThresh = 35;

// Check Pots
void checkPots() {
  curVal0 = analogRead(potPins[0]);
  curVal1 = analogRead(potPins[1]);
  curVal2 = analogRead(potPins[2]);
  curVal3 = analogRead(potPins[3]);

  if ((abs(curVal0 - pastVal0) > potThresh)) {
    pastVal0 = curVal0;
    int mappedPot0 = map(curVal0, 0, 1027, 0, 127);
    controlChange(0, 25, mappedPot0);
    Serial.print("Slider: "); Serial.println(mappedPot0);
  }
  if ((abs(curVal1 - pastVal1) > potThresh)) {
    pastVal1 = curVal1;
    int mappedPot1 = map(pastVal1, 0, 1027, 127, 0);
    controlChange(0, 22, mappedPot1);
    Serial.print("Pot 1: "); Serial.println(mappedPot1);
  }
  if ((abs(curVal2 - pastVal2) > potThresh)) {
    pastVal2 = curVal2;
    int mappedPot2 = map(pastVal2, 0, 1027, 127, 0);
    controlChange(0, 23, mappedPot2);
    Serial.print("Pot 2: "); Serial.println(mappedPot2);
  }
  if ((abs(curVal3 - pastVal3) > potThresh)) {
    pastVal3 = curVal3;
    int mappedPot3 = map(pastVal3, 0, 1027, 127, 0);
    controlChange(0, 24, mappedPot3);
    Serial.print("Pot 3: "); Serial.println(mappedPot3);
  }
}
