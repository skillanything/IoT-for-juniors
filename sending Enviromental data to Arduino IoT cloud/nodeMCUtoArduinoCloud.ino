#include "thingProperties.h"
#include "DHT.h"
#define DHTpin 2 // D4 on the nodemcu ESP8266
#define DHTTYPE DHT11
DHT dht(DHTpin,DHTTYPE);
 
void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
 
  // Defined in thingProperties.h
  initProperties();
 
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
 
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}
 
void loop() {
  ArduinoCloud.update();
  // Your code here 
  dht_sensor_getdata();
}
 
void onHumidityChange() {
  // Do something
 
}
 
void onMsgChange() {
  // Do something
}
 void dht_sensor_getdata()
  {
    float hm= dht.readHumidity();
    Serial.print("Humidity ");
    Serial.println(hm);
    float temp=dht.readTemperature();
      Serial.print("Temperature ");
    Serial.println(temp);
    humidity=hm;
    temperature=temp;
    msg="Temperature = " + String (temperature)+"  Humidity = " + String(humidity);
  }