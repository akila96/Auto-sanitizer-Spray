#include <Ultrasonic.h>

Ultrasonic ultrasonic1(2, 3); 
Ultrasonic ultrasonic2(5, 6);   

int distance1, distance2;

int led1 = A0;
int led2 = A1;
int led3 = A2;
int led4 = A3;
int led5 = A4;

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);

  pinMode(12, INPUT);
  pinMode(10, OUTPUT);
}

void loop() {

  distance1 = ultrasonic1.read("CM");
  distance2 = ultrasonic2.read("CM");

  if (distance1 > 20) {
    digitalWrite(8, LOW);
  } else {
    digitalWrite(8, HIGH);
  }

  Serial.print("distance 1 :");
  Serial.print(distance1);
  Serial.print(" distance 2 :");
  Serial.print(distance2);
  Serial.println();

  /////////////////////////////////////////////////////////////////////////////

  if (  (distance2 > 0) && (distance2 <= 5)   )
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  } 
  
  else if (  (distance2 > 5) && (distance2 <= 8)  )
  {

    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);

  } else

    if (  (distance2 > 8) && (distance2 <= 10)  )
    {

      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
    } else

      if (  (distance2 > 10) && (distance2 <= 13)  )
      {

       digitalWrite(led1, LOW);
       digitalWrite(led2, LOW);
       digitalWrite(led3, LOW);
       digitalWrite(led4, HIGH);
       digitalWrite(led5, HIGH);
      } else

        if (  (distance2 > 13) && (distance2 <= 15)  )
        {

        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        digitalWrite(led5, HIGH);
        } else

          if ( distance2 > 15 )
          {

         digitalWrite(led1, LOW);
         digitalWrite(led2, LOW);
         digitalWrite(led3, LOW);
         digitalWrite(led4, LOW);
         digitalWrite(led5, LOW);
          }
 /////////////////////////////////////////////////////////////////////////////////////////         
  if (digitalRead(12) == HIGH) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }

  delay(1000);
}
