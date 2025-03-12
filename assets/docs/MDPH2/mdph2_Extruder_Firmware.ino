// extrudercontrol.ino
//
//
// Luis Pacheco 3/27/24
//
// This work may be reproduced, modified, distributed,
// performed, and displayed for any purpose, but must
// acknowledge this project. Copyright is retained and
// must be preserved. The work is provided as is; no
// warranty is provided, and users accept all liability.
//


 #include <Arduino.h>

// Motor variables
int OutStep = 25;
int OutDir = 26;
int OutEnable = 27;
bool MotorEnable = false;
float MotorRev = 800;
float MotorSpeed = 0;  // revolutions per minute
unsigned long LastRunTime = 0;
unsigned long currentMotorTime = 0;
unsigned long previousMotorTime = 0;
long motorInterval = 0.1;

// Rotary encoder variables
#define SPIN_A 2
#define SPIN_B 4
#define SPIN_BUTTON 15
volatile bool sturnedCW = false;
volatile bool sturnedCCW = false;
static int svalue = 0;
int DEBONCE_TO = 150;
unsigned long sdebounceTime = 0;
bool slastWasCW = false;
bool slastWasCCW = false;

void setup() {
  Serial.begin(115200);
  
  // MOTOR setup
  pinMode(OutDir, OUTPUT);
  pinMode(OutStep, OUTPUT);
  pinMode(OutEnable, OUTPUT);
  digitalWrite(OutEnable, HIGH);  // activate extruder motor
  digitalWrite(OutDir, HIGH);     // Set direction
  Serial.println("Motor setup OK");
  currentMotorTime = millis();
  previousMotorTime = millis();

  // Motor Encoder setup
  pinMode(SPIN_A, INPUT_PULLUP);
  pinMode(SPIN_B, INPUT_PULLUP);
  pinMode(SPIN_BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SPIN_B), scheckEncoder, CHANGE);
  Serial.println("Reading from encoder: MOTOR ");
}

void loop() {
  // motor control logic here
  if (MotorEnable && MotorSpeed != 0) {
    currentMotorTime = millis();
    float StepPerMillis = MotorRev * MotorSpeed / 30000000;
    float MillisPerStep = 1 / StepPerMillis;
    digitalWrite(OutStep, HIGH);
    delayMicroseconds(MillisPerStep);
    digitalWrite(OutStep, LOW);
    delayMicroseconds(MillisPerStep);
  }

  // Rotary encoder logic for motor speed control
  if (sturnedCW) {
    svalue++;
    MotorSpeed = svalue * 25;  // Example: Adjusting speed with each CW turn
    sturnedCW = false;
    slastWasCW = true;
    sdebounceTime = millis();
  }

  if (sturnedCCW) {
    if (MotorSpeed > 0) {
      svalue--;
      MotorSpeed = svalue * 25;  // Example: Decreasing speed with each CCW turn
    }
    sturnedCCW = false;
    slastWasCCW = true;
    sdebounceTime = millis();
  }

  // Reset motor speed to zero if encoder button is pressed
  int sbtnState = digitalRead(SPIN_BUTTON);
  if (sbtnState == LOW && millis() - sdebounceTime > DEBONCE_TO) {
    MotorSpeed = 0;
    sdebounceTime = millis();
  }
}

void scheckEncoder() {
  if ((!sturnedCW) && (!sturnedCCW)) {
    int spinA = digitalRead(SPIN_A);
    delayMicroseconds(1500);  // Debounce delay
    int spinB = digitalRead(SPIN_B);
    if (spinA == spinB) {
      sturnedCW = !slastWasCCW;
      sturnedCCW = slastWasCCW;
    } else {
      sturnedCW = slastWasCW;
      sturnedCCW = !slastWasCW;
    }
  }
}
