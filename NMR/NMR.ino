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
String Data= "";
String VARIABLE;
String Data2;
uint32_t Data_float[50];
String chopped;
uint32_t Time[50];
// PP TX RX PD PS PCS
uint8_t Pin[50];
uint8_t Switch[50];
int var =4;
int index=0;
uint32_t D=0;
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
    counter = counter+1;
    }
    declearing_array(Data);
}
uint32_t declearing_array(String str)
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
        if ((VARIABLE == "Time") && temp_var != ""){Time[p]=temp_var.toFloat();}
        if (VARIABLE == "Switch"){Switch[p]=temp_var.toFloat();}
        if (VARIABLE == "Pin"){Pin[p]=temp_var.toFloat();}   
      str=str.substring(str.indexOf(" "));
      Serial.print("\n");Serial.print(str.length());Serial.print("\n");
      p=p+1;
      if (str.length() == 0){Data= "";}
      }
}
