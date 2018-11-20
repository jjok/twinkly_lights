#include <Adafruit_NeoPixel.h>

// Pins
int ledDataPin = 2;
int motionPin = 4;

// State
int pirState = LOW;

double brightness = 1;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, ledDataPin, NEO_RGB + NEO_KHZ800);

void setup() {
  pinMode(ledDataPin, OUTPUT);
  pinMode(motionPin, INPUT);
  strip.begin();
  strip.show();
}

void loop() {
  uint8_t pixel, colour, dimmedColour;
  int val = 0;

  val = digitalRead(motionPin);

  if (val == HIGH) {
    if (pirState == LOW) {
      pirState = HIGH;
    }

    pixel = random(strip.numPixels());
    colour = random(255);
    dimmedColour = colour * brightness;

    strip.setPixelColor(pixel, strip.Color(dimmedColour, dimmedColour, dimmedColour));

    strip.show();
    delay(100);

  } else {
    if (pirState == HIGH) {
      pirState = LOW;
      strip.clear();
      strip.show();
    }

    delay(500);
  }
}
