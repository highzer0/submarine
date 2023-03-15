#include <Servo.h>
#include <math.h>
int command;

float min_PWM; //default arduino 544
float max_PWM; //default arduino 2400

float Pi = 3.141592653589793;

float X_End_Effector = 0; 
float Y_End_Effector; 
float Z_End_Effector; 

float Yoffset;
float D;
float d;
float R;

float L1 = 200.00; //height of the first link from surface to 2nd joint position
float L2 = 125.00; //length of the second link from 2nd joint to 3rd joint
float L3 = 125.50; //length of the 3rd joint to 4th joint
float L4 = 115.00; //length of the 4th joint to the tip of the arm (gripper)

float alpha1;
float alpha2;
float Theta_2;  
float Theta_4;   
float Theta_3;  

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo gripper; // chỉ chạy từ 0 tới 85!!!! 0 là mở, 85 là đóng

int ang1, ang2, ang3, ang4, anggripper;

void IK(){
    D = sqrt(pow(X_End_Effector,2) + pow(Z_End_Effector,2));
    d = D - L4;
    Yoffset = Y_End_Effector - L1;
    R = sqrt(pow(d,2) + pow(Yoffset,2));
    alpha1 = (acos(d/R))*(180.00/Pi);
    alpha2 = (acos((pow(L2,2) + pow(R,2) - pow(L3,2))/(2*L2*R)))*(180.00/Pi);
    Theta_2 = (alpha2 - alpha1); //theta 2
    Theta_3 = ((acos((pow(L2,2) + pow(L3,2) - pow(R,2))/(2*L2*L3)))*(180.00/Pi)); //theta 3
    Theta_4 = 180.00 - ((180.00 - (alpha2 + Theta_3)) + alpha1); //theta 4
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  servo1.attach(A0);
  servo2.attach(A1);
  servo3.attach(A2);
  servo4.attach(A3);
  gripper.attach(A4);
  
  servo1.writeMicroseconds(1500);
  servo2.writeMicroseconds(1500);
  servo3.writeMicroseconds(1500);
  servo4.writeMicroseconds(1500);
  gripper.writeMicroseconds(1500);

   gripper.write(85);
   ang1 = servo1.read();
   ang2 = servo2.read();
   ang3 = servo3.read();
   ang4 = servo4.read();
   for (ang4; ang4 >= 170; ang4--){
    servo4.write (ang4);
    delay (20);
   }
   for (ang4; ang4 < 170; ang4++){
    servo4.write (ang4);
    delay (20);
   }
  delay(100);

   for (ang3; ang3 >= 170; ang3--){
    servo3.write (ang3);
    delay (20);
  }
  for (ang3; ang3 < 170; ang3++){
    servo3.write (ang3);
    delay (20);
  }
 delay(100);
for (ang1; ang1 >= 150; ang1--){
    servo1.write (ang1);
    servo2.write (180-ang1);
    delay (20);
  }
  for (ang1; ang1 < 150; ang1++){
    servo1.write (ang1);
    servo2.write (180-ang1);
    delay (20);
  }
 
}

void loop() {
  if (Serial.available()>0){
    command = Serial.read();

    if (command == 'A'){
      ang1 = servo1.read();
      ang2 = servo2.read();
      servo1.write (ang1 + 5);
      servo2.write (ang2 - 5);
      ang1 += 5;
      ang2 -= 5;
      if (ang1 >= 180){
        ang1 = 180;
      }
      if (ang2 <= 0){
        ang2 = 0;
      }
    }
    else if (command == 'B'){
      ang1 = servo1.read();
      ang2 = servo2.read();
      servo1.write (ang1 - 5);
      servo2.write (ang2 + 5);
      ang1 -= 5;
      ang2 += 5;
      if (ang2 >= 180){
        ang2 = 180;
      }
      if (ang1 <= 0){
        ang1 = 0;
      }
    }  
    else if (command == 'C'){
      ang3 = servo3.read();
      servo3.write (ang3 - 5);
      ang3 -= 5;
      if (ang3 <= 0){
        ang3 = 0;
      }
    }
    else if (command == 'D'){
      ang3 = servo3.read();
      servo3.write (ang3 + 5);
      ang3 += 5;
      if (ang3 >= 180){
        ang3 = 180;
      }
    }
    else if (command == 'E'){
      ang4 = servo4.read();
      servo4.write (ang4 + 5);
      ang4 += 5;
      if (ang4 >= 180){
        ang4 = 180;
      }
    }
    else if (command == 'F'){
      ang4 = servo4.read();
      servo4.write (ang4 - 5);
      ang4 -= 5;
      if (ang4 <= 0){
        ang4 = 0;
      }
    }
    
    if (command == 'G'){ 
   gripper.write(85);
   ang1 = servo1.read();
   ang2 = servo2.read();
   ang3 = servo3.read();
   ang4 = servo4.read();
   for (ang4; ang4 >= 170; ang4--){
    servo4.write (ang4);
    delay (20);
  }
  for (ang4; ang4 < 170; ang4++){
    servo4.write (ang4);
    delay (20);
  }
  delay(200);

   for (ang3; ang3 >= 170; ang3--){
    servo3.write (ang3);
    delay (20);
  }
  for (ang3; ang3 < 170; ang3++){
    servo3.write (ang3);
    delay (20);
  }
 delay(200);
for (ang1; ang1 >= 150; ang1--){
    servo1.write (ang1);
     servo2.write (180-ang1);
    delay (20);
  }
  for (ang1; ang1 < 150; ang1++){
    servo1.write (ang1);
    servo2.write (180-ang1);
    delay (20);
  }
 
    }

    if (command == 'H'){ 
      Y_End_Effector = 0; 
      Z_End_Effector = 0; 
      IK();
    for (ang4; ang4 >= Theta_4+10; ang4--){
    servo4.write (ang4);
    delay (20);
  }
  for (ang4; ang4 < Theta_4+10; ang4++){
    servo4.write (ang4);
    delay (20);
  }
  delay(100);
  
    for (ang3; ang3 >= Theta_3; ang3--){
    servo3.write (ang3);
    delay (20);
  }
  for (ang3; ang3 < Theta_3; ang3++){
    servo3.write (ang3);
    delay (20);
  }
 delay(100);
 
 for (ang1; ang1 >= Theta_2; ang1--){
    servo1.write (ang1);
    servo2.write (180-ang1);
    delay (20);
  }
  for (ang1; ang1 < Theta_2; ang1++){
    servo1.write (ang1);
    servo2.write (180-ang1);
    delay (20);
  }
    }
    
    if (command == 'I'){
        anggripper = gripper.read();
        if (anggripper >= 85){
          for (anggripper; anggripper >= 0; anggripper--){
            gripper.write (anggripper);
            delay (10);
          }
        }
        else if (anggripper == 0 || anggripper < 85){
          for (anggripper; anggripper <= 85; anggripper++){
            gripper.write (anggripper);
            delay (10);
          }
        }
    } 
    
    if (command == 'K'){ 
      gripper.write(85);
      ang1 = servo1.read();
      ang2 = servo2.read();
      ang3 = servo3.read();
      ang4 = servo4.read();
    
      for (ang1; ang1 >= 160; ang1--){
       servo1.write (ang1);
       servo2.write (180-ang1);
       delay (20);
      }
      for (ang1; ang1 < 160; ang1++){
        servo1.write (ang1);
        servo2.write (180-ang2);
        delay (20);
      }
      delay(100);
      
      for (ang3; ang3 >= 170; ang3--){
        servo3.write (ang3);
        delay (20);
      }
      for (ang3; ang3 < 170; ang3++){
        servo3.write (ang3);
        delay (20);
      }
      delay(100);
      
      for (ang4; ang4 >= 170; ang4--){
        servo4.write (ang4);
        delay (20);
      }
      for (ang4; ang4 < 170; ang4++){
        servo4.write (ang4);
        delay (20);
      }
    } 
  }
}
