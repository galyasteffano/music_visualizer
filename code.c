#include <Adafruit_NeoPixel.h>

#define PIN 6


const int sampleWindow=50;
unsigned int sample;
Adafruit_NeoPixel   pixel =Adafruit_NeoPixel(64,PIN,NEO_GRB+NEO_KHZ800);
 

void setup() 
{

 Serial.begin(9600);
 pixel.begin(); 
 pixel.show(); // Initialize all pixels to 'off'
  
}

void loop()
{
  
  unsigned long startMillis=millis(); //start sample window
  unsigned int peakToPeak=0;  //peak to peak level
  
  unsigned int signalMax=0;
  unsigned int signalMin=1024;
  //double freq;
  //colect data for 50 ms

  while(millis()-startMillis<sampleWindow)
  {
    sample=analogRead(0);
    if(sample<1024)  //tos out spurious readings
    {
      if(sample>signalMax)
      {
        signalMax=sample;  //save just the max levels
      }
      else if(sample<signalMin)
      {
        signalMin=sample;//save just min levels
      }
    }
    
  }  
  peakToPeak=signalMax-signalMin;  //max-min=peak to peak amplitude
  double freq=(peakToPeak); 
   Serial.println(freq);

  
    if(freq<20)
    {
      for(int j=0;j<40;j++)
      {
        pixel.setPixelColor(j,0,0,0);
        pixel.show();
  
      }

    }
    Serial.println(freq);
    if(freq>22&&freq<200)   //pink
   {
    for(int i=0;i<8;i++)
    {
      pixel.setPixelColor(i,255,105,105);
      pixel.show();
      
    if(freq>23 &&freq<100)
     {  
        pixel.setPixelColor(7,0,0,0);
        pixel.setPixelColor(6,0,0,0);
        pixel.setPixelColor(5,0,0,0);
        pixel.show();
       // delay(50);
      }
      if(freq>23&&freq<50)
      {
        pixel.setPixelColor(4,0,0,0);
        pixel.setPixelColor(3,0,0,0);
        pixel.show();
      }
     
    }
 }

 

else if(freq>200&&freq<400)    //blue
{
    for(int i=8;i<16;i++)
    {
       pixel.setPixelColor(i,0,0,139);  //blue
       pixel.show();
       
       if(freq>201&&freq<300)
       {
         pixel.setPixelColor(15,0,0,0);
         pixel.setPixelColor(14,0,0,0);
         pixel.setPixelColor(13,0,0,0);
         pixel.show();
        
       }
       if(freq>201&&freq<251)
       {
         pixel.setPixelColor(12,0,0,0);
         pixel.setPixelColor(11,0,0,0);
         pixel.show();
       }
    }
}
else if(freq>400&&freq<600)
{
    for(int i=16;i<24;i++)
    {
      pixel.setPixelColor(i,255,215,0); //baby pink
      pixel.show();
      
      if(freq>400&&freq<500)
      {
        pixel.setPixelColor(23,0,0,0);
        pixel.setPixelColor(22,0,0,0);
        pixel.setPixelColor(21,0,0,0);
        pixel.show();
        
       }
      if(freq>400&&freq<450)
      {
         pixel.setPixelColor(20,0,0,0);
         pixel.setPixelColor(19,0,0,0);
         pixel.show();
         
      }
    }
}
else if(freq>600&&freq<800)
{
    for(int i=24;i<32;i++)
    {
         pixel.setPixelColor(i,204,0,102);//gold 
         pixel.show();
        
         if(freq>600&&freq<700)
         {
            pixel.setPixelColor(31,0,0,0);
            pixel.setPixelColor(30,0,0,0);
            pixel.setPixelColor(29,0,0,0);
            pixel.show(); 
          
         }
         if(freq>600 && freq<650)
         {
           pixel.setPixelColor(28,0,0,0);
           pixel.setPixelColor(27,0,0,0);
           pixel.show();
         }
    }
}
 else if(freq>800&&freq<1000)
 {
   theaterChase(pixel.Color(127,127,127),50);
  
  }
}


void theaterChase(uint32_t c, uint8_t wait)
{
  for (int j=0; j<10; j++) 
  {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) 
    {
      for (int i=0; i < pixel.numPixels()-2; i=i+3)
      {
        pixel.setPixelColor(i+q, c);    //turn every third pixel on
      }
      pixel.show();
     
      delay(wait);
     
      for (int i=0; i < pixel.numPixels()-2; i=i+3)
      {
        pixel.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }

  }
}
 


 





