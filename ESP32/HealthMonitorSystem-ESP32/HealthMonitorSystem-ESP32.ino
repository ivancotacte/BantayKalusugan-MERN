#include <WiFiManager.h>
#include <LiquidCrystal_I2C.h>

char ssid[32];
char password[32];

WiFiManager wifiManager;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  displayMessage("Initializing...", "Please wait");
  wifiManager.autoConnect("ICCT San Mateo - AutoConnectAP");

  WiFi.begin(ssid, password);
}

void displayMessage(String line1, String line2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
}