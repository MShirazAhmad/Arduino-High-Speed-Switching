#define pol_coil_disconnect 2
#define tx 3
#define rx 4
#define probe_disconnect 5
#define pol_coil_short 6
#define pol_coil_on 7

String incomingByte = ""; // for incoming serial Switch
uint32_t Time[] = {100,200,300,400,500,600,700,3700,3800,3900,4000,4100,4200,4300,20000,20100};
uint32_t Switch[] = {1,0,0,0,0,0,1,0,1,1,0,1,0,1,0,1};
int Pin[] = {5,7,3,4,6,2,7,7,6,2,5,3,3,4,4,5};
uint32_t Loop_Delay = 100;

int Loop = 7;

uint32_t offset =0;
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
