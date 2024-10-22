#include "DHT.h"
#include "LowPower.h"
//#include <SoftwareSerial.h>



#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

#define LEDPIN 11

DHT dht(DHTPIN, DHTTYPE);

// Teensy 5V <--> HC-05 Vcc
// Teensy Ground <--> HC-05 GND
#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx
//SoftwareSerial BTSerial =  SoftwareSerial(rxPin, txPin);

const int ledPin = 11; //soil sensor set up
const int soilPin = 20; //soil sensor set up


void setup() {
 // Setup serial for monitor
  Serial.begin(9600); 

  // Setup DHT Sensor
  pinMode(DHTPIN, INPUT);
  dht.begin();
  //pinMode(LED_BUILTIN,OUTPUT);
  //digitalWrite(LED_BUILTIN,LOW);
  

  // Setup Serial1 for BlueTooth
  Serial1.begin(9600); // Default communication rate of the Bluetooth module
}
//pinMode(ledPin, OUTPUT);
//Serial.begin (9600);



void loop() {
 

if(Serial1.available() > 0){ // Checks whether data is coming from the serial port
 digitalWrite(LEDPIN, HIGH);
 int val = analogRead(soilPin); //soil pin
  
  Serial1.print("Peace Lily: ");
  Serial1.println(val);
  digitalWrite(ledPin, HIGH);
  
  delay(10000);
  digitalWrite(ledPin, LOW);
  delay(10000);

// Enter power down state for 8 s with ADC and BOD module disabled
LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 


}}