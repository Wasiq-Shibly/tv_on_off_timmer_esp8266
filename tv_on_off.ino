
//change file 
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
//1. Change the following info
#define WIFI_SSID "Super Home 8"
#define WIFI_PASSWORD "neways@12345"
#define FIREBASE_HOST "https://smarttv-b9325-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "Bnw62qhpYqlow4GyuamEjM6eLEjQdcOf4NhL0bMA"
int data;

FirebaseData fbdo;
int last_minute, hh, mm;
int last_hh, last_mm, timemin, timef, timer;


#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
const char *ssid     = "Super Home 8";
const char *password = "neways@12345";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
int currentHour, currentMinute;
bool check_status = true;

#include <Arduino.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>
const uint16_t kRecvPin = 14;

const uint16_t kIrLedPin = 4;


const uint32_t kBaudRate = 115200;


const uint16_t kCaptureBufferSize = 1024;  // 1024 == ~511 bits

const uint8_t kTimeout = 50;  // Milli-Seconds

const uint16_t kFrequency = 38000;  // in Hz. e.g. 38kHz.


IRsend irsend(kIrLedPin);

IRrecv irrecv(kRecvPin, kCaptureBufferSize, kTimeout, false);
// Somewhere to store the captured message.
decode_results results;

// This section of code runs only once at start-up.
void setup() {

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  //4. Enable auto reconnect the WiFi when connection lost
  Firebase.reconnectWiFi(true);





  irrecv.enableIRIn();  // Start up the IR receiver.
  irsend.begin();       // Start up the IR sender.

  Serial.begin(kBaudRate, SERIAL_8N1);
  while (!Serial)  // Wait for the serial connection to be establised.
    delay(50);
  Serial.println();

  Serial.print("SmartIRRepeater is now running and waiting for IR input "
               "on Pin ");
  Serial.println(kRecvPin);
  Serial.print("and will retransmit it on Pin ");
  Serial.println(kIrLedPin);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }


  timeClient.begin();
  timeClient.setTimeOffset(21600);


}

void loop() {

  check_time();
  database();
  timef = hh * 60 + mm;
  timer = currentHour * 60 + currentMinute;
  Serial.println(timef);
  Serial.println(timer);

  if ((timer - timef) > 35)
  {
    tv_on();
    run_app();
    Serial.println("need to turn on");

  }

  else
  {

    Serial.println("tv is ON");
  }




  if (24<currentHour >= 6 && data == 0  )
  {
    Serial.println("on funtion is called ");
    tv_on();
    run_app();
    //get firebase time
    //database();
    //check_time();
    
  }


  if (currentMinute == 0 &&  currentHour == 0 )
  {

    Serial.println("off funtion is called ");
    tv_off();
    check_status = true;
    Serial.println("waiting :::::::::::");
    delay(70000);
    Serial.println("waiting ::::::::::: end ");
  }


  yield();
}
