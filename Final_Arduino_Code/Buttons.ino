// Button/Potontiometer Functions

// Initialize Buttons
void initButtons() {
  for (int i = 0; i < numButtons; i++) {
    buttons[i].attach(buttonPins[i], INPUT);
    buttons[i].interval(50);
  }
}

// Check Buttons
void checkButtons() {
  for (int i = 0; i < numButtons; i++)  {
    buttons[i].update();
    if (buttons[i].rose() ) {               //if a button is pressed
      if (buttonMode == 1) {                    //if buttonMode is in Mode 1: melody
        buttonStates1[i] = !buttonStates1[i]; //change the state of that specific button in this state
      }
      else if (buttonMode == 2) {               //if buttonMode is in Mode 2: drums
        buttonStates2[i] = !buttonStates2[i];
      }
      else if (buttonMode == 3) {               //if buttonMode is in Mode 3: motives
        buttonStates3[i] = !buttonStates3[i];
      }
      else if (buttonMode == 4) {               //if buttonMode is in Mode 4: samples
        buttonStates4[i] = !buttonStates4[i];
      }
    }
  }
}

void buttonModes() {
  int on = 0;
  int off = 127;

  //PLAYING WITH FOR LOOPS
  for (int i = 0; i <= 4; i++) {
    //    Serial.println(buttonMode);
    if (buttons[i].rose()) {
      //MODE 1
      if (buttonMode == 1) {  //MAIN
        if (buttonStates1[i] == 1) {
          controlChange(0, i + 1, on);
        } else {
          controlChange(0, i + 1, off);
        }
        if (buttons[2].rose()) {
          buttonStates1[3] = 0;           //change state of otherbass to off      //MIGHT NOT WORK
          controlChange(0, 4, off); //channel, control, value
        } else if (buttons[3].rose()) {
          buttonStates1[2] = 0;
          controlChange(0, 3, off); //channel, control, value
        }
      }
      //MODE 2
      if (buttonMode == 2) {  //DRUMS
        if (buttonStates2[i] == 1) {
          controlChange(0, i + 6, on);
        } else {
          controlChange(0, i + 6, off);
        }
//        if (buttonStates2[4] = 1) {
//          controlChange(0, 4, off);
//        } else if (buttonStates2[4] = 0) {
//          controlChange(0, 4, on);
//        }
      }
      //MODE 3
      if (buttonMode == 3) {  //MOTIVES
        if (buttonStates3[i] == 1) {
          controlChange(0, i + 11, on);
        } else {
          controlChange(0, i + 11, off);
        }
        if (buttonStates3[4] = 1) {
          buttonStates3[4] = 0;
        }
      }
      //MODE 4
      if (buttonMode == 4) {  //SAMPLES
        if (buttonStates4[i] == 1) {
          controlChange(0, i + 16, on);
        } else {
          controlChange(0, i + 16, off);
        }
        if (buttonStates4[4] == 1) {
          controlChange(0, 15, off);  //unmute solo mario
          controlChange(0, 10, off);  //mute drums
        } else if (buttonStates4[4] == 0) {
          controlChange(0, 15, on);   //mute solo mario
          controlChange(0, 10, on);  //unmute drums
        }
      }
    }
  }

  //CHANGING MODES IN FIRST MODE
  if (buttonMode == 1) {            //in the first mode (blue/melody)
    if (buttons[5].rose()) {  //if the first button (red) is pressed
      buttonMode = 2;               //change to mode 2  (red/drums)
      ledMode = 2;
    }
    if (buttons[6].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 3;               //change to mode 3
      ledMode = 3;
    }
    if (buttons[7].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 4;               //change to mode 3
      ledMode = 4;
    }
  }

  //CHANGING MODES IN SECOND MODE
  else if (buttonMode == 2) {            //in the second mode (red/drums)
    if (buttons[5].rose()) {  //if the first button (red) is pressed
      buttonMode = 1;               //change to mode 2  (red/drums)
      ledMode = 1;
    }
    if (buttons[6].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 3;               //change to mode 3
      ledMode = 3;
    }
    if (buttons[7].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 4;               //change to mode 3
      ledMode = 4;
    }
  }

  //CHANGING MODES IN MODE 3
  else if (buttonMode == 3) {
    if (buttons[5].rose()) {  //if the first button (red) is pressed
      buttonMode = 1;               //change to mode 2  (red/drums)
      ledMode = 1;
    }
    if (buttons[6].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 2;               //change to mode 3
      ledMode = 2;
    }
    if (buttons[7].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 4;               //change to mode 3
      ledMode = 4;
    }
  }

  //CHANGING MODES IN MODE 4
  else if (buttonMode == 4) {
    if (buttons[5].rose()) {  //if the first button (red) is pressed
      buttonMode = 1;               //change to mode 2  (red/drums)
      ledMode = 1;
    }
    if (buttons[6].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 2;               //change to mode 3
      ledMode = 2;
    }
    if (buttons[7].rose()) {  //if the fourth button (yellow) is pressed
      buttonMode = 3;               //change to mode 3
      ledMode = 3;
    }
  }
}

//NOTES

  //CHANNELS//
  //  //MAIN
  //  int lead = 1;
  //  int COD = 2;
  //  int CODBass = 3;
  //  int otherBass = 4;
  //  int lowC = 5;
  //  //DRUMS
  //  int bassDrum = 6;
  //  int clap = 7;
  //  int hihat = 8;
  //  int snare = 9;
  //  int muteDrums = 10;
  //  //VIDEO GAME MOTIVES
  //  int megalovania = 11;
  //  int vampireKiller = 12;
  //  int zelda = 13;
  //  int sonic = 14;
  //  int soloMario = 15;
  //  //SAMPLES
  //  int playstation = 16;
  //  int mortalKombat = 17;
  //  int secretSound = 18;
  //  int pokemon = 19;
  //  int superMario = 20;
  ///////
