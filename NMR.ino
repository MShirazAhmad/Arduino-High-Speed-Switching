String incomingByte = ""; // for incoming serial data
uint32_t Time[] = {50,100,153,2300,2500,7000,8000,9000};
uint32_t Data[] = {1,0,1,1,0};
int Pin[] = {2,3,13,5,7,1,8};
int Index = 7;
int var =0;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}
void loop() {
uint32_t t = millis();
while ((Time[var] < t) && (var<Index)) {
      pinMode(Pin[var], OUTPUT);
      digitalWrite(Pin[var], Data[var]);
      Serial.print("Index: ");
      Serial.print(var);
      Serial.print(" , ");
      Serial.print("Pin No: ");
      Serial.print(Pin[var]);
      Serial.print(", Digital Data: ");
      Serial.print(Data[var]);
      Serial.print(" , ");
      Serial.print("Time Stamp:");
      Serial.print(" , ");
      Serial.print(Time[var]);
      Serial.print(", Current Time:");
      Serial.print(t);
      Serial.print("\n");
  var++;
}
}
