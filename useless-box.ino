// 

#include <Servo.h>
#include <Bounce2.h>

#define PIN_UNCONNECTED 0  // for seeding random number generator
#define PIN_SWITCH 11  // switch is on pin 11
#define PIN_FINGER 8  // finger servo is on pin 8
#define PIN_LID 7  // lid servo is on pin 7
#define MIN_ANGLE_FINGER 0
#define MAX_ANGLE_FINGER 80
#define MIN_ANGLE_LID 50
#define MAX_ANGLE_LID 130

typedef void(*offFunction)(void);

Servo servoFinger;  // finger servo
Servo servoLid;  // box lid servo
int switchStatus = 0;
int action = 1;
long int actionCounter = 0;
Bounce debouncer = Bounce(); // this is needed for a decent trigger signal

#include "animations.h"  // contains functions to switch off as well as array offFunctions[] listing them


// ---- done once when Arduino boots -------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(PIN_SWITCH, INPUT_PULLUP);
  debouncer.attach(PIN_SWITCH);
  debouncer.interval(50);
  servoFinger.attach(PIN_FINGER);
  servoFinger.write(MAX_ANGLE_FINGER);
  servoLid.attach(PIN_LID);
  servoLid.write(MIN_ANGLE_LID);
  randomSeed(analogRead(PIN_UNCONNECTED));
}


// ---- repeat until Arduino is turned off -------------------------------------
void loop() {
  debouncer.update();
  switchStatus = debouncer.rose();
  Serial.print("At ");
  Serial.print(millis());
  Serial.print(" msecs,");
  if (switchStatus == LOW) {
    Serial.println(" no action required");
  } else if (switchStatus == HIGH){
    action = (random(7)+1);
    actionCounter++;
    // action=7;
    Serial.print(" action is ");
    Serial.print(action);
    Serial.print(" (");
    Serial.print(actionCounter);
    Serial.println(". action overall)");
    offFunctions[action - 1]();
    servoFinger.write(MAX_ANGLE_FINGER);
    delay(200);
    servoLid.write(MIN_ANGLE_LID);
    delay(200);
  }
  delay(100);    
}



