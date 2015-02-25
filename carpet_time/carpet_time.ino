#include <Adafruit_NeoPixel.h>


//define all neopixel flora F numbers
#define NUMPIXELS 1
#define F0 3
#define F1 2
#define F2 10
#define F3 9



Adafruit_NeoPixel p0 = Adafruit_NeoPixel(NUMPIXELS, F0, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel p1 = Adafruit_NeoPixel(NUMPIXELS, F1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel p2 = Adafruit_NeoPixel(NUMPIXELS, F2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel p3 = Adafruit_NeoPixel(NUMPIXELS, F3, NEO_GRB + NEO_KHZ800);

//containers for handling the heat_map
unsigned long off[4] , on[4];
unsigned int diff_on[4], diff_off[4];

int delayval = 100;

int fadeValue = 0;
int time = 0;
int sensor[4];
int counter[4];

// the setup routine runs once when you press reset:

void setup() {
  // initialize serial communication at 9600 bits per second:
  p0.begin();
  p1.begin();
  p2.begin();
  p3.begin();
  p0.show();
  p1.show();
  p2.show();
  p3.show();
  Serial.begin(9600);
    
}

void loop() {
  
  //get analog readings
  /*
  p1.setPixelColor(0,p1.Color(0,0,150));
         p1.show();
  
   p2.setPixelColor(0,p2.Color(0,150,0));
         p2.show();
         
        p3.setPixelColor(0,p3.Color(0,0,150));
         p3.show();  
         
         delay(2000);
         p0.setPixelColor(0,p0.Color(150,0,0));
         p0.show();
         
         delay(2000);
         
         p0.setPixelColor(0,p0.Color(0,150,0));
         p0.show();
         
         delay(2000);
         
         p0.setPixelColor(0,p0.Color(150,150,150));
         p0.show();
         */
  
 
  
  sensor[0] = analogRead(A2);
  sensor[1] = analogRead(A3);
  sensor[2] = analogRead(A4);
  sensor[3] = analogRead(A5);
  
  Serial.println("Sensor 1 is : "+String(sensor[1]));  //Detect press and time and LED logic
  //NeoPixel Flora LEDs 0,1,2,3 connected to 9,10,11,12
  //delay(50);
  
  
  //Counter Logic
  for(int i = 0; i < 4; i++)
  {
    //increase counter with every 
    if(sensor[i] > 280)
    {
      off[i] = millis();
    }
    
    else
   {
     
     on[i] = millis();
   } 
   
  }// get press times
  
    
  //Color Logic
 time = millis();
 
 for(int i = 0; i<4; i++)
 {
 diff_off[i] = abs(time - off[i]);
 diff_on[i] = abs(time - on[i]); 
 }
  
  //Heat Map
  heatMap();
  //need to keep time

}



    void heatMap()
    {
      /////0
        if(diff_off[0]< 200000000)
     {
      if(diff_off[0] > 60000)
        {
         p0.setPixelColor(0,p0.Color(255,0,0));
         p0.show();
        }
      if(diff_off[0] > 20000 && diff_off[0] < 60000)
       {
        p0.setPixelColor(0,p0.Color(255,255,0));
         p0.show();
         
       } 
      if(diff_off[0] > 10000 && diff_off[0] < 19999)
      {
        p0.setPixelColor(0,p0.Color(255,255,255));
         p0.show();
        
      }
       if(diff_off[0] > 7000 && diff_off[0] < 9999)
      {
       p0.setPixelColor(0,p0.Color(0,255,255));
         p0.show();
        
      }
  
     if(diff_off[0] > 4000 && diff_off[0] < 6999)
      {
       p0.setPixelColor(0,p0.Color(255,0,255));
         p0.show();
        
      }
     if(diff_off[0]<3999)
      {
          p0.setPixelColor(0,p0.Color(0,0,30));
         p0.show();
        
      }
   }
 //managing overflows due to different data lengths
  else
  { 
     p0.setPixelColor(0,p0.Color(0,0,0));
         p0.show();
        
  }
      /////
      
        if(diff_off[1]< 200000000)
     {
      if(diff_off[1] > 60000)
        {
         p1.setPixelColor(0,p1.Color(255,0,0));
         p1.show();
        }
      if(diff_off[1] > 20000 && diff_off[1] < 60000)
       {
        p1.setPixelColor(0,p1.Color(255,255,0));
         p1.show();
         
       } 
      if(diff_off[1] > 10000 && diff_off[1] < 19999)
      {
        p1.setPixelColor(0,p1.Color(255,255,255));
         p1.show();
        
      }
       if(diff_off[1] > 7000 && diff_off[1] < 9999)
      {
       p1.setPixelColor(0,p1.Color(0,255,255));
         p1.show();
        
      }
  
     if(diff_off[1] > 4000 && diff_off[1] < 6999)
      {
       p1.setPixelColor(0,p1.Color(255,0,255));
         p1.show();
        
      }
     if(diff_off[1]<3999)
      {
          p1.setPixelColor(0,p1.Color(0,0,30));
         p1.show();
        
      }
 }
 //managing overflows due to different data lengths
  else
  { 
     p1.setPixelColor(0,p1.Color(0,0,0));
         p1.show();
        
  }
  
    if(diff_off[2]< 200000000)
     {
      if(diff_off[2] > 60000)
        {
         p2.setPixelColor(0,p2.Color(255,0,0));
         p2.show();
        }
      if(diff_off[2] > 20000 && diff_off[2] < 60000)
       {
        p2.setPixelColor(0,p2.Color(255,255,0));
         p2.show();
         
       } 
      if(diff_off[2] > 10000 && diff_off[2] < 19999)
      {
        p2.setPixelColor(0,p2.Color(255,255,255));
         p2.show();
        
      }
       if(diff_off[2] > 7000 && diff_off[2] < 9999)
      {
       p2.setPixelColor(0,p2.Color(0,255,255));
         p2.show();
        
      }
  
     if(diff_off[2] > 4000 && diff_off[2] < 6999)
      {
       p2.setPixelColor(0,p2.Color(255,0,255));
         p2.show();
        
      }
     if(diff_off[2]<3999)
      {
          p2.setPixelColor(0,p2.Color(0,0,30));
         p2.show();
        
      }
 }
 //managing overflows due to different data lengths
  else
  { 
     p2.setPixelColor(0,p2.Color(0,0,0));
         p2.show();
        
  }
  
    if(diff_off[3]< 200000000)
     {
      if(diff_off[3] > 60000)
        {
         p3.setPixelColor(0,p3.Color(255,0,0));
         p3.show();
        }
      if(diff_off[3] > 20000 && diff_off[3] < 60000)
       {
        p3.setPixelColor(0,p3.Color(255,255,0));
         p3.show();
         
       } 
      if(diff_off[3] > 10000 && diff_off[3] < 19999)
      {
        p3.setPixelColor(0,p3.Color(255,255,255));
         p3.show();
        
      }
       if(diff_off[3] > 7000 && diff_off[3] < 9999)
      {
       p3.setPixelColor(0,p3.Color(0,255,255));
         p3.show();
        
      }
  
     if(diff_off[3] > 4000 && diff_off[3] < 6999)
      {
       p3.setPixelColor(0,p3.Color(255,0,255));
         p3.show();
        
      }
     if(diff_off[3]<3999)
      {
          p3.setPixelColor(0,p3.Color(0,0,30));
         p3.show();
        
      }
 }
 //managing overflows due to different data lengths
  else
  { 
     p3.setPixelColor(0,p3.Color(0,0,0));
         p3.show();
        
  }  
      
}//heatMap





