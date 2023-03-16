#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0
void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, INPUT);
}
 
void motor_1_Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
void motor_2_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
void motor_3_Dung() {
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}
void motor_4_Dung() {
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}
 
 
void motor_1_Lui(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);// chân này không có PWM
  analogWrite(IN2, 255 - speed);
}
 
void motor_1_Tien(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
        // aaaaaaaa

void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN3, speed);
  digitalWrite(IN4, LOW);// chân này không có PWM
}
void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN3, 255 - speed);
  digitalWrite(IN4, HIGH);// chân này không có PWM
}

        // aaaaaaaa
void motor_3_Lui(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(8, HIGH);// chân này không có PWM
  analogWrite(9, 255 - speed);
}
void motor_3_Tien(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(8, LOW);// chân này không có PWM
  analogWrite(9, speed);
}

        // aaaaaaaa
void motor_4_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(10, speed);
  digitalWrite(11, LOW);// chân này không có PWM
}
void motor_4_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(10, 255 - speed);
  digitalWrite(11, HIGH);// chân này không có PWM
}

void loop()
{
if(digitalRead(2) == HIGH){
  motor_1_Tien(MAX_SPEED - 26); // motor 1 tiến
  motor_2_Tien(MAX_SPEED - 26); // motor 2 tiến
  motor_3_Tien(MAX_SPEED - 14); // motor 3 tiến
  motor_4_Tien(MAX_SPEED - 39); // motor 4 tiến
} else {
  motor_1_Lui(MAX_SPEED -26); //motor 1 lùi
  motor_2_Lui(MAX_SPEED - 26); //motor 2 lùi
  motor_3_Lui(MAX_SPEED - 14); //motor 3 lùi
  motor_4_Lui(MAX_SPEED - 39); //motor 4 lùi
  }
}
