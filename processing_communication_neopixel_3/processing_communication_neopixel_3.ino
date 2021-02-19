#include <Adafruit_NeoPixel.h>
#define PIN  13 // what port the neopixels are connected to
#define NUMPIXELS 4 //how many neopixels there are

Adafruit_NeoPixel neo(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  neo.begin();//these two lines set up the neopixels
  neo.setBrightness(50);//sets the brightness of the neopixels
  neo.show();
  Serial.begin(9600);//inializes the serial
}
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<neo.numPixels(); i++) { // For each pixel in strip...
    neo.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    neo.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
void rainbow(int wait) {
  
  for(long firstPixelHue = 0; firstPixelHue < 3*65536; firstPixelHue += 256) {
    for(int i=0; i<neo.numPixels(); i++) { // For each pixel in strip...
      int pixelHue = firstPixelHue + (i * 65536L / neo.numPixels());
      neo.setPixelColor(i, neo.gamma32(neo.ColorHSV(pixelHue)));
    }
    neo.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}
void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<2; a++) {  // Repeat 10 times...
    for(int b=0; b<3; b++) { //  'b' counts from 0 to 2...
      neo.clear();         //   Set all pixels in RAM to 0 (off)
      // 'c' counts up from 'b' to end of strip in steps of 3...
      for(int c=b; c<neo.numPixels(); c += 3) {
        neo.setPixelColor(c, color); // Set pixel 'c' to value 'color'
      }
      neo.show(); // Update strip with new contents
      delay(wait);  // Pause for a moment
    }
  }
}
void loop() {
  if(Serial.available() > 0) {
    char ledState = Serial.read();//reads the serial coming from processing
  
    if(ledState == '1'){// if the serial reads 1 turn light red/green/blue
      
      colorWipe(neo.Color(255,   0,   0), 50);
      colorWipe(neo.Color(0,   255,   0), 50);
      colorWipe(neo.Color(0,   0,   255), 50);
      
    }
    if(ledState == '0'){// if the serial reads 0 turn light rainbow
      
      rainbow(1);
      
    }
    if(ledState == '2'){// if the serial reads 0 turn light rainbow
      theaterChase(neo.Color(127, 127, 127), 50); // White
      theaterChase(neo.Color(127,   0,   0), 50); // Red
      theaterChase(neo.Color(  0,   0, 127), 50); // Blue
    }
  }
}
