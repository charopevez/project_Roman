void setupRoutes(){
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/html", index_html); 
      Serial.println("Client Connected");
  });
  server.on("/order", HTTP_GET, [] (AsyncWebServerRequest *request) {
      String inputMessage;
      String inputParam;
  
      if (request->hasParam("coctail")) {
        inputMessage = request->getParam("coctail")->value();
        inputParam = "coctail";
        coctail = inputMessage;
        Serial.println(inputMessage);
        order_received = true;
      }

      if (request->hasParam("amount")) {
        inputMessage = request->getParam("amount")->value();
        inputParam = "amount";
        amount = inputMessage;
        Serial.println(inputMessage);
        amount_received = true;
      }
      request->send(200, "text/html", "order recived <br><a href=\"/\">Return to Home Page</a>");
  });
  server.on("/X54PD", HTTP_GET, [] (AsyncWebServerRequest *request) {
          AsyncResponseStream *response = request->beginResponseStream("application/captive+json");

    DynamicJsonDocument doc(1024);
    doc["captive"] = true;
    doc["user-portal-url"] = "https://example.org/portal.html";
    doc["venue-info-url"] ="https://flight.example.com/entertainment";
    doc["expire-date"] = "2014-01-01T23:28:56.782Z";
    serializeJson(doc, *response);
    request->send(response);
  });
}
