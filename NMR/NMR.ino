
String Index;
int counter=0;
int Loop_Count = 0;
int D1=1;
String Data= "";
String VARIABLE;
String Data2;
uint32_t Data_float[50];
String chopped;
uint32_t Time[50];
uint8_t Pin[50];
uint8_t Switch[50];
int var =4;
int BREAK = 1;
int initiate_switching_status=0;
int index=0;
uint32_t Loop_Delay=0;
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
    }

    if (initiate_switching_status==0){processing_array(Data);}
    if (initiate_switching_status==1){initiate_switching();}
    
}





int initiate_switching()
{
    while (BREAK == 0) {
    uint32_t t = millis()-offset;
    while ((Time[var] < t) && (16 > var) ) {
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
    if (var==15){Loop_Count=Loop_Count+1;var = 0;delay(Loop_Delay);offset=millis();}
    }
}



uint32_t processing_array(String str)
{
int p=0;
while (str.length()!=0)
      {
      while (str.startsWith(" ")){str=str.substring(1);}
      VARIABLE=Data.substring(0,Data.indexOf(" "));
      if (temp_var == "Time"){VARIABLE=temp_var;}
      if (temp_var == "Switch"){VARIABLE=temp_var;}
      if (temp_var == "Pin"){VARIABLE=temp_var;}
      temp_var=str.substring(0,str.indexOf(" "));
        if ((VARIABLE == "Time") && temp_var != ""){Time[p]=temp_var.toFloat();Serial.print("\n");Serial.print(Time[p]);}
        if (VARIABLE == "Switch"){Switch[p]=temp_var.toFloat();}
        if (VARIABLE == "Pin"){Pin[p]=temp_var.toFloat();}   
      str=str.substring(str.indexOf(" "));
      Serial.print("\n");Serial.print(str.length());Serial.print("\n");
      p=p+1;
      if (str.length() == 0){Data= "";}
      }
}
