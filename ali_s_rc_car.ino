#include <IRremote.h>
const int RECV_PIN=14;
IRrecv irrecv(RECV_PIN);
decode_results results;
int a=0, b=0, c=0, d=0;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  irrecv.blink13(true);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() 
{
  if (irrecv.decode(&results)) 
   {
     Serial.println(results.value);


     if (results.value!=4294967295) //No Multiple Pressed Button
     {
      
        if (results.value==16718055){ //Forward
           c=1;
           a=0;
           b=0;
           d=0;
           Serial.println("FORWARD");
        }
        else if (results.value==16730805){ //Backward
           d=1;
           c=0;
           b=0;
           a=0;
           Serial.println("BACKWARD");
        }
        else if (results.value==16724175){ //Forward and Left
           a=1;
           c=1;
           b=0;
           d=0;
           Serial.println("FORWARD & LEFT");
           
        }
        else if (results.value==16743045){ //Farward and Right
           b=1;
           c=1;
           a=0;
           d=0;
           Serial.println("FORWARD & RIGHT");
        }
        else if (results.value==16728765){ //Backward and Left
           b=1;
           c=1;
           a=0;
           d=0;
           Serial.println("BACKWARD & LEFT");
        }
        else if (results.value==16732845){ //Backward and Right
           b=1;
           c=1;
           a=0;
           d=0;
           Serial.println("BACKWARD & RIGHT");
        }
        else //Stop on any unwanted signal
        {
          a=0;
          b=0;
          c=0;
          d=0;
          Serial.println("ERROR 404");
        }

        digitalWrite(8, a);
        digitalWrite(9, b);
        digitalWrite(10, c);
        digitalWrite(11, d);
     }
     else {  //Multiple Pressed Button
        digitalWrite(8, a);
        digitalWrite(9, b);
        digitalWrite(10, c);
        digitalWrite(11, d);
        Serial.println("CONTINUE PREVIOUS COMMAND");
     }
     irrecv.resume(); // Receive the next value
     }
     }
