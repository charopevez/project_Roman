//******************************** SETUP ********************************************

void setup(){
  // initialize serial
  Serial.begin(115200);
  Serial.println();
  // setting AP
  Serial.println("Setting up AP Mode");
  WiFi.mode(WIFI_AP); 
  WiFi.softAPConfig(apIP, apIP, netMsk);
  WiFi.softAP(ap_ssid, ap_password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());

  //setting web server
  Serial.println("Setting up Async WebServer");
  setupRoutes();
  //setting dns server
  Serial.println("Setting up DNS Server");
  portalServer.start(DNS_PORT, HOST_NAME, apIP);
  //setup handlers
  server.addHandler(new CaptiveRequestHandler()).setFilter(ON_AP_FILTER);//only when requested from AP
  //check settings
  loadSettings();
  standalone = !strlen(ssid) > 0; // Request WLAN connect if there is a user credentials
  server.begin();
  Serial.println("All Done!");
}
