#ifndef LED_h
#define LED_h

#include "Arduino.h"



#define RED_PIN 22     //22
#define GREEN_PIN 21   //21
#define BLUE_PIN 24    //24

#define AH_LED 0



typedef enum {RED, GREEN, BLUE, YELLOW, PURPLE} color;

class LED{

  public:
    LED(uint8_t redPin, uint8_t greenPin, uint8_t bluePin);
    void flash(color ledColor, double pulseLength);
    void turnOff(void);
    void setColor(color ledColor);
    void pulse(color ledColor, int pulseDelay);
   
  private:
    uint8_t _redPin;
    uint8_t _greenPin;
    uint8_t _bluePin;

    bool _redState;
    bool _greenState;
    bool _blueState;

    bool _ledState;
    
    double _lastEventTime;
    double _currentTime;
    
};

#endif
