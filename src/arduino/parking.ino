#include <NewPing.h>
#include <Servo.h>

#define TRIG1_PIN 6
#define ECHO1_PIN 7
#define TRIG2_PIN 4
#define ECHO2_PIN 5
//#define TRIG3_PIN 4  //***** change this trig pin to pin 4
//#define ECHO3_PIN 12
#define GATE_TRIG_PIN 10
#define GATE_ECHO_PIN 11
#define SERVO_PIN 9   // ****** change the servo pin to pin 9
#define MAX_DISTANCE 200

NewPing sonar1(TRIG1_PIN, ECHO1_PIN, MAX_DISTANCE);
NewPing sonar2(TRIG2_PIN, ECHO2_PIN, MAX_DISTANCE);
//NewPing sonar3(TRIG3_PIN, ECHO3_PIN, MAX_DISTANCE);
NewPing gate_sonar(GATE_TRIG_PIN, GATE_ECHO_PIN, MAX_DISTANCE);
Servo servo;

int num_slots = 3;
bool empty_slots[2];
int min_distance = 10;
bool slots_available = true;

void setup() {
  Serial.begin(9600);
  servo.attach(SERVO_PIN);
}

void loop() {
  int distance1 = sonar1.ping_cm();
  int distance2 = sonar2.ping_cm();
  //int distance3 = sonar3.ping_cm();
  int gate_distance = gate_sonar.ping_cm();

  if (distance1 > min_distance) {
    empty_slots[0] = true;
  }
  else{
    empty_slots[0] = false;
  }
  if (distance2 > min_distance) {
    empty_slots[1] = true;
  }
  else{
    empty_slots[1] = false;
  }

  int slot_num=0;
  for(int i=0;i<2;i++){
    if(empty_slots[i]==true){
      slot_num+=1;
    }
  }
  num_slots=slot_num;
  if(slot_num>0){
    slots_available=true;
  }
  else{
    slots_available=false;
  }

  if (gate_distance <= min_distance) {
    Serial.print("message2\n");
    Serial.print("Car detected!\n");
    if (slots_available) {
      openGate();
      Serial.print("message\n");
      for(int i=0;i<2;i++){
        if(empty_slots[i]==true){
          Serial.print("You can Park at slot: ");
          Serial.print(i+1);
          Serial.print("\n");
          break;
        }
      }
    }
    else {
      Serial.print("message\n");
      Serial.print("slot full cannot open gate\n");
    }
  }
  else {
    Serial.print("message2\n");
    Serial.print("No car at gate\n");
    closeGate();
    
    slots_available = true;
  }
  Serial.print("slots\n");
  for(int i=0;i<2;i++){
    if(empty_slots[i]==true){
          Serial.print("1\n");
  }
  else
  {
    Serial.print("0\n");
  }
  }
  delay(500);
}

void openGate() {
  servo.write(0);
  delay(1000);
}
void closeGate() {
  servo.write(90);
  delay(1000);
}
