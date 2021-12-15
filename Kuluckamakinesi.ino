
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
    delay(2000); //Delay 2 sec.

    if (temp > 37) { //benim rölelerimin ışıkları ters çalıştığı için bu şekilde büyüktür yaptım 
    digitalWrite(RELAYPINT, HIGH);
  } else  {
    digitalWrite(RELAYPINT, LOW);
  }
    if (hum > 60) {
    digitalWrite(RELAYPINH, HIGH);
  } else  {
    digitalWrite(RELAYPINH, LOW);
  }
  
 digitalWrite(RELAYPINM, HIGH);
  delay (3600000); //1 saat boyunca kuluçka motorunu beklet

digitalWrite(RELAYPINM, LOW);

delay (18000); //Motorunuz kaç milisaniyede yarım tur yapıyorsa o kadar çalıştırın
}
