// ---------------------------------------------------------------------------
// Example  Support of GOOUUU TECH IOT-GA6-B Gprs Gsm Module 
// ---------------------------------------------------------------------------

#include <SoftwareSerial.h>


#define GSM_RX  2  // Arduino pin 2 to URX
#define GSM_TX  3  // Arduino pin 3 to URX

SoftwareSerial sim(GSM_RX, GSM_TX);  //
// The GSM

String number = "07905582XXX"; //-> change with your number




void setup() {
  Serial.begin(9600); // GPS on 0,1 pin
 
  Serial.println("System Started...");
  sim.begin(115200);
  delay(1000);
  
 Serial.println("Communicating GSM/GPS.....");
 
sms();   //send sms
call();   //call to us

}

void loop() {
 
 //do your code
 
} //loop

//-----------GSM Function ---------------------------------------------------------

void sms()
{
  Serial.println ("Sending Message");
  sim.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);
  Serial.println ("Set SMS Number");
  sim.println("AT+CMGS=\"" + number + "\"\r"); //Mobile phone number to send message
  delay(1000);
  String SMS = "Sample SMS is sending.....";   //sms content
  
   sim.println(SMS);
   
   delay(100);
  sim.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
 
}

void call() {
  sim.print (F("ATD"));
  sim.print (number);
  sim.print (F(";\r\n"));
 
  
}
  
