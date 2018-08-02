
#include "pitches.h"

unsigned long lastMillis = 0;

int buttonState12 = 0;
int buttonState13 = 0;

boolean button12isDOWN = false;
boolean button13isDOWN = false;
const int buttonPin12 = 12;
const int buttonPin13 = 13;
const int TIMEBETWEEN = 1000;
const int ledPin = 1;

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4};
// notes in the melody:
int melody[] = {
  NOTE_C4};
//make sure that the song length is equal to 'melody' length and 'noteDuration' length
int SONG_LENGTH = 1;

void setup(){
  Serial.begin(9600);
  pinMode(2, OUTPUT);     //solenoid
  pinMode(3, OUTPUT);     //solenoid
  pinMode(4, OUTPUT);     //solenoid
  pinMode(5, OUTPUT);     //solenoid
  pinMode(buttonPin12, INPUT); 
  pinMode(buttonPin13, INPUT);

  lastMillis = millis(); 
}

void loop(){

  buttonState12 = digitalRead(buttonPin12);
  buttonState13 = digitalRead(buttonPin13);

  if (buttonState12 == HIGH)  { 

    if (button12isDOWN == false)  {
      lastMillis = millis();
      button12isDOWN = true; 

    } 
    else {
      if ((millis() - lastMillis) > TIMEBETWEEN)  {
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        digitalWrite(ledPin, LOW);
        Serial.println("PRESSED TOO LONG");
      } 
      else  {

        for (int thisNote = 0; thisNote <  SONG_LENGTH; thisNote++) {

          // to calculate the note duration, take one second
          // divided by the note type.
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000/noteDurations[thisNote];
          tone(8, melody[thisNote],noteDuration);

          // to distinguish the notes, set a minimum time between them.
          // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          // stop the tone playing:
          noTone(8);

          digitalWrite(2, HIGH);
          digitalWrite(3, HIGH);
          digitalWrite(ledPin, HIGH);
          Serial.println("PRESSING...");
        }

      }
    }

  }  
  else  {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);    
    digitalWrite(ledPin, LOW);    // sets the LED off
    Serial.println("NOT PRESSED");
    button12isDOWN = false;
  }


  ////button13////

  if (buttonState13 == HIGH)  { 

    if (button13isDOWN == false)  {
      lastMillis = millis();
      button13isDOWN = true; 

    } 
    else {
      if ((millis() - lastMillis) > TIMEBETWEEN)  {
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
        digitalWrite(ledPin, LOW);
        Serial.println("PRESSED TOO LONG");
      } 
      else  {

        for (int thisNote = 0; thisNote <  SONG_LENGTH; thisNote++) {

          // to calculate the note duration, take one second
          // divided by the note type.
          //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
          int noteDuration = 1000/noteDurations[thisNote];
          tone(7, melody[thisNote],noteDuration);

          // to distinguish the notes, set a minimum time between them.
          // the note's duration + 30% seems to work well:
          int pauseBetweenNotes = noteDuration * 1.30;
          delay(pauseBetweenNotes);
          // stop the tone playing:
          noTone(7);

          digitalWrite(4, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(ledPin, HIGH);
          Serial.println("PRESSING...");
        }

      }
    }

  }  
  else  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);    
    digitalWrite(ledPin, LOW);    // sets the LED off
    Serial.println("NOT PRESSED");
    button13isDOWN = false;
  }  

}











