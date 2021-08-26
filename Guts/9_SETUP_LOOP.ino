/*
 * Setup and Loop
 */

 void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  initWiFi();
  initWebSocket();
  initWebServer();
}
void loop() {
  ws.cleanupClients();
  //update status every @refresh period
   if ((millis() - started_at )% refresh ==0 ) 
      {
       notifyClients();
      }
  // check if there is an orders
  if (is_ready && currentOrders>0&&(millis() > order_start_time + order_time)){
        order_start_time= millis();
        make();
    }
}
