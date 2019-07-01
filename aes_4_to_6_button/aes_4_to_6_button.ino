// Code for Arduino Pro Micro with Kamencesc MVS DB9 to Arduino
// using USB Joystick library:
// https://github.com/MHeironimus/ArduinoJoystickLibrary
// 
// Code by: Kamencesc
// Board by: Kamencesc
// 
// Site: http://www.kamencesc.com/
// 01-07-2019
//--------------------------------------------------------------------

byte stick[] = { 3, 2, 1, 0 };
byte jamma[] = { 8, 9, 10, 11, 12, 13 };

void setup() {
  for (int j=0; j < (sizeof(stick)/sizeof(stick[0])); j++) {
    pinMode(stick[j], INPUT_PULLUP);
  }
  for (int j=0; j < (sizeof(jamma)/sizeof(jamma[0])); j++) {
    pinMode(jamma[j], OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  byte aes1 = digitalRead(3);
  byte aes2 = digitalRead(2);
  byte aes3 = digitalRead(1);
  byte aes4 = digitalRead(0);

  if ( !aes1 && !aes2 ) {
    digitalWrite(9, LOW);   //middle punch
    digitalWrite(8, HIGH);  //light punch
    digitalWrite(10, HIGH); //heavy punch
  } else if  ( !aes1 ) {
    digitalWrite(8, LOW);   //light punch
    digitalWrite(10, HIGH); //heavy punch
    digitalWrite(9, HIGH);  //middle punch
  } else if ( !aes2 ) {
    digitalWrite(10, LOW);  //heavy punch
    digitalWrite(8, HIGH);  //light punch
    digitalWrite(9, HIGH);  //middle punch
  } else if ( aes1 && aes2 ) {
    digitalWrite(10, HIGH);  //heavy punch
    digitalWrite(8, HIGH);   //light punch
    digitalWrite(9, HIGH);   //middle punch 
  }

  if ( !aes3 && !aes4 ) {
    digitalWrite(12, LOW);   //middle kick
    digitalWrite(11, HIGH);   //light kick
    digitalWrite(13, HIGH);  //heavy kick
  } else if  ( !aes3 ) {
    digitalWrite(12, HIGH);   //middle kick
    digitalWrite(11, LOW);   //light kick
    digitalWrite(13, HIGH);  //heavy kick
  } else if ( !aes4 ) {
    digitalWrite(12, HIGH);   //middle kick
    digitalWrite(11, HIGH);   //light kick
    digitalWrite(13, LOW);  //heavy kick
  } else if ( aes3 && aes4 ) {
    digitalWrite(12, LOW);   //middle kick
    digitalWrite(11, LOW);   //light kick
    digitalWrite(13, LOW);  //heavy kick
  }
}
