//fruit Box health check
#include <SoftwareSerial.h>
#include<LiquidCrystal.h>
SoftwareSerial SIM900(7, 8);//7 rx 8 tx
LiquidCrystal lcd(12,11,2,3,4,5);
unsigned char j=0;
int x1, y1, z1;
const int bzr=13;
unsigned char x=0;
void setup() {
pinMode(bzr,OUTPUT);
digitalWrite(bzr,0);
lcd.begin(16,2);
Serial.begin(9600);
SIM900.begin(9600);
delay(2000)
lcd.clear();
lcd.setCursor(0,0);
lcd.print("GSM WEAPON ");
lcd.setCursor(0,1);
lcd.print("DETECTOR");
delay(3000);
}
void loop()
{
for(x=0;x<5;x++)
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("WAITING : ");
lcd.setCursor(0,1);
lcd.print("FOR WEAPON ");
int y=analogRead(1);
int z=analogRead(0);
y1=map(y,0,1023,200,0);
z1=map(z,0,1023,0,100);
delay(1000);
lcd.setCursor(13,0);
lcd.print(y1);
//lcd.setCursor(6,1);
//lcd.print(z1);
delay(1000);
}
if((y1>100))
{
digitalWrite(bzr,1);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("WEAPON DETECTED ");
lcd.setCursor(0,1);
lcd.print("DETECTED... ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("SMS Sending");
lcd.setCursor(0,1);
lcd.print("Wait ......");
delay(1000);
sendSMS();
}
else
{
digitalWrite(bzr,0);
delay(200);
}
}
// SUB FUNCTIONS
void sendSMS()
{
for(j=0;j<2;j++)
{
SIM900.print("AT+CMGF=1\r"); // AT command
to send SMS message
delay(1000);
if(j==0)
{
SIM900.println("AT+CMGS=\"+919515199511\""); // recipient's mobile number, in
international format
}
if(j==1)
{
SIM900.println("AT+CMGS=\"+916302515494\"");
}
delay(1000);
SIM900.print("WEAPON DETECTED IN THE BAG PLEASE CHECK. " );
// message to send
delay(1000);
SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
delay(1000);
41
SIM900.println();
delay(2000);
}
  

