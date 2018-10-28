#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

/* Set NeoPixel pin */
#define PIN            15

/* NeoPixel array length */
#define NUMPIXELS      32

/* Assert initial NeoPixel library settings */
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/* Initialize color value variables with random values */
int red = random(0,255);
int green = random(0,255);
int blue = random(0,255);

/* Initializes value for delay between changes */
int delayval = 100;

void setup() {

  /* Initialize NeoPixel Library.*/
  pixels.begin(); 
  /* Open serial port at 115200bps for debugging data */
  Serial.begin(115200);
}

void loop() {

  /* Loop through NeoPixels */
  for(int i=0;i<NUMPIXELS;i++){

    /* Randomly choose a color to vary */
    int colordim = random(1,3);

    /* Randomly vary the chosen color by +/- 1 */
    if (colordim = 1) {red = red + random(-1,1);}
    if (colordim = 2) {green = green + random(-1,1);}
    if (colordim = 3) {blue = blue + random(-1,1);}

    /* Reset out of bounds colors to the extreme */ 
    if (red < 0) {red = 0;}
    if (green < 0) {green = 0;}
    if (blue < 0){blue = 0;}

    if (red > 255 ) {red = 255;}
    if (green > 255 ) {green = 255;}
    if (blue > 255 ){blue = 255;}
    
    /* Set NeoPixel RGB values */  
    pixels.setPixelColor(i, pixels.Color(red, green, blue)); 
    
    /* Send to NeoPixels */
    pixels.show(); 

    /* output values to serial for debugging*/
    Serial.print(red);
    Serial.print("\t");
    Serial.print(green);
    Serial.print("\t");
    Serial.print(blue);
    Serial.print("\n");
    
    /* wait for delayval ms */
    delay(delayval); 

  }
}
