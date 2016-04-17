#ifndef FIREWORKS_H
#define FIREWORKS_H

#include "animation.h"

class Fireworks : public Animation {
public:
	Fireworks()
	{
		position = 0;
		delay_time = 200;
		explode_phase = 0;
		current_color = CRGB::Blue;//fix later
	}

	void explode(CRGB *leds)
	{
		//if first phase, set current led to black and +-1 LED to color
		if(explode_phase == 1){

		}		
	}
	
	void step()
	{
		leds[position] = CRGB::Black;

		//index position of lit LED
		if(position == 10)
		{			
			if(explode_phase == 2)
			{
				leds[position+2] = CRGB::Black;
				leds[position-2] = CRGB::Black;
				explode_phase++;
			}
			
			if(explode_phase == 1)
			{
				leds[position+1] = CRGB::Black;
				leds[position-1] = CRGB::Black;				
				leds[position+2] = current_color;
				leds[position-2] = current_color;
				explode_phase++;
			}
			
			if(explode_phase == 0)
			{
				delay_time = 50;
				leds[position+1] = current_color;
				leds[position-1] = current_color;
				explode_phase++;
			}
			
			if(explode_phase == 3)
			{
				//reset things
				position = 0;
				explode_phase = 0;
				delay_time = 200;
			    current_color = CHSV(random(255),random(255),random(255));
				leds[position] = current_color;
			}
		}
		else
		{
			position++;
			leds[position] = current_color;
			delay_time = delay_time*1.1;
		}
	// load the CRGB values into led
		FastLED.show();
		delay(delay_time);
	}

private:	
	int position;
	int delay_time;
	int explode_phase;
	CRGB current_color;
	CRGB buffer[NUM_LEDS];
};

Animation * fireworks_factory() {
  return new Fireworks();  
} 

#endif
