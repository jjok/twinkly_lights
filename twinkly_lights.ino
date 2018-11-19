#include <Adafruit_NeoPixel.h>

int ledDataPin = 2;
int motionPin = 4;              // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
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

  
    val = digitalRead(motionPin);  // read input value
    if (val == HIGH) {            // check if the input is HIGH
//        digitalWrite(ledPin, HIGH);  // turn LED ON
        if (pirState == LOW) {
//            // We only want to print on the output change, not state
            pirState = HIGH;
        }
        
        pixel = random(strip.numPixels());
        colour = random(255);
        dimmedColour = colour * brightness;
  
        strip.setPixelColor(pixel, strip.Color(dimmedColour, dimmedColour, dimmedColour));

        strip.show();
        delay(100);

    } else {
        if (pirState == HIGH){
//            // We only want to print on the output change, not state
            pirState = LOW;    
            strip.clear();     
            strip.show();    
        }
        
        delay(500);
    }
}
