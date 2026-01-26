#define BLYNK_TEMPLATE_ID "TMPL3k4bRZD-x"
#define BLYNK_TEMPLATE_NAME "Baby Motion Alert System"
#define BLYNK_AUTH_TOKEN "KAepG6AvyP7LKtx-95rUl-7Ow7D1RNWe"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "Prachi"; 
char pass[] = "f2b2gdi8";

char auth[] = BLYNK_AUTH_TOKEN;

#define PIR_SENSOR 4

BlynkTimer timer;

void notifyOnMovement()
{
  int isMovement = digitalRead(PIR_SENSOR);
  Serial.print("PIR Status: ");
  Serial.println(isMovement);

  if (isMovement == HIGH)
  {
    Serial.println("Baby motion detected!");
    Blynk.logEvent("motion_alert", "Baby Motion Detected!");
  }
}

// Setup function
void setup()
{
  Serial.begin(115200);
  pinMode(PIR_SENSOR, INPUT);

  Serial.println("Connecting to WiFi...");
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, notifyOnMovement);
}

// Loop function
void loop()
{
  Blynk.run();
  timer.run();
}
