#include <Adafruit_NeoPixel.h>

// Pins
int ledDataPin = 2;
int motionPin = 4;

// State
int pirState = LOW;

uint8_t brightness = 255;

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
    }

    pixel = random(strip.numPixels());
    colour = random(255);

    strip.setPixelColor(pixel, strip.Color(colour, colour, colour));

    strip.show();
    delay(200);

  } else {
    if (pirState == HIGH) {
      pirState = LOW;
      strip.clear();
      strip.show();
    }

    delay(500);
  }
}

//int anyLightsAreOn(Adafruit_NeoPixel lights) {
//  for(int n = 0; n < l; n++) {
//
//  }
//}
