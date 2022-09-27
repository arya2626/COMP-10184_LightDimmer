// Mohawk College - COMP-10184 

//I, Arya Bhoiwala, student number 000828466, certify that this material is my original work. 
//No other person's work has been used without due acknowledgment and I have not made my work available to anyone else.

#include <Arduino.h> 

 byte recentbtnstate = HIGH;
 byte lightstate = HIGH;
 int iVal;

  void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
  digitalWrite(D4, HIGH);
 
// configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
}
 
 
void loop()
{ 

  //Identifying what state button is in right now
  byte buttonState = digitalRead(D5);
  if (buttonState != recentbtnstate) {
    recentbtnstate = buttonState;
    // Switching the button state
    if (buttonState == LOW) {
      // This will change the state of the light 
      lightstate = (lightstate == HIGH) ? LOW: HIGH;
      digitalWrite(D4, lightstate);
    }

  }

if (lightstate == LOW){
  // read digitized value from the D1 Mini's A/D convertor 
  // defined and used from the LAB 2
    iVal = analogRead(A0);
    // defining the width of the PWM pulse
    analogWrite(D4, iVal);
}
   else{
    // this will turn of the light
      digitalWrite(D4, 1);
  }
//Delaying it for 1ms
  delay(1);
}

