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

Servo servoFinger;  // finger servo
Servo servoLid;  // box lid servo
Bounce debouncer = Bounce(); // this is needed for a decent trigger signal

typedef void(*offFunction)(void);  // pointer to switch functions
#include "animations.h"  // contains functions to switch off as well as array offFunctions[] listing them

int action = 1;  // function to execute
long int actionCounter = 0;  // count execution of all functions
long int actionCounters[MAX_FUNCTION];  // count execution of each function


// ---- done once when Arduino boots -------------------------------------------
void setup() {
  Serial.begin(9600);
  pinMode(PIN_SWITCH, INPUT_PULLUP);
  debouncer.attach(PIN_SWITCH);
  debouncer.interval(10);
  servoFinger.attach(PIN_FINGER);
  servoFinger.write(MAX_ANGLE_FINGER);
  servoLid.attach(PIN_LID);
  servoLid.write(MIN_ANGLE_LID);
  randomSeed(analogRead(PIN_UNCONNECTED));
  for (int i = 0; i < MAX_FUNCTION; i++) {
    actionCounters[i] = 0;
  }
}


// ---- repeat until Arduino is turned off -------------------------------------
void loop() {
  Serial.print("At ");
  Serial.print(millis());
  Serial.print(" msecs, button is ");
  // for some reason, update() registers the new state correctly only if called twice with delay... 
  debouncer.update();  delay(30);  debouncer.update();
  Serial.print(debouncer.read());
  Serial.print(", ");
  if (debouncer.read()) {
    action = (random(7)+1);
    // action=7;
    actionCounter++;
    actionCounters[action - 1]++;
    Serial.print("action is ");
    Serial.print(action);
    Serial.print(" (");
    Serial.print(actionCounters[action - 1]);
    Serial.print(" times executed, ");
    Serial.print(actionCounter);
    Serial.println(" executions overall)");
    offFunctions[action - 1]();
    servoFinger.write(MAX_ANGLE_FINGER);
    delay(200);
    servoLid.write(MIN_ANGLE_LID);
    delay(200);
  } else {
    Serial.println("no action required");
  }
}



