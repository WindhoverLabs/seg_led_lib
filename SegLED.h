/*!
 * @file SegLED.h
 *
 */

#ifndef SegLED_H
#define SegLED_H

#include <Arduino.h>
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 60

// For led chips like WS2812, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
// Clock pin only needed for SPI based chipsets when not using hardware SPI
#define DATA_PIN 6
#define CLOCK_PIN 13

/*!
 * @brief Main SegLED class
 */
class SegLED {
public:
  SegLED();
  void helloWorld();
  void configureLED(); // Maybe call it "begin" to follow conventions
  void testLED();
  void writeSegment(int32_t start, int32_t num);
  void writeSegments(int32_t start, String num);
  void writeFirstSegment(int32_t start);
  void writeSecondSegment(int32_t start);
  void writeThirdSegment(int32_t start);
  void writeFourthSegment(int32_t start);
  void writeFifthSegment(int32_t start);
  void writeSixthSegment(int32_t start);
  void writeSeventhSegment(int32_t star);
  void onLEDSegement(int32_t start);
  void onLED(int32_t index);
  void offLED(int32_t index);

private:
  int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
  uint16_t ac4, ac5, ac6;
  CRGB leds[NUM_LEDS];
};

#endif //  SegLED_H
