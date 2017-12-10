/*
 * Seven Segment LED Clock
 * 
 * Author: Agastya Jindal
 * Date: 10 Dec, 2017
 * Student of III-E, Bal Bharti Public School, New Delhi
 * 
 * Programming help by Amit Jindal (father)
 * 
 * (c) Copyrights Agastya Jindal, 2017. All rights reserved.
 */

#include <Time.h>
#include <TimeLib.h>
#include <SevenSeg.h>

// Define 7 segment display pin connections
SevenSeg disp(13,2,3,4,5,6,7);

// We plan to use 4 digits
const int numOfDigits=4;

// Defining array for those 4 digits.
int digitPins[numOfDigits]={12,11,10,9};

// Switches for incrementing time
#define SW_HOUR   1
#define SW_MIN    0

void setup() {
   disp.setDigitPins(numOfDigits, digitPins);
   disp.setDPPin(8);
   pinMode(SW_HOUR, INPUT);
   pinMode(SW_MIN,  INPUT);
   // Set a fake time to initialize. Anything is good.
   setTime(5,40, 00, 10, 12, 2017);
}

// Buffer to hold printable time
char buff[10];

void loop() {
  int hr = hour();
  int mn = minute();
  int sec = second();

  if (digitalRead(SW_HOUR) == LOW) {
    // Increase Hour
    hr = hr + 1;
    if (hr > 23) hr = 0;
    setTime(hr, mn, sec, 10, 12, 2017);
    delay(200);
  }
  
  if (digitalRead(SW_MIN) == LOW) {
    // Increase Minute
    mn = mn + 1;
    if (mn == 60) {
      mn = 0;
      hr = hr + 1;
    }
    if (hr > 23) hr = 0;
    setTime(hr, mn, sec, 10, 12, 2017);
    delay(200);
  }
  if (hr > 12) hr = hr-12;
  sprintf(buff, "%2d%s%02d", hr, (sec%2==0?".":"") ,mn);
  disp.write(buff);
}

