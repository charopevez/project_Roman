/**
 * ----------------------------------------------------------------------------
 * Roman's GUTS 
 * ----------------------------------------------------------------------------
 * Arduino based bartender's controller
 * ----------------------------------------------------------------------------
 * © 2021 Mikhaylov Dmitry
 * ----------------------------------------------------------------------------
 */
#include <Arduino.h>
//#include <SPIFFS.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <Preferences.h>

// ----------------------------------------------------------------------------
// Definition of macros
// ----------------------------------------------------------------------------
#define LED_PIN   4
#define HTTP_PORT 80


// ----------------------------------------------------------------------------
// Definition of global constants
// ----------------------------------------------------------------------------

// WiFi credentials
const char *WIFI_SSID = "charopevezWiFi";
const char *WIFI_PASS = "08085125398";

// Romans HEAD credentials
const char *HEAD_SSID = "ROMAN";
const char *HEAD_PASS = "";

// ADMIN credentials
const char *USERNAME = "admin";
const char *PASSWORD = "admin";

// Guts NETWORK
IPAddress gutsIP(192, 168, 43, 87); //ToDo init in HEAD
IPAddress gateway(192, 168, 43, 87);  //ToDo init in HEAD
IPAddress subnet(255, 255, 0, 0);   //ToDo init in HEAD
IPAddress primaryDNS(8, 8, 8, 8);   //ToDo init in HEAD
IPAddress secondaryDNS(8, 8, 4, 4); //ToDo init in HEAD


// ----------------------------------------------------------------------------
// Definition of the Coctail component
// ----------------------------------------------------------------------------


// ----------------------------------------------------------------------------
// Definition of the Orders line component
// ----------------------------------------------------------------------------

int order_ids[]={0,0,0,0,0,0,0,0,0,0};
boolean order_status[10]; 
int order[10];
const char* keys[] = {
    "first_in_line",
    "2nd_in_line",
    "3rd_in_line",
    "4th_in_line",
    "5th_in_line",
    "6th_in_line",
    "7th_in_line",
    "8th_in_line",
    "9th_in_line",
    "10th_in_line"
};
// ----------------------------------------------------------------------------
// Definition of global variables
// ----------------------------------------------------------------------------


AsyncWebServer server(HTTP_PORT);
AsyncWebSocket ws("/ws");


unsigned long started_at; //turn on time
const unsigned long refresh = 1*15*1000UL;
const unsigned long order_time = 1*30*1000UL;



int order_id=1;
int currentOrders=0;
boolean is_ready=true;

bool ledState = 0;
const int ledPin = 4;
// ----------------------------------------------------------------------------
// initialize WiFi network
// ----------------------------------------------------------------------------

void initWiFi(){
  
  WiFi.mode(WIFI_STA);
  // try to configure static IP address
  if (!WiFi.config(gutsIP, gateway, subnet)) {
    Serial.println("WiFi-STA Failed to configure");
  }
  // check if there is a wifi config
  boolean connectToWLAN=strlen(WIFI_SSID) > 0; 
  if (connectToWLAN) {
    //if WLAN credecntials provided
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    Serial.printf("Trying to connect [%s] ", WIFI_SSID);
  }else{
    //if no WLAN credentials connect to ROMAN_HEAD
    WiFi.begin(HEAD_SSID, HEAD_PASS);
    Serial.printf("Trying to connect [%s] ", HEAD_SSID);
  }
  
  while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
  }
  Serial.printf(" Connected\n");
  Serial.printf(" %s\n", WiFi.localIP().toString().c_str());
  Serial.printf(" %s\n", WiFi.gatewayIP().toString().c_str());
  Serial.printf(" %s\n", WiFi.subnetMask().toString().c_str());
}
