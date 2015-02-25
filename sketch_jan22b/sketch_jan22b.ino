#include <Adafruit_NeoPixel.h>
#define NUMPIXELS      1

/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.
 
 This example code is in the public domain.
 */
 
 #define F0 12
 
int fadeValue = 0;
unsigned long t2;
int time = 0;
unsigned long off2;
unsigned long on2;
unsigned long diff;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, F0, NEO_GRB + NEO_KHZ800);


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  //pinMode(13, OUTPUT);
  pixels.begin();
  Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read the input on analog pin 0:
  //int s1 = analogRead(A0);
  int s2 = analogRead(A4);
  
  /*
  Serial.print("Time: ");
  time = millis();
  Serial.println(time);
  */
   if(s2 >200)
  {
     off2 = millis();
     //pixels.setPixelColor(0, pixels.Color(150,150,0));
     //pixels.show(); // This sends the updated pixel color to the hardware.
   //  delay(100); 
    //digitalWrite(13, LOW);
    /*
    if(fadeValue<5)
    {
      fadeValue=0;
    }
    else
    {
      fadeValue-=5;
      delay(10);
    }
    */
  }
  else
  {  on2=millis();
  
     //pixels.setPixelColor(0, pixels.Color(0,150,150));
     //pixels.show(); // This sends the updated pixel color to the hardware.
    //delay(100); // Delay for a period of time (in milliseconds).
    /*
    if(fadeValue>250)
    {
      fadeValue = 255;
    }
    else
    {
      fadeValue+=1;
      delay(10);
    }
    */
  }
  
  time = millis();
  diff = time - off2;
  
  if(diff > 10000)
  {
    pixels.setPixelColor(0, pixels.Color(150,0,0));
     pixels.show(); 
  }
  else if(diff > 7000){
     pixels.setPixelColor(0, pixels.Color(0,150,150));
     pixels.show();
  }
  
   else if(diff > 4000){
     pixels.setPixelColor(0, pixels.Color(150,0,150));
     pixels.show();
  }
  
  else
  {
    
     pixels.setPixelColor(0, pixels.Color(0,150,0));
     pixels.show();
  
  }
  
  
 // if(time
  
  

  //analogWrite(A1,fadeValue);
  // print out the value you read:
  //time++;
  //Serial.println("At time "+String(time)+" sensor1 is " + String(s2));
 // Serial.println("At time "+String(time)+" sensor2 is " + String(s2));
  delay(1);        // delay in between reads for stability
}
