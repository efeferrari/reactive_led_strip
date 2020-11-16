#include "FastLED.h"

/** Hardware configuration **/
#define LED_PIN 6
#define ANALOG_READ 0
#define LED_TYPE NEOPIXEL /* antes decía NEOPIXEL WS2812B */

/** Environtment params **/
#define NUM_LEDS 10
#define BRIGHTNESS 70   /* Control the brightness of your leds */
#define SATURATION 255   /* Control the saturation of your leds */

/** Global configs **/
CRGB leds[NUM_LEDS];

void setup() {
  
  Serial.begin(9600);

  // turn on every led to check if all it's working well
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);

  clearStrip();
  delay(250);
  initLights();
}

void loop() {
  rainbow();
}

void rainbow()
{
  for (int j = 0; j < 255; j++) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CHSV(i - (j * 2), SATURATION, BRIGHTNESS); /* The higher the value 4 the less fade there is and vice versa */ 
    }
    FastLED.show();
    delay(30); /* Change this to your hearts desire, the lower the value the faster your colors move (and vice versa) */
  }
}

void initLights()
{
  for(int i=0; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(randomColor(), randomColor(), randomColor());
    FastLED.show();
    delay(80);
  }
}

/**
 * This method turn off al lights
 */
void clearStrip()
{
  for(int i=0; i<NUM_LEDS; i++)
  {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}

/**
 * This method returns a value between 0 ans 255
 */
int randomColor()
{
  return random(0, 255);
}
