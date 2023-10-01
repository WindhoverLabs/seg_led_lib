/*!
 * @file SegLED.cpp
 */

#include "SegLED.h"

SegLED::SegLED() {}

void SegLED::helloWorld() {
  Serial.println("Hello from SegLED");
}

/**
 * TODO: I think eventually this should be callback given by the user
*/
void SegLED::configureLED()
{
      // Uncomment/edit one of the following lines for your leds arrangement.
    // ## Clockless types ##
  // Serial.begin(9600);
  // pinMode(ledPin, OUTPUT);
  // while (!Serial);

  // Serial.println("Hello World"); 
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  // Serial.println("Hello World2"); 
  FastLED.setBrightness(255);
    // FastLED.addLeds<SM16703, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1829, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1812, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS1904, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<UCS2903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2852, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<GS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA106, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<PL9823, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SK6822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2813, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2811_400, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GE8822, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD1886, DATA_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<LPD1886_8BIT, DATA_PIN, RGB>(leds, NUM_LEDS);
    // ## Clocked (SPI) types ##
    // FastLED.addLeds<LPD6803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<WS2803, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
    // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical
    // FastLED.addLeds<SK9822, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);  // BGR ordering is typical

}

void SegLED::onLED(int32_t index)
{
  leds[index] = CRGB ( 0, 255, 0);
  FastLED.delay(100);
  FastLED.show();
}

void SegLED::offLED(int32_t index)
{
  leds[index] = CRGB ( 0, 0, 0);
  FastLED.show();
}

void SegLED::testLED()
{
    // Turn the LED on, then pause
  for(int i = 42;i<NUM_LEDS;i++)
  {
      leds[i] = CRGB ( 0, 255, 0);
      FastLED.delay(100);
      FastLED.show();
  }
}

void SegLED::onLEDSegement(int32_t start)
{
    for(int i = start;i<start+3;i++)
  {
      leds[i] = CRGB ( 255, 255, 0);
  }
}


void SegLED::writeSegment(int32_t start, int32_t num)
{
  switch (num)
  {
    case 0:
    {
      onLEDSegement(start+3);
      onLEDSegement(start+6);
      onLEDSegement(start+9);
      onLEDSegement(start+13);
      onLEDSegement(start+16);
      onLEDSegement(start+19);
      break;
    }
    case 1:
    {
      onLEDSegement(start+3);
      onLEDSegement(start+19);
      break;
    }
    case 2:
    {
      onLEDSegement(start+16);
      onLEDSegement(start+19);
      onLEDSegement(start);
      onLEDSegement(start+9);
      onLEDSegement(start+6);
      break;
    }
    case 3:
    {
      onLEDSegement(start+16);
      onLEDSegement(start+19);
      onLEDSegement(start);
      onLEDSegement(start+19);
      onLEDSegement(start+6);
      onLEDSegement(start+3);
      break;
    }
    case 4:
    {
      onLEDSegement(start+13);
      onLEDSegement(start);
      onLEDSegement(start+19);
      onLEDSegement(start+3);
      break;
    }
    case 5:
    {
      onLEDSegement(start+16);
      onLEDSegement(start+13);
      onLEDSegement(start);
      onLEDSegement(start+3);
      onLEDSegement(start+6);
      break;
    }
    case 6:
    {
      onLEDSegement(start+16);
      onLEDSegement(start+13);
      onLEDSegement(start);
      onLEDSegement(start+3);
      onLEDSegement(start+6);
      onLEDSegement(start+9);
      break;
    }
    case 7:
    {
      onLEDSegement(start+16);
      onLEDSegement(start+19);
      onLEDSegement(start+3);
      break;
    }
    case 8:
    {
      onLEDSegement(start);
      onLEDSegement(start+3);
      onLEDSegement(start+6);
      onLEDSegement(start+9);
      onLEDSegement(start+13);
      onLEDSegement(start+16);
      onLEDSegement(start+19);
      break;
    }
    case 9:
    {
      onLEDSegement(start);
      onLEDSegement(start+3);
      onLEDSegement(start+13  );
      onLEDSegement(start+16);
      onLEDSegement(start+19);
      break;
    }
  }
}

void SegLED::writeSegments(int32_t start, String num)
{
  int startIndex = start;
  FastLED.clear();
 for(int i = 0; i<num.length();i++)
 {
  writeSegment(startIndex, num.substring(i, i+1).toInt());
  startIndex += 25;
 }

  FastLED.show();
}