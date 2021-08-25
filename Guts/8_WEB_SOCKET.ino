/*
 * initialize Web Socket
 */


 
void notifyClients() {
    const int capacity = JSON_ARRAY_SIZE(10)+JSON_ARRAY_SIZE(2);
    StaticJsonDocument<capacity> doc;
    if (currentOrders>0) {
      doc["status"]="Making coctails";
      doc["orders"]=currentOrders;
      for (int i; i<10; i++){
        if (order_ids[i]!=0) {
          doc[keys[i]]=order_ids[i];
        }
      }
    } else {
      doc["status"]="Waiting for order";
    }
    Serial.printf("Making %d orders\n", currentOrders);
    char output[200];
    serializeJson(doc, output);
    ws.textAll(output);
}

void notifyClient(uint8_t id, String message) {

  ws.text(id, message);
}

void handleWebSocketMessage(void *arg, uint8_t *data, size_t len, uint8_t client_id) {
    AwsFrameInfo *info = (AwsFrameInfo*)arg;
    if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
      Serial.printf("message from [%u]\n", client_id);
        const uint8_t size = JSON_OBJECT_SIZE(3);
        StaticJsonDocument<size> doc;
        DeserializationError err = deserializeJson(doc, data);
        if (err) {
            Serial.print(F("deserializeJson() failed with code "));
            Serial.println(err.c_str());
            return;
        }
        //check action
        const char *action = doc["action"];
        if (strcmp(action, "order") == 0) {
          //if recived order
            ledState = !ledState; // visualisation ONLY
            const char *action = doc["action"];
            Serial.printf("New order \n");
            serializeJson(doc, Serial);
            const char *order = doc["order"];
            add_order_to_line(atoi(order));
            notifyClient(client_id, String(ledState));
            notifyClients();
        }
      }
}

void onEvent(AsyncWebSocket       *server,
             AsyncWebSocketClient *client,
             AwsEventType          type,
             void                 *arg,
             uint8_t              *data,
             size_t                len) {

    switch (type) {
        case WS_EVT_CONNECT:
            Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
            break;
        case WS_EVT_DISCONNECT:
            Serial.printf("WebSocket client #%u disconnected\n", client->id());
            break;
        case WS_EVT_DATA:
            handleWebSocketMessage(arg, data, len, client->id());
            break;
        case WS_EVT_PONG:
        case WS_EVT_ERROR:
            break;
    }
}
void initWebSocket() {
    ws.onEvent(onEvent);
    server.addHandler(&ws);
}
