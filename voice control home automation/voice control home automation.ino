#define BLYNK_TEMPLATE_ID "TMPLOjMlJPPn"
#define BLYNK_TEMPLATE_NAME "Voice control Home Automation"
#define BLYNK_AUTH_TOKEN "BVHM8b7dSyd_i7LQrgGntrB9uPZsGb27"

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Flash";
char pass[] = "nopassword@";

BLYNK_WRITE(V0)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D5, LOW);
    Serial.println("turn on fan");
  }
  if(value == 0)
  {
    digitalWrite(D5,HIGH);
    Serial.println("turn off fan");
  }
}

BLYNK_WRITE(V1)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D6, LOW);
    Serial.println("turn on light");
  }
  if(value == 0)
  {
    digitalWrite(D6,HIGH);
    Serial.println("turn off light");
  }
}

BLYNK_WRITE(V2)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D7, LOW);
    Serial.println("turn on dream light");
  }
  if(value == 0)
  {
    digitalWrite(D7,HIGH);
    Serial.println("turn off dream light");
  }
}

BLYNK_WRITE(V3)
{
  int value = param.asInt();
  Serial.println(value);
  if(value == 1)
  {
    digitalWrite(D8, LOW);
    Serial.println("turn on room light");
  }
  if(value == 0)
  {
    digitalWrite(D8,HIGH);
    Serial.println("turn off room light");
  }
}


void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(D5,OUTPUT);
  pinMode(D6,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
}

void loop()
{
  Blynk.run();
  
}
