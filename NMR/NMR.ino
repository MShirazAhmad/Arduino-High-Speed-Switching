String Index;
int counter=0;
int Loop_Count = 0;
int D1=1;
String Data= "";
String VARIABLE;
//String Data2;
uint32_t Data_float[50];
//String chopped;
uint32_t Time[50];
uint8_t Pin[50];
uint8_t Switch[50];
int Loops=0;
int var =4;
int Length=0;
int BREAK = 0;
int initiate_switching_status=0;
int index=0;
uint32_t Delay=0;
uint32_t R=0;
uint32_t offset=0;
String temp_var= "";
uint32_t str_float[50];
void setup() {
  Serial.begin(9600);
  Serial.println("Type something!");
}
void loop() {
if (Serial.available() > 0)
    {
    Data = Serial.readStringUntil('\n');
    while (Data.startsWith(" ")){Data=Data.substring(1);}
    }
    processing_array(Data);
    if (initiate_switching_status==1){serial_print();initiate_switching();}
}
int initiate_switching(){

while (Loop_Count<Loops)
{uint32_t offset = millis();
{ var=0;
    while (BREAK == 0) {
    uint32_t t = millis()-offset;
    while ((Time[var] < t)) {
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
          Serial.print(t);
          Serial.print("\n");
      var++;
    }
    if (var==Length){Loop_Count=Loop_Count+1;var = 0;delay(Delay);offset=millis();}
    }
}
}}
uint32_t processing_array(String str)
{Serial.print(str);
int p=-1; // P=-1 because in first iteration, variable stamps are assigned and from second, values.
while (str.length()!=0)
      {
      while (str.startsWith(" ")){str=str.substring(1);}
      VARIABLE=Data.substring(0,Data.indexOf(" "));
      if (temp_var == "Time"){Serial.print(temp_var);VARIABLE=temp_var;}
      if (temp_var == "Switch"){VARIABLE=temp_var;}
      if (temp_var == "Pin"){VARIABLE=temp_var;}
      if (temp_var == "Delay"){VARIABLE=temp_var;}
      if (temp_var == "Loops"){VARIABLE=temp_var;}
      if (temp_var == "Length"){VARIABLE=temp_var;}
      if (temp_var == "Run"){initiate_switching_status=1;Serial.print("Switch:");Serial.print(initiate_switching_status);}
      while (str.startsWith(" ")){str=str.substring(1);}
      temp_var=str.substring(0,str.indexOf(" "));
        if ((VARIABLE == "Time") && temp_var != ""){Serial.print(" ");Time[p]=temp_var.toFloat();}
        if (VARIABLE == "Switch"){Switch[p]=temp_var.toFloat();}
        if (VARIABLE == "Pin"){Pin[p]=temp_var.toFloat();}  
        if (VARIABLE == "Delay"){Delay=temp_var.toFloat();}  
        if (VARIABLE == "Loops"){Loops=temp_var.toFloat();}
        if (VARIABLE == "Length"){Length=temp_var.toFloat();} 
      str=str.substring(str.indexOf(" "));
     // Serial.print("\n");Serial.print(str.length());Serial.print("\n");
      p=p+1;
      if (str.length() == 0){Data= ""; temp_var="";}
      }
}




uint32_t serial_print()
{
Serial.print("\n Time");for (int p; p<=11; p++){Serial.print(" ");Serial.print(Time[p]);}
Serial.print("\n Switch");for (int p; p<=11; p++){Serial.print(" ");Serial.print(Switch[p]);}
Serial.print("\n Pin");for (int p; p<=11; p++){Serial.print(" ");Serial.print(Pin[p]);}
Serial.print("\n Delay");Serial.print(" ");Serial.print(Delay);
Serial.print("\n Loops");Serial.print(" ");Serial.print(Loops);
Serial.print("\n Length");Serial.print(" ");Serial.print(Length);
}
