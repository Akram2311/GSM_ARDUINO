#include<SoftwareSerial.h>

SoftwareSerial gsm(6,7);
void setup(){
Serial.begin(9600);
gsm.begin(9600);

}
void loop(){
  if(gsm.available()) // check if the connection is estsblish or not
  { Serial.write(gsm.read()); 
    }
  if(Serial.available()) // GSm establish connection then we are good to go
  {
    byte a =Serial.read();
    if(a=='$')
    {
      gsm.write((char)26); ///hexadeciaml value for Ctrl+z== to tell the GSM its the end of the message..
   
      }
    else{
      gsm.write(a);
      }
    }
   
  }


  //AT+CMGF=1 to start messaging service on gsm
  //AT+CMGS="+9195601XXXXX" Enter the no you want to send text message
  // than enter message followed by $.
  //IF get OK then our message is succesfully send..

  //AT+CNMI=2,2,0,0,0 if you want to receive message using GSM
