
 
 #include <SoftwareSerial.h>

SoftwareSerial gsm(6,7);

void setup()
{
  gsm.begin(9600);   //  baud rate of GSM Module  
  Serial.begin(9600);    //  baud rate of Arduino
  delay(100);
}


void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      gsm.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(100);   
     gsm.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace x with mobile number
     delay(100);
     gsm.println("Its GSM");// The SMS text you want to send
     delay(100);
     gsm.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
      delay(100);
      break;



      
    case 'r':
      gsm.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
      delay(100);
      break;
  }

 if (gsm.available()>0)
   Serial.write(gsm.read());
}
