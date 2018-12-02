#include <Adafruit_NeoPixel.h>

// Pins
int ledDataPin = 2;
int motionPin = 4;

// State
int pirState = LOW;

uint8_t brightness = 40;
bool someLightsAreOn = false;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(50, ledDataPin, NEO_RGB + NEO_KHZ800);

void setup() {
  pinMode(ledDataPin, OUTPUT);
  pinMode(motionPin, INPUT);
  strip.begin();
  strip.setBrightness(brightness);
  strip.show();
}

void loop() {
  uint8_t pixel, colour;
  int val = 0;

  val = digitalRead(motionPin);

  if (val == HIGH) {
    if (pirState == LOW) {
      pirState = HIGH;
      someLightsAreOn = true;
    }

    pixel = random(strip.numPixels());
    colour = random(255);

    strip.setPixelColor(pixel, strip.Color(colour, colour, colour));
    //    strip.setPixelColor(0, strip.Color(0, 0, 40));

    strip.show();
    delay(200);

  } else if (someLightsAreOn) {
    pirState = LOW;

    //    strip.setPixelColor(0, strip.Color(0, 40, 0));
    //    strip.show();

    // The PIR takes 3 seconds to reset, so just keep the lights on until then
    delay(3000);

    int n = 0;
    for (n = 0; n < strip.numPixels(); n++) {
      strip.setPixelColor(n, strip.Color(0, 0, 0));
      strip.show();
      delay(300);

      if (digitalRead(motionPin) == HIGH) {
        break;
      }
    }
    // Got all the way to the end of the loop
    if (n == strip.numPixels()) {
      someLightsAreOn = false;
    }
    //if (pirState == HIGH) {
    //      strip.clear();
    //      strip.setPixelColor(0, strip.Color(0, 40, 0));
    //      strip.show();

    //}

  }
  else {
    //    strip.setPixelColor(0, strip.Color(40, 0, 0));
    //    strip.show();

    delay(1000);
  }
}
