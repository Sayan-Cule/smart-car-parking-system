#define RXp2 16 // *** attach this with arduino's tx pin.
#define TXp2 17 //*** attach this with arduino's rx pin (not mandatory)a
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
 // Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
}
void loop() {
    Serial.println("Message Received ");
    Serial.println(Serial.readString());
}
