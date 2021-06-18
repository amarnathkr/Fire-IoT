#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;
char auth[] = "ABh-xoJWXLdCJtJ3PW_8R2F7tFGAq88v"; //Auth code sent via Email
char ssid[] = "let's go"; //Wifi name
char pass[] = "12345678";  //Wifi Password
int flag=0;
void notifyOnFire()
{
  int isButtonPressed = digitalRead(1);
  if (isButtonPressed==1 && flag==0) {
    Serial.println("Please bhai bura lagta hai bhai");
    Blynk.notify("kaha ho bsdk😒?? aag🔥 lagi hai😰");
    flag=1;
  }
  else if (isButtonPressed==0)
  {
    flag=0;
  }
}
void setup()
{
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
pinMode(1,INPUT_PULLUP);
timer.setInterval(1000L,notifyOnFire); 
}
void loop()
{
  Blynk.run();
  timer.run();
}

