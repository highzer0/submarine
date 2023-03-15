#define LF1 9
#define LF2 8
#define enLF 10
#define LB1 13
#define LB2 12
#define enLB 11
#define RF1 7
#define RF2 6
#define enRF 5
#define RB1 4
#define RB2 2
#define enRB 3

int Speed=130;
int command;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LB1,OUTPUT);
  pinMode(LB2,OUTPUT);
  pinMode(enLF,OUTPUT);
  pinMode(LF1,OUTPUT);
  pinMode(LF2,OUTPUT);
  pinMode(enLB,OUTPUT);
  pinMode(RB1,OUTPUT);
  pinMode(RB2,OUTPUT);
  pinMode(enRF,OUTPUT);
  pinMode(RF1,OUTPUT);
  pinMode(RF2,OUTPUT);
  pinMode(enRB,OUTPUT);
}
void forward() {
  digitalWrite(LF1,HIGH);
  digitalWrite(LF2,LOW);
  analogWrite(enLF,Speed);
  digitalWrite(RF1,HIGH);
  digitalWrite(RF2,LOW);
  analogWrite(enRF,Speed);
  digitalWrite(LB1,HIGH);
  digitalWrite(LB2,LOW);
  analogWrite(enLB,Speed);
  digitalWrite(RB1,HIGH);
  digitalWrite(RB2,LOW);
  analogWrite(enRB,Speed);
}

void back() {
  digitalWrite(LF1,LOW);
  digitalWrite(LF2,HIGH);
  analogWrite(enLF,Speed);
  digitalWrite(RF1,LOW);
  digitalWrite(RF2,HIGH);
  analogWrite(enRF,Speed);
  digitalWrite(LB1,LOW);
  digitalWrite(LB2,HIGH);
  analogWrite(enLB,Speed);
  digitalWrite(RB1,LOW);
  digitalWrite(RB2,HIGH);
  analogWrite(enRB,Speed);
}

void left() {
  digitalWrite(LF1,LOW);
  digitalWrite(LF2,HIGH);
  analogWrite(enLF,Speed);
  digitalWrite(RF1,HIGH);
  digitalWrite(RF2,LOW);
  analogWrite(enRF,Speed);
  digitalWrite(LB1,LOW);
  digitalWrite(LB2,HIGH);
  analogWrite(enLB,Speed);
  digitalWrite(RB1,HIGH);
  digitalWrite(RB2,LOW);
  analogWrite(enRB,Speed);
}

void right() {
  digitalWrite(LF1,HIGH);
  digitalWrite(LF2,LOW);
  analogWrite(enLF,Speed);
  digitalWrite(RF1,LOW);
  digitalWrite(RF2,HIGH);
  analogWrite(enRF,Speed);
  digitalWrite(LB1,HIGH);
  digitalWrite(LB2,LOW);
  analogWrite(enLB,Speed);
  digitalWrite(RB1,LOW);
  digitalWrite(RB2,HIGH);
  analogWrite(enRB,Speed);
}
void forwardleft() {
  digitalWrite(LF1,HIGH);
  digitalWrite(LF2,LOW);
  analogWrite(enLF,Speed/3);
  digitalWrite(RF1,HIGH);
  digitalWrite(RF2,LOW);
  analogWrite(enRF,Speed);
  digitalWrite(LB1,HIGH);
  digitalWrite(LB2,LOW);
  analogWrite(enLB,Speed/3);
  digitalWrite(RB1,HIGH);
  digitalWrite(RB2,LOW);
  analogWrite(enRB,Speed);
}
void forwardright() {
  digitalWrite(LF1,HIGH);
  digitalWrite(LF2,LOW);
  analogWrite(enLF,Speed);
  digitalWrite(RF1,HIGH);
  digitalWrite(RF2,LOW);
  analogWrite(enRF,Speed/3);
  digitalWrite(LB1,HIGH);
  digitalWrite(LB2,LOW);
  analogWrite(enLB,Speed);
  digitalWrite(RB1,HIGH);
  digitalWrite(RB2,LOW);
  analogWrite(enRB,Speed/3);
}
void backright() {
  digitalWrite(LF1,LOW);
  digitalWrite(LF2,HIGH);
  analogWrite(enLF,Speed);
  digitalWrite(RF1,LOW);
  digitalWrite(RF2,HIGH);
  analogWrite(enRF,Speed/3);
  digitalWrite(LB1,LOW);
  digitalWrite(LB2,HIGH);
  analogWrite(enLB,Speed);
  digitalWrite(RB1,LOW);
  digitalWrite(RB2,HIGH);
  analogWrite(enRB,Speed/3);
}
void backleft() {
  digitalWrite(LF1,LOW);
  digitalWrite(LF2,HIGH);
  analogWrite(enLF,Speed/3);
  digitalWrite(RF1,LOW);
  digitalWrite(RF2,HIGH);
  analogWrite(enRF,Speed);
  digitalWrite(LB1,LOW);
  digitalWrite(LB2,HIGH);
  analogWrite(enLB,Speed/3);
  digitalWrite(RB1,LOW);
  digitalWrite(RB2,HIGH);
  analogWrite(enRB,Speed);
}

void Stop() {
  digitalWrite(LF1,LOW);
  digitalWrite(LF2,LOW);
  analogWrite(enLF,0);
  digitalWrite(RF1,LOW);
  digitalWrite(RF2,LOW);
  analogWrite(enRF,0);
  digitalWrite(LB1,LOW);
  digitalWrite(LB2,LOW);
  analogWrite(enLB,0);
  digitalWrite(RB1,LOW);
  digitalWrite(RB2,LOW);
  analogWrite(enRB,0);
}
void loop() {
//+   put your main code here, to run repeatedly:
if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); //Initialize with motors stoped.
//set direction
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
//set speed
      case '1':
        Speed = 130;
        break;
      case '2':
        Speed = 145;
        break;
      case '3':
        Speed = 160;
        break;
      case '4':
        Speed = 175;
        break;
      case '5':
        Speed = 190;
        break;
      case '6':
        Speed = 205;
        break;
      case '7':
        Speed = 220;
        break;
      case '8':
        Speed = 235;
        break;
      case '9':
        Speed = 245;
        break;
      case 'q':
        Speed = 255;
        break;
    
    }
  }
}
