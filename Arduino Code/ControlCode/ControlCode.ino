#include <Servo.h> 

char recv,speed_;
char B;
int resetPin = 12;

byte bluerobESC1PIN = 6; //HorizontalRightFront_(R1)
byte bluerobESC2PIN = 9; //HorizontalRightBack_(R2)
byte bluerobESC3PIN = 3; //HorizontalLeftFront_(L1)
byte bluerobESC4PIN = A0; //HorizontalLeftBack_(L2)
byte bluerobESC5PIN = 11; //VerticalRight_(V1)
byte bluerobESC6PIN = 5; //VerticalLeft_(V2)
byte bluerobESC7PIN = 10; //VerticalTail_(V3)

Servo bluerobESC1; 
Servo bluerobESC2; 
Servo bluerobESC3; 
Servo bluerobESC4; 
Servo bluerobESC5; 
Servo bluerobESC6; 
Servo bluerobESC7;



void setup() {
  B=0;
  Serial.begin(9600);
  Serial.println("Ready");
  digitalWrite(resetPin, HIGH);
  
  
  bluerobESC1.attach(bluerobESC1PIN);
  bluerobESC2.attach(bluerobESC2PIN);
  bluerobESC3.attach(bluerobESC3PIN);
  bluerobESC4.attach(bluerobESC4PIN);
  bluerobESC5.attach(bluerobESC5PIN);
  bluerobESC6.attach(bluerobESC6PIN);  
  bluerobESC7.attach(bluerobESC7PIN);


  //stopping signals "essential" at the beginning
  bluerobESC1.writeMicroseconds(1500);
  bluerobESC2.writeMicroseconds(1500);
  bluerobESC3.writeMicroseconds(1500);
  bluerobESC4.writeMicroseconds(1500);
  bluerobESC5.writeMicroseconds(1500);
  bluerobESC6.writeMicroseconds(1500);
  bluerobESC7.writeMicroseconds(1500);


  //delay to allow the ESCs to recognize the stopped signal
  delay(2000);
pinMode(resetPin, OUTPUT);

}
 
 
 void loop() {
 
  if(Serial.available()) {//Restart
    
    recv = Serial.read();
    if (recv == 'r'){  
       // Serial.println(recv);
         digitalWrite(resetPin, LOW);
      }
    delay(30);
  }
  
  
  if(Serial.available()){
    speed_ = Serial.read();
      if(recv == 'F'){   //if serial receives FORWARD command
          //Serial.println(recv);

          
          //Horizontal Motors
          bluerobESC1.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500+(100*(speed_-'0'))));

          //Vertical Motors
          bluerobESC5.writeMicroseconds(1200);
          bluerobESC6.writeMicroseconds(1200);
          bluerobESC7.writeMicroseconds(1650);
      }
      

      else if (recv == 'B'){ //if serial receives BACKWARD command
         // Serial.println(recv);
          
          //Horizontal Motors
          bluerobESC1.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500-(100*(speed_-'0'))));

          //Vertical Motors
          bluerobESC5.writeMicroseconds(1200);
          bluerobESC6.writeMicroseconds(1200);
          bluerobESC7.writeMicroseconds(1650);
      }
     
      
      else if(recv == 'S'){ //if serial receives STOP command
         // Serial.println(recv);
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);
          bluerobESC5.writeMicroseconds(1500);
          bluerobESC6.writeMicroseconds(1500);
          bluerobESC7.writeMicroseconds(1500);
          
      }
     
     
      else if (recv == 'R'){  //if serial receives RIGHT command
         // Serial.println(recv);
          //Horizontal Motors
          bluerobESC1.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500-(100*(speed_-'0'))));

          //Vertical Motors
          bluerobESC5.writeMicroseconds(1200);
          bluerobESC6.writeMicroseconds(1200);
          bluerobESC7.writeMicroseconds(1650);
      }
     
      
      else if (recv == 'L'){  //if serial receives LEFT command
       // Serial.println(recv);
         //Horizontal Motors
          bluerobESC1.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500+(100*(speed_-'0'))));

          //Vertical Motors
          bluerobESC5.writeMicroseconds(1200);
          bluerobESC6.writeMicroseconds(1200);
          bluerobESC7.writeMicroseconds(1650);
      }
     
       else if (recv == 'T'){  //if serial receives RotateRight command
      //  Serial.println(recv);
          //Horizontal Motors
          bluerobESC1.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500+(100*(speed_-'0'))));

          //Vertical Motors
          bluerobESC5.writeMicroseconds(1200);
          bluerobESC6.writeMicroseconds(1200);
          bluerobESC7.writeMicroseconds(1650);
          
      }
      
      
      else if (recv == 'O'){  //if serial receives RotateLeft command
       // Serial.println(recv);
           //Horizontal Motors
          bluerobESC1.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500-(100*(speed_-'0'))));

          //Vertical Motors
          bluerobESC5.writeMicroseconds(1200);
          bluerobESC6.writeMicroseconds(1200);
          bluerobESC7.writeMicroseconds(1650);
      }

      
      else if (recv == 'U'){  //if serial receives UP command
      //  Serial.println(recv);
          //Horizontal Motors
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);

          //Vertical Motors
          bluerobESC5.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC6.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC7.writeMicroseconds(1400);
          
      }
      
      
      else if (recv == 'D'){  //if serial receives DOWN command
        //Serial.println(recv);
          //Horizontal Motors
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);

          //Vertical Motors
          bluerobESC5.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC6.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC7.writeMicroseconds(1650);
      }


     else if (recv == 'd'){  //if serial receives Down three motors
     // Serial.println(recv);
          //Horizontal Motors
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);

          //Vertical Motors
          bluerobESC5.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC6.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC7.writeMicroseconds((1500+(100*(speed_-'0'))));
      }
       else if (recv == 'u'){  //if serial receives UP three motors command
       // Serial.println(recv);
          //Horizontal Motors
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);

          //Vertical Motors
          bluerobESC5.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC6.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC7.writeMicroseconds((1500-(100*(speed_-'0'))));
          
      }
      delay(30); 
  }
  /*
      if (recv == 'G'){  //if serial receives OPEN GRIPPER command, Run those ESCs with these speeds "pwm signals"
        Serial.println(recv);
      }
      else if (recv == 'g'){  //if serial receives CLOSE GRIPPER command, Run those ESCs with these speeds "pwm signals"
        Serial.println(recv);
      }s
      else if (recv == 'D'){  //if serial receives DETECTED METAL command
        Serial.println(recv);
      }
      else if (recv == 'H'){  //if serial receives SCREENSHOT command
        Serial.println(recv);
      }
  delay(30);
  */
 }
