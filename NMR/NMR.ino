#define PCD 2
#define TX 3
#define RX 4
#define PD 5
#define PS 6
#define PCS 7
#define ResetLoop 8;
int Waiting=0;
String Index;
int counter=0;
int D1=1;
String cc= "   TX Off 320";
String cc1;
String cc2;
String chopped;
uint32_t TimeStamps[] = {};
// PP TX RX PD PS PCS
uint8_t Trigger[] = {};
uint8_t SwitchNo[] = {};
int var =4;
int index=0;
uint32_t D=0;
uint32_t Delay=0;
uint32_t R=0;
uint32_t offset=0;



void setup() {
  Serial.begin(9600);
  Serial.println("Type something!");
}
void loop() {


if (Serial.available() > 0) {
    cc = Serial.readStringUntil('\n');
    // say what you got:
    Serial.print("I received: ");
    Serial.println(cc);
    counter = counter+1;
  }

while (cc.length()>0){chopping();
if (cc1=="PCD"){Serial.println("PCD\n");
              chopping();
              if (cc1=="1"){Trigger[counter]=1; Serial.println("1\n");}
              if (cc1=="0"){Trigger[counter]=0; Serial.println("0\n");}
              Trigger[counter]=cc1.toFloat();
              SwitchNo[counter]=PCD;
              chopping();
              TimeStamps[counter]=cc1.toFloat();
              Serial.println(TimeStamps[counter]);
              }
if (cc1=="TX"){Serial.println("TX\n");
              chopping();
              if (cc1=="1"){Serial.println("1\n");}
              if (cc1=="0"){Serial.println("0\n");}
              Trigger[counter]=cc1.toFloat();
              SwitchNo[counter]=TX;
              chopping();
              TimeStamps[counter]=cc1.toFloat();
              Serial.println(TimeStamps[counter]);
              }
if (cc1=="RX"){Serial.println("RX\n");
              chopping();
              if (cc1=="1"){Serial.println("1\n");}
              if (cc1=="0"){Serial.println("0\n");}
              Trigger[counter]=cc1.toFloat();
              SwitchNo[counter]=RX;
              chopping();
              TimeStamps[counter]=cc1.toFloat();
              Serial.println(TimeStamps[counter]);
              }
if (cc1=="PD"){Serial.println("PD\n");
              chopping();
              if (cc1=="1"){Serial.println("1\n");}
              if (cc1=="0"){Serial.println("0\n");}
              Trigger[counter]=cc1.toFloat();
              SwitchNo[counter]=PD;
              chopping();
              TimeStamps[counter]=cc1.toFloat();
              Serial.println(TimeStamps[counter]);
              }
              
if (cc1=="PS"){Serial.println("PS\n");
              chopping();
              if (cc1=="1"){Serial.println("1\n");}
              if (cc1=="0"){Serial.println("0\n");}
              Trigger[counter]=cc1.toFloat();
              SwitchNo[counter]=PS;
              chopping();
              TimeStamps[counter]=cc1.toFloat();
              Serial.println(TimeStamps[counter]);
              }
              
if (cc1=="PCS"){Serial.println("PCS\n");
              chopping();
              if (cc1=="1"){Serial.println("1\n");}
              if (cc1=="0"){Serial.println("0\n");}
              Trigger[counter]=cc1.toFloat();
              SwitchNo[counter]=PCS;
              chopping();
              TimeStamps[counter]=cc1.toFloat();
              Serial.println(TimeStamps[counter]);
              }
if (cc1=="D"){Serial.println("D\n");
              chopping();
              D=1;
              if (cc1=="1"){D=1;Serial.println("1\n");}
              if (cc1=="0"){D=0;Serial.println("0\n");}
              chopping();
              Delay=cc1.toFloat();
              Serial.println(Delay);
              }
if (cc1=="R"){Serial.println("R\n");
              chopping();
              R=cc1.toInt();
              Serial.println(R);
              } 
if (cc1=="D1"){Serial.println("D1\n");
              chopping();
              D1=cc1.toInt();
              Serial.println(D);
              } 
while (D1==0) {
  Serial.println("Entered into second while");
uint32_t t = millis()-offset;
if ((TimeStamps[index] <= t)) {
if (SwitchNo[index]  == PCD){digitalWrite(PCD, Trigger[index]); Serial.print("PCD: ");Serial.print(", Trigger: ");Serial.print(Trigger[index]);Serial.print(", SwitchNo: ");SwitchNo[index];Serial.print("\n");}
if (SwitchNo[index]  == TX){digitalWrite(TX, Trigger[index]); Serial.print("TX\n");Serial.print(", Trigger: ");Serial.print(Trigger[index]);Serial.print(", SwitchNo: ");SwitchNo[index];Serial.print("\n");}
if (SwitchNo[index]  == RX){digitalWrite(RX, Trigger[index]); Serial.print("RX\n");Serial.print(", Trigger: ");Serial.print(Trigger[index]);Serial.print(", SwitchNo: ");SwitchNo[index];Serial.print("\n");}
if (SwitchNo[index]  == PD){digitalWrite(PD, Trigger[index]); Serial.print("PD\n");Serial.print(", Trigger: ");Serial.print(Trigger[index]);Serial.print(", SwitchNo: ");SwitchNo[index];Serial.print("\n");}
if (SwitchNo[index]  == PS){digitalWrite(PS, Trigger[index]); Serial.print("PS\n");Serial.print(", Trigger: ");Serial.print(Trigger[index]);Serial.print(", SwitchNo: ");SwitchNo[index];Serial.print("\n");}
if (SwitchNo[index]  == PCS){digitalWrite(PCS, Trigger[index]); Serial.print("PCS\n");Serial.print(", Trigger: ");Serial.print(Trigger[index]);Serial.print(", SwitchNo: ");SwitchNo[index];Serial.print("\n");}
index++; 
delay(D);
if (Trigger[index] > D){index=0;offset=millis();Serial.print("Reset\n");}
}

}
}}




float chopping(){
while (cc.startsWith(" ")){cc=cc.substring(1);}
cc1=cc.substring(0,cc.indexOf(" "));
cc=cc.substring(cc.indexOf(" "));}
