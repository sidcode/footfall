int ledPin = 9; // LED connected to digital pin 9
int c1,c2,c3,c4,c5=0; 
void setup()  { 
  
  Serial.begin(9600);
} 

void loop()  { 
  int s1,s2,s3,s4,s5;
  s1 = analogRead(A0);
  Serial.println("S1 "+ String(s1)); 
  delay(1);
  /*
  s2 = analogRead(A2);
  delay(1);
  s3 = analogRead(A3);
  delay(1);
  s4 = analogRead(A4);
  delay(1);
  s5 = analogRead(A5);
  delay(1);
  */
  /*Button press
  if()
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 

  // fade out from max to min in increments of 5 points:
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);         
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
*/
}

