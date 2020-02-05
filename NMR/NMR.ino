#define ResetLoop 8;
int Waiting=0;
String Index;
int counter=0;
int D1=1;
String Data= "";
String Data1;
String Data2;
uint32_t Data_float[50];
String chopped;
uint32_t TimeStamps[] = {};
uint8_t Trigger[] = {};
uint8_t SwitchNo[] = {};
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
    Serial.println(Data);
    counter = counter+1;
    }
    declearing_array(Data);
    Serial.print(str_float[0]);
}
float chopping(){
while (Data.startsWith(" ")){Data=Data.substring(1);}
Data1=Data.substring(0,Data.indexOf(" "));
Data=Data.substring(Data.indexOf(" "));}
uint32_t declearing_array(String str)
{
int p=0;
while (str.length()>0)
      {
      while (str.startsWith(" ")){str=str.substring(1);}
      temp_var=str.substring(0,str.indexOf(" "));
      str_float[p]=temp_var.toFloat();
      str=str.substring(str.indexOf(" "));
      //Serial.print(Data_float[p]);
      //Serial.print("\n");
      p=p+1;
      }
}
