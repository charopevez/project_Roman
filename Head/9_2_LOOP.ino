//******************************** LOOP ********************************************
void loop(){
  // try to connect to wlan
    if (!standalone) {
    Serial.println ( "Connect requested" );
    standalone = true;
    ConnectToWLAN();
    lastConnectTry = millis();
  }
  {
    int s = WiFi.status();
    if (s == 0 && millis() > (lastConnectTry + reconnectTime) ) {
      standalone = false;
    }
    if (status != s) { // WLAN status change
      Serial.print ( "Status: " );
      Serial.println ( s );
      status = s;
      if (s == WL_CONNECTED) {
        /* Just connected to WLAN */
        Serial.println ( "" );
        Serial.print ( "Connected to " );
        Serial.println ( ssid );
        Serial.print ( "IP address: " );
        Serial.println ( WiFi.localIP() );
      } else if (s == WL_NO_SSID_AVAIL) {
        WiFi.disconnect();
      }
    }
  }
  
  portalServer.processNextRequest();
  if(order_received && amount_received){
      Serial.print("coctail ");Serial.println(coctail);
      Serial.print("amount ");Serial.println(amount);
      order_received = false;
      amount_received = false;
      Serial.println("We'll wait for the next order now");
    }
}
