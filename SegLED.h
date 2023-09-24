/*!
 * @file SegLED.h
 *
 */

#ifndef SegLED_H
#define SegLED_H

#include <Arduino.h>

/*!
 * @brief Main SegLED class
 */
class SegLED {
public:
  SegLED();
  void helloWorld();


private:
  int16_t ac1, ac2, ac3, b1, b2, mb, mc, md;
  uint16_t ac4, ac5, ac6;
};

#endif //  SegLED_H
