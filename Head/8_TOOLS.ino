//**************************************************Roman's tools*********************************************
void ConnectToWLAN(){
  Serial.println("Connecting to WLAN...");
  WiFi.disconnect();
  WiFi.begin ( ssid, password );
  int connRes = WiFi.waitForConnectResult();
  Serial.print ( "connRes: " );
  Serial.println ( connRes );
}
