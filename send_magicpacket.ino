#define BLYNK_TEMPLATE_ID "TMPL3WLA9P8P0"
#define BLYNK_TEMPLATE_NAME "Demo"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <WakeOnLan.h> // Import the WakeOnLan library

char auth[] = "haJDVw6TIMNxS-wcdaLKWyxhhk2vV3Qw";
char ssid[] = "FTTH-B739";
char pass[] = "12345678";

#define TRIGGER_PIN V0 // Change this to the virtual pin you assigned in the Blynk app
#define TARGET_MAC "84:a9:3e:92:a0:9d" // MAC address of the target device

// Create a global instance of WiFiUDP
WiFiUDP udp;

// Create an instance of the WakeOnLan class
WakeOnLan WOL(udp);

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, INPUT_PULLUP); // Set trigger pin as input with internal pull-up resistor
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();
}

BLYNK_WRITE(TRIGGER_PIN) {
  int triggerValue = param.asInt();
  
  if (triggerValue == 1) {
    // Send the magic packet using the instance of WakeOnLan
    WOL.sendMagicPacket(TARGET_MAC);
    Serial.println("Magic packet sent to target device");
  }
}
