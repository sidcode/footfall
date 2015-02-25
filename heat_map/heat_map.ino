#include <Adafruit_NeoPixel.h>
#define NUMPIXELS      1 
#define F0 6

int s2; 
int fadeValue = 0;
unsigned long t2;
int time = 0;
unsigned long off2;
unsigned long on2;
unsigned int diff1;
unsigned int diff2;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, F0, NEO_GRB + NEO_KHZ800);

int flag = 0 ;

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
  s2 = analogRead(A0);
  //Detect contact
   if(s2 >200)
  {
     flag=0;
     off2 = millis();
  }
  else
  
  { 
   flag=1; 
   on2=millis();
  
  }
  
  
 //core heat-mapping logic 
  time = millis();
  diff1 = abs(time - off2);
  diff2 = abs(time - on2);
  
  
 if(diff1< 200000000)
 {
  
  if(diff1 > 60000)
  {
   pixels.setPixelColor(0, pixels.Color(255,0,0));
     pixels.show();  
  }
  if(diff1 > 20000 && diff1 < 
  60000)
 {
   pixels.setPixelColor(0, pixels.Color(255,255,0));
     pixels.show(); 
 } 
  if(diff1 > 10000 && diff1 < 19999)
  {
    pixels.setPixelColor(0, pixels.Color(255,255,255));
     pixels.show(); 
  }
  if(diff1 > 7000 && diff1 < 9999){
     pixels.setPixelColor(0, pixels.Color(0,255,255));
     pixels.show();
  }
  
   if(diff1 > 4000 && diff1 < 6999)
   {
     pixels.setPixelColor(0, pixels.Color(255,0,255));
     pixels.show();
  }
  
  if(diff1<3999)
  {
    pixels.setPixelColor(0, pixels.Color(0,0,30));
     pixels.show();
  }
  
 }
 //managing overflows due to different data lengths
  else
  {
    
     pixels.setPixelColor(0, pixels.Color(0,0,0));
     pixels.show();
  
  }
  
 Serial.println(String(diff1)+"\t"+ String(diff2) + " " + String(s2));
 
 //delay(100);       // delay in between reads for stability
}

