class CaptiveRequestHandler : public AsyncWebHandler {
public:
  CaptiveRequestHandler() {}
  virtual ~CaptiveRequestHandler() {}

  bool canHandle(AsyncWebServerRequest *request){
    //request->addInterestingHeader("ANY");
    return true;
  }

  void handleRequest(AsyncWebServerRequest *request) {
    //AsyncResponseStream *response = request->beginResponseStream("application/captive+json");

    //DynamicJsonDocument doc(1024);
    //doc["captive"] = false;
    //doc["user-portal-url"] = "https://1.1.1.1/page.html";
    //doc["venue-info-url"] ="https://1.1.1.1/";
    //serializeJson(doc, *response);
    //request->send(response);

    request->send_P(200, "text/html", index_html); 
  }
};
