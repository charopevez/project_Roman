//****************************Declaration section********************

// servers
DNSServer dnsServer;
DNSServer portalServer;
AsyncWebServer server(80);

// AP credetials
char* ap_ssid = "ROMAN";
char* ap_password = "";
IPAddress apIP(1,1,1,1);
IPAddress netMsk(255, 255, 255, 0);

// DNS server
const byte DNS_PORT = 53;
char* HOST_NAME = "*";
//WiFi Credentals provided by user stored in preferences
Preferences preferences;
char ssid[32] = "";
char password[32] = "";

// WiFi mode variables
boolean standalone;
long lastConnectTry=0;
int status = WL_IDLE_STATUS; // current status
int maxTry; //stored in preferences
long reconnectTime; ///stored in preferences


String coctail;
String amount;
bool order_received = false;
bool amount_received = false;
