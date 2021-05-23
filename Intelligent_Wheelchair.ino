int BUZZER=52;
int BUTTON_buzzer=53;
int vibrationSensor=21;
int BUTTON_vibration
// Motor R1 connections
int enR1 = 2;
int in1 = 3;
int in2 = 4;

// Motor R2 connections
int enR2 = 6;
int in3 = 7;
int in4 = 5;

// Motor L1 connections
int enL1 = 44;
int in5 = 42;
int in6 = 43;

// Motor L2 connections
int enL2 = 46;
int in7 = 47;
int in8 = 48;

//Ultrasonic sensor right
#define echoPin1 14
#define trigPin1 15
long duration1;
int distanceright;

//Ultrasonic sensor left
#define echoPin2 16
#define trigPin2 17
long duration2;
int distanceleft;

//Ultrasonic sensor forward
#define echoPin3 18
#define trigPin3 19
long duration3;
int distanceforward;

String text;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
    pinMode(BUTTON_buzzer, INPUT);
    pinMode(vibrationSensor, OUTPUT);
    pinMode(BUTTON_vibration, INPUT);
    
    pinMode(enR1, OUTPUT);
    pinMode(enR2, OUTPUT);
    pinMode(enL1, OUTPUT);
    pinMode(enL2, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(in5, OUTPUT);
    pinMode(in6, OUTPUT);
    pinMode(in7, OUTPUT);
    pinMode(in8, OUTPUT);
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    digitalWrite(in5, LOW);
    digitalWrite(in6, LOW);
    digitalWrite(in7, LOW);
    digitalWrite(in8, LOW);

    pinMode(trigPin1,OUTPUT);
    pinMode(echoPin1,INPUT);
    pinMode(trigPin2,OUTPUT);
    pinMode(echoPin2,INPUT);
    pinMode(trigPin3,OUTPUT);
    pinMode(echoPin3,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin1,LOW);
delayMicroseconds(2);
digitalWrite(trigPin1,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1,LOW);
duration1=pulseIn(echoPin1,HIGH);
distanceright=(duration1*0.034/2);    //obstacle distance in right direction

digitalWrite(trigPin2,LOW);
delayMicroseconds(2);
digitalWrite(trigPin2,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2,LOW);
duration1=pulseIn(echoPin2,HIGH);
distanceleft=(duration2*0.034/2);   //obstacle distance in left direction

digitalWrite(trigPin3,LOW);
delayMicroseconds(2);
digitalWrite(trigPin3,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3,LOW);
duration1=pulseIn(echoPin3,HIGH);
distanceforward=(duration3*0.034/2);    //obstacle distance in forward direction


while(Serial.available()){
  delay(10);
  char c=Serial.read();
  text+=c;
}
if(text.length()>0)
{
  Serial.println(text);
  if(text=="right")
  { 
    if(distanceright<100){
    analogWrite(enR2, 255);
    analogWrite(enL1, 255);
    analogWrite(enR1, 0);
    analogWrite(enL2, 0);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    digitalWrite(in5, HIGH);
    digitalWrite(in6, LOW);
    }
  }
  if(text=="left")
    {
    if(distanceleft<100){
    analogWrite(enR1, 0);
    analogWrite(enL2, 0);
    analogWrite(enR2, 255);
    analogWrite(enL1, 255);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    digitalWrite(in5, LOW);
    digitalWrite(in6, HIGH);
    }
    }
    
   if(text=="forward")
    {
    if(distanceforward<100){
    analogWrite(enR1, 255);
    analogWrite(enL2, 255);
    analogWrite(enR2, 0);
    analogWrite(enL1, 0);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in7, HIGH);
    digitalWrite(in8, LOW);
    }
    }

    if(text=="backward")
    {
    analogWrite(enR1, 255);
    analogWrite(enL2, 255);
    analogWrite(enR2, 0);
    analogWrite(enL1, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in7, LOW);
    digitalWrite(in8, HIGH);
    }

    if(text=="stop"){
      
    analogWrite(enR1, 0);
    analogWrite(enL2, 0);
    analogWrite(enR2, 0);
    analogWrite(enL1, 0);

    }
 
  text="";
  buzzer_read=digitalRead(BUTTON_buzzer);
  if (buzzer_read==HIGH){
    digitalWrite(BUZZER,HIGH);
  }

  vibration_read=digitalRead(BUTTON_vibration);
  if (buzzer_read==HIGH){
    digitalWrite(vibrationSensor,HIGH);
  }
}
}
