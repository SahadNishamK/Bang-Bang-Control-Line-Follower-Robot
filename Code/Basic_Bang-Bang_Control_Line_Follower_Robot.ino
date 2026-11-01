/*


██╗███╗░░██╗███╗░░██╗░█████╗░██╗░░░██╗░█████╗░░█████╗░██████╗░███████╗
██║████╗░██║████╗░██║██╔══██╗██║░░░██║██╔══██╗██╔══██╗██╔══██╗╚════██║
██║██╔██╗██║██╔██╗██║██║░░██║╚██╗░██╔╝╚█████╔╝██║░░██║██████╔╝░░███╔═╝
██║██║╚████║██║╚████║██║░░██║░╚████╔╝░██╔══██╗██║░░██║██╔══██╗██╔══╝░░
██║██║░╚███║██║░╚███║╚█████╔╝░░╚██╔╝░░╚█████╔╝╚█████╔╝██║░░██║███████╗
╚═╝╚═╝░░╚══╝╚═╝░░╚══╝░╚════╝░░░░╚═╝░░░░╚════╝░░╚════╝░╚═╝░░╚═╝╚══════╝

Instagram: https://www.instagram.com/sahadnisham.k/
LinkedIn : https://www.linkedin.com/in/sahad-nisham-k/

*/

/*************************************************************************************************************
Basic Line Follower Robot using Bang - Bang Control
**************************************************************************************************************/

//L298N Motor Driver Pins

#define ENA 5
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENB 10

//IR Sensor Pins

#define IrSensorRight 3
#define IrSensorLeft 4

//Motor Speed
int RightMotorSpeed = 100; // Adjust according to your right motor speed
int LeftMotorSpeed = 100; // Adjust according to your left motor speed

void setup() {
  pinMode (ENA, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (ENB, OUTPUT);

  pinMode (IrSensorRight, INPUT);
  pinMode (IrSensorLeft, INPUT);

  analogWrite (ENA, RightMotorSpeed);
  analogWrite (ENB, LeftMotorSpeed);
}

void loop() {
  int IrSensorRightValue = digitalRead(IrSensorRight);
  int IrSensorLeftValue = digitalRead(IrSensorLeft);

  if(IrSensorRightValue == LOW && IrSensorLeftValue == LOW) {
    move_forward();
  }

  else if(IrSensorRightValue == HIGH && IrSensorLeftValue == LOW) {
    turn_left();
  }

  else if(IrSensorRightValue == LOW && IrSensorLeftValue == HIGH) {
    turn_right();
  }

  else {
    stop_robot();
  }
}

void move_forward() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void turn_right() {
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}

void turn_left() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}

void stop_robot() {
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
}
