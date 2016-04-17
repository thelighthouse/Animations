#ifndef ANIMATION_H
#define ANIMATION_H

//typedef void (*Pattern) (); //define the pattern class
class Animation
{
/*
** Class that stores all of the animations that are being used in an LED array
** Purpose: Loop only calls Animation.animate: a function that essentailly loops the 
**
*/

	// Class Member Variables
	// FRAMERATE, 
	// These are initialized at startup
	//int NUM_LEDS; // number of LEDS on the animation. May change this for multiple strips. Taken out for now. 
	//Pattern *Patternlist; // List of animation pattern functions
public:
	//initialize
	//inline virtual void begin(){ /*nothing*/ };
	//step function must be implemented
	virtual void step() = 0;
};

/*
	Animation(Pattern List[], int numpatterns)
	{
		//NUM_LEDS = num;
		Patternlist = List;
		NUM_PATTERNS = numpatterns;
		current_pattern=0;
	}
	virtual 
	void animate()
	{
		Patternlist[current_pattern]();
	}

	void iterate_animation() //simple for purposes of testing
	{
		if(current_pattern ==NUM_PATTERNS-1){
			current_pattern =0;
		}
		else{
			current_pattern++;
		}
	}
	void set_current_animation(int pcode)
	{
		lastpattern = pcode;
	}
	int get_current_animation()
	{
		return(current_pattern)
	}
private:
	int current_pattern;
	int NUM_PATTERNS;
	int lastpattern;
};
*/
#endif
