#include "FastLED.h"

/** Hardware configuration **/
#define LED_PIN 6
#define ANALOG_READ 0
#define LED_TYPE NEOPIXEL /* NEOPIXEL WS2812B */

/** Environtment params **/
#define BRIGHTNESS 70   /* Control the brightness of your leds */
#define SATURATION 255  /* Control the saturation of your leds */

class Strip
{
    private:
        int iLedCount = 10;
    
    public:
        int getLedCount()
        {
            return this->iLedCount;
        }

        void rainbow()
        {
            for (int j = 0; j < 255; j++) {
                for (int i = 0; i < this->getLedCount(); i++) {
                    leds[i] = CHSV(i - (j * 2), SATURATION, BRIGHTNESS); /* The higher the value 4 the less fade there is and vice versa */
                }
                FastLED.show();
                delay(30); /* Change this to your hearts desire, the lower the value the faster your colors move (and vice versa) */
            }
        }

        /**
         * Just a fancy action to show in the main setup() method
         */
        void initLights()
        {
            for(int i=0; i<this->getLedCount(); i++)
            {
                leds[i] = CRGB(randomColor(), randomColor(), randomColor());
                FastLED.show();
                delay(80);
            }
        }
        
        /**
         * Turn off all lights
         */
        void clearStrip()
        {
            for(int i=0; i<this->getLedCount(); i++)
            {
                leds[i] = CRGB(0, 0, 0);
            }
        
            FastLED.show();
        }

};
