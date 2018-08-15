 #include <Servo.h>
#include<SoftwareSerial.h>
SoftwareSerial BT(11,12);
int serialA;

  //defining Servos
  Servo servohori;
  int servoh = 0;
  int servohLimitHigh = 160;
  int servohLimitLow = 20;
  
  Servo servoverti; 
  int servov = 0; 
  int servovLimitHigh = 160;
  int servovLimitLow = 20;
  //Assigning LDRs
  int ldrtopl = 2; //top left LDR green
  int ldrtopr = 1; //top right LDR yellow
  int ldrbotl = 3; // bottom left LDR blue
  int ldrbotr = 0; // bottom right LDR orange
  
   void setup () 
   {
    BT.begin(9600);
    servohori.attach(10);
    servohori.write(0);
    servoverti.attach(9);
    servoverti.write(0);
    delay(500);
   }
  
  void loop()
  {
     if (BT.available() > 2) {serialA = BT.read();Serial.println(serialA);
      {
    unsigned int servopos = BT.read();
    Serial.println(servopos); 
    
    if (servopos >= 1000 && servopos <1180){
    int servoh = servopos;
    servoh = map(servov, 1000,1180,0,180);
    servohori.write(servoh);
    Serial.println("servo 1 ON");
    delay(10);

    }
    
    if (servopos >=2000 && servopos <2180){
      int servov = servopos;
      servov = map(servoh,2000,2180,0,180);
      servoverti.write(servov);
      Serial.println("servo 2 On");
      delay(10);
    } 
   }
   }
 
  
  
  }
