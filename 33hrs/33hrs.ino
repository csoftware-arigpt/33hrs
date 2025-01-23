#include "GyverTM1637.h"
#include "microDS3231.h"
MicroDS3231 rtc;

GyverTM1637 disp(2, 3);

void getCustomTime(uint8_t &customHour, uint8_t &customMinute) {
    uint32_t unixTime = rtc.getUnix(0);
    uint32_t totalMinutes = unixTime / 60;
    customMinute = totalMinutes % 100;
    customHour = (totalMinutes / 100) % 33;
}

void setup() {
    disp.clear();
    disp.brightness(7);
}

void loop() {
    uint8_t hour, minute;
    getCustomTime(hour, minute);
    disp.displayClock(hour, minute);
    disp.point(0);
    delay(500);
    disp.point(1);
    delay(500);
}
