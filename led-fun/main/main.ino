#include "Bounce2.h"
#include "FastLED.h"

#define NUM_LEDS 240
#define LED_DATA_PIN 30
#define BUTTON_PIN 32

CRGB leds[NUM_LEDS];

// Max number of shooting pixels
#define MAX_NUM_INDICES 200
int led_indices[MAX_NUM_INDICES];

Bounce bouncer = Bounce(); 

void setup() {
  FastLED.addLeds<WS2811, LED_DATA_PIN>(leds, NUM_LEDS);
  
  pinMode(BUTTON_PIN,INPUT);
  bouncer.attach(BUTTON_PIN);
  bouncer.interval(1);
  
  for (int i = 0; i < MAX_NUM_INDICES; i++) {
    led_indices[i] = -1;
  }  
}

void loop() {
  int bc = bouncer.update();
  int bs = bouncer.read();

  // If this is a new button press
  if (bs == 1 && bc == 1) {
    // Fire a new pixel
    for (int i = 0; i < MAX_NUM_INDICES; i++) {
      if (led_indices[i] == -1) {
        led_indices[i] = 0;
        break;
      }
    }
  } else {
    // Move all pixels forward, killing them when they run off the end
    for (int i = 0; i < MAX_NUM_INDICES; i++) {
      if (led_indices[i] != -1)
        led_indices[i] = (led_indices[i] + 1);
        if (led_indices[i] == NUM_LEDS)
          led_indices[i] = -1;
    }
  }

  // Light up pixels
  for (int i = 0; i < MAX_NUM_INDICES; i++) {
    if (led_indices[i] != -1)
      leds[led_indices[i]].r = 10;
      leds[led_indices[i]].g = 10;
      leds[led_indices[i]].b = 10;
  }
  FastLED.show();
  delay(15);

  // Kill pixels
  for (int i = 0; i < MAX_NUM_INDICES; i++) {
    if (led_indices[i] != -1)
      leds[led_indices[i]] = CRGB::Black;
  }
  FastLED.show();
  delay(5);
}
