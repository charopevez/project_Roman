//************************************************** Roman settings
/** Load WLAN credentials from Preferences */
void loadSettings() {
  preferences.getInt("maxTry", maxTry);
  preferences.getLong("reconnectTime", reconnectTime);
  preferences.getString("ssid", ssid, sizeof(ssid));
  preferences.getString("password", password, sizeof(password));
  printf("Current settings\n");
  printf("SSID : %s, PASSWORD: %s\n", ssid, strlen(password)>0?"********":"<no password>");
  printf("MAX_TRY : %d, RECONNECT_TIME: %f\n", maxTry, reconnectTime);
}

/** Store WLAN credentials to Preference */
void saveSettings() {
  preferences.putInt("maxTry", maxTry);
  preferences.putLong("reconnectTime", reconnectTime);
  preferences.putString("ssid", ssid);
  preferences.putString("password", password);
  
  printf("New settings\n");
  printf("SSID : %s, PASSWORD: %s\n", ssid, strlen(password)>0?"********":"<no password>");
  printf("MAX_TRY : %d, RECONNECT_TIME: %f\n", maxTry, reconnectTime);
}
