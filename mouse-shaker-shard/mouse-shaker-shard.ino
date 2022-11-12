#include <DigiMouse.h>
#include <oddebug.h>
#include <osccal.h>
#include <osctune.h>
#include <usbconfig-prototype.h>
#include <usbconfig.h>
#include <usbdrv.h>
#include <usbportability.h>

#include "Ramp.h"

#define SLEEP_DELAY 30UL * 60UL * 1000UL
#define DISTANCE 10
#define DISTANCE_TIME 1000
#define PAUSE_DELAY 1UL * 60UL * 1000UL
#define MOVE_TIME 200

int series = 0;
unsigned long pause_delay = 0;
int delta[2] = { 0, 0 };
rampInt tween[3];

void setup() {
  // // pinMode(0, OUTPUT);  //LED on Model B
  // pinMode(1, OUTPUT);  //LED on Model A

  delay(SLEEP_DELAY);

  DigiMouse.begin();

  tween[2].go(DISTANCE, DISTANCE_TIME, LINEAR);
  tween[2].update();
}

void loop() {
  if (tween[2].isFinished()) {
    if (tween[2].getValue() == 0) {
      series += 1;
      int distance = min(DISTANCE * series, 50);
      tween[2].go(distance, DISTANCE_TIME * series, LINEAR);
      pause_delay = millis() + PAUSE_DELAY;
    } else {
      tween[2].go(0, DISTANCE_TIME * series, LINEAR);
    }
  }

  if (millis() > pause_delay) {
    for (int i = 0; i < 2; i++) {
      if (tween[i].isFinished()) {
        if (tween[i].getValue() < 0) {
          tween[i].go(random(tween[i].getValue(), tween[2].update()), MOVE_TIME, BACK_INOUT);
        } else {
          tween[i].go(random(-tween[2].update(), tween[i].getValue()), MOVE_TIME, BACK_INOUT);
        }
        tween[i].update();
      }
      delta[i] = -1 * tween[i].getValue();
      delta[i] += tween[i].update();
    }
    DigiMouse.moveX(delta[0]);
    DigiMouse.moveY(delta[1]);
  }

  DigiMouse.update();
  delay(25);
}

// void ledOn() {
//   // digitalWrite(0, HIGH);
//   digitalWrite(1, HIGH);
// }

// void ledOff() {
//   // digitalWrite(0, LOW);
//   digitalWrite(1, LOW);
// }