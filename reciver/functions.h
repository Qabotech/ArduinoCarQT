// Pin-Zuweisungen
int Right_Motor_Backward = 7; //First_Motor_Backward
int Right_Motor_Forward = 6; //First_Motor_Forward
int buzzerPin = 8;
int Left_Motor_Forward = 3; //Sec_Motor_Forward
int Left_Motor_Backward = 2; //Sec_Motor_Backward
/*int frontBlinkerPinR = 8;
int frontBlinkerPinL = 5;
int frontLightRight = 9;
int frontLightLeft = 10;*/


// Funktion zur Einrichtung der Pins
void funcSetup() {
  pinMode(Right_Motor_Backward, OUTPUT);
  pinMode(Right_Motor_Forward, OUTPUT);
  pinMode(Left_Motor_Forward, OUTPUT);
  pinMode(Left_Motor_Backward, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  //pinMode(frontBlinkerPinR, OUTPUT);
  //pinMode(frontBlinkerPinL, OUTPUT);
  //pinMode(frontLightRight, OUTPUT);
  //pinMode(frontLightLeft, OUTPUT);
}

// Funktion, um das Fahrzeug vorwärts zu bewegen
void forward() {
  digitalWrite(Right_Motor_Backward, LOW);
  digitalWrite(Right_Motor_Forward, HIGH);
  digitalWrite(Left_Motor_Backward, LOW);
  digitalWrite(Left_Motor_Forward, HIGH);
  //blinkers();
}

// Funktion, um das Fahrzeug rückwärts zu bewegen
void backward() {
  digitalWrite(Right_Motor_Backward, HIGH);
  digitalWrite(Right_Motor_Forward, LOW);
  digitalWrite(Left_Motor_Backward, HIGH);
  digitalWrite(Left_Motor_Forward, LOW);
}

// Funktion, um nach links zu fahren, während es vorwärts geht
void leftForward() {
  digitalWrite(Right_Motor_Backward, LOW);
  digitalWrite(Right_Motor_Forward, LOW);
  digitalWrite(Left_Motor_Backward, LOW);
  digitalWrite(Left_Motor_Forward, HIGH);

}

// Funktion, um nach rechts zu fahren, während es vorwärts geht
void rightForward() {
  digitalWrite(Right_Motor_Backward, LOW);
  digitalWrite(Right_Motor_Forward, HIGH);
  digitalWrite(Left_Motor_Backward, LOW);
  digitalWrite(Left_Motor_Forward, LOW);

}

// Funktion, um nach links zu fahren, während es rückwärts geht
void leftBackward() {
  digitalWrite(Right_Motor_Backward, LOW);
  digitalWrite(Right_Motor_Forward, LOW);
  digitalWrite(Left_Motor_Backward, HIGH);
  digitalWrite(Left_Motor_Forward, LOW);

}

// Funktion, um nach rechts zu fahren, während es rückwärts geht
void rightBackward() {
  digitalWrite(Right_Motor_Backward, HIGH);
  digitalWrite(Right_Motor_Forward, LOW);
  digitalWrite(Left_Motor_Backward, LOW);
  digitalWrite(Left_Motor_Forward, LOW);

}
void Stop() {
  digitalWrite(Right_Motor_Backward, LOW);
  digitalWrite(Right_Motor_Forward, LOW);
  digitalWrite(Left_Motor_Backward, LOW);
  digitalWrite(Left_Motor_Forward, LOW);
}
// Funktion zum Abspielen eines Autohupe-Sounds
void carHornSound() {
  int hornSound[] = {900, 1800, 2400, 1800, 0};  // Adjusted values for potentially louder sound
  int noteDuration = 1000;  // Increased duration for each note

  for (int i = 0; i < 5; i++) {
    if (hornSound[i] == 0) {
      noTone(buzzerPin);
    } else {
      tone(buzzerPin, hornSound[i], noteDuration);
    }
    delay(noteDuration + 50);
  }
}


// Funktion zur Simulation des Auto-Blinkers (Blinklicht)
/*void carBlinker() {
  if (mode == 'r')
  {
    digitalWrite(frontBlinkerPinR, HIGH);
    delay(200);
    digitalWrite(frontBlinkerPinR, LOW);
    delay(200);
  }
  else if (mode == 'l')
  {
    digitalWrite(frontBlinkerPinL, HIGH);
    delay(200);
    digitalWrite(frontBlinkerPinL, LOW);
    delay(200);
  }
}*/

/*void blinkers() {

    digitalWrite(frontBlinkerPinR, HIGH);
    digitalWrite(frontBlinkerPinL, HIGH);
    delay(200);
    digitalWrite(frontBlinkerPinR, LOW);
    digitalWrite(frontBlinkerPinL, LOW);
    delay(200);
}*/
