#include <dht.h>
dht DHT;
//Constants
#define DHT22_PIN 2     // DHT 22  (AM2302) - what pin we're connected to
#define RELAYPINT 3
#define RELAYPINH 4
#define RELAYPINM 5
//Variables
float hum;  //Stores humidity value
float temp; //Stores temperature value
int x=0;
int y=0;
int a=0;
int b=0;
void setup()
{
    Serial.begin(9600);
  pinMode(RELAYPINT, OUTPUT);
  pinMode(RELAYPINH, OUTPUT);
  pinMode(RELAYPINM, OUTPUT);
}

void loop()
{
    int chk = DHT.read22(DHT22_PIN);

    hum = DHT.humidity;
    temp= DHT.temperature;



    //arduinonuzu laptopunuza bağlayarak sıcaklık ve nem değerlerini okuyabilirsiniz seri port ekranından
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(1000); //Delay 2 sec.

    if (temp > 37) { //benim rölelerimin ışıkları ters çalıştığı için bu şekilde büyüktür yaptım 
    
    digitalWrite(RELAYPINT, HIGH);
    
  } 
  else  {
       digitalWrite(RELAYPINT, LOW);
  }
    if (hum > 60) {
    digitalWrite(RELAYPINH, HIGH);
  } else  {
    digitalWrite(RELAYPINH, LOW);
  }

 if (b==0){
  digitalWrite(RELAYPINM, HIGH);
 b++;
 }
    if (a==1){
    if (x==3600){
 digitalWrite(RELAYPINM, LOW);
 x=0;
 a=0;
 }
 if (x<=3600)
 delay (1000);
 x=x+2;}



 if (a==0){
 if (y==18){
digitalWrite(RELAYPINM, HIGH);
y=0;
a=1;
}
if (y<=18){
delay (1000);
y=y+2;}}
}
