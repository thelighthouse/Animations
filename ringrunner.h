#ifndef RINGRUNNER_H
#define RINGRUNNER_H

#include "animation.h"

class RingRunner : public Animation {
public:
	RingRunner()
	{
		position = 0;
		current_color = CRGB::Blue;//fix later
	}

	void mirror_leds(CRGB *leds)
	{
  		for(int i=0; i<NUM_LEDS/2;i++)
  		{
    		buffer[NUM_LEDS-1-i] = leds[i];
    		buffer[i] = leds[i];
  		}
  		for(int i=0; i<NUM_LEDS;i++){
   		 	leds[i] = buffer[i];
  		}

	}
	void step()
	{
		leds[position] = CRGB::Black;

		//index position of lit LED
		if(position == NUM_LEDS/2)
		{
			position = 0;
			current_color = CHSV(random(255),random(255),random(255));
		}
		else
		{
			position++;

		}
	// load the CRGB values into led, mirror around the middle
		leds[position] = current_color;
		mirror_leds(leds);
		FastLED.show();
		delay(100);

	}

private:	
	int position;
	CRGB current_color;
	CRGB buffer[NUM_LEDS];


};

#endif