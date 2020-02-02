#define pol_coil_disconnect 2
#define tx 3
#define rx 4
#define probe_disconnect 5
#define pol_coil_short 6
#define pol_coil_on 7

String incomingByte = ""; // for incoming serial Switch
uint32_t Time[] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000, 200};
uint32_t Switch[] = {1,0,1,1,1,1,0,1,0,0,0,0};
int Pin[] = {7,7,6,2,5,3,3,4,4,5,6,2};
uint32_t Loop_Delay = 100;
uint32_t offset =0;
int Loop = 7;


int Loop_Count=0;
int var =0;

void setup() {
  Serial.begin(9600); // opens serial port, sets Switch rate to 9600 bps
}
void loop() {

  
uint32_t t = millis()-offset;
while ((Time[var] < t) && (12 > var) ) {
      pinMode(Pin[var], OUTPUT);
      digitalWrite(Pin[var], Switch[var]);
      Serial.print("Event# ");
      Serial.print(var);
      Serial.print(" ,");
      Serial.print("Pin: ");
      Serial.print(Pin[var]);
      Serial.print(", Switch:");
      Serial.print(Switch[var]);
      Serial.print(" ,");
      Serial.print("Time: ");
      Serial.print(Time[var]);
      Serial.print(", Current:");
      Serial.print(millis());
      Serial.print("\n");
  var++;
}

if (var==12){Loop_Count=Loop_Count+1;var = 0;delay(Loop_Delay);offset=millis();}


}
