#include <Servo.h> 

char recv,speed_;

byte bluerobESC1PIN = 2; //Right
byte bluerobESC2PIN = 3; //Left
byte bluerobESC3PIN = 4; //Up
byte bluerobESC4PIN = 5; //Down
byte bluerobESC5PIN = 6; //Up
byte bluerobESC6PIN = 7; //Down
byte bluerobESC7PIN = 8; //Down
char B;
int resetPin = 7;


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
  //Serial.println("Ready");
   //digitalWrite(resetPin, HIGH);
  
  
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
 
  if(Serial.available()) {
    recv = Serial.read();
    if (recv == 'r'){  
        Serial.println(recv);
         digitalWrite(resetPin, LOW);
      }
    delay(30);
  }
  if(Serial.available()){
    speed_ = Serial.read();
      if(recv == 'F'){   //if serial receives FORWARD command, Run those ESCs with these speeds "pwm signals", 1700 is considered medium speed
          //Serial.println(recv);
          bluerobESC1.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);
          bluerobESC5.writeMicroseconds(1500);
          bluerobESC6.writeMicroseconds(1500);
      }
      else if(recv == 'S'){ //if serial receives STOP command, Run those ESCs with these speeds "pwm signals", 1500 is considered stop signal
          //Serial.println(recv);
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);
          bluerobESC5.writeMicroseconds(1500);
          bluerobESC6.writeMicroseconds(1500);
          bluerobESC7.writeMicroseconds(1500);
          
      }
      else if (recv == 'B'){ //if serial receives BACKWARD command, Run those ESCs with these speeds "pwm signals", 1300 is considered medium speed
          //Serial.println(recv);
          bluerobESC1.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);
          bluerobESC5.writeMicroseconds(1500);
          bluerobESC6.writeMicroseconds(1500);
      }
      else if (recv == 'R'){  //if serial receives RIGHT command, Run those ESCs with these speeds "pwm signals"
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);
      }
      else if (recv == 'L'){  //if serial receives LEFT command, Run those ESCs with these speeds "pwm signals"
          bluerobESC1.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds(1500);
          bluerobESC4.writeMicroseconds(1500);
      }
      else if (recv == 'U'){  //if serial receives UP command
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds((1500+(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500+(100*(speed_-'0'))));
          
      }
      else if (recv == 'W'){  //if serial receives DOWN command
          bluerobESC1.writeMicroseconds(1500);
          bluerobESC2.writeMicroseconds(1500);
          bluerobESC3.writeMicroseconds((1500-(100*(speed_-'0'))));
          bluerobESC4.writeMicroseconds((1500-(100*(speed_-'0'))));
      }
      /*else if (recv == 'T'){  //if serial receives FORWARDRIGHT command
        Serial.println(recv);
      }
      else if (recv == 'E'){  //if serial receives FORWARDLEFT command
        Serial.println(recv);
      }   */
      delay(30); 
  }
  /*
      if (recv == 'G'){  //if serial receives OPEN GRIPPER command, Run those ESCs with these speeds "pwm signals"
        Serial.println(recv);
      }
      else if (recv == 'g'){  //if serial receives CLOSE GRIPPER command, Run those ESCs with these speeds "pwm signals"
        Serial.println(recv);
      }
      else if (recv == 'A'){  //if serial receives AUTOMODE command, Run those ESCs with these speeds "pwm signals"
        Serial.println(recv);
      }
      else if (recv == 'M'){  //if serial receives RUN MICRO command, Run those ESCs with these speeds "pwm signals"
        Serial.println(recv);
      }
      else if (recv == 'm'){  //if serial receives STOP MICRO command, Run those ESCs with these speeds "pwm signals"
        Serial.println(recv);
      }
      else if (recv == 'P'){  //if serial receives CALCULATE SHAPES command
        Serial.println(recv);
      }
      else if (recv == 'D'){  //if serial receives DETECTED METAL command
        Serial.println(recv);
      }
      else if (recv == 'H'){  //if serial receives SCREENSHOT command
        Serial.println(recv);
      }
  delay(30);
  */
 }
